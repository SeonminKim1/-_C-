// 2017�� 1�б� ���α׷��ַ�
// Lab4-4 ����ü ����
#include <stdio.h>

typedef struct complex {
	int real;
	int img;
} COMPLEX;
//#define ABS(x) ((x>0) ? (x) : (-x))
void print_complex(COMPLEX *x)
{
	if(x->img>=0)
		printf("(%d %c %di)",x->real,'+',x->img);
	else if (x->img<0)
		printf("(%d %c %di)",x->real,'-',-(x->img));
}

//	printf("(%d %c %di)", x->real, x->img>0 ? '+' :'-',ABS(x->img)); // +���ֱ� ����. %d+%di -> %d %c %di�� �ٲ�.

COMPLEX add(COMPLEX x, COMPLEX y)
{
	COMPLEX z;
	z.real = x.real + y.real;
	z.img = x.img + y.img;
	return z;
}

COMPLEX sub(COMPLEX x, COMPLEX y)
{
	COMPLEX z;
	z.real = x.real - y.real;
	z.img = x.img - y.img;
	return z;
}

void main()
{
	COMPLEX x, y, z,z1;

	scanf("%d %d", &x.real, &x.img);
	scanf("%d %d", &y.real, &y.img);
	z = add(x, y);
	print_complex(&x); printf(" + "); print_complex(&y);
	printf(" = "); print_complex(&z);
	printf("\n");

	z1 = sub(x, y);
	print_complex(&x); printf(" - "); print_complex(&y);
	printf(" = "); print_complex(&z1);
	printf("\n");
}
