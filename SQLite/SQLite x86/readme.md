# ![](../../assets/SQLite.png)SQLite x86

SQLite static libraries compiled for x86 masm assembler 

SQLite: https://www.sqlite.org/

> SQLite is an in-process library that implements a self-contained, serverless, zero-configuration, transactional SQL database engine.
>

Includes SQLiteTest (x86 version) - a demo program by Mark Jones created to show the usage of the SQLite library

## Usage

* Copy `Sqlite3.inc` to your `masm32\include` folder (or wherever your includes are located)
* Copy `Sqlite3.lib` to your `masm32\lib` folder (or wherever your libraries are located)
* Add the following to your project:
```assembly
include Sqlite3.inc
includelib Sqlite3.lib
```
Note: `Sqlite3.lib` was compiled with Visual Studio 2013 and also requires `msvcrt.lib` (included as `msvcrt12.lib`)

## Functions

SQLite Library reference documentation is available on the SQLite website: [https://www.sqlite.org/c3ref/intro.html](https://www.sqlite.org/c3ref/intro.html)

## Download

The latest downloadable release is available [here](https://github.com/mrfearless/libraries/blob/master/releases/SQLite_x86.zip?raw=true)

SQLiteTest is available to download [here](https://github.com/mrfearless/libraries/blob/master/releases/SQLiteTest.zip?raw=true)