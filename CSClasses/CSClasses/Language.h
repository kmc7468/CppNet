#ifndef LANGUAGE_H
#define LANGUAGE_H

#if defined(LANG_KOR)
#define TXT_INVALID_CAST_DEFMSG "잘못된 변환 오류가 발생하였습니다."
#define TXT_INVAILD_CAST_CHAR2BOOL "Char를 Boolean으로 변환할 수 없습니다."
#define TXT_INVALID_CAST_DATETIME2BOOL "DateTime을 Boolean으로 변환할 수 없습니다."
#define TXT_INVALID_CAST_DATETIME2BYTE "DateTime을 Byte로 변환할 수 없습니다."

#define TXT_FORMAT_DEFMSG "포맷 또는 구성이 잘못되어 오류가 발생하였습니다."
#define TXT_FORMAT_STRING2BOOL_NOTSTR "잘못된 문자열입니다."

#define TXT_NOTIMPL_DEFMSG "요청한 메서드 또는 연산이 구현되지 않았습니다."

#define TXT_EXCEPTION_DEFMSG "오류가 발생하였습니다."

#define TXT_INVALID_OPER_DEFMSG "메서드 호출이 유효하지 않습니다."


#elif defined(LANG_ESP)
#define TXT_INVALID_CAST_DEFMSG "Nevalida rolantaro escepto."
#define TXT_INVAILD_CAST_CHAR2BOOL "Vi ne povas konverti Char al Boolean."
#define TXT_INVALID_CAST_DATETIME2BOOL "Vi ne povas konverti DateTime al Boolean."
#define TXT_INVALID_CAST_DATETIME2BYTE "Vi ne povas konverti DateTime al Byte."

#define TXT_FORMAT_DEFMSG "Nevalida formato escepto."
#define TXT_FORMAT_STRING2BOOL_NOTSTR "Nevalida kordoj."

#define TXT_NOTIMPL_DEFMSG "Petitaj metodo a? operacio ne efektivigis."

#define TXT_EXCEPTION_DEFMSG "Eraro okazis."

#define TXT_INVALID_OPER_DEFMSG "La metodo alvoko estas nevalida."

#else
#define TXT_INVALID_CAST_DEFMSG "Invalid cast exception."
#define TXT_INVAILD_CAST_CHAR2BOOL "Can't cast a from Char to Boolean."
#define TXT_INVALID_CAST_DATETIME2BOOL "Can't cast a from DateTime to Boolean."
#define TXT_INVALID_CAST_DATETIME2BYTE "Can't cast a from DateTime to Byte."

#define TXT_FORMAT_DEFMSG "Invalid format exception."
#define TXT_FORMAT_STRING2BOOL_NOTSTR "Invalid string."

#define TXT_NOTIMPL_DEFMSG "Requested method or operation is not implemented."

#define TXT_EXCEPTION_DEFMSG "An error has occurred."

#define TXT_INVALID_OPER_DEFMSG "The method call is invalid."


#endif

#endif