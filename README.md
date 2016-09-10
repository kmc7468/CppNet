# CSClasses
.Net framework Classes for C++14

## 설명
.Net framework에 있는 기능들을 C++14에 있는 기능들을 이용해 구현했습니다. 최대한 비슷하게 구현하게 노력하고 있으나 일부 기능이 누락되거나 .Net framework 와 100% 똑같게 작동하지 않을 수 있습니다.<br>
타겟 버전: .Net framework 4.6

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

## 파일 목록
모두 작업 되었거나 사용에 지장이 없을 수준으로 개발 되었을 경우 체크, 개발 중이라서 문법이 바뀌거나 기능이 바뀌거나 할 수 있거나 사용이 불가능 할 수준으로 많이 개발되지 않았을 경우 체크 해제입니다.
### 헤더 파일
- 종합 헤더 파일
  - CSClasses.h

- 네임스페이스 종합 헤더 파일
  - System.h
  - System.Drawing.h
  - System.Collections.h
  - System.Collections.Generic.h
  - System.Windows.Forms.h

- 특수 용도 헤더 파일
  - Language.h
  - Utility.h
  
- System 네임스페이스
  - [x] Object.h
  - [x] Console.h
  - [ ] Convert.h
  - [ ] DateTime.h
  - [ ] TimeSpan.h
  - [x] Exception.h
    - [x] InvalidCastException.h
    - [x] FormatException.h
    - [x] NotImplementedException.h
  
  - [x] Math.h
  - [x] Random.h
  - [x] ICloneable.h
  - [x] IConvertible.h
  - [ ] IFormatProvider.h
  
- System.Drawing 네임스페이스
  - [ ] Point.h
  - [ ] PointF.h

- System.Collections 네임스페이스
  - [x] _ICollection.h
  - [x] _IEnumerable.h

- System.Collections.Generic 네임스페이스
  - [x] ICollection.h
  - [x] IEnumerable.h
  - [x] IList.h

- System.Windows.Forms 네임스페이스
  - [ ] Control.h

### 소스 파일
- 특수 용도 헤더파일
  - [ ] Utility.h

- System 네임스페이스
  - [x] Object.cpp
  - [x] Console.cpp
  - [ ] Convert.cpp
  - [ ] DateTime.cpp
  - [ ] TimeSpan.cpp
  - [x] Exception.cpp
    - [x] FormatException.cpp
    - [x] InvalidCastException.cpp
    - [x] NotImplementedException.cpp
  
  - [x] Random.cpp
  - [x] Math.cpp

- System.Drawing 네임스페이스
  - [ ] Point.cpp
  - [ ] PointF.cpp

## 특징
- 닷넷 프레임워크와 맞물려 작동하지 않고 100% Native 코드로 이루어져 있음으로 닷넷 프레임워크의 기능과 유사하게 사용하고 싶을 때 사용 가능합니다.
- 각 컴파일러의 비표준 확장을 사용하지 않고 100% 표준 코드만 사용하였기 때문에 크로스 플랫폼이 가능합니다.
- 라이브러리를 사용하지 않고 100% 저희가 직접 타이핑한 코드만 사용하기 때문에 추가 라이브러리 설치가 필요하지 않습니다.
- 현재까지의 최신 표준인 C++14를 사용하였고 C++14 문법을 적극 사용하였습니다.
- 닷넷 프레임워크에서 제공하는 클래스뿐만이 아니라 직접 고안한 기능도 추가하여 더욱 강력하게 사용할 수 있습니다.

## 지원 언어
- 한국어 ```#define LANG_KOR```
- English (영어) ```#define LANG_ENG```
- Esperanto (에스페란토어) ``` #define LANG_ESP```

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

## 저작권자
코드 저작권자: 작성자<br>
.Net framework에 있는 기능 저작권자: Microsoft<br>
직접 고안한 기능 저작권자: 고안한 기능 계획자 및 구현자

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
