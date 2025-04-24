# Treeview x64 Functions

### TreeViewBranchCollapse

*Description*: Collapse the specified item and all the children below it (branch)

*Parameters*: `hTreeview`, `hItem`

*Returns*: None.

### TreeViewBranchDepth

*Description*: Returns the maximum depth of all children branches from the specified item downwards.

*Parameters*: `hTreeview`, `hItem`

*Returns*: `rax` contains the max depth of children branches.

### TreeViewBranchExpand

*Description*: Expand the specified item and all the children below it (branch)

*Parameters*: `hTreeview`, `hItem`

*Returns*: None.

### TreeViewChildItemsToggle

*Description*: 

*Parameters*: `hTreeview`, `hItem`

*Returns*: None.

### TreeViewClearAll

*Description*: Clears / Deletes all treeview items.

*Parameters*: `hTreeview`

*Returns*: None.

### TreeViewCountChildren

*Description*: Counts the number of items under the specified item.

*Parameters*: `hTreeview`, `hItem`, `bRecurse`

*Returns*: `rax` contains number of items.

### TreeViewCountItems

*Description*: Counts total number of items in the treeview.

*Parameters*: `hTreeview`

*Returns*: `rax` contains total number of items.

### TreeViewDeleteAll

*Description*: Clears / Deletes all treeview items.

*Parameters*: `hTreeview`

*Returns*: None.

### TreeViewFindItem

*Description*: Finds the specified text in any item, starting from the specified item.

*Parameters*: `hTreeview`, `hItem`, `lpszFindText`

*Returns*: `rax` contains hItem that contains the matching text searched for, or NULL otherwise.

### TreeViewGetItemImage

*Description*: Gets the imagelist index used by the specified item.

*Parameters*: `hTreeview`, `hItem`

*Returns*: `rax` contains the imagelist index number associated with the icon used in the item.

### TreeViewGetItemParam

*Description*: Gets the lParam value associated with the item, when it was created or assigned to it via `TreeViewItemInsert` or `TreeViewSetItemParam`.

*Parameters*: `hTreeview`, `hItem`

*Returns*: `rax` contains the lParam value associated with the item.

### TreeViewGetItemText

*Description*: Gets the text of the specified item and stores it in the buffer pointed to by lpszTextBuffer.

*Parameters*: `hTreeview`, `hItem`, `lpszTextBuffer`, `qwSizeTextBuffer`

*Returns*: `rax` contains the length of text returned in the `lpszTextBuffer` or 0 otherwise.

### TreeViewGetSelectedImage

*Description*: Gets the imagelist index used by the currently selected item.

*Parameters*: `hTreeview`

*Returns*: `rax` contains the imagelist index number associated with the icon used in the item.

### TreeViewGetSelectedItem

*Description*: Gets the currently selected item of the treeview.

*Parameters*: `hTreeview`

*Returns*: `rax` contains `hItem` or `NULL` if no item is currently selected.

### TreeViewGetSelectedParam

*Description*: Gets the lParam value associated with the currently selected item, when it was created or assigned to it via `TreeViewItemInsert` or `TreeViewSetItemParam`

*Parameters*: `hTreeview`

*Returns*: `rax` contains the lParam value associated with the item.

### TreeViewGetSelectedText

*Description*: Gets the text of the currently selected  item and stores it in the buffer pointed to by lpszTextBuffer.

*Parameters*: `hTreeview`, `lpszTextBuffer`, `qwSizeTextBuffer`

*Returns*: `rax` contains the length of text returned in the `lpszTextBuffer` or 0 otherwise.

### TreeViewItemCollapse

*Description*: Collapse the specified item if it has children.

*Parameters*: `hTreeview`, `hItem`

*Returns*: None.

### TreeViewItemDelete

*Description*: Deletes the specified item from the treeview. To delete all items use `TreeViewClearAll` or `TreeViewDeleteAll`

*Parameters*: `hTreeview`, `hItem`

*Returns*: None.

### TreeViewItemExpand

*Description*: Expand the specified item if it has children.

*Parameters*: `hTreeview`, `hItem`

*Returns*: None.

### TreeViewItemHasChildren

*Description*: Determines if the specified item has children items under it.

*Parameters*: `hTreeview`, `hItem`

*Returns*: `rax` contains `TRUE` if item has children or `FALSE` otherwise.

### TreeViewItemInsert

*Description*: Insert / Add a new item to the treeview. New item to be inserted is relative to the hNodeParent and NodePosition. After each insertion the nNodeIndex value should be incremented for use with the next item to be inserted. lpszNodeText points to a buffer containing text to display in the treeview item. User can set qwParam to a custom value for their own usage.

*Parameters*: `hTreeview`, `hNodeParent`, `lpszNodeText`, `nNodeIndex`, `NodePosition`, `nImage`, `nImageSelected`, `qwParam`

*Returns*: `rax` contains hItem of newly inserted item or `NULL` otherwise.

### TreeViewItemToggle

*Description*: Collapse or expands the specified item, depening on the previous state.

*Parameters*: `hTreeview`, `hItem`

*Returns*: None.

### TreeViewLinkImageList

*Description*: Links a previously created imagelist and associates it and its icons with the treeview. The index of icons added to the imagelist are used when using TreeViewInsert, `TreeViewGetItemImage`, `TreeViewSetItemImage` or `TreeViewGetSelectedImage`

*Parameters*: `hTreeview`, `hImagelist`, `ImagelistType`

*Returns*: None.

### TreeViewRootCollapse

*Description*: Collapses all items in the treeview and all branches.

*Parameters*: `hTreeview`

*Returns*: None.

### TreeViewRootExpand

*Description*: Expands all items in the treeview and all branches.

*Parameters*: `hTreeview`

*Returns*: None

### TreeViewSetItemImage

*Description*: Set the specified item's icon, which is a index from the associated and linked imagelist used by the treeview.

*Parameters*: `hTreeview`, `hItem`, `nImageListIndex`

*Returns*: None.

### TreeViewSetItemParam

*Description*: Sets the specified item's lParam value. A custom value for your own usage.

*Parameters*: `hTreeview`, `hItem`, `qwParam`

*Returns*: None.

### TreeViewSetItemText

*Description*: Sets the specified item's text to the string pointed to by lpszTextBuffer.

*Parameters*: `hTreeview`, `hItem`, lpszTextBuffer

*Returns*: None.

### TreeViewSetSelectedItem

*Description*: Sets the currently selected item in the treeview and scrolls the item into view if `bVisible` is `TRUE`

*Parameters*: `hTreeview`, `hItem`, `bVisible`

*Returns*: None.

### TreeViewSubClassData

*Description*: Set subclass data to the subclassed treeview (subclassed via `TreeViewSubClassProc`) This is just a wrapper of `SetWindowLong` / `SetWindowLongPtr`.

*Parameters*: `hTreeview`, `lpqwTVSubClassData`

*Returns*: None.

### TreeViewSubClassProc

*Description*: Set the procedure of the treeview subclass. This is just a wrapper of `SetWindowLong` / `SetWindowLongPtr`.

*Parameters*: `hTreeview`, `lpqwTVSubClassProc`

*Returns*: `rax` contains pointer to original procedure.

### TreeViewWalk

*Description*: Walks the treeview and returns each item in turn back via a callback function. Walk starts at the specified hItem. 

*Parameters*: `hTreeview`, `hItem`, `lpTreeViewWalkCallback`, `lpCustomData`

*Returns*: `rax` contains `TRUE` if succesful or `FALSE` otherwise.

### TreeViewWalkCallback

*Description*: Callback function defined by user and used with TreeViewWalk. The callback functions expects the parameters as listed below. Returning `TRUE` from the callback function continues the walk process or `FALSE` to cancel out of it. `qwStatus` will contain one of the following values:

`TREEVIEWWALK_NULL`
`TREEVIEWWALK_ITEM`
`TREEVIEWWALK_ITEM_START`
`TREEVIEWWALK_ITEM_FINISH`
`TREEVIEWWALK_ROOT_START`
`TREEVIEWWALK_ROOT_FINISH`

*Parameters*: `hTreeview`, `hItem`, `qwStatus`, `qwTotalItems`, `qwItemNo`, `qwLevel`, `qwCustomData`

*Returns*: `rax` should contain `TRUE` to continue or `FALSE` to cancel the walk process.
