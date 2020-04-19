#include <stdio.h>
#define MAXROWS	100
#define MAXCOLS	100
typedef struct matrix {
	int rows, cols;
	int data[MAXROWS][MAXCOLS];
} Matrix;
void print_matrix(Matrix *m)
{
int i,j;
	for (i = 0; i<m->rows; i++)
	{
		for (j = 0; j<m->cols; j++){
			printf("%3d", m->data[i][j]);
	}
	printf("\n");
	}
}
	void add_matrix(Matrix *a, Matrix *b, Matrix *c)
	{
		int i, j;
		for (i = 0; i<a->rows; i++)
		{
			for (j = 0; j < a->cols; j++)
			{
				c->data[i][j]=a->data[i][j]+b->data[i][j];
				printf("%3d",c->data[i][j]);
			}
			printf("\n");
		}
	}
	
	void sub_matrix(Matrix *a, Matrix *b, Matrix *c)
	{
		int i, j;
		for (i = 0; i<a->rows; i++)
		{
			for (j = 0; j < a->cols; j++)
			{
				c->data[i][j] = a->data[i][j] - b->data[i][j];
				printf("%3d", c->data[i][j]);
			}
			printf("\n");
		}
	}
	
	void main()
	{
		Matrix A = {{3},{3},{{1,2,3},{4,5,6},{7,8,9}}};
		Matrix B = {{3},{3},{{11,12,13},{14,15,16},{17,18,19}}};
		Matrix C = {{3},{3},{0}}; // = Matrix C;

		printf("Matrix ADT »ç¿ë\n");
		printf("A = \n"); 	print_matrix(&A);
		printf("\n");
		printf("B = \n"); 	print_matrix(&B);
		printf("\n");
		printf("A + B = \n"); 
		add_matrix(&A, &B, &C);
		printf("\n");
		printf("B - A = \n"); 
		sub_matrix(&B, &A, &C);

		printf("\n");
	}