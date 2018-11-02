（このレポジトリはブログ記事[「C#からコールバック関数を使うCの関数を呼ぶ」](https://blog.sgry.jp/entry/2006/04/22/000000)の添付資料です）

以下 3 種類のプログラムを同梱しています。

- CallBackTenTimes
- qsort
- qsort-wrapper

# CallBackTenTimes

ネイティブコードからマネージドコードをコールバックさせる簡単な例です。CallBackTenTimes ディレクトリ下にファイルを納めています。なお、ビルド済みのファイルも同ディレクトリ直下に納めています。細かいファイル構成は次の通り。

## ネイティブコード用のファイル

    CallBackTenTimes/native/CallBackTenTimes.c
        ネイティブコード DLL のソース
    CallBackTenTimes/native/CallBackTenTimes.def
        ネイティブコード DLL のモジュール定義ファイル
    CallBackTenTimes/native/dmc.mk
        Digital Mars C++ 用 makefile
    CallBackTenTimes/native/mingw.mk
        MinGW 用 makefile
    CallBackTenTimes/native/vc.mk
        Visual C++ 6.0 用 makefile

## C# 用ファイル

    CallBackTenTimes/non-native/CSharpApp.cs
        C# プログラム例のソース



# qsort

stdcall でない関数をコールバックに使う仕様の関数を P/Invoke する例です。C# コード上でコールバック関数を cdecl と宣言して直接呼び出す例です。qsort ディレクトリ下にファイルを納めています。なお、ビルド済みのファイルは同ディレクトリ直下に納めています。細かいファイル構成は次の通り。

## C# 用ファイル

    qsort/QSort.cs
        C# プログラム例のソース



# qsort-wrapper

stdcall でない関数をコールバックに使う仕様の関数を P/Invoke する例です。ネイティブコード側でラッパー関数を定義して、それを経由させることで無理矢理対応させています。関連ファイルは qsort-wrapper ディレクトリ下にあります。なお、ビルド済みのファイルは同ディレクトリ直下に納めています。細かいファイル構成は次の通り。

## ネイティブコード用のファイル]

    qsort-wrapper/native/stdcall_qsort.c
        ネイティブコード DLL のソース
    qsort-wrapper/native/stdcall_qsort.def
        ネイティブコード DLL のモジュール定義ファイル
    qsort-wrapper/native/mingw.mk
        MinGW 用 makefile
    qsort-wrapper/native/vc.mk
        Visual C++ 6.0 用 makefile

## C# 用ファイル

    qsort-wrapper/non-native/CSharpApp.cs
        C# プログラム例のソース
