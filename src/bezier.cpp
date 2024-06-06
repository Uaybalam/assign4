#include "bezier.h"
#include <cmath>

Point bezier(float t, const std::vector<Point>& controlPoints) {
    Point result = {0.0f, 0.0f};
    size_t n = controlPoints.size() - 1;
    for (size_t i = 0; i <= n; ++i) {
        float binomialCoeff = 1.0;
        for (size_t j = 1; j <= i; ++j) {
            binomialCoeff *= float(n - (i - j)) / j;
        }
        float powT = pow(t, i);
        float powOneMinusT = pow(1.0f - t, n - i);
        result.x += binomialCoeff * powT * powOneMinusT * controlPoints[i].x;
        result.y += binomialCoeff * powT * powOneMinusT * controlPoints[i].y;
    }
    return result;
}
