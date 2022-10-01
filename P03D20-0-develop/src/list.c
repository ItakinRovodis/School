#include <stdio.h>
#include <stdlib.h>
#include "list.h"


struct list* push_list(struct list* root, char value) {
    struct list* new = (struct list*)malloc(sizeof(struct list));
    if (new != NULL) {
        new->value = value;
        struct list* ptr = root;
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = new;
    }
    return root;
}

struct list* init_list(char value) {
    struct list* new = (struct list*)malloc(sizeof(struct list));
    if (new != NULL) {
        new->value = value;
        new->next = NULL;
    }
    return new;
}


void output_list(struct list* root) {
    struct list* ptr = root;
    while (ptr != NULL) {
        printf("%c", ptr->value);
        ptr = ptr->next;
    }
}

void destoy_list(struct list* root) {
    if (root == NULL) {
        return;
    }
    destoy_list(root->next);
    free(root);
}

