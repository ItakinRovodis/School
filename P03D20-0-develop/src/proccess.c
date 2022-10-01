#include "stack.h"
#include "list.h"
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int check(char c);

int main() {
    struct stack* st = NULL;
    struct list* lis = init_list(' ');
    char c;
    int flag = 0;
    int result = 1;
    while(scanf("%c", &c) == 1 && c != '\n' && result) {
        if (c >= '0' && c <= '9') { // записываем числа в список
            flag = 1;
            lis = push_list(lis, c);
        } else if (check(c)) { // записываем операторы в стек
            if (flag == 1) {
                lis = push_list(lis, ' ');
                flag = 0;
            }
            st = push(st, c);
        } else if (c == 's') { // Находим синус или sqrt - корень
            int check_sin = 1;
            int check_sqrt = 1;
            if (scanf("%c", &c) != 1 || c != 'i') {
                check_sin = 0; // запись синуса НЕ ВЕРНА!
                if (c != 'q') {
                    check_sqrt = 0;
                } else if (scanf("%c", &c) != 1 && c != 'r') {
                    check_sqrt = 0;
                } else if (scanf("%c", &c) != 1 && c != 't') {
                    check_sqrt = 0;
                }
            } else if (scanf("%c", &c) != 1 || c != 'n') { // ЗДЕСЬ ПРЕДУСМОТРЕТЬ ЧТОБЫ ПОСЛЕ ШЛА СКОБКА (
                check_sin = 0;
            }
            if (check_sin) { //  если запись синуса верна 
                st = push(st, 's'); //  записываем синус в стек как символ s
            } else  if (check_sqrt){ // если запись корня верна - sqrt то записываем в стек q
                st = push(st, 'q');
            } else {
                result = 0;  // если запись не верна - значит ошибка! - мы не сможем ничего посчитать - ввод должен быть верным!!
            }
        } else if (c == 'c') { // Находим косинус или котангенс
            int check_cos = 1;
            int check_ctg = 1;
            if (scanf("%c", &c) != 1 || c != 'o') {
                check_cos = 0; // запись синуса НЕ ВЕРНА!
                if (c != 't') {
                    check_ctg = 0;
                } else if (scanf("%c", &c) != 1 && c != 'g') {
                    check_ctg = 0;
                }
            } else if (scanf("%c", &c) != 1 || c != 's') { // ЗДЕСЬ ПРЕДУСМОТРЕТЬ ЧТОБЫ ПОСЛЕ ШЛА СКОБКА (
                check_cos = 0;
            }
            if (check_cos) { //  если запись косинуса верна 
                st = push(st, 'c'); //  записываем косинус в стек как символ c
            } else  if (check_ctg){ // если запись корня верна - ctg то записываем в стек С
                st = push(st, 'C');
            } else {
                result = 0;  // если запись не верна - значит ошибка! - мы не сможем ничего посчитать - ввод должен быть верным!!
            }
        } else if (c == '(') {
            st = push(st, c);
        } else if (c == ')') {
            while (st->value != '(') { // Если находим в стеке операцию страше то вытаскиваем ее в список
                if (flag == 1) {
                    lis = push_list(lis, ' ');
                    flag = 0;
                }
                char fa;
                st = pop(st, &fa);
                lis = push_list(lis, fa);
                lis = push_list(lis, ' ');
                flag = 1;
            } // после этого в стеке должна остаться открывающая скобка - её надо удалить
            pop(st, &c);
        }
        if (st != NULL) {
            int index = check_stack(st->value, st);
            while (index) { // Если находим в стеке операцию страше то вытаскиваем ее в список
                if (flag == 1) {
                    lis = push_list(lis, ' ');
                    flag = 0;
                }
                char fa = pull_ind(st, index);
                index = 0;
                lis = push_list(lis, fa);
                lis = push_list(lis, ' ');
                flag = 1;
            }
        }
        
    }
    if (flag) {
        lis = push_list(lis, ' ');
    }
    while(st != NULL) {
        char in_stack;
        st = pop(st, &in_stack);
        lis = push_list(lis, in_stack);
        lis = push_list(lis, ' ');
    }
    output_list(lis);
}

int check(char c) {
    return (c == '+' || c == '-' || c == '/' || c == '*' || c == '^');
}
