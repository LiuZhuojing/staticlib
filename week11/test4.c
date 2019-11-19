#include "my.h"

int main()
{
	int pid1,pid2,s1,s2,p1,p2;
	


	if((pid1=fork())&&((pid2=fork()))<0)//失败
	{
		perror("failed to fork@\n");
		return -1;
	}
	else if(pid1==0)//子进程pid1
	{
		printf("%d:child1 is runing now!\n",getpid());
		printf("%d:child1 is exit now!\n",getpid());
		//while(1);
		exit(120);
	}
	else if(pid2==0)//子进程pid2
	{
		printf("%d:child2 is runing now!\n",getpid());
		printf("%d:child2 is exit now!\n",getpid());
		//while(1);
		exit(130);
	}
	else//if(pid>0)//父进程
	{
		sleep(5);
		printf("%dparent is waiting zombie now!\n",getpid());
		p1=wait(&s1);
		p2=wait(&s2);
		if(WIFEXITED(s1)==120)
				printf("child1 %d is exiting normally.exit code =%d\n",pid1,WEXITSTATUS(s1));
		
		/*while((pid=wait(&s))!=-1)
		{
			if(WIFEXITED(s))
				printf("child %d is exiting normally.exit code =%d\n",pid,WEXITSTATUS(s));
			else if(WIFSIGNALED(s))
				printf("child %d is exit by signal.signal no =%d\n",pid,WTERMSIG(s));
			else
				printf("not know!");
		}*/
		printf("parent finished!");
	}

}





