#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main(){
	printf("call:pid=%d,ppid=%d\n",getppid(),getppid());
	system("/home/liu/Desktop/linuxprogram/week9/Code/test3");
	printf("after calling");
}
