#include<stdio.h>
#include<unistd.h>
int main(){

	printf("test3 pid=%d, ppid=%d", getpid(), getppid());
}
