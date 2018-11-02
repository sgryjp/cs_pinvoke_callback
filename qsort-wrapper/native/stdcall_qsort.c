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

// stdcall_qsort で使う比較関数への関数ポインタ型
typedef int (__stdcall *stdcall_compare_proc)( const void* item1, const void* item2 );

// qsort 関数へ実際に渡される関数ポインタ型
typedef int (__cdecl *cdecl_compare_proc)( const void* item1, const void* item2 );

static int __cdecl my_cdecl_compare_proc( const void* item1, const void* item2 );



//==========================================================
//
//  global variables
//
//==========================================================

// stdcall な比較関数を保持しておくためのグローバル変数
static stdcall_compare_proc g_stdcall_compare_proc = NULL;



//==========================================================
//
//  functions
//
//==========================================================

//-------------------------------------
// function : stdcall_qsort
// brief    : stdcall な比較関数を使うための qsort 用ラッパー
//-------------------------------------
void __stdcall
stdcall_qsort( void * items, int itemCount, int itemSize, stdcall_compare_proc proc )
{
	// 引数として受け取った stdcall な比較関数をグローバル変数に保持
	g_stdcall_compare_proc = proc;
	
	// 用意してある cdecl の比較関数を使って qsort を実行
	qsort( items, itemCount, itemSize, &my_cdecl_compare_proc );
}


//-------------------------------------
// function : my_cdecl_compare_proc
// brief    : グローバル変数に保持されている
//            stdcall な比較関数を呼び出すだけの関数
//-------------------------------------
static int __cdecl
my_cdecl_compare_proc( const void* item1, const void* item2 )
{
	// __stdcall の比較関数へ委譲
	return (*g_stdcall_compare_proc)( item1, item2 );
}


//-------------------------------------
// function : DllMain
// notes    : DLL を作るのに必要なので定義
//-------------------------------------
BOOL APIENTRY
DllMain( HMODULE moduleHdl, ULONG reason_for_call, void* reserved )
{
	return TRUE;
}

#ifdef __cplusplus
} // extern "C"
#endif
