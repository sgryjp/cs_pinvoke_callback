using System;
using System.Runtime.InteropServices;

class QSort
{
	static void Main( string[] args )
	{
		// �z����쐬
		int[] numbers
			= new int[]{ 12, 24, 3, 10, 22, 2, 15, 5, 21, 18, 11, 4, 1, 23, 13, 9, 14, 6, 20, 17, 7, 8, 16, 19 };
		
		unsafe {
			fixed( int * p = numbers )
			{
				// �����z����\�[�g
				qsort(
					p,
					numbers.Length,
					sizeof( int ),
					new CompareProc( MyCompareProc )
				);
			}
		}
		
		// �\�[�g���ʂ�\��
		foreach( int number in numbers )
		{
			Console.WriteLine( "{0}", number );
		}
	}
	
	// ������ C# �̔�r�֐�
	static int MyCompareProc( IntPtr item1, IntPtr item2 )
	{
		int value;
		
		unsafe {
			int* pNum1 = (int*)( item1.ToPointer() );
			int* pNum2 = (int*)( item2.ToPointer() );
			value = ( *pNum1 - *pNum2 );
		}
		
		return value;
	}
	
	// qsort �p�� cdecl �Ȕ�r�֐��̐錾
	[UnmanagedFunctionPointer(CallingConvention.Cdecl)]
	delegate int CompareProc( IntPtr item1, IntPtr item2 );
	
	// IntPtr (size_t) �� int �Ƃ̕ϊ��̎�Ԃ��Ȃ����߂̃I�[�o�[���[�h
	static unsafe void qsort( void* items, int itemCount, int itemSize, CompareProc proc )
	{
		qsort( items, new IntPtr(itemCount), new IntPtr(itemSize), proc );
	}
	
	[DllImport("msvcrt.dll", CallingConvention=CallingConvention.Cdecl)]
	static extern unsafe void qsort( void* items, IntPtr itemCount, IntPtr itemSize, CompareProc proc );
}
