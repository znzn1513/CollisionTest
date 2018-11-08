#pragma once
class CMathMgr
{
private:
    explicit CMathMgr();
    virtual ~CMathMgr();

public:
    static float SlopeToRadian(float fY, float fX);
    static float CalcDist(POINT tDst, POINT tSrc);
};

