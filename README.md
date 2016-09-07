# CSClasses
C# Classes for C++14

## 설명
.Net framework에 있는 기능들을 C++14에 있는 기능들을 이용해 구현했습니다.

## VC++에서의 적용 방법
(1) include 폴더에 추가
- 첫번째. Visual Studio가 설치된 경로로 이동합니다.
- 두번째. /VC/include/ 폴더로 들어갑니다.
- 세번째. 헤더파일들을 붙여넣습니다.

(2) 프로젝트에 추가
- 첫번째. 프로젝트를 열거나 생성합니다.
- 두번째. 추가를 하고자 하는 필터를 우클릭합니다.
- 세번째. 기존 파일 추가를 누르고 헤더파일들을 선택하고 확인을 누릅니다.

## 사용 방법 (VC++, GCC등 공통)
- 사용하고자 하는 헤더파일이나 소스파일 상단에 사용하고자 하는 네임스페이스를 include합니다.<br>```#include <System.h>```이런식으로요.

## 제공하는 기능들
- System 네임스페이스
  - [ ]Console 클래스
  - [ ]Math 클래스
  - [ ]String 클래스
  - [ ]Char 클래스

## 라이센스
```
MIT License

Copyright (c) 2016 kmc7468

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
```
