# miniz x64

miniz static libraries compiled for x64 uasm assembler 

miniz: https://github.com/richgel999/miniz

> Deflate/Inflate compression library with zlib-compatible API, ZIP archive reading/writing, PNG writing

## Usage

* Copy `miniz_x64.inc` to your `uasm\include` folder (or wherever your includes are located)
* Copy `miniz_x64.lib` to your `uasm\lib\x64` folder (or wherever your 64bit libraries are located)
* Add the following to your project:
  
  ```assembly
  include miniz_x64.inc
  includelib miniz_x64.lib
  ```

## Functions

miniz API Library Reference documentation is available via the header files in the source repository.

## Download

The latest downloadable release is available [here](https://github.com/mrfearless/libraries/blob/master/releases/miniz_x64.zip?raw=true)