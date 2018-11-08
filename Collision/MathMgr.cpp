#include "stdafx.h"
#include "MathMgr.h"


CMathMgr::CMathMgr()
{
}


CMathMgr::~CMathMgr()
{
}

float CMathMgr::SlopeToRadian(float fY, float fX)
{
    float fRadian = atan2f(fY, fX);
    return fRadian;
}

float CMathMgr::CalcDist(POINT tDst, POINT tSrc)
{
    float fDX = tDst.x - tSrc.x;
    float fDY = tDst.y - tSrc.y;
    return sqrtf(fDX * fDX + fDY * fDY);
}


