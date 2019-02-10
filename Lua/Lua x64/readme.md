# ![](../../assets/Lua.png) Lua x64

Lua v5.2.3 static libraries for x64 uasm assembler.

Lua: https://www.lua.org

> Lua is a powerful, efficient, lightweight, embeddable scripting language. It supports procedural programming, object-oriented programming, functional programming, data-driven programming, and data description.
>
> Lua combines simple procedural syntax with powerful data description constructs based on associative arrays and extensible semantics. Lua is dynamically typed, runs by interpreting bytecode with a register-based virtual machine, and has automatic memory management with incremental garbage collection, making it ideal for configuration, scripting, and rapid prototyping. 
>

## Usage

* Copy `*.inc` to your `uasm\include` folder (or wherever your includes are located)
* Copy `*.lib` to your `uasm\lib\x64` folder (or wherever your 64bit libraries are located)
* Add the following to your project:
```assembly
include lua523.inc
includelib lua523.lib
```
Note: Lua libraries may also require a c library for a few functions.

## Functions

Lua api reference documentation is available on the Lua website [here](https://www.lua.org/docs.html)

## Download

The latest downloadable release is available [here](https://github.com/mrfearless/libraries/blob/master/releases/Lua_x64.zip?raw=true)