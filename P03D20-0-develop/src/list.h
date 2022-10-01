#ifndef SRC_LIST_H_
#define SRC_LIST_H_

struct list{
    char value;
    struct list* next;
};

struct list* push_list(struct list* top, char value);
struct list* init_list(char value);
void output_list(struct list* top);
void destoy_list(struct list* root);

#endif  // SRC_LIST_H_
