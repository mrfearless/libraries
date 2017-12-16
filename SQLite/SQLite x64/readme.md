# ![](../../assets/SQLite.png)SQLite x64

SQLite static libraries compiled for x64 uasm assembler 

SQLite: https://www.sqlite.org/

> SQLite is an in-process library that implements a self-contained, serverless, zero-configuration, transactional SQL database engine.

## Usage

* Copy `Sqlite3.inc` to your `uasm\include` folder (or wherever your includes are located)
* Copy `Sqlite3.lib` to your `uasm\lib\x64` folder (or wherever your 64bit libraries are located)
* Add the following to your project:
```assembly
include Sqlite3.inc
includelib Sqlite3.lib
```
Note: `Sqlite3.lib` was compiled with Visual Studio 2013 and also requires `msvcrt.lib` (included as `msvcrt12.lib`)

## Functions

SQLite Library reference documentation is available on the SQLite website: [https://www.sqlite.org/c3ref/intro.html](https://www.sqlite.org/c3ref/intro.html)

## Download

The latest downloadable release is available [here](https://github.com/mrfearless/libraries/blob/master/releases/SQLite_x64.zip?raw=true)