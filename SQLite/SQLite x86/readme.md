# ![](../../assets/SQLite.png) SQLite x86

SQLite static libraries compiled for x86 masm assembler 

SQLite: https://www.sqlite.org/

> SQLite is an in-process library that implements a self-contained, serverless, zero-configuration, transactional SQL database engine.

Includes SQLiteTest (x86 version) - a demo program by Mark Jones created to show the usage of the SQLite library

## Usage

* Copy `Sqlite3_x86.inc` to your `masm32\include` folder (or wherever your includes are located)
* Copy `Sqlite3_x86.lib` to your `masm32\lib` folder (or wherever your libraries are located)
* Add the following to your project:

```assembly
include Sqlite3_x86.inc
includelib Sqlite3_x86.lib
```

Note: `Sqlite3_x86.lib` was compiled with Visual Studio 2019 (v142) and also requires the Windows C Universal Runtime. 

Note: Visual Studio 2022 introduces an error when linking `Unresolved external symbol: __dtoul3` or `Unresolved external symbol: __dtoul3__legacy`

## Functions

SQLite Library reference documentation is available on the SQLite website: [https://www.sqlite.org/c3ref/intro.html](https://www.sqlite.org/c3ref/intro.html)

## Download

The latest downloadable release is available [here](https://github.com/mrfearless/libraries/blob/master/releases/SQLite_x86.zip?raw=true)

SQLiteTest is available to download [here](https://github.com/mrfearless/libraries/blob/master/releases/SQLiteTest.zip?raw=true)

## Windows 10 Universal C Runtime

https://www.microsoft.com/en-us/download/details.aspx?id=50410