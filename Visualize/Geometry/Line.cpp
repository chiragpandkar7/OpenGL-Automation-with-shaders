#include "pch.h"
#include "Line.h"

Line::Line(Point2D p1, Point2D p2) : mP1(p1), mP2(p2)
{
}
Line::~Line() {}

Point2D Line::getP1()
{
	return mP1;
}

Point2D Line::getP2()
{
	return mP2;
}

void Line::setP1(Point2D p)
{
	mP1 = p;
}

void Line::setP2(Point2D p)
{
	mP2 = p;
}