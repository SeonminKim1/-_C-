#include <stdio.h>
#define ROWS 2
#define COLS 2

void print_matrix(int m[ROWS][COLS]){//행렬 나타내줌.
	int i, j;
	for (i = 0; i < ROWS; i++){
		for (j = 0; j < COLS; j++){
			printf("%2d ", m[i][j]);
		}
		printf("\n");
	}

}

void mul_matrix(int a[][COLS], int b[][COLS], int c[][COLS]){
	int i, j, k, l;
	for (i = 0; i < ROWS; i++)
		for (j = 0; j < COLS; j++){
			for (k = 0; k < COLS; k++)
				c[i][j] = c[i][j]+ a[i][k] * b[k][j];
		}
}

void input_matrix(int m[][COLS]){ // 행렬 A,B 수동입력하게해주는것.
	int i, j;
	for (i = 0; i < ROWS; i++)
		for (j = 0; j < COLS; j++)
			scanf("%d", &m[i][j]);
}

void main(){
	int A[ROWS][COLS] = { 0 };
	int B[ROWS][COLS] = { 0 };
	int C[ROWS][COLS] = { 0 };
	printf("Matrix 곱셈\n");
	printf("A = \n");
	input_matrix(A);
	printf("B = \n");
	input_matrix(B);
	mul_matrix(A, B, C);
	printf("AxB = \n");
	print_matrix(C);
}