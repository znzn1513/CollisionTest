#pragma once
class CObj;
class CCollisionMgr
{
private:
    CCollisionMgr();
    ~CCollisionMgr();

public:
    static void BasicCollision(list<CObj*>& pDst, CObj* pSrc);
    static void AdvancedCollision(list<CObj*>& pDst, CObj* pSrc);

private:
    static bool CheckRect(const INFO& pDst, const INFO& pSrc, float& fMoveX, float& fMoveY);
    //�̵��ӵ��� ����������! �̵��Ŀ� ������ ����� ���� �̵��Ŀ� ���� ��ģ��� �ΰ����� �ִ�.
    //��ģ��쿡�� CheckRect�� ����ؼ� �о��ָ� �ǰ�, ������ ����� ��� ��� ������ ��ġ�� �Ű�����Ѵ�.
    //�̰�쿡 �΋H���� ������ ģ����� ��ȣ�ۿ��� �� ����� �ִ�. ���� �ӵ��� �ƴ� ��ġ���� ������ �ʿ䰡 �־�δ�.
    //�ƴϸ� �غ��� �˵�.
    static bool CheckPenetrate(const INFO& pDst, const INFO& pSrc, float& fMoveX, float& fMoveY, INFO* tInfo);

    static void PushObj(CObj* pBlock, CObj* pObj, const float& fMoveX, const float& fMoveY);
    static void AdvancedPush(CObj* pBlock, CObj* pObj, const float& fMoveX, const float& fMoveY);
};

