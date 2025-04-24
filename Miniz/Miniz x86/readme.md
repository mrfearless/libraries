# miniz x86

miniz static libraries compiled for x86 masm assembler 

miniz: https://github.com/richgel999/miniz

> Deflate/Inflate compression library with zlib-compatible API, ZIP archive reading/writing, PNG writing

## Usage

* Copy `miniz_x86.inc` to your `masm32\include` folder (or wherever your includes are located)

* Copy `miniz_x86.lib` to your `masm32\lib` folder (or wherever your libraries are located)

* Add the following to your project:
  
  ```assembly
  include miniz_x86.inc
  includelib miniz_x86.lib
  ```

## Functions

miniz_x86 API Library Reference documentation is available via the header files in the source repository.

## Download

The latest downloadable release is available [here](https://github.com/mrfearless/libraries/blob/master/releases/miniz_x86.zip?raw=true)