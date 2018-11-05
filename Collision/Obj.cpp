#include "stdafx.h"
#include "Obj.h"


CObj::CObj()
    :m_bIsInit(false)
{
    ZeroMemory(&m_tInfo, sizeof(INFO));
    ZeroMemory(&m_tRect, sizeof(RECT));
}


CObj::~CObj()
{
}

void CObj::SetPos(const float fX,const float fY)
{
    m_tInfo.fX = fX; m_tInfo.fY = fY;
}

void CObj::LateInit()
{
    if (!m_bIsInit)
    {
        this->LateInit();
        m_bIsInit = !m_bIsInit;
    }
}

void CObj::UpdateRect()
{
    m_tRect.left = LONG(m_tInfo.fX - m_tInfo.fCX*0.5f);
    m_tRect.right = LONG(m_tInfo.fX + m_tInfo.fCX*0.5f);
    m_tRect.top = LONG(m_tInfo.fY - m_tInfo.fCY*0.5f);
    m_tRect.bottom = LONG(m_tInfo.fY + m_tInfo.fCY*0.5f);
}
