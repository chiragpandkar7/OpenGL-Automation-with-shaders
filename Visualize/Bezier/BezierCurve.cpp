#include "pch.h"
#include "BezierCurve.h"

#include <vector>

BezierCurve::BezierCurve(std::vector<Point2D> points, std::vector<float>& curvePoints) : mControlPoints(points)
{
    calculateBezier(curvePoints);
}

BezierCurve::~BezierCurve()
{
}

void BezierCurve::calculateBezier(std::vector<float>& cp)
{
    for (double t = 0; t <= 1; t += 0.01) {
        Point2D r = evaluateBezier(t);
        cp.push_back(r.x());
        cp.push_back(r.y());
    }
}

Point2D BezierCurve::evaluateBezier(double t)
{
    double u = 1.0 - t;
    double tt = t * t;
    double uu = u * u;
    double uuu = uu * u;
    double ttt = tt * t;

    double x = uuu * mControlPoints[0].x() + 3 * uu * t * mControlPoints[1].x() + 3 * u * tt * mControlPoints[2].x() + ttt * mControlPoints[3].x();
    double y = uuu * mControlPoints[0].y() + 3 * uu * t * mControlPoints[1].y() + 3 * u * tt * mControlPoints[2].y() + ttt * mControlPoints[3].y();
    Point2D p(x, y);

    return p;
}