#include <stdio.h>
//입력 리버스
#define MAX_S 80
void reverse(char *to, char *from);
void main(){
	int ntest;
	char inputs[MAX_S], outputs[MAX_S];
	scanf("%d", &ntest);
	while (ntest--){
		scanf("%s", inputs);
		reverse(outputs, inputs);
		printf("%s\n", outputs);
	}

}

void reverse(char *to, char *from){
	char *p;
	p = from;
	while (*p)
		p++;
	p--;
	while (from <= p){
		if ((*p & 0x80) == 0x80){
			*(to++) = *(--p);
			*(to++) = *(++p);
			p -= 2;
		}
		else
			*to++ = *p--;
	}
	*to = NULL;
}

