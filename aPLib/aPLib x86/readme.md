# aPLib x86

aPLib static libraries for x86 assembler 

aPLib: https://ibsensoftware.com/products_aPLib.html

> aPLib is a compression library based on the algorithm used in aPACK (my  executable compressor). aPLib is an easy-to-use alternative to many of the heavy-weight compression libraries available.

> The compression ratios achieved by aPLib combined with the speed and tiny footprint of the depackers (as low as 169 bytes!) makes it the ideal choice
> for many products.

> Since the first public release in 1998, aPLib has been one of the top pure LZ-based compression libraries available. It is used in a wide range of products including executable compression and protection software, archivers, games, embedded systems, and handheld devices.

## Usage

* Copy `aplib_x86.inc` to your `masm32\include` folder (or wherever your includes are located)

* Copy `aplib_x86.lib` to your `masm32\lib` folder (or wherever your libraries are located)

* Add the following to your project:
  
  ```assembly
  include aplib_x86.inc
  includelib aplib_x86.lib
  ```

## Download

The latest downloadable release is available [here](https://github.com/mrfearless/libraries/blob/master/releases/aplib_x86.zip?raw=true)
