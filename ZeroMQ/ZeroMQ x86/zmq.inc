;
;    Copyright (c) 2007-2016 Contributors as noted in the AUTHORS file
;
;    This file is part of libzmq, the ZeroMQ core engine in C++.
;
;    libzmq is free software; you can redistribute it and/or modify it under
;    the terms of the GNU Lesser General Public License (LGPL) as published
;    by the Free Software Foundation; either version 3 of the License, or
;    (at your option) any later version.
;
;    As a special exception, the Contributors give you permission to link
;    this library with independent modules to produce an executable,
;    regardless of the license terms of these independent modules, and to
;    copy and distribute the resulting executable under terms of your choice,
;    provided that you also meet, for each linked independent module, the
;    terms and conditions of the license of that module. An independent
;    module is a module which is not derived from or based on this library.
;    If you modify this library, you must extend this exception to your
;    version of the library.
;
;    libzmq is distributed in the hope that it will be useful, but WITHOUT
;    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
;    FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public
;    License for more details.
;
;    You should have received a copy of the GNU Lesser General Public License
;    along with this program.  If not, see <http://www.gnu.org/licenses/>.
;
;    *************************************************************************
;    NOTE to contributors. This file comprises the principal public contract
;    for ZeroMQ API users. Any change to this file supplied in a stable
;    release SHOULD not break existing applications.
;    In practice this means that the value of constants must not change, and
;    that old values may not be reused for new constants.
;    *************************************************************************
;

; Version macros for compile-time API version detection

ZMQ_VERSION_MAJOR EQU 4
ZMQ_VERSION_MINOR EQU 3
ZMQ_VERSION_PATCH EQU 0
ZMQ_MAKE_VERSION MACRO major,minor,patch
EXITM <( ( major ) * 10000 + ( minor ) * 100 + ( patch ) ) >
ENDM
ZMQ_VERSION EQU <ZMQ_MAKE_VERSION ( ZMQ_VERSION_MAJOR , ZMQ_VERSION_MINOR , ZMQ_VERSION_PATCH )>


include winsock2.inc

ZMQ_DEFINED_STDINT EQU 1
  
;******************************************************************************
; 0MQ errors.                                                               
;******************************************************************************

; A number random enough not to collide with different errno ranges on
; different OSes. The assumption is that error_t is at least 32-bit type.  
  
ZMQ_HAUSNUMERO EQU 156384712
  
; On Windows platform some of the standard POSIX errnos are not defined.
IFNDEF ENOTSUP
    ENOTSUP             EQU ( ZMQ_HAUSNUMERO + 1 )
ENDIF
IFNDEF EPROTONOSUPPORT
    EPROTONOSUPPORT     EQU ( ZMQ_HAUSNUMERO + 2 )
ENDIF
IFNDEF ENOBUFS
    ENOBUFS             EQU ( ZMQ_HAUSNUMERO + 3 )
ENDIF
IFNDEF ENETDOWN
    ENETDOWN            EQU ( ZMQ_HAUSNUMERO + 4 )
ENDIF
IFNDEF EADDRINUSE
    EADDRINUSE          EQU ( ZMQ_HAUSNUMERO + 5 )
ENDIF
IFNDEF EADDRNOTAVAIL
    EADDRNOTAVAIL       EQU ( ZMQ_HAUSNUMERO + 6 )
ENDIF
IFNDEF ECONNREFUSED
    ECONNREFUSED        EQU ( ZMQ_HAUSNUMERO + 7 )
ENDIF
IFNDEF EINPROGRESS
    EINPROGRESS         EQU ( ZMQ_HAUSNUMERO + 8 )
ENDIF
IFNDEF ENOTSOCK
    ENOTSOCK            EQU ( ZMQ_HAUSNUMERO + 9 )
ENDIF
IFNDEF EMSGSIZE
    EMSGSIZE            EQU ( ZMQ_HAUSNUMERO + 10 )
ENDIF
IFNDEF EAFNOSUPPORT
    EAFNOSUPPORT        EQU ( ZMQ_HAUSNUMERO + 11 )
ENDIF
IFNDEF ENETUNREACH
    ENETUNREACH         EQU ( ZMQ_HAUSNUMERO + 12 )
ENDIF
IFNDEF ECONNABORTED
    ECONNABORTED        EQU ( ZMQ_HAUSNUMERO + 13 )
ENDIF
IFNDEF ECONNRESET
    ECONNRESET          EQU ( ZMQ_HAUSNUMERO + 14 )
ENDIF
IFNDEF ENOTCONN
    ENOTCONN            EQU ( ZMQ_HAUSNUMERO + 15 )
ENDIF
IFNDEF ETIMEDOUT
    ETIMEDOUT           EQU ( ZMQ_HAUSNUMERO + 16 )
ENDIF
IFNDEF EHOSTUNREACH
    EHOSTUNREACH        EQU ( ZMQ_HAUSNUMERO + 17 )
ENDIF
IFNDEF ENETRESET
    ENETRESET           EQU ( ZMQ_HAUSNUMERO + 18 )
ENDIF

; Native 0MQ error codes.
EFSM                    EQU ( ZMQ_HAUSNUMERO + 51 )
ENOCOMPATPROTO          EQU ( ZMQ_HAUSNUMERO + 52 )
ETERM                   EQU ( ZMQ_HAUSNUMERO + 53 )
EMTHREAD                EQU ( ZMQ_HAUSNUMERO + 54 )


;******************************************************************************
; 0MQ infrastructure (a.k.a. context) initialisation & termination.         
;******************************************************************************

; Context options   
ZMQ_IO_THREADS          EQU 1
ZMQ_MAX_SOCKETS         EQU 2
ZMQ_SOCKET_LIMIT        EQU 3
ZMQ_THREAD_PRIORITY     EQU 3
ZMQ_THREAD_SCHED_POLICY EQU 4
ZMQ_MAX_MSGSZ           EQU 5
ZMQ_MSG_T_SIZE          EQU 6

; Default for new contexts 
ZMQ_IO_THREADS_DFLT     EQU 1
ZMQ_MAX_SOCKETS_DFLT    EQU 1023
ZMQ_THREAD_PRIORITY_DFLT EQU - 1
ZMQ_THREAD_SCHED_POLICY_DFLT EQU - 1

; 0MQ message definition.
ZMQ_MSG                 STRUCT
    _                   BYTE 64 dup (?)
ZMQ_MSG                 ENDS

;******************************************************************************
; 0MQ socket definition.                                                    
;******************************************************************************
; Socket types

ZMQ_PAIR                EQU 0
ZMQ_PUB                 EQU 1
ZMQ_SUB                 EQU 2
ZMQ_REQ                 EQU 3
ZMQ_REP                 EQU 4
ZMQ_DEALER              EQU 5
ZMQ_ROUTER              EQU 6
ZMQ_PULL                EQU 7
ZMQ_PUSH                EQU 8
ZMQ_XPUB                EQU 9
ZMQ_XSUB                EQU 10
ZMQ_STREAM              EQU 11
  
; Deprecated aliases  
ZMQ_XREQ                EQU <ZMQ_DEALER>
ZMQ_XREP                EQU <ZMQ_ROUTER>

; Socket options  
ZMQ_AFFINITY            EQU 4
ZMQ_ROUTING_ID          EQU 5
ZMQ_SUBSCRIBE           EQU 6
ZMQ_UNSUBSCRIBE         EQU 7
ZMQ_RATE                EQU 8
ZMQ_RECOVERY_IVL        EQU 9
ZMQ_SNDBUF              EQU 11
ZMQ_RCVBUF              EQU 12
ZMQ_RCVMORE             EQU 13
ZMQ_FD                  EQU 14
ZMQ_EVENTS              EQU 15
ZMQ_TYPE                EQU 16
ZMQ_LINGER              EQU 17
ZMQ_RECONNECT_IVL       EQU 18
ZMQ_BACKLOG             EQU 19
ZMQ_RECONNECT_IVL_MAX   EQU 21
ZMQ_MAXMSGSIZE          EQU 22
ZMQ_SNDHWM              EQU 23
ZMQ_RCVHWM              EQU 24
ZMQ_MULTICAST_HOPS      EQU 25
ZMQ_RCVTIMEO            EQU 27
ZMQ_SNDTIMEO            EQU 28
ZMQ_LAST_ENDPOINT       EQU 32
ZMQ_ROUTER_MANDATORY    EQU 33
ZMQ_TCP_KEEPALIVE       EQU 34
ZMQ_TCP_KEEPALIVE_CNT   EQU 35
ZMQ_TCP_KEEPALIVE_IDLE  EQU 36
ZMQ_TCP_KEEPALIVE_INTVL EQU 37
ZMQ_IMMEDIATE           EQU 39
ZMQ_XPUB_VERBOSE        EQU 40
ZMQ_ROUTER_RAW          EQU 41
ZMQ_IPV6                EQU 42
ZMQ_MECHANISM           EQU 43
ZMQ_PLAIN_SERVER        EQU 44
ZMQ_PLAIN_USERNAME      EQU 45
ZMQ_PLAIN_PASSWORD      EQU 46
ZMQ_CURVE_SERVER        EQU 47
ZMQ_CURVE_PUBLICKEY     EQU 48
ZMQ_CURVE_SECRETKEY     EQU 49
ZMQ_CURVE_SERVERKEY     EQU 50
ZMQ_PROBE_ROUTER        EQU 51
ZMQ_REQ_CORRELATE       EQU 52
ZMQ_REQ_RELAXED         EQU 53
ZMQ_CONFLATE            EQU 54
ZMQ_ZAP_DOMAIN          EQU 55
ZMQ_ROUTER_HANDOVER     EQU 56
ZMQ_TOS                 EQU 57
ZMQ_CONNECT_ROUTING_ID  EQU 61
ZMQ_GSSAPI_SERVER       EQU 62
ZMQ_GSSAPI_PRINCIPAL    EQU 63
ZMQ_GSSAPI_SERVICE_PRINCIPAL EQU 64
ZMQ_GSSAPI_PLAINTEXT    EQU 65
ZMQ_HANDSHAKE_IVL       EQU 66
ZMQ_SOCKS_PROXY         EQU 68
ZMQ_XPUB_NODROP         EQU 69
ZMQ_BLOCKY              EQU 70
ZMQ_XPUB_MANUAL         EQU 71
ZMQ_XPUB_WELCOME_MSG    EQU 72
ZMQ_STREAM_NOTIFY       EQU 73
ZMQ_INVERT_MATCHING     EQU 74
ZMQ_HEARTBEAT_IVL       EQU 75
ZMQ_HEARTBEAT_TTL       EQU 76
ZMQ_HEARTBEAT_TIMEOUT   EQU 77
ZMQ_XPUB_VERBOSER       EQU 78
ZMQ_CONNECT_TIMEOUT     EQU 79
ZMQ_TCP_MAXRT           EQU 80
ZMQ_THREAD_SAFE         EQU 81
ZMQ_MULTICAST_MAXTPDU   EQU 84
ZMQ_VMCI_BUFFER_SIZE    EQU 85
ZMQ_VMCI_BUFFER_MIN_SIZE EQU 86
ZMQ_VMCI_BUFFER_MAX_SIZE EQU 87
ZMQ_VMCI_CONNECT_TIMEOUT EQU 88
ZMQ_USE_FD              EQU 89
ZMQ_GSSAPI_PRINCIPAL_NAMETYPE EQU 90
ZMQ_GSSAPI_SERVICE_PRINCIPAL_NAMETYPE EQU 91
ZMQ_BINDTODEVICE        EQU 92

; Message options  
ZMQ_MORE                EQU 1
ZMQ_SHARED              EQU 3
  
; Send/recv options
ZMQ_DONTWAIT            EQU 1
ZMQ_SNDMORE             EQU 2

; Security mechanisms
ZMQ_NULL                EQU 0
ZMQ_PLAIN               EQU 1
ZMQ_CURVE               EQU 2
ZMQ_GSSAPI              EQU 3

; RADIO-DISH protocol
ZMQ_GROUP_MAX_LENGTH    EQU 15

; Deprecated options and aliases
ZMQ_IDENTITY            EQU <ZMQ_ROUTING_ID>
ZMQ_CONNECT_RID         EQU <ZMQ_CONNECT_ROUTING_ID>
ZMQ_TCP_ACCEPT_FILTER   EQU 38
ZMQ_IPC_FILTER_PID      EQU 58
ZMQ_IPC_FILTER_UID      EQU 59
ZMQ_IPC_FILTER_GID      EQU 60
ZMQ_IPV4ONLY            EQU 31
ZMQ_DELAY_ATTACH_ON_CONNECT EQU <ZMQ_IMMEDIATE>
ZMQ_NOBLOCK             EQU <ZMQ_DONTWAIT>
ZMQ_FAIL_UNROUTABLE     EQU <ZMQ_ROUTER_MANDATORY>
ZMQ_ROUTER_BEHAVIOR     EQU <ZMQ_ROUTER_MANDATORY>

; Deprecated Message options
ZMQ_SRCFD               EQU 2

;******************************************************************************
; GSSAPI definitions                                                        
;******************************************************************************

; GSSAPI principal name types
ZMQ_GSSAPI_NT_HOSTBASED EQU 0
ZMQ_GSSAPI_NT_USER_NAME EQU 1
ZMQ_GSSAPI_NT_KRB5_PRINCIPAL EQU 2
ZMQ_EVENT_CONNECTED     EQU 0001h
ZMQ_EVENT_CONNECT_DELAYED EQU 0002h
ZMQ_EVENT_CONNECT_RETRIED EQU 0004h
ZMQ_EVENT_LISTENING     EQU 0008h
ZMQ_EVENT_BIND_FAILED   EQU 0010h
ZMQ_EVENT_ACCEPTED      EQU 0020h
ZMQ_EVENT_ACCEPT_FAILED EQU 0040h
ZMQ_EVENT_CLOSED        EQU 0080h
ZMQ_EVENT_CLOSE_FAILED  EQU 0100h
ZMQ_EVENT_DISCONNECTED  EQU 0200h
ZMQ_EVENT_MONITOR_STOPPED EQU 0400h
ZMQ_EVENT_ALL           EQU 0FFFFh


;******************************************************************************
; Deprecated I/O multiplexing. Prefer using zmq_poller API                  
;******************************************************************************
ZMQ_POLLIN              EQU 1
ZMQ_POLLOUT             EQU 2
ZMQ_POLLERR             EQU 4
ZMQ_POLLPRI             EQU 8

ZMQ_POLLITEM            STRUCT
    socket              POINTER ?
    fd                  SOCKET ?
    events              SWORD ?
    revents             SWORD ?
ZMQ_POLLITEM            ENDS

ZMQ_POLLITEMS_DFLT      EQU 16
ZMQ_HAS_CAPABILITIES    EQU 1

; Deprecated aliases  
ZMQ_STREAMER            EQU 1
ZMQ_FORWARDER           EQU 2
ZMQ_QUEUE               EQU 3
  

;******************************************************************************
; These functions are DRAFT and disabled in stable releases, and subject to 
; change at ANY time until declared stable.                                
;******************************************************************************

; DRAFT Socket types.
ZMQ_SERVER              EQU 12
ZMQ_CLIENT              EQU 13
ZMQ_RADIO               EQU 14
ZMQ_DISH                EQU 15
ZMQ_GATHER              EQU 16
ZMQ_SCATTER             EQU 17
ZMQ_DGRAM               EQU 18

; DRAFT Socket options.
ZMQ_ZAP_ENFORCE_DOMAIN  EQU 93
ZMQ_LOOPBACK_FASTPATH   EQU 94
ZMQ_METADATA            EQU 95
ZMQ_MULTICAST_LOOP      EQU 96
ZMQ_ROUTER_NOTIFY       EQU 97

; DRAFT 0MQ socket events and monitoring 
ZMQ_EVENT_HANDSHAKE_FAILED_NO_DETAIL EQU 0800h
ZMQ_EVENT_HANDSHAKE_SUCCEEDED EQU 1000h
ZMQ_EVENT_HANDSHAKE_FAILED_PROTOCOL EQU 2000h
ZMQ_EVENT_HANDSHAKE_FAILED_AUTH EQU 4000h
ZMQ_PROTOCOL_ERROR_ZMTP_UNSPECIFIED EQU 10000000h
ZMQ_PROTOCOL_ERROR_ZMTP_UNEXPECTED_COMMAND EQU 10000001h
ZMQ_PROTOCOL_ERROR_ZMTP_INVALID_SEQUENCE EQU 10000002h
ZMQ_PROTOCOL_ERROR_ZMTP_KEY_EXCHANGE EQU 10000003h
ZMQ_PROTOCOL_ERROR_ZMTP_MALFORMED_COMMAND_UNSPECIFIED EQU 10000011h
ZMQ_PROTOCOL_ERROR_ZMTP_MALFORMED_COMMAND_MESSAGE EQU 10000012h
ZMQ_PROTOCOL_ERROR_ZMTP_MALFORMED_COMMAND_HELLO EQU 10000013h
ZMQ_PROTOCOL_ERROR_ZMTP_MALFORMED_COMMAND_INITIATE EQU 10000014h
ZMQ_PROTOCOL_ERROR_ZMTP_MALFORMED_COMMAND_ERROR EQU 10000015h
ZMQ_PROTOCOL_ERROR_ZMTP_MALFORMED_COMMAND_READY EQU 10000016h
ZMQ_PROTOCOL_ERROR_ZMTP_MALFORMED_COMMAND_WELCOME EQU 10000017h
ZMQ_PROTOCOL_ERROR_ZMTP_INVALID_METADATA EQU 10000018h
ZMQ_PROTOCOL_ERROR_ZMTP_CRYPTOGRAPHIC EQU 11000001h
ZMQ_PROTOCOL_ERROR_ZMTP_MECHANISM_MISMATCH EQU 11000002h
ZMQ_PROTOCOL_ERROR_ZAP_UNSPECIFIED EQU 20000000h
ZMQ_PROTOCOL_ERROR_ZAP_MALFORMED_REPLY EQU 20000001h
ZMQ_PROTOCOL_ERROR_ZAP_BAD_REQUEST_ID EQU 20000002h
ZMQ_PROTOCOL_ERROR_ZAP_BAD_VERSION EQU 20000003h
ZMQ_PROTOCOL_ERROR_ZAP_INVALID_STATUS_CODE EQU 20000004h
ZMQ_PROTOCOL_ERROR_ZAP_INVALID_METADATA EQU 20000005h
ZMQ_THREAD_AFFINITY_CPU_ADD EQU 7
ZMQ_THREAD_AFFINITY_CPU_REMOVE EQU 8
ZMQ_THREAD_NAME_PREFIX  EQU 9
ZMQ_ZERO_COPY_RECV      EQU 10

; DRAFT Msg property names.
ZMQ_MSG_PROPERTY_ROUTING_ID     db "Routing-Id",0
ZMQ_MSG_PROPERTY_SOCKET_TYPE    db "Socket-Type",0
ZMQ_MSG_PROPERTY_USER_ID EQU    db "User-Id",0
ZMQ_MSG_PROPERTY_PEER_ADDRESS   db "Peer-Address",0

; Router notify options     
ZMQ_NOTIFY_CONNECT      EQU 1
ZMQ_NOTIFY_DISCONNECT   EQU 2

;******************************************************************************
; Poller polling on sockets,fd and thread-safe sockets                     
;******************************************************************************
ZMQ_POLLER_EVENT        STRUCT
    socket              POINTER ?
    fd                  SOCKET ?
    user_data           POINTER ?
    events              SWORD ?
ZMQ_POLLER_EVENT        ENDS
