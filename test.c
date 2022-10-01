#include <stdio.h>
#include <stdlib.h>

int main() {
	char *str = (char*)malloc(sizeof(char));
	int size = 1;
	char c;
	while(scanf("%c", &c) && c != '\n') {
		str[size - 1] = c;
		size++;
		str = (char*)realloc(str,size * sizeof(char));
	}
	size--;
	str = realloc(str, size * sizeof(char));
	for(int i = 0; i < size; i++) {
		if ( (str[i] >= 'A') && (str[i] <= 'Z'))
			str[i] = str[i] + 32;
		}
	char *str2 = (char*)malloc(size * sizeof(char));
	int index = 0;
	for(int i = size - 1; i >= 0; i--){
		str2[index]=str[i];
		index++;
	}
	int result = 1;
	for (int i = 0; i < size && result; ++i) {
		if(str[i] != str2[i]) {
			result = 0;
		}
	}
	free(str);
	free(str2);
	if(result){
		printf("YES");
	} else {
		printf("NO");
	}
	return 0;
}
