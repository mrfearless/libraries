# ![](../assets/VirtualStack.png)VirtualStack x86

Static x86 assembler library for creating a virtual stack and manipulating it (push, pop, peek etc)

## Usage

* Copy `VirtualStack.inc` to your `masm\include` folder (or wherever your includes are located)
* Copy `VirtualStack.lib` to your `masm\lib` folder (or wherever your libraries are located)
* Add the following to your project:
```assembly
include VirtualStack.inc
includelib VirtualStack.lib
```
## Functions

### VirtualStackCreate

*Description*: Creates a virtual size. dwStackSize indicates the size (max amount of stack items) that can be created on the virtual stack

*Parameters*: `dwStackSize`

*Returns*: `eax` contains handle to the virtual stack (hVirtualStack) or `NULL` if an error occured

### VirtualStackDelete

*Description*: Deletes a virtual stack

*Parameters*: `hVirtualStack`

*Returns*: `eax` contains `TRUE` if successful or `FALSE` otherwise

### VirtualStackPush

*Description*: 'Pushes' a value onto a virtual stack

*Parameters*: `hVirtualStack`, `dwPushValue`

*Returns*: `eax` contains `TRUE` if successful or `FALSE` otherwise

### VirtualStackPop

*Description*: 'Pops' a value from a virtual stack and returns it in the qword value pointed to by lpdwPopValue

*Parameters*: `hVirtualStack`, `lpdwPopValue`

*Returns*: `eax` contains `TRUE` if successful or `FALSE` otherwise. Additionally returns `-1` if stack is empty (no more items on stack)

### VirtualStackPeek

*Description*: Peeks (reads) a value from a virtual stack and returns it in the dword value pointed to by lpdwPeekValue. VIrtualStackPeek does not 'pop' the virtual stack, only reads the stack

*Parameters*: `hVirtualStack`, `lpdwPeekValue`

*Returns*: `eax` contains `TRUE` if successful or `FALSE` otherwise. Additionally returns `-1` if stack is empty (no more items on stack)

### VirtualStackZero

*Description*: Zeros the entire virtual stack and resets it back to 0, clearing all data

*Parameters*: `hVirtualStack`

*Returns*: `eax` contains `TRUE` if successful or `FALSE` otherwise

### VirtualStackCount

*Description*: Returns the total number of items on a virtual stack

*Parameters*: `hVirtualStack`

*Returns*: `eax` contains total number of items on a virtual stack

### VirtualStackSize

*Description*: Returns the maximum no of items that can be on the virtual stack (as defined when creating the stack with VirtualStackCreate)

*Parameters*: `hVirtualStack`

*Returns*: `eax` contains the maximum no of items that can be on the virtual stack

