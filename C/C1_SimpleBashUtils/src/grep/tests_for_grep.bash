#!/bin/bash

check_test() {
    printf "\'[0-9]\'\n\'[A-Z]\'" > pattern.txt
    touch empty.txt
    printf "\n" > empty_string.txt
    printf "This is the first file.\n It contains some text, numbers like 123 and symbols: @#*()!\n\n\t\tWe can add\t\ttabs here for better readability. \nAlso, there are empty lines to separate sections. \nEnd of file 1."  > test1.txt
    printf "The second file has a different message. \nIt includes numbers: 456 and special characters: \n!&*()_+{}|:<>?\n\t\nTabs can be used    to align text properly. \n\nLet's keep it organized. \n\nEnd of file 2.\n\n\n" > test2.txt
    printf "In the third file, we discuss how to use files in C. \nImportant numbers: 789 and symbols like\n [];'\,. \n\n\n\nweiufihwufj@yandex.ru\n\nMake sure to    format your text correctly. \nEmpty lines help improve clarity. \nEnd of file 3." > test3.txt
    printf "The fourth file serves as a final example. \nIt shows how to use    tabs and numbers like\n 101112. \nSpecial characters: ~!@^&*() help in formatting.\n\nRemember to keep everything neat! \n\n\nEnd of file 4.\n\n\n\t\t\t\t"  > test4.txt

    Myres=$(./s21_grep $1 2>/dev/null)
    Grepres=$(grep $1 2>/dev/null)

    if [ "$Myres" = "$Grepres" ]; then
        ((cnt_success++))
        echo "SUCCESS: $1"
    else
        ((cnt_failed++))
        echo "FAIL: $1"
    fi
    ((cnt++))
}

cnt=0
cnt_success=0
cnt_failed=0

check_test "file test1.txt test2.txt test3.txt test4.txt"
check_test "-e 'like' -e '101' test1.txt test2.txt test3.txt test4.txt"
check_test "-e 'like' -e '101' test1.txt"
check_test "-i 'SpEcIaL' test1.txt test2.txt test3.txt test4.txt"
check_test "-i 'SpEcIaL' test2.txt"
check_test "-v '[0-9]' test1.txt test2.txt test3.txt test4.txt"
check_test "-v '[a-z]' test3.txt"
check_test "-c I test1.txt test2.txt test3.txt test4.txt"
check_test "-c I test4.txt"
check_test "-l ':' test1.txt test2.txt test3.txt test4.txt"
check_test "-l ':' test1.txt"
check_test "-n and test1.txt test2.txt test3.txt test4.txt"
check_test "-n and test2.txt"
check_test "-h and test1.txt test2.txt test3.txt test4.txt"
check_test "-h and test1.txt"
check_test "-s '.' test1.txt test2.txt test3.txt test4.txt"
check_test "-s '.' test2.txt"
check_test "-s '.' test1.txt test2.txt test3.txt tes.txt"
check_test "-f pattern.txt test1.txt test2.txt test3.txt test4.txt"
check_test "-f pattern.txt test3.txt"
check_test "-o and test1.txt test2.txt test3.txt test4.txt"
check_test "-o and test1.txt"
check_test "-s text q.txt"
check_test "abc empty_string.txt"
check_test "-e abc -e abcd empty_string.txt"
check_test "-i AbC empty_string.txt"
check_test "-v 1 empty_string.txt"
check_test "-c , empty_string.txt"
check_test "-l qwerty empty_string.txt"
check_test "-n Q empty_string.txt"
check_test "-h and empty_string.txt"
check_test "-s '.' empty_string.txt"
check_test "-f pattern.txt empty_string.txt"
check_test "-o and empty_string.txt"

rm -f pattern.txt empty_string.txt space.txt test1.txt test2.txt test3.txt test4.txt

echo "ALL: $cnt"
echo "SUCCESS: $cnt_success"
echo "FAILED: $cnt_failed"