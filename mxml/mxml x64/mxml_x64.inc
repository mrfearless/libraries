; Mini-XML, a small XML file parsing library. 
;
; https://www.msweet.org/mxml
;
; Copyright © 2003-2021 by Michael R Sweet.

; mxml_x64.inc converted from mxml source for assembler by fearless 2023
; www.github.com/mrfearless

include msvcrt.inc
includelib ucrt.lib
includelib vcruntime.lib

mxmlAdd PROTO parent:QWORD,where:QWORD,child:QWORD,node:QWORD
mxmlDelete PROTO node:QWORD
mxmlElementDeleteAttr PROTO node:QWORD,lpszname:QWORD
mxmlElementGetAttr PROTO node:QWORD,lpszname:QWORD
mxmlElementGetAttrByIndex PROTO node:QWORD,idx:QWORD,lpszname:QWORD
mxmlElementGetAttrCount PROTO node:QWORD
mxmlElementSetAttr PROTO node:QWORD,lpszname:QWORD,value:QWORD
mxmlElementSetAttrf PROTO C :VARARG
mxmlEntityAddCallback PROTO cb:QWORD
mxmlEntityGetName PROTO val:QWORD
mxmlEntityGetValue PROTO lpszname:QWORD
mxmlEntityRemoveCallback PROTO cb:QWORD
mxmlFindElement PROTO node:QWORD,top:QWORD,element:QWORD,attr:QWORD,value:QWORD,descend:QWORD
mxmlFindPath PROTO node:QWORD,path:QWORD
mxmlGetCDATA PROTO node:QWORD
mxmlGetCDAT equ <mxmlGetCDATA>

mxmlGetCustom PROTO node:QWORD
mxmlGetElement PROTO node:QWORD
mxmlGetFirstChild PROTO node:QWORD
mxmlGetInteger PROTO node:QWORD
mxmlGetLastChild PROTO node:QWORD
mxmlGetNextSibling PROTO node:QWORD
mxmlGetOpaque PROTO node:QWORD
mxmlGetParent PROTO node:QWORD
mxmlGetPrevSibling PROTO node:QWORD
mxmlGetReal PROTO node:QWORD
mxmlGetRefCount PROTO node:QWORD
mxmlGetText PROTO node:QWORD,whitespace:QWORD
mxmlGetType PROTO node:QWORD
mxmlGetUserData PROTO node:QWORD
mxmlIndexDelete PROTO ind:QWORD
mxmlIndexEnum PROTO ind:QWORD
mxmlIndexFind PROTO ind:QWORD,element:QWORD,value:QWORD
mxmlIndexGetCount PROTO ind:QWORD
mxmlIndexNew PROTO node:QWORD,element:QWORD,attr:QWORD
mxmlIndexReset PROTO ind:QWORD
mxmlLoadFd PROTO top:QWORD,fd:QWORD,cb:QWORD
mxmlLoadFile PROTO top:QWORD,fp:QWORD,cb:QWORD
mxmlLoadString PROTO top:QWORD,s:QWORD,cb:QWORD
mxmlNewCDATA PROTO parent:QWORD,string:QWORD
mxmlNewCDAT equ <mxmlNewCDATA>

mxmlNewCustom PROTO parent:QWORD,data:QWORD,destroy:QWORD
mxmlNewElement PROTO parent:QWORD,lpszname:QWORD
mxmlNewInteger PROTO parent:QWORD,integer:QWORD
mxmlNewOpaque PROTO parent:QWORD,opaque:QWORD
mxmlNewOpaquef PROTO C :VARARG
mxmlNewReal PROTO parent:QWORD,real:QWORD
mxmlNewText PROTO parent:QWORD,whitespace:QWORD,string:QWORD
mxmlNewTextf PROTO C :VARARG
mxmlNewXML PROTO version:QWORD
mxmlRelease PROTO node:QWORD
mxmlRemove PROTO node:QWORD
mxmlRetain PROTO node:QWORD
mxmlSAXLoadFd PROTO top:QWORD,fd:QWORD,cb:QWORD,sax:QWORD,sax_data:QWORD
mxmlSAXLoadFile PROTO top:QWORD,fp:QWORD,cb:QWORD,sax:QWORD,sax_data:QWORD
mxmlSAXLoadString PROTO top:QWORD,s:QWORD,cb:QWORD,sax:QWORD,sax_data:QWORD
mxmlSaveAllocString PROTO node:QWORD,cb:QWORD
mxmlSaveFd PROTO node:QWORD,fd:QWORD,cb:QWORD
mxmlSaveFile PROTO node:QWORD,fp:QWORD,cb:QWORD
mxmlSaveString PROTO node:QWORD,buffer:QWORD,bufsize:QWORD,cb:QWORD
mxmlSetCDATA PROTO node:QWORD,data:QWORD
mxmlSetCDAT equ <mxmlSetCDATA>

mxmlSetCustom PROTO node:QWORD,data:QWORD,destroy:QWORD
mxmlSetCustomHandlers PROTO load:QWORD,save:QWORD
mxmlSetElement PROTO node:QWORD,lpszname:QWORD
mxmlSetErrorCallback PROTO cb:QWORD
mxmlSetInteger PROTO node:QWORD,integer:QWORD
mxmlSetOpaque PROTO node:QWORD,opaque:QWORD
mxmlSetOpaquef PROTO C :VARARG
mxmlSetReal PROTO node:QWORD,real:QWORD
mxmlSetText PROTO node:QWORD,whitespace:QWORD,string:QWORD
mxmlSetTextf PROTO C :VARARG
mxmlSetUserData PROTO node:QWORD,data:QWORD
mxmlSetWrapMargin PROTO column:QWORD
mxmlWalkNext PROTO node:QWORD,top:QWORD,descend:QWORD
mxmlWalkPrev PROTO node:QWORD,top:QWORD,descend:QWORD
mxml_error PROTO C :VARARG
mxml_ignore_cb PROTO node:QWORD
mxml_integer_cb PROTO node:QWORD
mxml_opaque_cb PROTO node:QWORD
mxml_real_cb PROTO node:QWORD

; Structures
MXML_ATTR_T                 STRUCT 8 ; An XML element attribute value. @private@ 
    attr_name               QWORD ?;    char *name              ; Attribute name
    attr_value              QWORD ?;    char *value             ; Attribute value
MXML_ATTR_T                 ENDS

MXML_ELEMENT_T              STRUCT 8 ; An XML element value. @private@
    element_name            QWORD ? ;   char *name              ; Name of element
    num_attrs               QWORD ? ;   int                     ; Number of attributes
    attrs                   QWORD ? ;   mxml_attr_t *attrs;     ; Attributes
MXML_ELEMENT_T              ENDS

MXML_TEXT_T                 STRUCT 8  ; An XML text value. @private@
    whitespace              QWORD ? ;   int                     ;Leading whitespace?
    string                  QWORD ? ;   char*string             ; Fragment string
MXML_TEXT_T                 ENDS

MXML_CUSTOM_T               STRUCT 8 ; An XML custom value. @private@
    data                    QWORD ? ;   void            *       ; Pointer to (allocated) custom data 
    destroy                 QWORD ? ;   mxml_custom_destroy_cb_t; Pointer to destructor function
MXML_CUSTOM_T               ENDS

MXML_VALUE_T                STRUCT 8 ; An XML node value. @private@
    element                 MXML_ELEMENT_T <> ; mxml_element_t  ; Element
    integer                 QWORD ? ;   int                     ; Integer number
    opaque                  QWORD ? ;   char *                  ; Opaque string
    real                    REAL4 ? ;   double                  ; Real number
    text                    MXML_TEXT_T <> ; mxml_text_t struct ; Text fragment
    custom                  MXML_CUSTOM_T <>;mxml_custom_t struc; Custom data @since Mini-XML 2.1@
MXML_VALUE_T                ENDS

MXML_NODE_T                 STRUCT 8 ; An XML node. @private@
    nodetype                QWORD ? ;   Node type
    next                    QWORD ? ;   pointer to mxml_node_t  *   ; Next node under same parent
    prev                    QWORD ? ;   pointer to mxml_node_t  *   ; Previous node under same parent
    parent                  QWORD ? ;   pointer to mxml_node_t  *   ; Parent node
    child                   QWORD ? ;   pointer to mxml_node_t  *   ; First child node
    last_child              QWORD ? ;   pointer to mxml_node_t  *   ; Last child nod
    node_value              MXML_VALUE_T <> ; mxml_value_t struct   ; Node value
    ref_count               QWORD ? ;   int                         ; Use count
    user_data               QWORD ? ;   pointer to user data        ; User data
MXML_NODE_T                 ENDS

MXML_INDEX_T                STRUCT 8 ; An XML node index. @private@
    attr                    QWORD ? ;   char    *   ; Attribute used for indexing or NULL
    num_nodes               QWORD ? ;   int         ; Number of nodes in index
    alloc_nodes             QWORD ? ;   int         ; Allocated nodes in index
    cur_node                QWORD ? ;   int         ; Current node
    nodes                   QWORD ? ;   mxml_node_t **mxml_node_t <>; Node array
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







