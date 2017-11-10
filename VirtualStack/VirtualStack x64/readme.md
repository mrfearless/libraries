# ![](../assets/VirtualStack.png)VirtualStack x64

Static x64 assembler library for creating a virtual stack and manipulating it (push, pop, peek etc)

## Usage

* Copy `VirtualStack.inc` to your `uasm\include` folder (or wherever your includes are located)
* Copy `VirtualStack.lib` to your `uasm\lib\x64` folder (or wherever your 64bit libraries are located)
* Add the following to your project:
```assembly
include VirtualStack.inc
includelib VirtualStack.lib
```
## Functions

### VirtualStackCreate

*Description*: Creates a virtual size. qwStackSize indicates the size (max amount of stack items) that can be created on the virtual stack

*Parameters*: `qwStackSize`, `qwStackOptions`

*Returns*: `rax` contains handle to the virtual stack (hVirtualStack) or `NULL` if an error occured

### VirtualStackDelete

*Description*: Deletes a virtual stack. lpqwVirtualDeleteCallbackProc (can be `NULL`) is a optional pointer to a callback function that accepts two parameters (hVirtualStack and qwUniqueValue) to pass to this function, allowing user to clear up any resources that have been stored on the virtual stack. qwUniqueValue will only contain unique values that where previously stored on the virtual stack.

*Parameters*: `hVirtualStack`, `lpqwVirtualDeleteCallbackProc`

*Returns*: `rax` contains `TRUE` if successful or `FALSE` otherwise

### VirtualStackPush

*Description*: 'Pushes' a `QWORD` value onto a virtual stack

*Parameters*: `hVirtualStack`, `qwPushValue`

*Returns*: `rax` contains `TRUE` if successful or `FALSE` otherwise

### VirtualStackPop

*Description*: 'Pops' a value from a virtual stack and returns it in the `QWORD` value pointed to by lpqwPopValue

*Parameters*: `hVirtualStack`, `lpqwPopValue`

*Returns*: `rax` contains `TRUE` if successful or `FALSE` otherwise. Additionally returns `-1` if stack is empty (no more items on stack)

### VirtualStackPeek

*Description*: Peeks (reads) a value from a virtual stack and returns it in the `QWORD` value pointed to by lpqwPeekValue. VIrtualStackPeek does not 'pop' the virtual stack, only reads the stack

*Parameters*: `hVirtualStack`, `lpqwPeekValue`

*Returns*: `rax` contains `TRUE` if successful or `FALSE` otherwise. Additionally returns `-1` if stack is empty (no more items on stack)

### VirtualStackPeer

*Description*: Peers (Similar to VirtualStackPeek, but reads stack+1) a value from a virtual stack and returns it in the `QWORD` value pointed to by lpqwPeerValue. VirtualStackPeer does not 'pop' the virtual stack, only reads the stack

*Parameters*: `hVirtualStack`, `lpqwPeerValue`

*Returns*: `rax` contains `TRUE` if successful or `FALSE` otherwise. Additionally returns `-1` if stack is empty (no more items on stack)

### VirtualStackZero

*Description*: Zeros the entire virtual stack and resets it back to 0, clearing all data

*Parameters*: `hVirtualStack`

*Returns*: `rax` contains `TRUE` if successful or `FALSE` otherwise

### VirtualStackCount

*Description*: Returns the total number of items on a virtual stack

*Parameters*: `hVirtualStack`

*Returns*: `rax` contains total number of items on a virtual stack

### VirtualStackSize

*Description*: Returns the maximum no of items that can be on the virtual stack (as defined when creating the stack with VirtualStackCreate)

*Parameters*: `hVirtualStack`

*Returns*: `rax` contains the maximum no of items that can be on the virtual stack

### VirtualStackDepth

*Description*: Returns the maximum no of items that was ever on the virtual stack

*Parameters*: `hVirtualStack`

*Returns*: `rax` contains the maximum no of items that was ever on the virtual stack

### VirtualStackData

*Description*: Returns a pointer to stack data

*Parameters*: `hVirtualStack`

*Returns*: `rax` contains the pointer to the stack data

### VirtualStackUniqueCount

*Description*: Returns number of unique items placed on virtual stack

*Parameters*: `hVirtualStack`

*Returns*: `eax` contains the number of unique items placed on virtual stack