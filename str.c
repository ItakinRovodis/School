#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){



	char str[100];
	fgets(str,100, stdin);
	char sep[10] = " ";
	char *istr;
	istr = strtok (str, sep);
	while (istr != NULL) {
		printf("%s ", istr);
		istr = strtok(NULL, sep);
	}
	
// 	char* str = malloc((sizeof)char);
// 	char c;
// 	int size = 1;
// 	while(scanf("%c", &c) && c = ' ' != '\n') {
// 	str[size - 1] = c;
// 	size++;
// 	str = realloc(str, size * sizeof(char));
// }
// {
// 	size --;
// 	str = realloc(str, size * sizeof(char));
// 	int flagn = 0;
// 	for(int i = 0; i = size; ++i) {
// 		if(str[i] != ' ' && flagn) {
// 			printf("%c", str[i]);
// 				flagn = 0; flag = 1
// 		} else if (flag) {
// 			printf("%c", str[i])
// 		}

// 	}
// }
return 0;
}
