# CppNet
.Net framework Classes for C++

## 설명
.Net framework에 있는 기능들을 C++에 있는 기능들을 이용해 구현했습니다. 최대한 비슷하게 구현하게 노력하고 있으나 일부 기능이 누락되거나 .Net framework 와 100% 똑같게 작동하지 않을 수 있습니다.<br>
타겟 버전: .Net framework 4.6<br>
C++ 표준: C++17 표준

## 레퍼런스 페이지
활용 예제나 자세한 설명 등은 CNWiki(CppNet Wiki)를 참조하십시오.<br>
https://github.com/kmc7468/CppNet/wiki

## 닷넷 코드
https://referencesource.microsoft.com/#System,namespaces<br>
닷넷에 있는 기능의 대부분은 이 사이트를 보고 구현하였습니다.

## 적용 방법 (Visual Studio)
- CppNet 프로젝트를 빌드합니다.
- CppNet의 헤더 파일(.h) 및 인라인 구현 파일(.inl), 그리고 선언 및 구현 파일(.hpp)을 한 폴더에 모아 놓습니다.
- 프로젝트 속성~C/C++~일반에 들어간 뒤 '추가 포함 디렉터리' 설정에 헤더 파일 및 인라인 구현 파일이 저장된 폴더 경로를 추가합니다.
- CppNet 프로젝트를 빌드해서 만들어진 lib 파일을 아무 폴더로 옮깁니다.
- 프로젝트 속성~링커~일반에 들어간 뒤 '추가 라이브러리 디렉터리' 설정에 lib 파일이 저장된 폴더 경로를 추가합니다.
- 프로젝트 속성~링커~입력에 들어간 뒤 '추가 종속성' 옵션에 CppNet.lib를 추가합니다.

## 사용 방법
- `#include <System.h>` 이런식으로 CppNet 의 헤더 파일을 include해서 사용합니다.
- 취향에 따라 `using namespace`를 사용할 수도 있습니다.

## 개발진
총 담당/기획자: static
### 프로그래밍
- static
- 아크릴새우
- kiwiyou
- NeuroWhAI
- ~~BasixKOR~~
- yoonki1207

### 도움
- .Net framework 자문: 맛난호빵

## 라이센스
요약: 출처만 제대로 남겨주시면 뭔짓을 하던 뭐라고 하지 않습니다.
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
