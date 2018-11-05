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

void CObjMgr::Initialize()
{
    int iNumTileX = int(WINCX / float(BLOCK_CX));
    int iNumTileY = int(WINCY / float(BLOCK_CY));

    for (int i = 0; iNumTileX > i; ++i)
    {
        CObj* pObj = new CBlock;
        pObj->Initialize();
        pObj->SetPos(i*BLOCK_CX + BLOCK_CX*0.5f, BLOCK_CY*0.5f);
        m_lstObj.push_back(pObj);
    }

    for (int i = 1; iNumTileY > i; ++i)
    {
        CObj* pObj = new CBlock;
        pObj->Initialize();
        pObj->SetPos(BLOCK_CX*0.5f, i*BLOCK_CY + BLOCK_CY*0.5f);
        m_lstObj.push_back(pObj);
    }

    for (int i = 1; iNumTileY > i; ++i)
    {
        CObj* pObj = new CBlock;
        pObj->Initialize();
        pObj->SetPos((iNumTileX-1)*BLOCK_CX + BLOCK_CX*0.5f, i*BLOCK_CY + BLOCK_CY*0.5f);
        m_lstObj.push_back(pObj);
    }

    for (int i = 1; iNumTileX - 1 > i; ++i)
    {
        CObj* pObj = new CBlock;
        pObj->Initialize();
        pObj->SetPos(i*BLOCK_CX + BLOCK_CX*0.5f, (iNumTileY - 1)*BLOCK_CY + BLOCK_CY*0.5f);
        m_lstObj.push_back(pObj);
    }
    CObj* pObj = new CMovable;
    pObj->Initialize();
    m_lstObj.push_back(pObj);    
}

void CObjMgr::LateInit()
{
}

void CObjMgr::Update()
{
    for (auto& pObj : m_lstObj)
        pObj->Update();
}

void CObjMgr::LateUpdate()
{
    for (auto& pObj : m_lstObj)
        pObj->LateUpdate();
}

void CObjMgr::Render(HDC hDC)
{
    for (auto& pObj : m_lstObj)
        pObj->Render(hDC);
}

void CObjMgr::Release()
{
    for_each(m_lstObj.begin(), m_lstObj.end(), SafeDelete<CObj*>);
}
