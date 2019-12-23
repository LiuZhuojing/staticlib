#include "my.h"
int i=0;
int fun(void* d)
{
	i++;
	printf("tid=%ld i=%d\n",pthread_self(),i);
	return 0;
}

int main()
{
	int i;
	pthread_t tid;
	int ret[4];

	for(i=0;i<4;i++)
	{
		ret[i]=pthread_create(&tid,NULL,(void*(*)())fun,NULL);
		if(ret[i]!=0)
		{
			perror("failed!\n");
			return -1;
		}
	}	
	for(i=0;i<4;i++)
		pthread_detach(tid);
		//pthread_join(tid,NULL);
	return 0;
}
