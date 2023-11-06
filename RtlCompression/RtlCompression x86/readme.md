# RtlCompression x86

Run Time Library compression for x86 assembler

RtlCompression static libraries created from a custom ntdll.def file for x86 assembler

Inspired by the modexp post from odzhan: https://modexp.wordpress.com/2019/12/08/shellcode-compression/#ntdll

## Usage

* Copy `RtlCompression_x86.inc` to your `masm32\include` folder (or wherever your includes are located)

* Copy `RtlCompression_x86.lib` to your `masm32\lib` folder (or wherever your libraries are located)

* Add the following to your project:
  
  ```assembly
  include RtlCompression_x86.inc
  includelib RtlCompression_x86.lib
  ```

## RadASM Autocomplete

Additional RadASM autocomplete / intellisense type files are also included for ease of use. Each .api.txt file contains instructions as to where to paste their contents to add this feature to RadASM for using this library.

## Functions

[RtlGetCompressionWorkSpaceSize](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlgetcompressionworkspacesize)
[RtlCompressBuffer](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlcompressbuffer)
[RtlDecompressBuffer](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtldecompressbuffer)
[RtlDecompressFragment](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtldecompressfragment)

## Download

The latest downloadable release is available: [RtlCompression_x86.zip](https://github.com/mrfearless/libraries/blob/master/releases/RtlCompression_x86.zip?raw=true) along with an example/test project: [RtlCompTest_x86.zip](https://github.com/mrfearless/libraries/blob/master/releases/RtlCompTest_x86.zip?raw=true)