# LMDB x86

LMDB static libraries compiled for x86 assembler 

LMDB: https://github.com/LMDB/lmdb

> Symas LMDB is an extraordinarily fast, memory-efficient database.

## Usage

* Copy `lmdb_x86.inc` to your `masm32\include` folder (or wherever your includes are located)

* Copy `lmdb_x86.lib` to your `masm32\lib` folder (or wherever your libraries are located)

* Add the following to your project:
  
  ```assembly
  include lmdb_x86.inc
  includelib lmdb_x86.lib
  ```

**Note:** `lmdb_x86.lib` also requires the Windows C Universal Runtime

## Functions

http://www.lmdb.tech/doc/index.html

## Download

The latest downloadable release is available [here](https://github.com/mrfearless/libraries/blob/master/releases/lmdb_x86.zip?raw=true)
