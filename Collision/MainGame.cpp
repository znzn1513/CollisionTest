#include "stdafx.h"
#include "MainGame.h"

CMainGame::CMainGame()
{
}


CMainGame::~CMainGame()
{
    Release();
}

void CMainGame::Initialize()
{
    m_hDC = GetDC(g_hWnd);


    GET_INSTANCE(CObjMgr)->Initialize();
}

void CMainGame::Update()
{
    GET_INSTANCE(CObjMgr)->Update();
}

void CMainGame::LateUpdate()
{
    GET_INSTANCE(CObjMgr)->LateUpdate();
}

void CMainGame::Render()
{
    HDC hBufferDC = CreateCompatibleDC(m_hDC);
    HBITMAP hBmp = CreateCompatibleBitmap(m_hDC, WINCX, WINCY);
    HBITMAP hOldBmp = (HBITMAP)SelectObject(hBufferDC, hBmp);

    GET_INSTANCE(CObjMgr)->Render(hBufferDC);

    BitBlt(m_hDC, 0, 0, WINCX, WINCY, hBufferDC, 0, 0, SRCCOPY);

    SelectObject(hBufferDC, hOldBmp);
    DeleteObject(hBmp);
    DeleteDC(hBufferDC);
}

void CMainGame::Release()
{
    ReleaseDC(g_hWnd, m_hDC);
}
