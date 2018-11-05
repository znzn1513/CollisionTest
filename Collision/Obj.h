#pragma once
class CObj
{
public:
    CObj();
    virtual ~CObj();

public:
    virtual void Initialize()PURE;
    virtual void LateInit();
    virtual int Update()PURE;
    virtual void LateUpdate()PURE;
    virtual void Render(HDC hDC)PURE;
    virtual void Release()PURE;

protected:
    void UpdateRect();

protected:
    bool m_bIsInit;
    INFO m_tInfo;
    RECT m_tRect;
};

