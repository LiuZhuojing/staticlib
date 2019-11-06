#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main(){
	pid_t result;
	result = fork();
	int newret;
	if(result==-1){
		perror("fial to son progress");
		exit;
	}else if(result==0){
		printf("return is:%d\n pid is:%d\n ppid is:%d\n", result, getpid(), getppid());
		newret = system("ls -1");
	}else{
		sleep(10);
		printf("return is %d is father progress\n pid is %d\n, ppid is %d\n", result, getpid(), getppid());
		newret = system("ping www.baidu.com");
	}
}
