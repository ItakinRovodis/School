#include <stdio.h>
#include <stdlib.h>

int main() {

	int *numbers = (int *) malloc (sizeof(int));
	int size = 1;
	while (scanf("%d", &numbers[size-1]) != 0 && numbers[size-1] != -1) {
		size++;
		numbers = realloc(numbers, size*(sizeof(int)));
	}

	size--;
	numbers = realloc(numbers, (size)*(sizeof(int)));
	int *result = malloc(size*sizeof(int));
	int index = 0;
	for (int i = 0; i < size ;i+=2) {
		result[i] = numbers[index];
		index++;
	}

	index = size -1;
	for (int i = 1; i < size; i += 2) {
		result[i] = numbers[index];
		index--;
	}

	free(numbers);
	for (int i = 0; i < size; i++) {
		printf("%d", result[i]);
		if (i < size -1) {
			printf(" ");
		}
	}
	free(result);
	return 0;
}



// int main() {
// 	char c;
// 	int flag = 1;
// 	while (scanf("%c", &c) && c != '\n') {
// 		if ((c >= 'a' && c <= 'z') && flag) {
// 			printf("%c", c - 32);
// 			flag = 0;
// 		} else if (c == ' ') {
// 			flag = 1;
// 			printf("%c", c);
// 		} else {
// 			printf("%c", c);
// 		}
// 	}
// 	return 0;
// }


// #include <stdio.h>
// #include <stdlib.h>

// int main() {
// 	int numbers[10] = {1, 2, 2, 3, 3, 4, 6, 4, 1, 2};
// 	int size = 10;
// 	int *result = malloc(size * sizeof(int));
// 	int index = 0;
// 	int flag = 1;
// 	result[index] = numbers[0];
// 	for (int i = 0; i < size; ++i) {
// 		flag = 1;
// 		for (int j = 0; j <= index; ++j) {
// 			if (numbers[i] == result[j]) {
// 				flag = 0;
// 			}
// 		}
// 		if (flag) {
// 			index++;
// 			result = realloc(result, (index + 1) * sizeof(int));
// 			result[index] = numbers[i];
// 		}
// 	}
// 	index++;
// 	for (int i = 0; i < index; ++i) {
// 		printf("%d", result[i]);
// 		if(i < index -1)
// 			printf(" ");
// 	}
// 	free(result);
// 	return 0;
// }

