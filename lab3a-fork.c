#include<stdio.h>
#include<unistd.h>
#include<string.h>

int main()
{
	int p;
	int status=1;
	char cmd[100];
	p=fork();
	if(p==0){
		printf("Child process entered\n");
		printf("%d : pid of child\n%d : pid of parent\n",getpid(), getppid());
		printf("Enter a command\n");
		scanf("%s",cmd);
		system(cmd);	
	}
	else{
		wait(&status);
		printf("%d: status",status);
		printf("parent process entered after child as wait() was used\n");
		printf("%d : pid of child\n%d : pid of parent\n",p,getpid());	
	}
	return 0;
}

