# CSClasses
C# Classes for C++14

## 설명
.Net framework에 있는 기능들을 C++14에 있는 기능들을 이용해 구현했습니다. 최대한 비슷하게 구현하게 노력하고 있으나 일부 기능이 누락되거나 .Net framework 와 100% 똑같게 작동하지 않을 수 있습니다.<br>
타겟 버전: .Net framework 4.6

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

## 헤더파일 목록
일반 종합 헤더파일: CSClasses.h<br>특수 종합 헤더파일: CSClassesCS.h
### 일반 네임스페이스 헤더파일
- System.h
- System.Collections.Generic.h

### 특수 네임스페이스 헤더파일
- SystemCS.h

### 클래스 헤더파일
- System 네임스페이스
  - [ ] Console.h
  - [x] Math.h
  - [ ] Convert.h
  - [ ] Exception.h
  - [x] Object.h
  - [x] Random.h
  
- System.Collections.Generic 네임스페이스
  - [ ] List.h

## 특징
- 닷넷 프레임워크와 맞물려 작동하지 않고 100% Native 코드로 이루어져 있음으로 닷넷 프레임워크의 기능과 유사하게 사용하고 싶을 때 사용 가능합니다.
- 각 컴파일러의 비표준 확장을 사용하지 않고 100% 표준 코드만 사용하였기 때문에 크로스 플랫폼이 가능합니다.
- 라이브러리를 사용하지 않고 100% 저희가 직접 타이핑한 코드만 사용하기 때문에 추가 라이브러리 설치가 필요하지 않습니다.
- 현재까지의 최신 표준인 C++14를 사용하였고 C++14 문법을 적극 사용하였습니다.
- 클래스별로 헤더파일이 분리되어 있어(일부 클래스는 서로 맞물려 작동합니다.) 필요한 클래스 헤더파일만 가져다가 사용할 수 있습니다.
- 클래스만 제공하는 것이 아니라 C# 문법대로 작성할 수 있도록 특수 네임스페이스 헤더파일 및 특수 종합 헤더파일을 제공합니다.

## 개발진
총 담당/기획자: static
### 프로그래밍
- static
- 아크릴새우(초급개발자)

## 저작권
코드 저작권: static 및 아크릴새우<br>
기능 저작권: Microsoft 및 개발진

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
