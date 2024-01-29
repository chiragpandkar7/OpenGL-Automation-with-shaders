// Hermite.cpp : Defines the exported functions for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "Hermite.h"


// This is an example of an exported variable
HERMITE_API int nHermite=0;

// This is an example of an exported function.
HERMITE_API int fnHermite(void)
{
    return 0;
}

// This is the constructor of a class that has been exported.
CHermite::CHermite()
{
    return;
}
