#pragma once

template<class T>
void SafeDelete(T& pObj)
{
    if (pObj)
    {
        delete pObj;
        pObj = nullptr;
    }
}