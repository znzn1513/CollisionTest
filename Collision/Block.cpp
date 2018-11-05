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
    return NO_EVENT;
}

void CBlock::LateUpdate()
{
}

void CBlock::Render(HDC hDC)
{
}

void CBlock::Release()
{
}
