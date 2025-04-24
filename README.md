# Libraries

Collection of libraries for use with x86 / x64 assembler.

Some of the libraries have been created by myself, the rest are by others and other projects, and in those cases I have only compiled static versions (if possible) and converted .h header files to assembler style .inc files for ease of use with x86 and x64 assemblers: masm, jwasm, hjwasm, uasm etc.

The libraries that I have created (some of them) have documentation on the functions they contain. More information can be found in the [wiki](https://github.com/mrfearless/libraries/wiki).

Some releases have been packaged for convenience and can be found [here](https://github.com/mrfearless/libraries/releases).

Hopefully you find them useful in your coding.

## Compression

| Project                                                                   | Version | Description                                 |
| ------------------------------------------------------------------------- | ------- | ------------------------------------------- |
| [APLib](https://github.com/mrfearless/libraries/tree/master/aPLib)        | 1.1.1   | Compression library by Jørgen Ibsen         |
| [BriefLZ](https://github.com/mrfearless/libraries/tree/master/brieflz)    | 1.3.0   | Compression library by Jørgen Ibsen         |
| [Brotli](https://github.com/mrfearless/libraries/tree/master/Brotli)      | 1.1.0   | Compression library by Google               |
| [Bzip2](https://github.com/mrfearless/libraries/tree/master/Bzip2)        | 1.1.0   | Compression library by Julian Seward        |
| [Bzip3](https://github.com/mrfearless/libraries/tree/master/Bzip3)        | 1.4.0   | Compression library by Kamila Szewczyk      |
| [FastLZ](https://github.com/mrfearless/libraries/tree/master/FastLZ)      | 0.5.0   | Compression library by Ariya Hidayat        |
| [FSE](https://github.com/mrfearless/libraries/tree/master/FSE)            | 0.9.0   | Compression library by Yann Collet          |
| [JCALG1](https://bitsum.com/portfolio/jcalg1/)                            | r5.xx   | Compression library by Jeremy Collake       |
| [libdeflate](https://github.com/mrfearless/libraries/tree/master/Deflate) | 1.3     | Compression library by Eric Biggers         |
| [Lizard](https://github.com/mrfearless/libraries/tree/master/Lizard)      | 1.0     | Compression library by Przemyslaw Skibinski |
| [LZ4](https://github.com/mrfearless/libraries/tree/master/LZ4)            | 1.9.5   | Compression library by Yann Collet          |
| [LZAV](https://github.com/mrfearless/libraries/tree/master/LZAV)          | 2.15    | Compression library by Aleksey Vaneev       |
| [LZFSE](https://github.com/mrfearless/libraries/tree/master/LZFSE)        | 1.0     | Compression library by Apple                |
| LZMA                                                                      |         |                                             |
| [Rtl](https://github.com/mrfearless/libraries/tree/master/RtlCompression) | -       | Native win32 compression by Microsoft       |
| [Snappy](https://github.com/mrfearless/libraries/tree/master/Snappy)      | 1.1.10  | Compression library by Google               |
| [Squish](https://github.com/mrfearless/libraries/tree/master/Squish)      | 1.11    | DXT library by Jack Andersen/Simon Brown    |
| [Zlib](https://github.com/mrfearless/libraries/tree/master/Zlib)          | 1.3.1   | Compression library by Mark Adler           |
| [zlib-ng](https://github.com/mrfearless/libraries/tree/master/zlib-ng)    | 2.2.0   | Compression library by zlib-ng              |
| [Zstd](https://github.com/mrfearless/libraries/tree/master/zstd)          | 1.5.5   | Compression library by Facebook             |

## Compression Archive Management

| Project                                                            | Version | Description                                           |
| ------------------------------------------------------------------ | ------- | ----------------------------------------------------- |
| libzip                                                             | 1.11.3  | zip archive library by Dieter Baron & Thomas Klausner |
| [miniz](https://github.com/mrfearless/libraries/tree/master/Miniz) | 3.0.2   | zlib and zip archive library by Rich Geldreich        |

## Database

| Project                                                              | Version | Description                           |
| -------------------------------------------------------------------- | ------- | ------------------------------------- |
| [LMDB](https://github.com/mrfearless/libraries/tree/master/LMDB)     | 0.9.70  | Key-Value database library by Symas   |
| [SQLite](https://github.com/mrfearless/libraries/tree/master/SQLite) | 3.47    | SQL database engine library by SQLite |

## Data Exchange/Serialization

| Project                                                                | Version | Description                    |
| ---------------------------------------------------------------------- | ------- | ------------------------------ |
| [cJSON](https://github.com/mrfearless/libraries/tree/master/cJSON)     | 1.7.16  | JSON library by Dave Gamble    |
| [Jansson](https://github.com/mrfearless/libraries/tree/master/Jansson) | 2.14    | JSON library by Petri Lehtinen |
| [Mini-XML](https://github.com/mrfearless/libraries/tree/master/mxml)   | 3.3.1   | XML library by Michael R Sweet |

## Debugging/Disassember/Assembler

| Project                                                                  | Version | Description                             |
| ------------------------------------------------------------------------ | ------- | --------------------------------------- |
| [Capstone](https://github.com/mrfearless/libraries/tree/master/Capstone) | 4.0.0   | Disassembly library by Nguyen Anh Quynh |
| [Debug64](https://github.com/mrfearless/libraries/tree/master/Debug64)   | -       | Debug x64 macros by fearless            |
| [Keystone](https://github.com/mrfearless/libraries/tree/master/Keystone) | 0.9     | Assembler library by Nguyen Anh Quynh   |

## Hashing

| Project                                                              | Version | Description                                   |
| -------------------------------------------------------------------- | ------- | --------------------------------------------- |
| [xxhash](https://github.com/mrfearless/libraries/tree/master/xxhash) | 0.7.1   | non-cryptographic hash library by Yann Collet |

## Image Handling

| Project                                                                  | Version | Description                                 |
| ------------------------------------------------------------------------ | ------- | ------------------------------------------- |
| [PNGLib](https://www.madwizard.org/programming/projects/pnglib)          | 1.0     | PNG file format library by Thomas Bleeker   |
| [GIFLIB](https://www.madwizard.org/programming/toolarchive)              | 1.0     | GIF file format library by Thomas Bleeker   |
| PlutoVG                                                                  | 0.0.2   | Vector rendering library bySamuel Ugochukwu |
| [PlutoSVG](https://github.com/mrfearless/libraries/tree/master/Plutosvg) | 0.0.8   | SVG rendering library by Samuel Ugochukwu   |

## Mathematics

| Project                                                      | Version | Description                          |
| ------------------------------------------------------------ | ------- | ------------------------------------ |
| [FpuLib](https://masm32.com/masmcode/rayfil/fpu.html#fpulib) | 2.341   | FPU library by Raymond Filiatreault  |
| [MixLib](https://masm32.com/masmcode/rayfil/fixmath.html)    | 1.0     | Math library by Raymond Filiatreault |
| [ZLIB](https://masm32.com/masmcode/rayfil/complex.html)      | 1.1     | Math library by Raymond Filiatreault |

## Scripting

| Project                                                        | Version | Description              |
| -------------------------------------------------------------- | ------- | ------------------------ |
| [Lua](https://github.com/mrfearless/libraries/tree/master/Lua) | 5.3.4   | Scripting library by Lua |

## SSL

| Project                                                                | Version | Description                      |
| ---------------------------------------------------------------------- | ------- | -------------------------------- |
| [BearSSL](https://github.com/mrfearless/libraries/tree/master/BearSSL) | ?       | SSL/TLS library by Thomas Pornin |
| [OpenSSL](https://github.com/mrfearless/libraries/tree/master/OpenSSL) | 1.1.1   | SSL/TLS library by OpenSSL       |

## Misc

| Project                                                                          | Version | Description                        |
| -------------------------------------------------------------------------------- |:------- | ---------------------------------- |
| [Console](https://github.com/mrfearless/libraries/tree/master/Console)           | -       | Win32 Console library by fearless  |
| [Listview](https://github.com/mrfearless/libraries/tree/master/Listview)         | -       | Win32 Listview library by fearless |
| [RPC](https://github.com/mrfearless/libraries/tree/master/RPC)                   | -       | RPC library by fearless            |
| [SDL](https://github.com/mrfearless/libraries/tree/master/SDL)                   | 2.x     | DirectMedia library by SDL         |
| [Treeview](https://github.com/mrfearless/libraries/tree/master/Treeview)         | -       | Win32 Treeview library by fearless |
| [VirtualStack](https://github.com/mrfearless/libraries/tree/master/VirtualStack) | -       | Virtual stack library by fearless  |
| [ZeroMQ](https://github.com/mrfearless/libraries/tree/master/ZeroMQ)             | ?       | Messaging library by ZeroMQ        |

## Older/Obsolte/WIP Projects:

| Project                                                              | Version | Description                                             |
| -------------------------------------------------------------------- |:------- | ------------------------------------------------------- |
| [Cuda](https://github.com/mrfearless/libraries/tree/master/Cuda)     | x       | x64 assembler port of Nvidia's CUDA SDK and NVML        |
| [Masm64](https://github.com/mrfearless/libraries/tree/master/Masm64) | x       | x64 assembler port of Steve Hutchesson's Masm32 library |
| [OpenCL](https://github.com/mrfearless/libraries/tree/master/OpenCL) | x       | x64 assembler port of Khronos OpenCL SDK                |
| [Vulkan](https://github.com/mrfearless/libraries/tree/master/Vulkan) | x       | Assembler port of Khronos Vulkan graphics api (WIP)     |