; Mini-XML, a small XML file parsing library. 
;
; https://www.msweet.org/mxml
;
; Copyright © 2003-2021 by Michael R Sweet.

; mxml_x86.inc converted from mxml source for assembler by fearless 2023
; www.github.com/mrfearless

include msvcrt.inc
includelib ucrt.lib
includelib vcruntime.lib

mxmlAdd PROTO STDCALL parent:DWORD,where:DWORD,child:DWORD,node:DWORD
mxmlDelete PROTO STDCALL node:DWORD
mxmlElementDeleteAttr PROTO STDCALL node:DWORD,lpszname:DWORD
mxmlElementGetAttr PROTO STDCALL node:DWORD,lpszname:DWORD
mxmlElementGetAttrByIndex PROTO STDCALL node:DWORD,idx:DWORD,lpszname:DWORD
mxmlElementGetAttrCount PROTO STDCALL node:DWORD
mxmlElementSetAttr PROTO STDCALL node:DWORD,lpszname:DWORD,value:DWORD
mxmlElementSetAttrf PROTO C :VARARG
mxmlEntityAddCallback PROTO STDCALL cb:DWORD
mxmlEntityGetName PROTO STDCALL val:DWORD
mxmlEntityGetValue PROTO STDCALL lpszname:DWORD
mxmlEntityRemoveCallback PROTO STDCALL cb:DWORD
mxmlFindElement PROTO STDCALL node:DWORD,top:DWORD,element:DWORD,attr:DWORD,value:DWORD,descend:DWORD
mxmlFindPath PROTO STDCALL node:DWORD,path:DWORD
mxmlGetCDATA PROTO STDCALL node:DWORD
mxmlGetCDAT equ <mxmlGetCDATA>

mxmlGetCustom PROTO STDCALL node:DWORD
mxmlGetElement PROTO STDCALL node:DWORD
mxmlGetFirstChild PROTO STDCALL node:DWORD
mxmlGetInteger PROTO STDCALL node:DWORD
mxmlGetLastChild PROTO STDCALL node:DWORD
mxmlGetNextSibling PROTO STDCALL node:DWORD
mxmlGetOpaque PROTO STDCALL node:DWORD
mxmlGetParent PROTO STDCALL node:DWORD
mxmlGetPrevSibling PROTO STDCALL node:DWORD
mxmlGetReal PROTO STDCALL node:DWORD
mxmlGetRefCount PROTO STDCALL node:DWORD
mxmlGetText PROTO STDCALL node:DWORD,whitespace:DWORD
mxmlGetType PROTO STDCALL node:DWORD
mxmlGetUserData PROTO STDCALL node:DWORD
mxmlIndexDelete PROTO STDCALL ind:DWORD
mxmlIndexEnum PROTO STDCALL ind:DWORD
mxmlIndexFind PROTO STDCALL ind:DWORD,element:DWORD,value:DWORD
mxmlIndexGetCount PROTO STDCALL ind:DWORD
mxmlIndexNew PROTO STDCALL node:DWORD,element:DWORD,attr:DWORD
mxmlIndexReset PROTO STDCALL ind:DWORD
mxmlLoadFd PROTO STDCALL top:DWORD,fd:DWORD,cb:DWORD
mxmlLoadFile PROTO STDCALL top:DWORD,fp:DWORD,cb:DWORD
mxmlLoadString PROTO STDCALL top:DWORD,s:DWORD,cb:DWORD
mxmlNewCDATA PROTO STDCALL parent:DWORD,string:DWORD
mxmlNewCDAT equ <mxmlNewCDATA>

mxmlNewCustom PROTO STDCALL parent:DWORD,data:DWORD,destroy:DWORD
mxmlNewElement PROTO STDCALL parent:DWORD,lpszname:DWORD
mxmlNewInteger PROTO STDCALL parent:DWORD,integer:DWORD
mxmlNewOpaque PROTO STDCALL parent:DWORD,opaque:DWORD
mxmlNewOpaquef PROTO C :VARARG
mxmlNewReal PROTO STDCALL parent:DWORD,real:QWORD
mxmlNewText PROTO STDCALL parent:DWORD,whitespace:DWORD,string:DWORD
mxmlNewTextf PROTO C :VARARG
mxmlNewXML PROTO STDCALL version:DWORD
mxmlRelease PROTO STDCALL node:DWORD
mxmlRemove PROTO STDCALL node:DWORD
mxmlRetain PROTO STDCALL node:DWORD
mxmlSAXLoadFd PROTO STDCALL top:DWORD,fd:DWORD,cb:DWORD,sax:DWORD,sax_data:DWORD
mxmlSAXLoadFile PROTO STDCALL top:DWORD,fp:DWORD,cb:DWORD,sax:DWORD,sax_data:DWORD
mxmlSAXLoadString PROTO STDCALL top:DWORD,s:DWORD,cb:DWORD,sax:DWORD,sax_data:DWORD
mxmlSaveAllocString PROTO STDCALL node:DWORD,cb:DWORD
mxmlSaveFd PROTO STDCALL node:DWORD,fd:DWORD,cb:DWORD
mxmlSaveFile PROTO STDCALL node:DWORD,fp:DWORD,cb:DWORD
mxmlSaveString PROTO STDCALL node:DWORD,buffer:DWORD,bufsize:DWORD,cb:DWORD
mxmlSetCDATA PROTO STDCALL node:DWORD,data:DWORD
mxmlSetCDAT equ <mxmlSetCDATA>

mxmlSetCustom PROTO STDCALL node:DWORD,data:DWORD,destroy:DWORD
mxmlSetCustomHandlers PROTO STDCALL load:DWORD,save:DWORD
mxmlSetElement PROTO STDCALL node:DWORD,lpszname:DWORD
mxmlSetErrorCallback PROTO STDCALL cb:DWORD
mxmlSetInteger PROTO STDCALL node:DWORD,integer:DWORD
mxmlSetOpaque PROTO STDCALL node:DWORD,opaque:DWORD
mxmlSetOpaquef PROTO C :VARARG
mxmlSetReal PROTO STDCALL node:DWORD,real:QWORD
mxmlSetText PROTO STDCALL node:DWORD,whitespace:DWORD,string:DWORD
mxmlSetTextf PROTO C :VARARG
mxmlSetUserData PROTO STDCALL node:DWORD,data:DWORD
mxmlSetWrapMargin PROTO STDCALL column:DWORD
mxmlWalkNext PROTO STDCALL node:DWORD,top:DWORD,descend:DWORD
mxmlWalkPrev PROTO STDCALL node:DWORD,top:DWORD,descend:DWORD
mxml_error PROTO C :VARARG
mxml_ignore_cb PROTO STDCALL node:DWORD
mxml_integer_cb PROTO STDCALL node:DWORD
mxml_opaque_cb PROTO STDCALL node:DWORD
mxml_real_cb PROTO STDCALL node:DWORD

; Structures
MXML_ATTR_T                 STRUCT ; An XML element attribute value. @private@ 
    attr_name               DWORD ?;    char *name              ; Attribute name
    attr_value              DWORD ?;    char *value             ; Attribute value
MXML_ATTR_T                 ENDS

MXML_ELEMENT_T              STRUCT ; An XML element value. @private@
    element_name            DWORD ? ;   char *name              ; Name of element
    num_attrs               DWORD ? ;   int                     ; Number of attributes
    attrs                   DWORD ? ;   mxml_attr_t *attrs;     ; Attributes
MXML_ELEMENT_T              ENDS

MXML_TEXT_T                 STRUCT  ; An XML text value. @private@
    whitespace              DWORD ? ;   int                     ;Leading whitespace?
    string                  DWORD ? ;   char*string             ; Fragment string
MXML_TEXT_T                 ENDS

MXML_CUSTOM_T               STRUCT ; An XML custom value. @private@
    data                    DWORD ? ;   void            *       ; Pointer to (allocated) custom data 
    destroy                 DWORD ? ;   mxml_custom_destroy_cb_t; Pointer to destructor function
MXML_CUSTOM_T               ENDS

MXML_VALUE_T                STRUCT ; An XML node value. @private@
    element                 MXML_ELEMENT_T <> ; mxml_element_t  ; Element
    integer                 DWORD ? ;   int                     ; Integer number
    opaque                  DWORD ? ;   char *                  ; Opaque string
    real                    REAL4 ? ;   double                  ; Real number
    text                    MXML_TEXT_T <> ; mxml_text_t struct ; Text fragment
    custom                  MXML_CUSTOM_T <>;mxml_custom_t struc; Custom data @since Mini-XML 2.1@
MXML_VALUE_T                ENDS

MXML_NODE_T                 STRUCT ; An XML node. @private@
    nodetype                DWORD ? ;   Node type
    next                    DWORD ? ;   pointer to mxml_node_t  *   ; Next node under same parent
    prev                    DWORD ? ;   pointer to mxml_node_t  *   ; Previous node under same parent
    parent                  DWORD ? ;   pointer to mxml_node_t  *   ; Parent node
    child                   DWORD ? ;   pointer to mxml_node_t  *   ; First child node
    last_child              DWORD ? ;   pointer to mxml_node_t  *   ; Last child nod
    node_value              MXML_VALUE_T <> ; mxml_value_t struct   ; Node value
    ref_count               DWORD ? ;   int                         ; Use count
    user_data               DWORD ? ;   pointer to user data        ; User data
MXML_NODE_T                 ENDS

MXML_INDEX_T                STRUCT ; An XML node index. @private@
    attr                    DWORD ? ;   char    *   ; Attribute used for indexing or NULL
    num_nodes               DWORD ? ;   int         ; Number of nodes in index
    alloc_nodes             DWORD ? ;   int         ; Allocated nodes in index
    cur_node                DWORD ? ;   int         ; Current node
    nodes                   DWORD ? ;   mxml_node_t **mxml_node_t <>; Node array
MXML_INDEX_T                ENDS


; Typedefs
MXML_ATTR_S                 TYPEDEF MXML_ATTR_T
MXML_ELEMENT_S              TYPEDEF MXML_ELEMENT_T
MXML_TEXT_S                 TYPEDEF MXML_TEXT_T
MXML_CUSTOM_S               TYPEDEF MXML_CUSTOM_T
MXML_VALUE_S                TYPEDEF MXML_VALUE_T
MXML_NODE_S                 TYPEDEF MXML_NODE_T
MXML_INDEX_S                TYPEDEF MXML_INDEX_T

.CONST
MXML_MAJOR_VERSION          EQU 3   ; Major version number
MXML_MINOR_VERSION          EQU 2   ; Minor version number

MXML_TAB                    EQU 8   ; Tabs every N columns

MXML_NO_CALLBACK            EQU 0   ; Don't use a type callback
MXML_INTEGER_CALLBACK       EQU 1   ; Treat all data as integers
MXML_OPAQUE_CALLBACK        EQU 2   ; Treat all data as opaque
MXML_REAL_CALLBACK          EQU 3   ; Treat all data as real numbers
MXML_TEXT_CALLBACK          EQU 0   ; Treat all data as text
MXML_IGNORE_CALLBACK        EQU -1  ; Ignore all non-element content

MXML_NO_PARENT              EQU 0   ; No parent for the node

MXML_DESCEND                EQU 1   ; Descend when finding/walking
MXML_NO_DESCEND             EQU 0   ; Don't descend when finding/walking
MXML_DESCEND_FIRST          EQU -1  ; Descend for first find

MXML_WS_BEFORE_OPEN         EQU 0   ; Callback for before open tag
MXML_WS_AFTER_OPEN          EQU 1   ; Callback for after open tag
MXML_WS_BEFORE_CLOSE        EQU 2   ; Callback for before close tag
MXML_WS_AFTER_CLOSE         EQU 3   ; Callback for after close tag

MXML_ADD_BEFORE             EQU 0   ; Add node before specified node
MXML_ADD_AFTER              EQU 1   ; Add node after specified node
MXML_ADD_TO_PARENT          EQU NULL; Add node relative to parent

; enum mxml_sax_event_e     ; SAX event type.
MXML_SAX_CDATA              EQU 0   ; CDATA node
MXML_SAX_COMMENT            EQU 1   ; Comment node
MXML_SAX_DATA               EQU 2   ; Data node
MXML_SAX_DIRECTIVE          EQU 3   ; Processing directive node
MXML_SAX_ELEMENT_CLOSE      EQU 4   ; Element closed
MXML_SAX_ELEMENT_OPEN       EQU 5   ; Element opened

; enum mxml_type_e          ; The XML node type.
MXML_IGNORE                 EQU -1  ; Ignore/throw away node @since Mini-XML 2.3@
MXML_ELEMENT                EQU 0   ; XML element with attributes
MXML_INTEGER                EQU 1   ; Integer value
MXML_OPAQUE                 EQU 2   ; Opaque string
MXML_REAL                   EQU 3   ; Real value
MXML_TEXT                   EQU 4   ; Text fragment
MXML_CUSTOM                 EQU 5   ; Custom data @since Mini-XML 2.1@







