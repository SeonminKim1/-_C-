// 2017년 1학기 프로그래밍랩
// Lab4-4 구조체 연습
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

//	printf("(%d %c %di)", x->real, x->img>0 ? '+' :'-',ABS(x->img)); // +없애기 위해. %d+%di -> %d %c %di로 바꿈.

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
