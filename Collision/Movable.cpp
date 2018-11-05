#include "stdafx.h"
#include "Movable.h"


Movable::Movable()
{
}


Movable::~Movable()
{
    Release();
}

void Movable::Initialize()
{
    m_tInfo.fX = WINCX*0.5f;
    m_tInfo.fY = WINCY*0.5f;

    m_tInfo.fCX = BLOCK_CX;
    m_tInfo.fCY = BLOCK_CY;
}

void Movable::LateInit()
{
    CObj::UpdateRect();
}

int Movable::Update()
{
    KeyInput();
    Move();

    return NO_EVENT;
}

void Movable::LateUpdate()
{
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

void Movable::Render(HDC hDC)
{
    CObj::UpdateRect();

    Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void Movable::Release()
{
}

void Movable::KeyInput()
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

void Movable::Move()
{
    m_tInfo.fX += m_tInfo.fXSpd;
    m_tInfo.fY += m_tInfo.fYSpd;
}
