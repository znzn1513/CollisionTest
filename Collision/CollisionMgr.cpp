#include "stdafx.h"
#include "CollisionMgr.h"
#include "Obj.h"

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
            if (fMoveX > fMoveY)
            {
                if (pBlock->GetInfo().fY > pSrc->GetInfo().fY)
                    pSrc->SetPos(pSrc->GetInfo().fX, pSrc->GetInfo().fY - fMoveY);
                else
                    pSrc->SetPos(pSrc->GetInfo().fX, pSrc->GetInfo().fY + fMoveY);
            }
            else
            {
                if (pBlock->GetInfo().fX > pSrc->GetInfo().fX)
                    pSrc->SetPos(pSrc->GetInfo().fX - fMoveX, pSrc->GetInfo().fY);
                else
                    pSrc->SetPos(pSrc->GetInfo().fX + fMoveX, pSrc->GetInfo().fY);
            }
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

