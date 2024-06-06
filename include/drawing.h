#ifndef DRAWING_H
#define DRAWING_H

#include "point.h"
#include <vector>

void drawPoint(Point p);
void drawLine(Point p1, Point p2);
void drawPolyLines(const std::vector<Point>& points);
void drawBezierCurve(const std::vector<Point>& points);

#endif // DRAWING_H
