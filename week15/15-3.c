#include "my.h"

void* reader(void*);
void* writer(void*);

static int share=0;
static pthread_rwlock_t rwlock;

int main()
{
	int i=0;	
	int ret=0;
	pthread_t tid[TN];
	pthread_rwlockattr_t rwlock_attr;
	pthread_rwlockattr_init(&rwlock_attr);
#ifdef WRITER_FIRST
	pthread_rwlockattr_setkind_np(&rwlock_attr,PTHREAD_RWLOCK_PREFER_WR);
#endif
	pthread_rwlock_init(&rwlock,&rwlock_attr);
	
	pthread_rwlock_rdlock(&rwlock);
	for(i=0;i<TN;i++)
	if(ret!=0)
	{
		perror("thread1 failed!\n");
		exit(1);
	}
	ret=pthread_create(&tid[1],NULL,worker2,NULL);
	if(ret!=0)
	{
		perror("thread2 failed!\n");
		exit(1);
	}
	for(i=0;i<2;i++)
	{
		pthread_join(tid[i],NULL);
	}

	return 0;
}

void* reader(void* param)
{
	int i=(int)param;
	while(1)
	{
		pthread_rwlock_rdlock(&rwlock);
		fprintf(stderr,"reader---%d:the share=%d\n",share);
		pthread_rwlock_unlock(&rwlock);	
	}
	return NULL;
}

void* writer(void* param)
{
	int i=(int)param;
	while(1)
	{
		pthread_rwlock_wrlock(&rwlock);
		fprintf(stderr,"reader---%d:the share=%d\n",share);
		pthread_rwlock_unlock(&rwlock);
		sleep(1);	
	}
	return NULL;
}

