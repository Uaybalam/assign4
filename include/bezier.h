#ifndef BEZIER_H
#define BEZIER_H

#include "point.h"
#include <vector>

Point bezier(float t, const std::vector<Point>& controlPoints);

#endif // BEZIER_H
