#include "my.h"
#include<signal.h>
#include<stdlib.h>
#include<string.h>
#include<sys/param.h>
#include<sys/stat.h>
int main(){
	pid_t result;
	int r_num;
	int pipe_fd[2];
	char buf_r[100];
	memset(buf_r, 0, sizeof(buf_r));
	if(pipe(pipe_fd)<0){
		printf("faile to process");
		return -1;	
	}
	result = fork();
	if(result<0){
		perror("faile to son process");
		exit;	
	}else if(result==0){
		close(pipe_fd[1]);
		if(r_num=read(pipe_fd[0], buf_r, 100)>0)
			printf("son process %d char, read string is %s\n", r_num, 				buf_r);
			close(pipe_fd[0]);
			exit(0);	
	}else{
		close(pipe_fd[0]);
		if(write(pipe_fd[1], "first txt", 10)!=-1)
			printf("father process write first world\n");
		if(write(pipe_fd[1], "two txt", 10)!=-1)
			printf("father process write two world\n");
		close(pipe_fd[1]);
		waitpid(result,NULL, 0);
		exit(0);
	}
}
