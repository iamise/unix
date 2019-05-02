#include<stdio.h>

int main()
{
	int i,s,r,n,tq,tm=0,wt[100],b[100],tat[100];
	printf("PRIORITY SCHEDULING\n");
	printf("Enter the number of processes\n");
	scanf("%d",&n);
	printf("Enter the burst time and priority of the processes respectively\n");
	
	for(i=0;i<n;i++)
	{
		scanf("%d",&s);
		printf("priority : ");
		scanf("%d",&r);
		b[r-1]=s;
	}
	
	printf("Prio\tBurstime\t");
	for (i=0;i<n;i++)
	{
		printf("%d\t%d\n",i+1, b[i]);
	}
	
	wt[0]=0;
	tat[0]=b[0];
	int tott=tat[0];
	int totw=wt[0];
	
	for(i=1;i<n;i++)
	{
		wt[i]=wt[i-1]+b[i-1];
		tat[i]=wt[i]+b[i];
		totw+=wt[i];
		tott+=tat[i];
	}
	
	float avgwt, avgtat;
	avgwt=(float)totw/n;
	avgtat=(float)tott/n;
	printf("The average waiting time is %f\n",avgwt);
	printf("The average turn around time is %f\n",avgtat);
	
	printf("\nROUND ROBIN\n");
	printf("Enter the number of processes\n");
	scanf("%d",&n);
	printf("Enter the burst time for each process\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&b[i]);
	}	
	for(i=0;i<n;i++)
	{
		printf("Burst time for process %d is %d\n",i,b[i]);
		wt[i]=0;
	}
	printf("Enter the value of time quantum\n");
	scanf("%d",&tq);
	int rem[10], flag=0;
	for(i=0;i<n;i++)
		rem[i]=b[i];
		
	while(flag==0)
	{
		for(i=0;i<n;i++)
		{
			
			if (rem[i]>tq)
			{
				tm+=tq;
				rem[i]=rem[i]-tq;
				printf("%d = tm and rem[%d] = %d\n",tm,i,rem[i]);
			}
			else
			{
				tm+=rem[i];
				rem[i]=0;
				printf("%d = tm and rem[%d] = %d\n",tm,i,rem[i]);
				if(wt[i]==0)
					wt[i]=tm-b[i];
			}
		}
		
		for(i=0;i<n;i++)
		{
			if(rem[i]==0)
				flag=1;
			else
			{
				flag=0;
				break;
			}	
		}
	}
	totw=0, tott=0;
	for(i=0;i<n;i++)
	{
		totw+=wt[i];
		tat[i]=wt[i]+b[i];
		tott+=tat[i];
		printf("wt[%d] = %d\n",i,wt[i]);
	}
	
	avgwt=(float)totw/n;
	avgtat=(float)tott/n;
	
	printf("The average waiting time is %f\n",avgwt);
	printf("The average turnaround time is %f\n",avgtat);
	
	return 0;
}
