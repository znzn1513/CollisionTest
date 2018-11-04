#include "stdafx.h"
#include "Obj.h"


CObj::CObj()
    :m_bIsInit(false)
{
}


CObj::~CObj()
{
}

void CObj::LateInit()
{
    if (!m_bIsInit)
    {
        this->LateInit();
        m_bIsInit = !m_bIsInit;
    }
}
