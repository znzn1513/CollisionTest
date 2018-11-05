#pragma once
#include "Obj.h"
class CMovable :
    public CObj
{
public:
    CMovable();
    virtual ~CMovable();

public:
    // CObj을(를) 통해 상속됨
    virtual void Initialize() override;
    virtual void LateInit() override;
    virtual int Update() override;
    virtual void LateUpdate() override;
    virtual void Render(HDC hDC) override;
    virtual void Release() override;

protected:
    virtual void KeyInput();
    virtual void Move();
};

