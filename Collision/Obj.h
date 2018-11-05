#pragma once
class CObj
{
public:
    CObj();
    virtual ~CObj();

public:
    void SetPos(const float fX, const float fY);

public:
    const INFO& GetInfo() const { return m_tInfo; }
    const RECT& GetRect() const { return m_tRect; }

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

