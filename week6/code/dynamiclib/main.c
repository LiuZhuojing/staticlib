#include "test.h"
#include "stdio.h"
int main(){
	int a[5];
	init(a, 5);
	show(a, 5);
	printf("max=%d", max(a, 5));
	printf("sun=%d", sum(a, 5));
}
