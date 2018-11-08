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
    //이동속도를 고려했을경우! 이동후에 완전히 통과한 경우와 이동후에 블럭과 겹친경우 두가지가 있다.
    //겹친경우에는 CheckRect를 사용해서 밀어주면 되고, 완전히 통과한 경우 통과 이전의 위치로 옮겨줘야한다.
    //이경우에 부딫힐때 수많은 친구들과 상호작용을 할 우려가 있다. 따라서 속도가 아닌 위치만을 제어할 필요가 있어보인다.
    //아니면 해봐야 알듯.
    static bool CheckPenetrate(const INFO& pDst, const INFO& pSrc, float& fMoveX, float& fMoveY, INFO* tInfo);

    static void PushObj(CObj* pBlock, CObj* pObj, const float& fMoveX, const float& fMoveY);
    static void AdvancedPush(CObj* pBlock, CObj* pObj, const float& fMoveX, const float& fMoveY);
};

