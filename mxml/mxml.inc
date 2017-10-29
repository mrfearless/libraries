;
; Header file for Mini-XML, a small XML-like file parsing library.
;
; Copyright 2003-2016 by Michael R Sweet.
;
; These coded instructions, statements, and computer programs are the
; property of Michael R Sweet and are protected by Federal copyright
; law.  Distribution and use rights are outlined in the file "COPYING"
; which should have been included with this file.  If this file is
; missing or damaged, see the license at:
;
;   http://www.msweet.org/projects.php/Mini-XML
;

;
; Constants...
;

MXML_MAJOR_VERSION          EQU 2   ; Major version number
MXML_MINOR_VERSION          EQU 10  ; Minor version number

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


;
; Data types...
;

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


; void (*mxml_custom_destroy_cb_t)(void *);                     ; Custom data destructor
; void (*mxml_error_cb_t)(const char *);                        ; Error callback function

mxml_attr_t                 STRUCT ; An XML element attribute value. @private@ 
    attr_name               DWORD ?;    char *name              ; Attribute name
    attr_value              DWORD ?;    char *value             ; Attribute value
mxml_attr_t                 ENDS

mxml_element_t              STRUCT ; An XML element value. @private@
    element_name            DWORD ? ;   char *name              ; Name of element
    num_attrs               DWORD ? ;   int                     ; Number of attributes
    attrs                   DWORD ? ;   mxml_attr_t *attrs;     ; Attributes
mxml_element_t              ENDS

mxml_text_t                 STRUCT  ; An XML text value. @private@
    whitespace              DWORD ? ;   int                     ;Leading whitespace?
    string                  DWORD ? ;   char*string             ; Fragment string
mxml_text_t                 ENDS

mxml_custom_t               STRUCT ; An XML custom value. @private@
  data                      DWORD ? ;   void            *       ; Pointer to (allocated) custom data 
  destroy                   DWORD ? ;   mxml_custom_destroy_cb_t; Pointer to destructor function
mxml_custom_t               ENDS

mxml_value_t                STRUCT ; An XML node value. @private@
  element                   mxml_element_t <> ; mxml_element_t  ; Element
  integer                   DWORD ? ;   int                     ; Integer number
  opaque                    DWORD ? ;   char *                  ; Opaque string
  real                      REAL4 ? ;   double                  ; Real number
  text                      mxml_text_t <> ; mxml_text_t struct ; Text fragment
  custom                    mxml_custom_t <>;mxml_custom_t struc; Custom data @since Mini-XML 2.1@
mxml_value_t                ENDS

mxml_node_t                 STRUCT ; An XML node. @private@
  nodetype                  DWORD ? ;   Node type
  next                      DWORD ? ;   pointer to mxml_node_t  *   ; Next node under same parent
  prev                      DWORD ? ;   pointer to mxml_node_t  *   ; Previous node under same parent
  parent                    DWORD ? ;   pointer to mxml_node_t  *   ; Parent node
  child                     DWORD ? ;   pointer to mxml_node_t  *   ; First child node
  last_child                DWORD ? ;   pointer to mxml_node_t  *   ; Last child nod
  node_value                mxml_value_t <> ; mxml_value_t struct   ; Node value
  ref_count                 DWORD ? ;   int                         ; Use count
  user_data                 DWORD ? ;   pointer to user data        ; User data
mxml_node_t                 ENDS

mxml_index_t                STRUCT ; An XML node index. @private@
  attr                      DWORD ? ;   char    *   ; Attribute used for indexing or NULL
  num_nodes                 DWORD ? ;   int         ; Number of nodes in index
  alloc_nodes               DWORD ? ;   int         ; Allocated nodes in index
  cur_node                  DWORD ? ;   int         ; Current node
  nodes                     DWORD ? ;   mxml_node_t **mxml_node_t <>; Node array
mxml_index_t                ENDS

; struct mxml_index_s mxml_index_t;                                 ; An XML node index.
; int (*mxml_custom_load_cb_t)(mxml_node_t *, const char *);        ; Custom data load callback function
; char *(*mxml_custom_save_cb_t)(mxml_node_t *);                    ; Custom data save callback function
; int (*mxml_entity_cb_t)(const char *);                            ; Entity callback function
; mxml_type_t (*mxml_load_cb_t)(mxml_node_t *);                     ; Load callback function
; const char *(*mxml_save_cb_t)(mxml_node_t *, int);                ; Save callback function
; void (*mxml_sax_cb_t)(mxml_node_t *, mxml_sax_event_t, void *);   ; SAX callback function


;
; Prototypes...
;

mxmlAdd                 PROTO C :DWORD, :DWORD, :DWORD, :DWORD                  ; extern void           mxmlAdd(mxml_node_t *parent, int where, mxml_node_t *child, mxml_node_t *node);
mxmlDelete              PROTO C :DWORD                                          ; extern void           mxmlDelete(mxml_node_t *node);
mxmlElementDeleteAttr   PROTO C :DWORD, :DWORD                                  ; extern void           mxmlElementDeleteAttr(mxml_node_t *node, const char *name);
mxmlElementGetAttr      PROTO C :DWORD, :DWORD                                  ; extern const char     *mxmlElementGetAttr(mxml_node_t *node, const char *name);
mxmlElementSetAttr      PROTO C :DWORD, :DWORD, :DWORD                          ; extern void           mxmlElementSetAttr(mxml_node_t *node, const char *name, const char *value);
;mxmlElementSetAttrf    PROTO C :DWORD, :DWORD, :DWORD                          ; extern void           mxmlElementSetAttrf(mxml_node_t *node, const char *name, const char *format, ...)

mxmlEntityAddCallback   PROTO C :DWORD                                          ; extern int            mxmlEntityAddCallback(mxml_entity_cb_t cb);
mxmlEntityGetName       PROTO C :DWORD                                          ; extern const char     *mxmlEntityGetName(int val);
mxmlEntityGetValue      PROTO C :DWORD                                          ; extern int            mxmlEntityGetValue(const char *name);
mxmlEntityRemoveCallback PROTO C :DWORD                                         ; extern void           mxmlEntityRemoveCallback(mxml_entity_cb_t cb);
mxmlFindElement         PROTO C :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD  ; extern mxml_node_t    *mxmlFindElement(mxml_node_t *node, mxml_node_t *top, const char *name, const char *attr, const char *value, int descend);
mxmlFindPath            PROTO C :DWORD, :DWORD                                  ; extern mxml_node_t    *mxmlFindPath(mxml_node_t *node, const char *path);
mxmlGetCDATA            PROTO C :DWORD                                          ; extern const char     *mxmlGetCDATA(mxml_node_t *node);
mxmlGetCustom           PROTO C :DWORD                                          ; extern const void     *mxmlGetCustom(mxml_node_t *node);
mxmlGetElement          PROTO C :DWORD                                          ; extern const char     *mxmlGetElement(mxml_node_t *node);
mxmlGetFirstChild       PROTO C :DWORD                                          ; extern mxml_node_t    *mxmlGetFirstChild(mxml_node_t *node);
mxmlGetInteger          PROTO C :DWORD                                          ; extern int            mxmlGetInteger(mxml_node_t *node);
mxmlGetLastChild        PROTO C :DWORD                                          ; extern mxml_node_t    *mxmlGetLastChild(mxml_node_t *node);
mxmlGetNextSibling      PROTO C :DWORD                                          ; extern mxml_node_t    *mxmlGetNextSibling(mxml_node_t *node);
mxmlGetOpaque           PROTO C :DWORD                                          ; extern const char     *mxmlGetOpaque(mxml_node_t *node);
mxmlGetParent           PROTO C :DWORD                                          ; extern mxml_node_t    *mxmlGetParent(mxml_node_t *node);
mxmlGetPrevSibling      PROTO C :DWORD                                          ; extern mxml_node_t    *mxmlGetPrevSibling(mxml_node_t *node);
mxmlGetReal             PROTO C :DWORD                                          ; extern double         mxmlGetReal(mxml_node_t *node);
mxmlGetRefCount         PROTO C :DWORD                                          ; extern int            mxmlGetRefCount(mxml_node_t *node);
mxmlGetText             PROTO C :DWORD, :DWORD                                  ; extern const char     *mxmlGetText(mxml_node_t *node, int *whitespace);
mxmlGetType             PROTO C :DWORD                                          ; extern mxml_type_t    mxmlGetType(mxml_node_t *node);
mxmlGetUserData         PROTO C :DWORD                                          ; extern void           *mxmlGetUserData(mxml_node_t *node);
mxmlIndexDelete         PROTO C :DWORD                                          ; extern void           mxmlIndexDelete(mxml_index_t *ind);
mxmlIndexEnum           PROTO C :DWORD                                          ; extern mxml_node_t    *mxmlIndexEnum(mxml_index_t *ind);
mxmlIndexFind           PROTO C :DWORD, :DWORD, :DWORD                          ; extern mxml_node_t    *mxmlIndexFind(mxml_index_t *ind, const char *element, const char *value);
mxmlIndexGetCount       PROTO C :DWORD                                          ; extern int            mxmlIndexGetCount(mxml_index_t *ind);
mxmlIndexNew            PROTO C :DWORD, :DWORD, :DWORD                          ; extern mxml_index_t   *mxmlIndexNew(mxml_node_t *node, const char *element, const char *attr);
mxmlIndexReset          PROTO C :DWORD                                          ; extern mxml_node_t    *mxmlIndexReset(mxml_index_t *ind);
mxmlLoadFd              PROTO C :DWORD, :DWORD, :DWORD                          ; extern mxml_node_t    *mxmlLoadFd(mxml_node_t *top, int fd, mxml_type_t (*cb)(mxml_node_t *));
mxmlLoadFile            PROTO C :DWORD, :DWORD, :DWORD                          ; extern mxml_node_t    *mxmlLoadFile(mxml_node_t *top, FILE *fp, mxml_type_t (*cb)(mxml_node_t *));
mxmlLoadString          PROTO C :DWORD, :DWORD, :DWORD                          ; extern mxml_node_t    *mxmlLoadString(mxml_node_t *top, const char *s, mxml_type_t (*cb)(mxml_node_t *));
mxmlNewCDATA            PROTO C :DWORD, :DWORD                                  ; extern mxml_node_t    *mxmlNewCDATA(mxml_node_t *parent, const char *string);
mxmlNewCustom           PROTO C :DWORD, :DWORD, :DWORD                          ; extern mxml_node_t    *mxmlNewCustom(mxml_node_t *parent, void *data, mxml_custom_destroy_cb_t destroy);
mxmlNewElement          PROTO C :DWORD, :DWORD                                  ; extern mxml_node_t    *mxmlNewElement(mxml_node_t *parent, const char *name);
mxmlNewInteger          PROTO C :DWORD, :DWORD                                  ; extern mxml_node_t    *mxmlNewInteger(mxml_node_t *parent, int integer);
mxmlNewOpaque           PROTO C :DWORD, :DWORD                                  ; extern mxml_node_t    *mxmlNewOpaque(mxml_node_t *parent, const char *opaque);
mxmlNewReal             PROTO C :DWORD, :DWORD                                  ; extern mxml_node_t    *mxmlNewReal(mxml_node_t *parent, double real);
mxmlNewText             PROTO C :DWORD, :DWORD, :DWORD                          ; extern mxml_node_t    *mxmlNewText(mxml_node_t *parent, int whitespace, const char *string);
;mxmlNewTextf           PROTO C :DWORD, :DWORD, :DWORD                          ; extern mxml_node_t    *mxmlNewTextf(mxml_node_t *parent, int whitespace, const char *format, ...)


mxmlNewXML              PROTO C :DWORD                                          ; extern mxml_node_t    *mxmlNewXML(const char *version);
mxmlRelease             PROTO C :DWORD                                          ; extern int            mxmlRelease(mxml_node_t *node);
mxmlRemove              PROTO C :DWORD                                          ; extern void           mxmlRemove(mxml_node_t *node);
mxmlRetain              PROTO C :DWORD                                          ; extern int            mxmlRetain(mxml_node_t *node);
mxmlSaveAllocString     PROTO C :DWORD, :DWORD                                  ; extern char           *mxmlSaveAllocString(mxml_node_t *node, mxml_save_cb_t cb);
mxmlSaveFd              PROTO C :DWORD, :DWORD, :DWORD                          ; extern int            mxmlSaveFd(mxml_node_t *node, int fd, mxml_save_cb_t cb);
mxmlSaveFile            PROTO C :DWORD, :DWORD, :DWORD                          ; extern int            mxmlSaveFile(mxml_node_t *node, FILE *fp, mxml_save_cb_t cb);
mxmlSaveString          PROTO C :DWORD, :DWORD, :DWORD, :DWORD                  ; extern int            mxmlSaveString(mxml_node_t *node, char *buffer, int bufsize, mxml_save_cb_t cb);
mxmlSAXLoadFd           PROTO C :DWORD, :DWORD, :DWORD, :DWORD, :DWORD          ; extern mxml_node_t    *mxmlSAXLoadFd(mxml_node_t *top, int fd, mxml_type_t (*cb)(mxml_node_t *), mxml_sax_cb_t sax, void *sax_data);
mxmlSAXLoadFile         PROTO C :DWORD, :DWORD, :DWORD, :DWORD, :DWORD          ; extern mxml_node_t    *mxmlSAXLoadFile(mxml_node_t *top, FILE *fp, mxml_type_t (*cb)(mxml_node_t *), mxml_sax_cb_t sax, void *sax_data);
mxmlSAXLoadString       PROTO C :DWORD, :DWORD, :DWORD, :DWORD, :DWORD          ; extern mxml_node_t    *mxmlSAXLoadString(mxml_node_t *top, const char *s,  mxml_type_t (*cb)(mxml_node_t *), mxml_sax_cb_t sax, void *sax_data);
mxmlSetCDATA            PROTO C :DWORD, :DWORD                                  ; extern int            mxmlSetCDATA(mxml_node_t *node, const char *data);
mxmlSetCustom           PROTO C :DWORD, :DWORD, :DWORD                          ; extern int            mxmlSetCustom(mxml_node_t *node, void *data, mxml_custom_destroy_cb_t destroy);
mxmlSetCustomHandlers   PROTO C :DWORD, :DWORD                                  ; extern void           mxmlSetCustomHandlers(mxml_custom_load_cb_t load, mxml_custom_save_cb_t save);
mxmlSetElement          PROTO C :DWORD, :DWORD                                  ; extern int            mxmlSetElement(mxml_node_t *node, const char *name);
mxmlSetErrorCallback    PROTO C :DWORD                                          ; extern void           mxmlSetErrorCallback(mxml_error_cb_t cb);
mxmlSetInteger          PROTO C :DWORD, :DWORD                                  ; extern int            mxmlSetInteger(mxml_node_t *node, int integer);
mxmlSetOpaque           PROTO C :DWORD, :DWORD                                  ; extern int            mxmlSetOpaque(mxml_node_t *node, const char *opaque);
mxmlSetReal             PROTO C :DWORD, :DWORD                                  ; extern int            mxmlSetReal(mxml_node_t *node, double real);
mxmlSetText             PROTO C :DWORD, :DWORD, :DWORD                          ; extern int            mxmlSetText(mxml_node_t *node, int whitespace, const char *string);
;mxmlSetTextf           PROTO C :DWORD, :DWORD, :DWORD                          ; extern int            mxmlSetTextf(mxml_node_t *node, int whitespace, const char *format, ...)


mxmlSetUserData         PROTO C :DWORD, :DWORD                                  ; extern int            mxmlSetUserData(mxml_node_t *node, void *data);
mxmlSetWrapMargin       PROTO C :DWORD                                          ; extern void           mxmlSetWrapMargin(int column);
mxmlWalkNext            PROTO C :DWORD, :DWORD, :DWORD                          ; extern mxml_node_t    *mxmlWalkNext(mxml_node_t *node, mxml_node_t *top, int descend);
mxmlWalkPrev            PROTO C :DWORD, :DWORD, :DWORD                          ; extern mxml_node_t    *mxmlWalkPrev(mxml_node_t *node, mxml_node_t *top, int descend);


;
; Semi-private functions...
;

;mxml_error extern void     mxml_error(const char *format, ...);
mxml_ignore_cb          PROTO C :DWORD                                          ; extern mxml_type_t    mxml_ignore_cb(mxml_node_t *node);
mxml_integer_cb         PROTO C :DWORD                                          ; extern mxml_type_t    mxml_integer_cb(mxml_node_t *node);
mxml_opaque_cb          PROTO C :DWORD                                          ; extern mxml_type_t    mxml_opaque_cb(mxml_node_t *node);
mxml_real_cb            PROTO C :DWORD                                          ; extern mxml_type_t    mxml_real_cb(mxml_node_t *node);
;
