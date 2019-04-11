
#include<stdio.h>
#include<sched.h>
#include<sys/resource.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	struct sched_param sp;
	switch(sched_getscheduler(0))
	{
		case SCHED_RR: printf("Round robin\n");
						break;
		case SCHED_FIFO: printf("FIFO\n");
						break;
		case SCHED_OTHER: printf("other\n");
						break;
	}
	printf("The current priority of the process is %d\n",sp.sched_priority);
	sp.sched_priority=0;
	printf("The changed priority is %d\n",sp.sched_priority);
	printf("The maximun priority is %d\n",sched_get_priority_max(SCHED_RR));
	printf("The minimum priority is %d\n", sched_get_priority_min(SCHED_RR));
	int x=sched_setscheduler(0,SCHED_RR,&sp);
	switch(sched_getscheduler(0))
	{
		case SCHED_RR: printf("Round robin\n");
						break;
		case SCHED_FIFO: printf("FIFO\n");
						break;
		case SCHED_OTHER: printf("other\n");
						break;
		default: printf("Something went wrong\n");
	}
	return 0;
}
