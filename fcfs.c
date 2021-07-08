#include<stdio.h>
void main()
{
 int bt[10],ct[10],at[10],turnaroundtime[10],i,n,wt[10];
 float atat=0,awt=0;
 printf("\nEnter number of processes:");
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
 printf("\nEnter arrival time of processes p%d:",i+1);
  scanf("%d",&at[i]);
  printf("\nEnter burst time of processes p%d:",i+1);
  scanf("%d",&bt[i]);
 }
 ct[0]=bt[0]+at[0];
 for(i=1;i<n;i++)
 {
   ct[i]=ct[i-1]+bt[i];
 }
 for(i=0;i<n;i++)
 {
 turnaroundtime[i]=ct[i]-at[i];
 wt[i]=turnaroundtime[i]-bt[i];
 awt=awt+wt[i];
 atat=atat+turnaroundtime[i];

 }
 printf("Arrival_time Burst_Time completion_time Turn_Around_Time Waiting_Time\n");
 for(i=0;i<n;i++)
{
 printf("%d	      %d	           %d	        %d             \t\t%d\n",at[i],bt[i],ct[i],turnaroundtime[i],wt[i]);

}
awt=awt/n;
atat=atat/n;
printf("Average waiting time:%.2f\nAverage Turn around time:%.2f",awt,atat);
}

