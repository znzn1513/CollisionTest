#pragma once
class CObj;
class CCollisionMgr
{
private:
    CCollisionMgr();
    ~CCollisionMgr();

public:
    static void BasicCollision(list<CObj*>& pDst, CObj* pSrc);
    static void AdvancedCollision(list<CObj*>& pDst, CObj* pSrc);

private:
    static bool CheckRect(const INFO& pDst, const INFO& pSrc, float& fMoveX, float& fMoveY);
};

