# aPLib x64

aPLib static libraries for x64 assembler 

aPLib: https://ibsensoftware.com/products_aPLib.html

> aPLib is a compression library based on the algorithm used in aPACK (my  executable compressor). aPLib is an easy-to-use alternative to many of the heavy-weight compression libraries available.

> The compression ratios achieved by aPLib combined with the speed and tiny footprint of the depackers (as low as 169 bytes!) makes it the ideal choice
> for many products.

> Since the first public release in 1998, aPLib has been one of the top pure LZ-based compression libraries available. It is used in a wide range of products including executable compression and protection software, archivers, games, embedded systems, and handheld devices.

## Usage

* Copy `aplib_x64.inc` to your `uasm\include` folder (or wherever your includes are located)

* Copy `aplib_x64.lib` to your `uasm\lib\x64` folder (or wherever your 64bit libraries are located)

* Add the following to your project:
  
  ```assembly
  include aplib_x64.inc
  includelib aplib_x64.lib
  ```

## RadASM Autocomplete

Additional RadASM autocomplete / intellisense type files are also included for ease of use. Each .api.txt file contains instructions as to where to paste their contents to add this feature to RadASM for using this library.

## Functions

See `aplib_x64.inc` for a summary or download the original source which includes documentation: https://www.ibsensoftware.com/products_aPLib.html

## Download

The latest downloadable release is available [here](https://github.com/mrfearless/libraries/blob/master/releases/aplib_x64.zip?raw=true)
