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


// CallBackTenTimes �p�R�[���o�b�N�֐��|�C���^�̌^
typedef void (__stdcall *CallBackTenTimesProc)( void );

// �����ɗ^�����֐����P�O��Ăяo��
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
