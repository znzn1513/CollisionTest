#pragma once
#include "Obj.h"
class Movable :
    public CObj
{
public:
    Movable();
    virtual ~Movable();

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
};

