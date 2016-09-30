# CSClasses
.Net framework Classes for C++14

## 설명
.Net framework에 있는 기능들을 C++14에 있는 기능들을 이용해 구현했습니다. 최대한 비슷하게 구현하게 노력하고 있으나 일부 기능이 누락되거나 .Net framework 와 100% 똑같게 작동하지 않을 수 있습니다.<br>
타겟 버전: .Net framework 4.6

## 레퍼런스 페이지
활용 예제나 자세한 설명 등은 [CSWiki(CSClasses Wiki)](https://github.com/kmc7468/CSClasses/wiki)를 참조하십시오.<br>

## 적용 방법 (Visual Studio)
- CSClasses 프로젝트를 빌드합니다.
- CSClasses의 헤더 파일을 한 폴더에 모아 놓습니다.
- 프로젝트 속성~C/C++~일반에 들어간 뒤 '추가 포함 디렉터리' 설정에 헤더 파일이 저장된 폴더 경로를 추가합니다.
- CSClasses 프로젝트를 빌드해서 만들어진 lib 파일을 어느 폴더로 옮깁니다.
- 프로젝트 속성~링커~일반에 들어간 뒤 '추가 라이브러리 디렉터리' 설정에 lib 파일이 저장된 폴더 경로를 추가합니다.
- 프로젝트 속성~링커~입력에 들어간 뒤 '추가 종속성' 옵션에 (만들어진 lib 파일 이름).lib (예: Classes.lib)를 추가합니다.

## 사용 방법
- ```#include <System.h>``` 이런식으로 CSClasses 의 헤더 파일을 include해서 사용합니다.
- 취향에 따라 ```using namespace```를 사용할 수도 있습니다.

## 특징
- 대부분의 코드가 표준 코드로 작성되어 있어 크로스 플랫폼에 용이합니다. (플랫폼 종속적인 기능은 Define 전처리기와 If 전처리기를 이용해 컴파일시 처리하도록 해 두었습니다.)
- 닷넷 프레임워크에서 제공하는 기능과 매우 유사하게 구현 하였습니다.
- 닷넷 프레임워크에서 제공하는 기능 위에 직접 고안해 낸 기능을 얹은 기능의 경우 닷넷 프레임워크의 기능보다 더욱 강력하게 사용할 수 있습니다.
- 정적 라이브러리 프로젝트이기 때문에 이식이 용이합니다.

## 개발진
총 담당/기획자: static
### 프로그래밍
- static
- 아크릴새우
- kiwiyou
- NeuroWhAI
- BasixKOR

### 도움
- .Net framework 자문: 맛난호빵

## 라이센스
정리: 출처만 남기면 뭔짓을 하던 뭐라 안할게요.
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
