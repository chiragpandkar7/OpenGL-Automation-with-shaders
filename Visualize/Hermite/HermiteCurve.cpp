#include "pch.h"
#include "HermiteCurve.h"

#include <vector>

HermiteCurve::HermiteCurve(std::vector<Point2D> points, std::vector<float>& curvePoints) : mControlPoints(points)
{
    calculateHermite(curvePoints);
}

HermiteCurve::~HermiteCurve()
{
}

void HermiteCurve::calculateHermite(std::vector<float>& cp)
{
    for (double t = 0; t <= 1; t += 0.01) {
        Point2D r = evaluateHermite(t);
        cp.push_back(r.x());  
        cp.push_back(r.y());
    }
}

Point2D HermiteCurve::evaluateHermite(double t)
{
    double t2 = t * t;
    double t3 = t2 * t;

    double h1 = 2 * t3 - 3 * t2 + 1;
    double h2 = -2 * t3 + 3 * t2;
    double h3 = t3 - 2 * t2 + t;
    double h4 = t3 - t2;

    double x = h1 * mControlPoints[0].x() + h2 * mControlPoints[1].x() + h3 * mControlPoints[2].x() + h4 * mControlPoints[3].x();
    double y = h1 * mControlPoints[0].y() + h2 * mControlPoints[1].y() + h3 * mControlPoints[2].y() + h4 * mControlPoints[3].y();

    return Point2D(x, y);
}
