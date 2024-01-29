// Bezier.cpp : Defines the exported functions for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "Bezier.h"


// This is an example of an exported variable
BEZIER_API int nBezier=0;

// This is an example of an exported function.
BEZIER_API int fnBezier(void)
{
    return 0;
}

// This is the constructor of a class that has been exported.
CBezier::CBezier()
{
    return;
}
