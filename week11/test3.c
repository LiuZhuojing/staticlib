#include "my.h"

int main()
{
	int pid,s;
	


	if((pid=fork())<0)//失败
	{
		perror("failed to fork@\n");
		return -1;
	}
	else if(pid==0)//子进程
	{
		printf("%d:child is runing now!\n",getpid());
		//printf("%:dchild is exit now!\n",getpid());
		//while(1);
		exit(120);
	}
	else//if(pid>0)//父进程
	{
		printf("%dparent is waiting zombie now!\n",getpid());
		while((pid=wait(&s))!=-1)
		{
			if(WIFEXITED(s))
				printf("child %d is exiting normally.exit code =%d\n",pid,WEXITSTATUS(s));
			else if(WIFSIGNALED(s))
				printf("child %d is exit by signal.signal no =%d\n",pid,WTERMSIG(s));
			else
				printf("not know!");

		}


	}


}





