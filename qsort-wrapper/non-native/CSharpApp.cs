using System;
using DllImportAttribute	= System.Runtime.InteropServices.DllImportAttribute;
using CallingConvention		= System.Runtime.InteropServices.CallingConvention;

public class CSharpApp
{
	public static void Main( string[] args )
	{
		int[] numbers
			= new int[]{ 12, 3, 10, 2, 15, 5, 18, 11, 4, 1, 13, 9, 14, 6, 17, 7, 8, 16 };
		
		unsafe {
			fixed( int * p = numbers )
			{
				stdcall_qsort(
					p,
					numbers.Length,
					sizeof( int ),
					new CompareProc( MyCompareProc )
				);
			}
		}
		
		foreach( int number in numbers )
		{
			System.Console.WriteLine( "{0}", number );
		}
	}
	
	static unsafe int MyCompareProc( IntPtr item1, IntPtr item2 )
	{
		return (  *(int*)(item1.ToPointer())  -  *(int*)(item2.ToPointer())  );
	}
	
	delegate int CompareProc( IntPtr item1, IntPtr item2 );
	
	[DllImport("stdcall_qsort.dll")]
	static extern unsafe void stdcall_qsort( void* items, int itemCount, int itemSize, CompareProc proc );
}
