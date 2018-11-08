#include "stdafx.h"
#include "ObjMgr.h"
#include "Obj.h"
#include "Movable.h"
#include "Block.h"

IMPLEMENT_SINGLETON(CObjMgr)

CObjMgr::CObjMgr()
{
}


CObjMgr::~CObjMgr()
{
    Release();
}

void CObjMgr::PlayerBlockX()
{
}

void CObjMgr::PlayerBlockY()
{
}

void CObjMgr::Initialize()
{
    int iNumTileX = int(WINCX / float(BLOCK_CX));
    int iNumTileY = int(WINCY / float(BLOCK_CY));

    for (int i = 0; iNumTileX > i; ++i)
    {
        CObj* pObj = new CBlock;
        pObj->Initialize();
        pObj->SetPos(i*BLOCK_CX + BLOCK_CX*0.5f, BLOCK_CY*0.5f);
        m_lstObj[BLOCK].push_back(pObj);
    }

    for (int i = 1; iNumTileY > i; ++i)
    {
        CObj* pObj = new CBlock;
        pObj->Initialize();
        pObj->SetPos(BLOCK_CX*0.5f, i*BLOCK_CY + BLOCK_CY*0.5f);
        m_lstObj[BLOCK].push_back(pObj);
    }

    for (int i = 1; iNumTileY > i; ++i)
    {
        CObj* pObj = new CBlock;
        pObj->Initialize();
        pObj->SetPos((iNumTileX-1)*BLOCK_CX + BLOCK_CX*0.5f, i*BLOCK_CY + BLOCK_CY*0.5f);
        m_lstObj[BLOCK].push_back(pObj);
    }

    for (int i = 1; iNumTileX - 1 > i; ++i)
    {
        CObj* pObj = new CBlock;
        pObj->Initialize();
        pObj->SetPos(i*BLOCK_CX + BLOCK_CX*0.5f, (iNumTileY - 1)*BLOCK_CY + BLOCK_CY*0.5f);
        m_lstObj[BLOCK].push_back(pObj);
    }
    CObj* pObj = new CMovable;
    pObj->Initialize();
    m_lstObj[PLAYER].push_back(pObj);
}

void CObjMgr::LateInit()
{
}

void CObjMgr::Update()
{
    for (int i = 0; i < OBJ_ID_END; ++i)
        for (auto& pObj : m_lstObj[i])
            pObj->Update();
}

void CObjMgr::LateUpdate()
{
    for (int i = 0; i < OBJ_ID_END; ++i)
        for (auto& pObj : m_lstObj[i])
            pObj->LateUpdate();

    CCollisionMgr::AdvancedCollision(m_lstObj[BLOCK], m_lstObj[PLAYER].front());
}

void CObjMgr::Render(HDC hDC)
{
    for (int i = 0; i < OBJ_ID_END; ++i)
        for (auto& pObj : m_lstObj[i])
            pObj->Render(hDC);
}

void CObjMgr::Release()
{
    for(int i=0; i<OBJ_ID_END ; ++i)
        for_each(m_lstObj[i].begin(), m_lstObj[i].end(), SafeDelete<CObj*>);
}
