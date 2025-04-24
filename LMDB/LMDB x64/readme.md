# LMDB x64

LMDB static libraries compiled for x64 uasm assembler 

LMDB: https://github.com/LMDB/lmdb

> Symas LMDB is an extraordinarily fast, memory-efficient database.

## Usage

* Copy `lmdb_x64.inc` to your `uasm\include` folder (or wherever your includes are located)

* Copy `lmdb_x64.lib` to your `uasm\lib\x64` folder (or wherever your 64bit libraries are located)

* Add the following to your project:
  
  ```assembly
  include lmdb_x64.inc
  includelib lmdb_x64.lib
  ```

**Note:** `lmdb_x64.lib` also requires the Windows C Universal Runtime

## Functions

http://www.lmdb.tech/doc/index.html

## Download

The latest downloadable release is available [here](https://github.com/mrfearless/libraries/blob/master/releases/lmdb_x64.zip?raw=true)