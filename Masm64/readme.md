# Masm64

An x64 assembler port of Steve Hutchesson's Masm32 library from www.masm32.com

**Note:**

- Original code from www.masm32.com MASM32.LIB modified to port it to x64.
- Not all functions have been ported.
- Not all functions have been tested.
- There may be differences from the original MASM32.LIB in usage for calling functions and expected return results. 

## Functions available

- Numeric Functions:  `qw2hex`, `dw2hex`, `dwtoa`, `a2qw`, `atoqw`, `ltoa`, `htodw`, `htoqw`

- Text functions: `InString`, `szappend`, `szCatStr`, `szCmp`, `szCmpi`, `Cmpi`, `szCopy`, `szLeft`, `szLen`, `szLower`, `szLtrim`, `szMid`, `szMonoSpace`, `szRemove`, `szRep`, `szRev`, `szRight`, `szRtrim`, `szTrim`, `szUpper`

- Path, folder functions: `exist`, `GetPathOnly`, `ArgByNumber`

- Other Functions: `nrandom`, `nseed`



## Usage

* Copy `masm64.inc` to your `uasm32\include` folder (or wherever your includes are located)
* Copy `masm64.lib` to your `uasm32\lib\x64` folder (or wherever your x64 libraries are located)
* Add the following to your project:
```assembly
include masm64.inc
includelib masm64.lib
```