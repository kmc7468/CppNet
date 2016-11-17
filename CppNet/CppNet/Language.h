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
#define TXT_FORMAT_FRACTION_NOSLASH "분자와 분모를 구분하는 문자인 '/'가 있어야 합니다."

#define TXT_NOTIMPL_DEFMSG "요청한 메서드 또는 연산이 구현되지 않았습니다."

#define TXT_EXCEPTION_DEFMSG "오류가 발생하였습니다."

#define TXT_INVALID_OPER_DEFMSG "메서드 호출이 유효하지 않습니다."
#define TXT_INVALID_OPER_UNSAFE "프로그램 등에 큰 영향을 끼칠 수 있는 코드가 포함되어 있어 명령을 수행할 수 없습니다."

#define TXT_IO_DEFMSG "I/O 오류가 발생하였습니다."
#define TXT_IO_FILEALREADY "파일이 이미 존재합니다."
#define TXT_IO_FILE404 "파일을 찾을 수 없습니다."

#define TXT_INDEX_DEFMSG "인덱스 범위를 벗어났습니다."

#define TXT_ARITHMETIC_DEFMSG "산술 오류가 발생하였습니다."

#define TXT_OVERFLOW_DEFMSG "산술 오버플로우가 발생하였습니다."

#define TXT_THREAD_ABORT_DEFMSG "스레드가 중단되었습니다."

#define TXT_NULLREF_DEFMSG "nullptr인 객체를 역참조할 수 없습니다."


#elif defined(LANG_ESP)
#define TXT_INVALID_ARGUMENT_DEFMSG "Nevalidaj argumentoj."

#define TXT_INVALID_CAST_DEFMSG "Nevalida rolantaro escepto."
#define TXT_INVAILD_CAST_CHAR2BOOL "Vi ne povas konverti Char al Boolean."
#define TXT_INVALID_CAST_DATETIME2BOOL "Vi ne povas konverti DateTime al Boolean."
#define TXT_INVALID_CAST_DATETIME2BYTE "Vi ne povas konverti DateTime al Byte."

#define TXT_FORMAT_DEFMSG "Nevalida formato escepto."
#define TXT_FORMAT_STRING2BOOL_NOTSTR "Nevalida kordoj."
#define TXT_FORMAT_FRACTION_NOSLASH "Vi devas havi la karakteron '/' apartigi la numeratoro kaj denominatoro."

#define TXT_NOTIMPL_DEFMSG "Petitaj metodo a? operacio ne efektivigis."

#define TXT_EXCEPTION_DEFMSG "Eraro okazis."

#define TXT_INVALID_OPER_DEFMSG "La metodo alvoko estas nevalida."
#define TXT_INVALID_OPER_UNSAFE "Ĝi enhavas la kodon kiu povas havi grandan efikon tiaj programoj ne povas kuri la komando."

#define TXT_IO_DEFMSG "I/O eraro."
#define TXT_IO_FILEALREADY "Dosiero jam ekzistas."
#define TXT_IO_FILE404 "Dosiero ne trovita."

#define TXT_INDEX_DEFMSG "Indekso ekster atingo."

#define TXT_ARITHMETIC_DEFMSG "Aritmetika eraro okazis."

#define TXT_OVERFLOW_DEFMSG "Aritmetika troplenigxis okazis."

#define TXT_THREAD_ABORT_DEFMSG "Fadeno estis abortita."

#define TXT_NULLREF_DEFMSG "Objekto kiu estas nullptr ne povas referencita."

#elif defined(LANG_CHI)
#define TXT_INVALID_ARGUMENT_DEFMSG "参数异常无效。"

#define TXT_INVALID_CAST_DEFMSG "类型转换异常无效。"
#define TXT_INVAILD_CAST_CHAR2BOOL "无法将Char转换为Boolean。"
#define TXT_INVALID_CAST_DATETIME2BOOL "无法将DateTime转换为Boolean。"
#define TXT_INVALID_CAST_DATETIME2BYTE "无法将DateTime转换为Byte。"

#define TXT_FORMAT_DEFMSG "格式异常无效。"
#define TXT_FORMAT_STRING2BOOL_NOTSTR "字符串无效。"
#define TXT_FORMAT_FRACTION_NOSLASH "您必须使用字符“/”来分隔分子和分母。"

#define TXT_NOTIMPL_DEFMSG "请求的方法或操作未实现。"

#define TXT_EXCEPTION_DEFMSG "发生了错误。"

#define TXT_INVALID_OPER_DEFMSG "方法调用无效。"
#define TXT_INVALID_OPER_UNSAFE "它包含的代码可以有很大的影响，这样的程序不能运行命令。"

#define TXT_IO_DEFMSG "发生I/O错误。"
#define TXT_IO_FILEALREADY "此文件已存在。"
#define TXT_IO_FILE404 "文件未找到。"

#define TXT_INDEX_DEFMSG "索引超出范围。"

#define TXT_ARITHMETIC_DEFMSG "发生算术错误。"

#define TXT_OVERFLOW_DEFMSG "发生算术溢出。"

#define TXT_THREAD_ABORT_DEFMSG "线程正在中止。"

#define TXT_NULLREF_DEFMSG "无法引用为nullptr的对象。"

#elif defined(LANG_JSP)
#define TXT_INVALID_ARGUMENT_DEFMSG "引数の例外が無効です。"

#define TXT_INVALID_CAST_DEFMSG "キャスト例外が無効です。"
#define TXT_INVAILD_CAST_CHAR2BOOL "CharをBooleanにキャストできません。"
#define TXT_INVALID_CAST_DATETIME2BOOL "DateTimeをBooleanにキャストできません。"
#define TXT_INVALID_CAST_DATETIME2BYTE "DateTimeをByteにキャストできません。"

#define TXT_FORMAT_DEFMSG "形式の例外が無効です。"
#define TXT_FORMAT_STRING2BOOL_NOTSTR "無効な文字列です。"
#define TXT_FORMAT_FRACTION_NOSLASH "分子と分母を分離するには、文字 '/'が必要です。"

#define TXT_NOTIMPL_DEFMSG "要求されたメソッドまたは操作は実装されていません。"

#define TXT_EXCEPTION_DEFMSG "エラーが発生しました。"

#define TXT_INVALID_OPER_DEFMSG "メソッド呼び出しが無効です。"
#define TXT_INVALID_OPER_UNSAFE "そのようなプログラムはコマンドを実行することができません大きな影響を与えることができるコードが含まれています。"

#define TXT_IO_DEFMSG "I/Oエラーが発生しました。"
#define TXT_IO_FILEALREADY "このファイルは既に存在します。"
#define TXT_IO_FILE404 "ファイルが見つかりません。"

#define TXT_INDEX_DEFMSG "インデックスが範囲外です。"

#define TXT_ARITHMETIC_DEFMSG "演算エラーが発生しました。"

#define TXT_OVERFLOW_DEFMSG "算術オーバーフローが発生しました。"

#define TXT_THREAD_ABORT_DEFMSG "スレッドが中止されました。"

#define TXT_NULLREF_DEFMSG "nullptrのオブジェクトは参照できません。"


#elif defined(LANG_RUS)
#define TXT_INVALID_ARGUMENT_DEFMSG "Неверный аргумент исключени."

#define TXT_INVALID_CAST_DEFMSG "Invalid литая исключение."
#define TXT_INVAILD_CAST_CHAR2BOOL "не может бросить из Чаре в логическое значение."
#define TXT_INVALID_CAST_DATETIME2BOOL "не может бросить из DateTime в логическое значение."
#define TXT_INVALID_CAST_DATETIME2BYTE "не может бросить из DateTime в Byte."

#define TXT_FORMAT_DEFMSG "Неверный формат исключение."
#define TXT_FORMAT_STRING2BOOL_NOTSTR "Недопустимая строка."
#define TXT_FORMAT_FRACTION_NOSLASH "Вы должны иметь символ '/', чтобы отделить числитель и знаменатель tor."

#define TXT_NOTIMPL_DEFMSG "Запрошенный метод или операция не реализована."

#define TXT_EXCEPTION_DEFMSG "Произошла ошибка."

#define TXT_INVALID_OPER_DEFMSG "Вызов метода является недействительным."
#define TXT_INVALID_OPER_UNSAFE "Он содержит код, который может иметь большое влияние такие программы не могут запустить команду."

#define TXT_IO_DEFMSG "Произошла ошибка ввода / вывода."
#define TXT_IO_FILEALREADY "Этот файл уже существует."
#define TXT_IO_FILE404 "Файл не найден."

#define TXT_INDEX_DEFMSG "Индекс выходит за пределы допустимого диапазона."

#define TXT_ARITHMETIC_DEFMSG "Произошла арифметическая ошибка."

#define TXT_OVERFLOW_DEFMSG "Арифметическое переполнение произошло."

#define TXT_THREAD_ABORT_DEFMSG "Тема была прервана время."

#define TXT_NULLREF_DEFMSG "Объект, который является nullptr нельзя ссылаться."

#elif defined(LANG_SPA)
#define TXT_INVALID_ARGUMENT_DEFMSG "Excepción de argumento no válido."

#define TXT_INVALID_CAST_DEFMSG "Excepción de conversión no válida."
#define TXT_INVAILD_CAST_CHAR2BOOL "No se puede emitir desde Char a Boolean."
#define TXT_INVALID_CAST_DATETIME2BOOL "No se puede emitir desde DateTime a Boolean."
#define TXT_INVALID_CAST_DATETIME2BYTE "No se puede emitir un DateTime a Byte."

#define TXT_FORMAT_DEFMSG "Excepción de formato no válido."
#define TXT_FORMAT_STRING2BOOL_NOTSTR "Cadena no válida."
#define TXT_FORMAT_FRACTION_NOSLASH "Debe tener el carácter '/' para separar el numerador y el denominador."

#define TXT_NOTIMPL_DEFMSG "El método u operación solicitada no se implementa."

#define TXT_EXCEPTION_DEFMSG "Se ha producido un error."

#define TXT_INVALID_OPER_DEFMSG "La llamada al método no es válida."
#define TXT_INVALID_OPER_UNSAFE "Contiene el código que puede tener un gran impacto tales programas no pueden ejecutar el comando."

#define TXT_IO_DEFMSG "Se ha producido un error de E/S."
#define TXT_IO_FILEALREADY "Este archivo ya existe."
#define TXT_IO_FILE404 "Archivo no encontrado."

#define TXT_INDEX_DEFMSG "Índice fuera de rango."

#define TXT_ARITHMETIC_DEFMSG "Se produjo un error aritmético."

#define TXT_OVERFLOW_DEFMSG "Se ha producido un desbordamiento aritmético."

#define TXT_THREAD_ABORT_DEFMSG "El hilo estaba siendo abortado."

#define TXT_NULLREF_DEFMSG "No se puede hacer referencia a un objeto que es nullptr."

#else
#define TXT_INVALID_ARGUMENT_DEFMSG "Invalid argument exception."

#define TXT_INVALID_CAST_DEFMSG "Invalid cast exception."
#define TXT_INVAILD_CAST_CHAR2BOOL "Can't cast a from Char to Boolean."
#define TXT_INVALID_CAST_DATETIME2BOOL "Can't cast a from DateTime to Boolean."
#define TXT_INVALID_CAST_DATETIME2BYTE "Can't cast a from DateTime to Byte."

#define TXT_FORMAT_DEFMSG "Invalid format exception."
#define TXT_FORMAT_STRING2BOOL_NOTSTR "Invalid string."
#define TXT_FORMAT_FRACTION_NOSLASH "You must have the character '/' to separate the numerator and denominator."

#define TXT_NOTIMPL_DEFMSG "Requested method or operation is not implemented."

#define TXT_EXCEPTION_DEFMSG "An error has occurred."

#define TXT_INVALID_OPER_DEFMSG "The method call is invalid."
#define TXT_INVALID_OPER_UNSAFE "It contains the code that can have a big impact such programs can not run the command."

#define TXT_IO_DEFMSG "An I/O error occurred."
#define TXT_IO_FILEALREADY "This file already exists."
#define TXT_IO_FILE404 "File not found."

#define TXT_INDEX_DEFMSG "Index out of range."

#define TXT_ARITHMETIC_DEFMSG "An arithmetic error occurred."

#define TXT_OVERFLOW_DEFMSG "An arithmetic overflow has occurred."

#define TXT_THREAD_ABORT_DEFMSG "Thread was being aborted."

#define TXT_NULLREF_DEFMSG "An object that is nullptr cannot be referenced."


#endif

#endif