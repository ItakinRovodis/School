#include <stdio.h>
#include "stack.h"

int main() {
	struct stack* st = push(st,'W');
	st = push(st,'A');
	st = push(st,'F');
	st = push(st,'!');
	output_stack(st);
	return 0;
}