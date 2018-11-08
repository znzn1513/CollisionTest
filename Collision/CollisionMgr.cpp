#include "stdafx.h"
#include "CollisionMgr.h"
#include "Obj.h"
#include "Movable.h"
CCollisionMgr::CCollisionMgr()
{
}


CCollisionMgr::~CCollisionMgr()
{
}

void CCollisionMgr::BasicCollision(list<CObj*>& pDst, CObj * pSrc)
{
    for (auto& pBlock : pDst)
    {
        float fMoveX = 0;
        float fMoveY = 0;
        if (CheckRect(pBlock->GetInfo(), pSrc->GetInfo(), fMoveX, fMoveY))
        {
            PushObj(pBlock, pSrc, fMoveX, fMoveY);
        }
    }
}

void CCollisionMgr::AdvancedCollision(list<CObj*>& pDst, CObj * pSrc)
{
    for (auto& pBlock : pDst)
    {
        float fMoveX = 0;
        float fMoveY = 0;
        INFO tInfo{};
        if (CheckPenetrate(pBlock->GetInfo(), pSrc->GetInfo(), fMoveX, fMoveY, &tInfo))
        {
            pSrc->SetPos(tInfo.fX, tInfo.fY);
            AdvancedPush(pBlock, pSrc, fMoveX, fMoveY);
            return;
        }
    }
}

bool CCollisionMgr::CheckRect(const INFO & pDst, const INFO & pSrc, float & fMoveX, float & fMoveY)
{
    float fDX = pDst.fX - pSrc.fX;
    float fDY = pDst.fY - pSrc.fY;
    
    if (fDX < 0)
        fDX *= -1.f;
    if (fDY < 0)
        fDY *= -1.f;

    float fSumCX = pDst.fCX + pSrc.fCX;
    float fSumCY = pDst.fCY + pSrc.fCY;

    fMoveX = fSumCX*0.5f - fDX;
    fMoveY = fSumCY*0.5f - fDY;

    if (fMoveX > 0 && fMoveY > 0)
        return true;
    else
        return false;
}

bool CCollisionMgr::CheckPenetrate(const INFO & pDst, const INFO & pSrc, float & fMoveX, float & fMoveY, INFO* tInfo)
{
    float fAngle = CMathMgr::SlopeToRadian(pSrc.fYSpd, pSrc.fXSpd);

    int iNum = sqrtf(pSrc.fYSpd*pSrc.fYSpd + pSrc.fXSpd * pSrc.fXSpd) / (BLOCK_CX*0.5f);
    //길이를 한번 이동값으로 나눴다!
    INFO tNextSrc = pSrc;
    for (int i = 0; iNum >= i; ++i)
    {
        tNextSrc.fX = pSrc.fX + pSrc.fXSpd*(i / float(iNum));
        tNextSrc.fY = pSrc.fY + pSrc.fYSpd*(i / float(iNum));
        if (CheckRect(pDst, tNextSrc, fMoveX, fMoveY))
        {
            *tInfo = tNextSrc;
            return true;
        }
    }
    tNextSrc.fX = pSrc.fX + pSrc.fXSpd;
    tNextSrc.fY = pSrc.fY + pSrc.fYSpd;
    if (CheckRect(pDst, tNextSrc, fMoveX, fMoveY))
    {
        *tInfo = tNextSrc;
        return true;
    }
    return false;
}

void CCollisionMgr::PushObj(CObj* pBlock, CObj * pObj, const float & fMoveX, const float & fMoveY)
{
    if (fMoveX > fMoveY)
    {
        if (pBlock->GetInfo().fY > pObj->GetInfo().fY)
        {
            pObj->SetPos(pObj->GetInfo().fX, pObj->GetInfo().fY - fMoveY);
            dynamic_cast<CMovable*>(pObj)->BlockY();
        }
        else
        {
            pObj->SetPos(pObj->GetInfo().fX, pObj->GetInfo().fY + fMoveY);
            dynamic_cast<CMovable*>(pObj)->BlockY();
        }
    }
    else
    {
        if (pBlock->GetInfo().fX > pObj->GetInfo().fX)
        {
            pObj->SetPos(pObj->GetInfo().fX - fMoveX, pObj->GetInfo().fY);
            dynamic_cast<CMovable*>(pObj)->BlockX();
        }
        else
        {
            pObj->SetPos(pObj->GetInfo().fX + fMoveX, pObj->GetInfo().fY);
            dynamic_cast<CMovable*>(pObj)->BlockX();
        }
    }
}

void CCollisionMgr::AdvancedPush(CObj * pBlock, CObj * pObj, const float & fMoveX, const float & fMoveY)
{
    INFO tBlock = pBlock->GetInfo();
    INFO tObj = pObj->GetInfo();

    float fObjAngle = CMathMgr::SlopeToRadian(tObj.fYSpd, tObj.fXSpd);

    if(fObjAngle < 0.f)
        fObjAngle += PI*2.f;
    float fObjSpd = sqrtf(tObj.fYSpd * tObj.fYSpd + tObj.fXSpd * tObj.fXSpd);

    float fTX = -fObjSpd *((tBlock.fCX + tObj.fCX)*0.5f + tObj.fX - tBlock.fX) / tObj.fXSpd;
    float fTY = -fObjSpd *((tBlock.fCY + tObj.fCY)*0.5f + tObj.fY - tBlock.fY) / tObj.fYSpd;
    
    float fXSign = 1.f;
    float fYSign = 1.f;
    if (tObj.fX > tBlock.fX)
        fXSign *= -1.f;
    if (tObj.fY > tBlock.fY)
        fYSign *= -1.f;

/*    if (abs(fTX) > _HUGE_ENUF)
    {
        pObj->SetPos(tObj.fX + tObj.fXSpd * fTY / fObjSpd, tObj.fY + tObj.fYSpd * fTY / fObjSpd);
        dynamic_cast<CMovable*>(pObj)->BlockY();
    }
    else if (abs(fTY) > _HUGE_ENUF)
    {
        pObj->SetPos(tObj.fX + tObj.fXSpd * fTX / fObjSpd, tObj.fY + tObj.fYSpd * fTX / fObjSpd);
        dynamic_cast<CMovable*>(pObj)->BlockX();
    }
    else*/ if (abs(fTX) < abs(fTY))
    {
        pObj->SetPos(tObj.fX + fXSign * tObj.fXSpd * fTX / fObjSpd, tObj.fY + fYSign * tObj.fYSpd * fTX / fObjSpd);
        dynamic_cast<CMovable*>(pObj)->BlockX();
    }
    else
    {
        pObj->SetPos(tObj.fX + fXSign * tObj.fXSpd * fTY / fObjSpd, tObj.fY + fYSign * tObj.fYSpd * fTY / fObjSpd);
        dynamic_cast<CMovable*>(pObj)->BlockY();
    }

}
