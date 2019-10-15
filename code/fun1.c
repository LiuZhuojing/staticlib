#include "test.h"
int max(int *a, int n)
{
	int max = a[0];
	int i = 1;
	for(i; i<n; i++){
		if(max<a[i])
			max = a[i];
	}
	return max;
}

int sum(int *a, int n){
	int sum = 0;
	int i = 0;
	for(i; i<n; i++)	
		sum+=a[i];
	return sum;
}
