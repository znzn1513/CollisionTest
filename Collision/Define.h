#pragma once

#define WINCX 1200
#define WINCY 800

#define PURE =0

#define NO_EVENT 0

#define BLOCK_CX 50
#define BLOCK_CY 50

#define D_SPD 5

#define PI 3.141592f


//½Ì±ÛÅæ ÆÐÅÏ ¼±¾ðºÎ
#define DECLARE_SINGLETON(classname)        \
private:                                    \
    static classname* m_pInstance;          \
public:                                     \
    static classname* GetInstance()         \
    {                                       \
        if (nullptr == m_pInstance)         \
        {                                   \
            m_pInstance = new classname;    \
        }                                   \
        return m_pInstance;                 \
    }                                       \
    void DestroyInstance()                  \
    {                                       \
        if (m_pInstance)                    \
        {                                   \
            delete m_pInstance;             \
            m_pInstance = nullptr;          \
        }                                   \
    }

//½Ì±ÛÅæ Á¤ÀÇºÎ
#define IMPLEMENT_SINGLETON(classname)      \
classname* classname::m_pInstance = nullptr;

//½Ì±ÛÅæ »ç¿ë
#define GET_INSTANCE(classname)             \
classname::GetInstance()

#define NULL_CHECK(ptr)     \
if (nullptr == ptr)         \
    return;