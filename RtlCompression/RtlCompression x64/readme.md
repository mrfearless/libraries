# RtlCompression x64

Run Time Library compression for x64 assembler

RtlCompression static libraries created from a custom ntdll.def file for x64 assembler

Inspired by the modexp post from odzhan: https://modexp.wordpress.com/2019/12/08/shellcode-compression/#ntdll

## Usage

* Copy `RtlCompression_x64.inc` to your `uasm\include` folder (or wherever your includes are located)

* Copy `RtlCompression_x64.lib` to your `uasm\lib\x64` folder (or wherever your 64bit libraries are located)

* Add the following to your project:
  
  ```assembly
  include RtlCompression_x64.inc
  includelib RtlCompression_x64.lib
  ```

## RadASM Autocomplete

Additional RadASM autocomplete / intellisense type files are also included for ease of use. Each .api.txt file contains instructions as to where to paste their contents to add this feature to RadASM for using this library.

## Functions

[RtlGetCompressionWorkSpaceSize](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlgetcompressionworkspacesize)
[RtlCompressBuffer](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlcompressbuffer)
[RtlDecompressBuffer](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtldecompressbuffer)
[RtlDecompressFragment](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtldecompressfragment)

## Download

The latest downloadable release is available: [RtlCompression_x64.zip](https://github.com/mrfearless/libraries/blob/master/releases/RtlCompression_x64.zip?raw=true) along with an example/test project: [RtlCompTest_x64.zip](https://github.com/mrfearless/libraries/blob/master/releases/RtlCompTest_x64.zip?raw=true)