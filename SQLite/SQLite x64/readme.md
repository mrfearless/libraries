# ![](../../assets/SQLite.png) SQLite x64

SQLite static libraries compiled for x64 uasm assembler 

SQLite: https://www.sqlite.org/

> SQLite is an in-process library that implements a self-contained, serverless, zero-configuration, transactional SQL database engine.

## Usage

* Copy `Sqlite3_x64.inc` to your `uasm\include` folder (or wherever your includes are located)
* Copy `Sqlite3_x64.lib` to your `uasm\lib\x64` folder (or wherever your 64bit libraries are located)
* Add the following to your project:

```assembly
include Sqlite3_x64.inc
includelib Sqlite3_x64.lib
```

Note: `Sqlite3_x64.lib` was compiled with Visual Studio 2022 (v143) and also requires the Windows C Universal Runtime. 

## Functions

SQLite Library reference documentation is available on the SQLite website: [https://www.sqlite.org/c3ref/intro.html](https://www.sqlite.org/c3ref/intro.html)

## Download

The latest downloadable release is available [here](https://github.com/mrfearless/libraries/blob/master/releases/sqlite3_x64.zip?raw=true)

## Windows 10 Universal C Runtime

https://www.microsoft.com/en-us/download/details.aspx?id=50410