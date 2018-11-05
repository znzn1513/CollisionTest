#include "stdafx.h"
#include "Block.h"


CBlock::CBlock()
{
}


CBlock::~CBlock()
{
}

void CBlock::Initialize()
{
    m_tInfo.fCX = BLOCK_CX;
    m_tInfo.fCY = BLOCK_CY;
}

void CBlock::LateInit()
{
    CObj::UpdateRect();
}

int CBlock::Update()
{
    CObj::LateInit();

    return NO_EVENT;
}

void CBlock::LateUpdate()
{
}

void CBlock::Render(HDC hDC)
{
    Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void CBlock::Release()
{
}
