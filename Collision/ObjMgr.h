#pragma once
class CObj;

class CObjMgr
{
    DECLARE_SINGLETON(CObjMgr)

private:
    CObjMgr();
    ~CObjMgr();

public:
    void Initialize();
    void LateInit();
    void Update();
    void LateUpdate();
    void Render(HDC hDC);
    void Release();

private:
    list<CObj*> m_lstObj;
};

