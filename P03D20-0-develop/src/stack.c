#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

struct stack* push(struct stack* top, char value) {
    struct stack* new = (struct stack*)malloc(sizeof(struct stack));
    if (new != NULL) {
        new->value = value;
        new->prev = top;
        top = new;
    }
    return top;
}
struct stack* pop(struct stack* top, char *value) {
    *value = top->value;
    struct stack* old = top;
    top = top->prev;
    free(old);
    return top;
}
struct stack* init(char value) {
    struct stack* new = (struct stack*)malloc(sizeof(struct stack));
    if (new != NULL) {
        new->value = value;
        new->prev = NULL;
    }
    return new;
}


void output_stack(struct stack* top) {
    struct stack* ptr = top;
    while (ptr != NULL) {
        printf("%c ", ptr->value);
        ptr = ptr->prev;
    }
}

void destroy_stack(struct stack* top) {
    if (top == NULL) {
        return;
    }
    destroy_stack(top->prev);
    free(top);
}

int check_stack(char c, struct stack* top) { // ищем в стеке операции старше и выносим их индекс
    int result = 0;
    int c_val;
    switch (c) {
        case '+' : c_val = 1;
            break;
        case '-' : c_val = 1;
            break;
        case '*' : c_val = 2;
            break;
        case '/' : c_val = 2;
            break;
        case '^' : c_val = 3;
            break;
        case 's' :
        case 'q' :
        case 'c' :
        case 'C' : c_val = 4;
            break;
        default:
            c_val = -1;

    }
    struct stack* ptr = top;
    int flag = 1;
     int ptr_val;
    while (ptr != NULL && flag) {       
        switch (ptr->value) {
            case '(' : ptr_val = 0;
                break;
            case '+' : ptr_val = 1;
                break;
            case '-' : ptr_val = 1;
                break;
            case '*' : ptr_val = 2;
                break;
            case '/' : ptr_val = 2;
                break;
            case '^' : ptr_val = 3;
                break;
            case 's' :
            case 'q' :
            case 'c' :
            case 'C' : ptr_val = 4;
                break;
            default:
                ptr_val = -1;
                break;
        }
        if (ptr_val == 0 || c_val == -1 || ptr_val == -1) { // Если встречаем открывающую скобку - то выходим
            flag = 0;
        } else if (ptr_val > c_val) {
            flag = 0;
        } else {
            ++result;
        }
        ptr = ptr->prev;
    }
    if (flag || ptr == NULL || ptr_val == 0 || c_val == -1) { // Если нет операций старше обнуляем результат
         result = 0;
    }
    return result;
}

char pull_ind(struct stack* top, int index) {
    struct stack* ptr = top;
    struct stack* ptr_2;
    char result;
    while (index != 0) {
        ptr_2 = ptr; // предыдущий указатель
        index--;
        ptr = ptr->prev; // находим нужный элемент
    }
    ptr_2->prev = ptr->prev;
    result = ptr->value;
    free(ptr);
    return result;
}



