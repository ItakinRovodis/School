#ifndef SRC_STACK_H_
#define SRC_STACK_H_

struct stack{
    char value;
    struct stack* prev;
};

struct stack* push(struct stack* top, char value);
struct stack* pop(struct stack* top, char *value);
struct stack* init(char value);
void output_stack(struct stack* top);
int check_stack(char c, struct stack* top);
char pull_ind(struct stack* top, int index);

#endif  // SRC_STACK_H_
