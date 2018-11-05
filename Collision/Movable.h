#pragma once
#include "Obj.h"
class Movable :
    public CObj
{
public:
    Movable();
    virtual ~Movable();

public:
    // CObj��(��) ���� ��ӵ�
    virtual void Initialize() override;
    virtual void LateInit() override;
    virtual int Update() override;
    virtual void LateUpdate() override;
    virtual void Render(HDC hDC) override;
    virtual void Release() override;

protected:
    virtual void KeyInput();
};

