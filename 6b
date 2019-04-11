#include<stdio.h>
#include<unistd.h>
#include<sys/time.h>

int main()
{
	int status,i,r;
	int fd[2];
	char msg[100], buf[100];
	fd_set rfds;
	struct timeval t;
	status = pipe(fd);
	if (status==-1)
	{
		perror("pipe");
		return 0;
	}
	i=fork();
	if(i== -1){
		perror("fork");
		return 0;
	}
	if (i==0)
	{
		printf("Enter the message to be written\n");
		scanf("%s",msg);
		write(fd[1],msg,100);
		close(fd[1]);
	} else
	{
		t.tv_sec=3;
		t.tv_usec=0;
		FD_ZERO(&rfds);
		FD_SET(fd[0],&rfds);
		r=select(fd[0]+1, &rfds, NULL , NULL, &t);
		if (r == 0)
		{
			printf("timeout\n");
			return 0;
		}
		if(r <0)
		{
			perror("select");
			return 0;
		}
		read(fd[0],buf,100);
		printf("The message read is %s \n", buf);
	}
	return 0;	

}
