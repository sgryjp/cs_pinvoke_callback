// file : CallBackTenTimes.c
#include <windows.h>

#ifdef __cplusplus
extern "C" {
#endif

BOOL APIENTRY
DllMain( HMODULE moduleHdl, ULONG reason_for_call, void* reserved )
{
	return TRUE;
}


// CallBackTenTimes 用コールバック関数ポインタの型
typedef void (__stdcall *CallBackTenTimesProc)( void );

// 引数に与えた関数を１０回呼び出す
void __stdcall
CallBackTenTimes( CallBackTenTimesProc proc )
{
    int i;
    for( i=0; i<10; i++ )
    {
        proc();
    }
}

#ifdef __cplusplus
} // extern "C"
#endif
