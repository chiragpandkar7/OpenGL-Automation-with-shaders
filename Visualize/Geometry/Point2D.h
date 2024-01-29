#pragma once

#include "pch.h"
class GEOMETRY_API Point2D
{
public:
    Point2D(float inX, float inY);
    ~Point2D();

    float x();
    float y();

    void setX(float x);
    void setY(float y);

private:
    float mX;
    float mY;
};