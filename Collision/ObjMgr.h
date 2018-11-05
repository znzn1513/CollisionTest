#pragma once
class CObj;

class CObjMgr
{
    DECLARE_SINGLETON(CObjMgr)

private:
    CObjMgr();
    ~CObjMgr();

public:
    enum OBJ_ID { PLAYER, BLOCK, OBJ_ID_END};

public:
    void Initialize();
    void LateInit();
    void Update();
    void LateUpdate();
    void Render(HDC hDC);
    void Release();

private:
    list<CObj*> m_lstObj[OBJ_ID_END];
};

