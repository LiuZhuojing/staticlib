#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main(){
	int choice = 0;
	int fd, size, i;
	const char *pathname = "choice1.txt";
	char s[] = "test for week7", buffer[80]; 
	struct stat fileInfo;
	unsigned int mask, access;
	printf("Please input your choice(0:6)0:");
	scanf("%d", &choice);
	
	if(choice==0){
		exit(0);
	}else if(choice==1){
		fd=fopen(pathname, O_CREAT, S_IRWXU);
		close(fd);
	}else if(choice==2){
		fd=fopen(pathname,  O_WRONLY|O_CREAT);
		fwrite(fd, s, sizeof(s));
		fclose(fd);	
	}else if(choice==3){
		fd=fopen(pathname, O_RDONLY);
		size=fread(fd, buffer, sizeof(buffer));
		fclose(fd);
		
		printf("%s\n", buffer);
	}else if(choice==4){
		chmod(pathname, 0644);
	}else if(choice==5){
		if (stat(pathname, &fileInfo) < 0)
                	exit(0);

       	        mask = 0000777;
       	        access = mask & fileInfo.st_mode;
                printf("%o\n%d\n", access, fileInfo.st_uid);
		chmod(pathname, 0644);
	}

	return 0;
}



