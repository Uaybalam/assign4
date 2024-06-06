#include "drawing.h"
#include "bezier.h"
#include <GL/glew.h>
#include <GL/glut.h>

void drawPoint(Point p) {
    glPointSize(10.0);
    glBegin(GL_POINTS);
    glColor3f(1.0, 0.0, 0.0); // Rojo para puntos
    glVertex2f(p.x, p.y);
    glEnd();
}

void drawLine(Point p1, Point p2) {
    glBegin(GL_LINES);
    glColor3f(0.0, 1.0, 0.0); // Verde para líneas
    glVertex2f(p1.x, p1.y);
    glVertex2f(p2.x, p2.y);
    glEnd();
}

void drawPolyLines(const std::vector<Point>& points) {
    if (points.size() < 2) return;
    for (size_t i = 0; i < points.size() - 1; ++i) {
        drawLine(points[i], points[i + 1]);
    }
}

void drawBezierCurve(const std::vector<Point>& points) {
    if (points.size() != 4) return;

    glColor3f(0.0, 0.0, 1.0); // Azul para la curva de Bézier
    glBegin(GL_LINE_STRIP);
    for (float t = 0.0; t <= 1.0; t += 0.01) {
        Point p = bezier(t, points);
        glVertex2f(p.x, p.y);
    }
    glEnd();
}
