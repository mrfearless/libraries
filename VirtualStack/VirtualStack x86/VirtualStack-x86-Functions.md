# VirtualStack x86 Functions

### VirtualStackCreate

*Description*: Creates a virtual size. dwStackSize indicates the size (max amount of stack items) that can be created on the virtual stack

*Parameters*: `dwStackSize`, `dwStackOptions`

*Returns*: `eax` contains handle to the virtual stack (hVirtualStack) or `NULL` if an error occured

### VirtualStackDelete

*Description*: Deletes a virtual stack. lpdwVirtualDeleteCallbackProc (can be `NULL`) is a optional pointer to a callback function that accepts two parameters (hVirtualStack and dwUniqueValue) to pass to this function, allowing user to clear up any resources that have been stored on the virtual stack. dwUniqueValue will only contain unique values that where previously stored on the virtual stack.

*Parameters*: `hVirtualStack`, `lpdwVirtualDeleteCallbackProc`

*Returns*: `eax` contains `TRUE` if successful or `FALSE` otherwise

### VirtualStackPush

*Description*: 'Pushes' a `DWORD` value onto a virtual stack

*Parameters*: `hVirtualStack`, `dwPushValue`

*Returns*: `eax` contains `TRUE` if successful or `FALSE` otherwise

### VirtualStackPop

*Description*: 'Pops' a value from a virtual stack and returns it in the `DWORD` value pointed to by lpdwPopValue

*Parameters*: `hVirtualStack`, `lpdwPopValue`

*Returns*: `eax` contains `TRUE` if successful or `FALSE` otherwise. Additionally returns `-1` if stack is empty (no more items on stack)

### VirtualStackPeek

*Description*: Peeks (reads) a value from a virtual stack and returns it in the `DWORD` value pointed to by lpdwPeekValue. VirtualStackPeek does not 'pop' the virtual stack, only reads the stack

*Parameters*: `hVirtualStack`, `lpdwPeekValue`

*Returns*: `eax` contains `TRUE` if successful or `FALSE` otherwise. Additionally returns `-1` if stack is empty (no more items on stack)

### VirtualStackPeer

*Description*: Peers (Similar to VirtualStackPeek, but reads stack+1) a value from a virtual stack and returns it in the `DWORD` value pointed to by lpdwPeerValue. VirtualStackPeer does not 'pop' the virtual stack, only reads the stack

*Parameters*: `hVirtualStack`, `lpdwPeerValue`

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

### VirtualStackDepth

*Description*: Returns the maximum no of items that was ever on the virtual stack

*Parameters*: `hVirtualStack`

*Returns*: `eax` contains the maximum no of items that was ever on the virtual stack

### VirtualStackData

*Description*: Returns a pointer to stack data

*Parameters*: `hVirtualStack`

*Returns*: `eax` contains the pointer to the stack data

### VirtualStackUniqueCount

*Description*: Returns number of unique items placed on virtual stack

*Parameters*: `hVirtualStack`

*Returns*: `eax` contains the number of unique items placed on virtual stack