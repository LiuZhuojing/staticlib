#include<stdio.h>
#include<stdlib.h>
#include "test.h"
#include<time.h>
void show(int *a, int n){
	int i = 0;
	for(i; i<n; i++)
		printf("%4d\n", a[i]);
}

void init(int *a, int n){
	int i = 0;
	srand(time(NULL));
	for(i; i<n; i++){
		a[i] = rand()%100;
	}
}
