#pragma once
#include "pch.h"
#include "Point2D.h"
#include<vector>

class HERMITE_API HermiteCurve
{
public:
	HermiteCurve(std::vector<Point2D> points, std::vector<float>& curvePoints);
	~HermiteCurve();

private:
	void calculateHermite(std::vector<float>& curvePoints);
	Point2D evaluateHermite(double t);
private:
	std::vector<Point2D> mControlPoints;
};