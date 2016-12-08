#ifndef DEFINES_H
#define DEFINES_H

/* 이곳에 정의를 하십시오. 사용자가 정의할 수 있는 정의 목록은 위키를 참고하세요.
https://github.com/kmc7468/CppNet/wiki/%EC%A0%84%EC%B2%98%EB%A6%AC%EA%B8%B0 */

#define BIT_64
#define WIN32
#define LANG_KOR










// 조작하지 마십시오.
#ifdef WIN32
#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#undef max
#undef min
#undef LMEM_FIXED
#undef LMEM_MOVEABLE
#undef LANG_NEUTRAL
#endif

#endif