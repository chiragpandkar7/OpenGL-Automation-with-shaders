#pragma once
#include "Point2D.h"
#include "pch.h"
class GEOMETRY_API Line
{
public:
	Line(Point2D p1, Point2D p2);
	~Line();

public:
	Point2D getP1();
	Point2D getP2();
	void setP1(Point2D);
	void setP2(Point2D);
private:
	Point2D mP1;
	Point2D mP2;
};
