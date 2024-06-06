#include <GL/glew.h>
#include <GL/glut.h>
#include "point.h"
#include "drawing.h"
#include <vector>
#include <iostream>

std::vector<Point> points; // Vector para almacenar puntos

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    for (const Point& p : points) {
        drawPoint(p);
    }

    if (points.size() == 4) {
        drawPolyLines(points);
        drawBezierCurve(points);
    }

    glutSwapBuffers();
}

void mouse(int button, int state, int x, int y) {
    if (state == GLUT_DOWN) {
        float xPos = (float)x / (glutGet(GLUT_WINDOW_WIDTH) / 2) - 1.0f;
        float yPos = 1.0f - (float)y / (glutGet(GLUT_WINDOW_HEIGHT) / 2);
        
        if (button == GLUT_LEFT_BUTTON && points.size() < 4) {
            points.push_back({xPos, yPos});
        } else if (button == GLUT_RIGHT_BUTTON && !points.empty()) {
            points.pop_back();
        }
        glutPostRedisplay();
    }
}

void initOpenGL() {
    glClearColor(0.5f, 0.5f, 1.0f, 1.0f); // Fondo azul claro
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Bezier Curve Drawing");

    glewInit();
    initOpenGL();

    glutDisplayFunc(display);
    glutMouseFunc(mouse);

    glutMainLoop();
    return 0;
}
