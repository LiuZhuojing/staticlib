#include<stdio.h>
#include<stdlib.h>

int main(){
	int pid=0;
	if((pid=fork())<0){
		perror("failes to fork\n");
		return -1;
	}else if(pid==0){
		printf("%d:child in running now\n", getpid());
		while(1);
		printf("%d:child in exit now\n", getpid());
		exit(0);
	}else{
		printf("%d:parent is waiting@\n", getpid());
		wait(NULL);
		printf("%d:parent is exit@\n", getpid());
		
	}
	exit(0);
}
