#!/bin/bash

check_test() {
    printf "\n" > empty_string.txt
    printf "      " > space.txt
    printf "\t\n\t\t" > tabl.txt
    printf "qwdyugqh qiwfuhf ihfiifihn fcmv,clbjk nbeobk,dberb 2b03 565\nv\n\n\t pijOkprg \n\t\t\t\toiwjokg w[ \n        wGwg\n\n    weplmlgwg ,bmvm bMb nnnnq\n              qytwufygqvfb@mail.ru     884586354wef4we5f" > test1.txt
    printf "qwfquhjk    f f vowv\t\nvwm ,b b45v4 w          eplmlgwgv\n\t\t    vw[vw w.v v.v3w9-vw]\nw[,wv   ,,vw[,v ]]\n\nbvnmc,mnbvncm,xc h278iv" > test2.txt
    printf "← ↑ → ↓\n♗♘♙" > test3.txt

    Myres=$(./s21_cat $1 2>/dev/null)
    Catres=$(cat $1 2>/dev/null)

    if [ "$Myres" = "$Catres" ]; then
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

check_test "test1.txt test2.txt"
check_test "-b test1.txt test2.txt"
check_test "-e test1.txt test2.txt"
check_test "-n test1.txt test2.txt"
check_test "-s test1.txt test2.txt"
check_test "-t test1.txt test2.txt"
check_test "empty_string.txt"
check_test "-b empty_string.txt"
check_test "-e empty_string.txt"
check_test "-n empty_string.txt"
check_test "-s empty_string.txt"
check_test "-t empty_string.txt"
check_test "space.txt"
check_test "-b space.txt"
check_test "-e space.txt"
check_test "-n space.txt"
check_test "-s space.txt"
check_test "-t space.txt"
check_test "tabl.txt"
check_test "-b tabl.txt"
check_test "-e tabl.txt"
check_test "-n tabl.txt"
check_test "-s tabl.txt"
check_test "-t tabl.txt"
check_test  "-b test3.txt"
check_test  "-e test3.txt"
check_test  "-n test3.txt"
check_test  "-s test3.txt"
check_test  "-t test3.txt"


rm -f *.txt

echo "ALL: $cnt"
echo "SUCCESS: $cnt_success"
echo "FAILED: $cnt_failed"