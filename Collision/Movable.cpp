#include "stdafx.h"
#include "Movable.h"


CMovable::CMovable()
{
}


CMovable::~CMovable()
{
    Release();
}

void CMovable::BlockX()
{
    m_tInfo.fXSpd = 0;
}

void CMovable::BlockY()
{
    m_tInfo.fYSpd = 0;
}

void CMovable::Initialize()
{
    m_tInfo.fX = WINCX*0.5f;
    m_tInfo.fY = WINCY*0.5f;

    m_tInfo.fCX = BLOCK_CX;
    m_tInfo.fCY = BLOCK_CY;
}

void CMovable::LateInit()
{
    CObj::UpdateRect();
}

int CMovable::Update()
{
    CObj::LateInit();

    KeyInput();

    return NO_EVENT;
}

void CMovable::LateUpdate()
{
    Move();

    float fFriction = D_SPD*0.3f;
    
    if (m_tInfo.fXSpd > 0)
        m_tInfo.fXSpd -= fFriction;
    else if (m_tInfo.fXSpd < 0)
        m_tInfo.fXSpd += fFriction;
    
    if (abs(int(m_tInfo.fXSpd)) < int(fFriction))
        m_tInfo.fXSpd = 0.f;

    if (m_tInfo.fYSpd > 0)
        m_tInfo.fYSpd -= fFriction;
    else if (m_tInfo.fYSpd < 0)
        m_tInfo.fYSpd += fFriction;

    if (abs(int(m_tInfo.fYSpd)) < int(fFriction))
        m_tInfo.fYSpd = 0.f;

}

void CMovable::Render(HDC hDC)
{
    CObj::UpdateRect();

    Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void CMovable::Release()
{
}

void CMovable::KeyInput()
{
    if (GetAsyncKeyState(VK_UP) & 0x8000)
    {
        m_tInfo.fYSpd -= D_SPD;
    }
    if (GetAsyncKeyState(VK_DOWN) & 0x8000)
    {
        m_tInfo.fYSpd += D_SPD;
    }
    if (GetAsyncKeyState(VK_LEFT) & 0x8000)
    {
        m_tInfo.fXSpd -= D_SPD;
    }
    if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
    {
        m_tInfo.fXSpd += D_SPD;
    }
}

void CMovable::Move()
{
    m_tInfo.fX += m_tInfo.fXSpd;
    m_tInfo.fY += m_tInfo.fYSpd;
}
