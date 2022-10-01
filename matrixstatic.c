#include <stdio.h>

int main() {
	int m, n;
	int x = 1;
	scanf("%d%d", &m, &n);
	int arr[m][n];
	for(int i = 0; i < m; i++){
	for (int j = 0; j < n; j++) {
	arr[i][j] = x++;
		}
	}
	for(int i = 0; i < m; i++){
	for (int j = 0; j < n; j++) {
	printf("%3d ", arr[i][j]);
		}
		printf("\n");
	}

}