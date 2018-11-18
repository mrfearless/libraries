# ![](../../assets/ZeroMQ.png) ZeroMQ x64

ZeroMQ static libraries compiled for x64 uasm assembler 

ZeroMQ: http://zeromq.org/

> ZeroMQ (also spelled ØMQ, 0MQ or ZMQ) is a high-performance asynchronous messaging library, aimed at use in distributed or concurrent applications.
>

## Usage

* Copy `*.inc` to your `uasm\include` folder (or wherever your includes are located)
* Copy `*.lib` to your `uasm\lib\x64` folder (or wherever your 64bit libraries are located)
* Add the following to your project:
```assembly
include zmq.inc
include libzmq.inc
includelib libzmq.lib
```

## Functions

ZeroMQ api reference documentation is available on the ZeroMQ website [here](http://api.zeromq.org/)

## Download

The latest downloadable release is available [here](https://github.com/mrfearless/libraries/blob/master/releases/ZeroMQ_x64.zip?raw=true)
