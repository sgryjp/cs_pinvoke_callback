// file : stdcall_qsort.c
#include <windows.h>

#ifdef __cplusplus
extern "C" {
#endif


//==========================================================
//
//  types & prototypes
//
//==========================================================

// stdcall_qsort �Ŏg����r�֐��ւ̊֐��|�C���^�^
typedef int (__stdcall *stdcall_compare_proc)( const void* item1, const void* item2 );

// qsort �֐��֎��ۂɓn�����֐��|�C���^�^
typedef int (__cdecl *cdecl_compare_proc)( const void* item1, const void* item2 );

static int __cdecl my_cdecl_compare_proc( const void* item1, const void* item2 );



//==========================================================
//
//  global variables
//
//==========================================================

// stdcall �Ȕ�r�֐���ێ����Ă������߂̃O���[�o���ϐ�
static stdcall_compare_proc g_stdcall_compare_proc = NULL;



//==========================================================
//
//  functions
//
//==========================================================

//-------------------------------------
// function : stdcall_qsort
// brief    : stdcall �Ȕ�r�֐����g�����߂� qsort �p���b�p�[
//-------------------------------------
void __stdcall
stdcall_qsort( void * items, int itemCount, int itemSize, stdcall_compare_proc proc )
{
	// �����Ƃ��Ď󂯎���� stdcall �Ȕ�r�֐����O���[�o���ϐ��ɕێ�
	g_stdcall_compare_proc = proc;
	
	// �p�ӂ��Ă��� cdecl �̔�r�֐����g���� qsort �����s
	qsort( items, itemCount, itemSize, &my_cdecl_compare_proc );
}


//-------------------------------------
// function : my_cdecl_compare_proc
// brief    : �O���[�o���ϐ��ɕێ�����Ă���
//            stdcall �Ȕ�r�֐����Ăяo�������̊֐�
//-------------------------------------
static int __cdecl
my_cdecl_compare_proc( const void* item1, const void* item2 )
{
	// __stdcall �̔�r�֐��ֈϏ�
	return (*g_stdcall_compare_proc)( item1, item2 );
}


//-------------------------------------
// function : DllMain
// notes    : DLL �����̂ɕK�v�Ȃ̂Œ�`
//-------------------------------------
BOOL APIENTRY
DllMain( HMODULE moduleHdl, ULONG reason_for_call, void* reserved )
{
	return TRUE;
}

#ifdef __cplusplus
} // extern "C"
#endif
