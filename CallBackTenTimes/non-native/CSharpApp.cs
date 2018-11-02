using System;
using DllImportAttribute	= System.Runtime.InteropServices.DllImportAttribute;
using CallingConvention		= System.Runtime.InteropServices.CallingConvention;

public class CSharpApp
{
	public static void Main( string[] args )
	{
		CallBackTenTimes(
			new CallBackTenTimesProc( MyCallBackTenTimesProc )
		);
	}
	
	static void MyCallBackTenTimesProc()
	{
		System.Console.WriteLine( "Hello, Callback!" );
	}
	
	delegate void CallBackTenTimesProc();
	
	[DllImport("CallBackTenTimes.dll")]
	static extern unsafe void CallBackTenTimes( CallBackTenTimesProc proc );
}
