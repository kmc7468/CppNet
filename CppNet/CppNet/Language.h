#ifndef LANGUAGE_H
#define LANGUAGE_H

#include "Defines.h"

#ifdef LANG_KOR
#define TXT_INVALID_ARGUMENT_DEFMSG "인자가 유효하지 않습니다."

#define TXT_INVALID_CAST_DEFMSG "잘못된 변환 오류가 발생하였습니다."
#define TXT_INVAILD_CAST_CHAR2BOOL "Char를 Boolean으로 변환할 수 없습니다."
#define TXT_INVALID_CAST_DATETIME2BOOL "DateTime을 Boolean으로 변환할 수 없습니다."
#define TXT_INVALID_CAST_DATETIME2BYTE "DateTime을 Byte로 변환할 수 없습니다."

#define TXT_FORMAT_DEFMSG "포맷 또는 구성이 잘못되어 오류가 발생하였습니다."
#define TXT_FORMAT_STRING2BOOL_NOTSTR "잘못된 문자열입니다."
#define TXT_FORMAT_FRACTION_NOSLASH "잘못된 문자열입니다. 분자와 분모를 구분하는 문자인 '/'가 있어야 합니다."

#define TXT_NOTIMPL_DEFMSG "요청한 메서드 또는 연산이 구현되지 않았습니다."

#define TXT_EXCEPTION_DEFMSG "오류가 발생하였습니다."

#define TXT_INVALID_OPER_DEFMSG "메서드 호출이 유효하지 않습니다."
#define TXT_INVALID_OPER_UNSAFE "프로그램 등에 큰 영향을 끼칠 수 있는 코드가 포함되어 있어 명령을 수행할 수 없습니다."

#define TXT_IO_DEFMSG "I/O 오류가 발생하였습니다."


#elif defined(LANG_ESP)
#define TXT_INVALID_ARGUMENT_DEFMSG "Nevalidaj argumentoj."

#define TXT_INVALID_CAST_DEFMSG "Nevalida rolantaro escepto."
#define TXT_INVAILD_CAST_CHAR2BOOL "Vi ne povas konverti Char al Boolean."
#define TXT_INVALID_CAST_DATETIME2BOOL "Vi ne povas konverti DateTime al Boolean."
#define TXT_INVALID_CAST_DATETIME2BYTE "Vi ne povas konverti DateTime al Byte."

#define TXT_FORMAT_DEFMSG "Nevalida formato escepto."
#define TXT_FORMAT_STRING2BOOL_NOTSTR "Nevalida kordoj."
#define TXT_FORMAT_FRACTION_NOSLASH "Nevalida kordoj. Vi devas havi la karakteron '/' apartigi la numeratoro kaj denominatoro."

#define TXT_NOTIMPL_DEFMSG "Petitaj metodo a? operacio ne efektivigis."

#define TXT_EXCEPTION_DEFMSG "Eraro okazis."

#define TXT_INVALID_OPER_DEFMSG "La metodo alvoko estas nevalida."
#define TXT_INVALID_OPER_UNSAFE "Ĝi enhavas la kodon kiu povas havi grandan efikon tiaj programoj ne povas kuri la komando."

#define TXT_IO_DEFMSG "I/O eraro."

#else
#define TXT_INVALID_ARGUMENT_DEFMSG "Invalid argument exception."

#define TXT_INVALID_CAST_DEFMSG "Invalid cast exception."
#define TXT_INVAILD_CAST_CHAR2BOOL "Can't cast a from Char to Boolean."
#define TXT_INVALID_CAST_DATETIME2BOOL "Can't cast a from DateTime to Boolean."
#define TXT_INVALID_CAST_DATETIME2BYTE "Can't cast a from DateTime to Byte."

#define TXT_FORMAT_DEFMSG "Invalid format exception."
#define TXT_FORMAT_STRING2BOOL_NOTSTR "Invalid string."
#define TXT_FORMAT_FRACTION_NOSLASH "Invalid string. You must have the character '/' to separate the numerator and denominator."

#define TXT_NOTIMPL_DEFMSG "Requested method or operation is not implemented."

#define TXT_EXCEPTION_DEFMSG "An error has occurred."

#define TXT_INVALID_OPER_DEFMSG "The method call is invalid."
#define TXT_INVALID_OPER_UNSAFE "It contains the code that can have a big impact such programs can not run the command."

#define TXT_IO_DEFMSG "An I/O error occurred."

#endif

#endif