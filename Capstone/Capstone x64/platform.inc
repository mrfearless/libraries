;Include file created by h2incX, Version 00.10.00, (C) 2018 Biterider, 2005-2009 Japheth
;Source file: 'M:\VS Projects\capstone\include\capstone\platform.h', last modified: 9/17/2018 14:1
;Command line used for creation:  platform.h

ifndef CAPSTONE_PLATFORM_H
  CAPSTONE_PLATFORM_H equ <>

      int8_t typedef SBYTE
      int16_t typedef SWORD
      int32_t typedef DWORD
      uint8_t typedef BYTE
      uint16_t typedef WORD
      uint32_t typedef DWORD
      int64_t typedef SDWORD
      uint64_t typedef DWORD

      INT8_MIN equ ( - 127 - 1 )
      INT16_MIN equ ( - 32767 - 1 )
      INT32_MIN equ ( - 2147483647 - 1 )
      INT64_MIN equ ( - 9223372036854775807 - 1 )
      INT8_MAX equ 127
      INT16_MAX equ 32767
      INT32_MAX equ 2147483647
      INT64_MAX equ 9223372036854775807
      UINT8_MAX equ 0ffh
      UINT16_MAX equ 0ffffh
      UINT32_MAX equ 0ffffffffh
      UINT64_MAX equ 0ffffffffffffffffh

endif
