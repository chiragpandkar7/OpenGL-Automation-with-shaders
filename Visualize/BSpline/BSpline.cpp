// BSpline.cpp : Defines the exported functions for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "BSpline.h"


// This is an example of an exported variable
BSPLINE_API int nBSpline=0;

// This is an example of an exported function.
BSPLINE_API int fnBSpline(void)
{
    return 0;
}

// This is the constructor of a class that has been exported.
CBSpline::CBSpline()
{
    return;
}
