# C-проекты

## О чем эта папка

Здесь собраны учебные проекты на языке **C**. Они демонстрируют алгоритмическое мышление, работу с памятью и реализацию базовых библиотек с нуля.

## Навигация по папкам

| Папка | Файл(ы) | Краткое описание |
|:---|:---|:---|
| C1_SimpleBashUtils | /cat/src `s21_cat.c`, `parce.c`, `parce.h` <br> <br> grep/src `s21_grep.c`, `parce_grep.c`, `parce_grep.h` | Реализация аналога команды `cat` для чтения и объединения файлов. <br> <br> Реализация аналога команды `grep` для поиска по шаблону. |
| C2_stringplus | /src `s21_string.c`, `s21_string.h`, `s21_sprintf.c`, `s21_sprintf.h` | Реализация основных функций работы со строками (memcpy, strcmp, strlen и др.). |
| C3_decimal | /src `s21_add.c`, `s21_additionals.h`, `s21_comparison`, `s21_converters`, `s21_decimal.h`, `s21_div`, `s21_mul`, `s21_other_funcs`, `s21_sub` | Реализация арифметики с десятичными числами (сложение, вычитание, округление). |
| C4_matrix | /src `s21_calc_complements.c`, `s21_create_matrix.c`, `s21_determinant.c`, `s21_eq_matrix.c`, `s21_inverse_matrix.c`, `s21_matrix.h`, `s21_mult_matrix.c`, `s21_mult_number.c`, `s21_other.c`, `s21_remove_matrix.c`, `s21_sub_matrix.c`, `s21_sum_matrix.c`, `s21_transpose.c` | Реализация операций с матрицами (сложение, умножение, определитель, обратная). |

## Как собрать и запустить

### Требования
- Компилятор GCC или Clang
- Make (опционально)

### Сборка (пример для библиотеки matrix.h)
```bash
gcc -c s21_matrix.c -o s21_matrix.o
ar rcs libs21_matrix.a s21_matrix.o