#ifndef LANGUAGE_H
#define LANGUAGE_H

#if defined(LANG_KOR)
#define TXT_INVALID_CAST_DEFMSG L"잘못된 변환 오류가 발생하였습니다."
#define TXT_INVAILD_CAST_CHAR2BOOL L"Char를 Boolean으로 변환할 수 없습니다."
#define TXT_INVALID_CAST_DATETIME2BOOL L"DateTime을 Boolean으로 변환할 수 없습니다."
#define TXT_INVALID_CAST_DATETIME2BYTE L"DateTime을 Byte로 변환할 수 없습니다."

#define TXT_FORMAT_DEFMSG L"포맷 또는 구성이 잘못되어 오류가 발생하였습니다."
#define TXT_FORMAT_STRING2BOOL_NOTSTR L"잘못된 문자열입니다."

#define TXT_NOTIMPL_DEFMSG L"요청한 메서드 또는 연산이 구현되지 않았습니다."

#define TXT_EXCEPTION_DEFMSG L"오류가 발생하였습니다."


#elif defined(LANG_ESP)
#define TXT_INVALID_CAST_DEFMSG L"Nevalida rolantaro escepto."
#define TXT_INVAILD_CAST_CHAR2BOOL L"Vi ne povas konverti Char al Boolean."
#define TXT_INVALID_CAST_DATETIME2BOOL L"Vi ne povas konverti DateTime al Boolean."
#define TXT_INVALID_CAST_DATETIME2BYTE L"Vi ne povas konverti DateTime al Byte."

#define TXT_FORMAT_DEFMSG L"Nevalida formato escepto."
#define TXT_FORMAT_STRING2BOOL_NOTSTR L"Nevalida kordoj."

#define TXT_NOTIMPL_DEFMSG L"Petitaj metodo a? operacio ne efektivigis."

#define TXT_EXCEPTION_DEFMSG L"Eraro okazis."

#else
#define TXT_INVALID_CAST_DEFMSG L"Invalid cast exception."
#define TXT_INVAILD_CAST_CHAR2BOOL L"Can't cast a from Char to Boolean."
#define TXT_INVALID_CAST_DATETIME2BOOL L"Can't cast a from DateTime to Boolean."
#define TXT_INVALID_CAST_DATETIME2BYTE L"Can't cast a from DateTime to Byte."

#define TXT_FORMAT_DEFMSG L"Invalid format exception."
#define TXT_FORMAT_STRING2BOOL_NOTSTR L"Invalid string."

#define TXT_NOTIMPL_DEFMSG L"Requested method or operation is not implemented."

#define TXT_EXCEPTION_DEFMSG L"An error has occurred."


#endif

#endif