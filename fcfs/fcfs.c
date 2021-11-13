
#include<stdio.h>
// Function to find the waiting time 
void display_name(){
    printf("**************************************************************** \n");
    printf("Name:Muhammed Hilal \n");
    printf("Reg No:20419056 \n");
    printf("class: IT-B \n");
    printf("**************************************************************** \n");
}
void findWaitingTime(int processes[], int n, int bt[], int wt[])
{
    wt[0] = 0;
    for (int  i = 1; i < n ; i++ )
        wt[i] =  bt[i-1] + wt[i-1] ;
}  
// Function to calculate turn around time
void findTurnAroundTime( int processes[], int n, int bt[], int wt[], int tat[])
{
    for (int  i = 0; i < n ; i++)
        tat[i] = bt[i] + wt[i];
}
   
//Function to calculate average time
void findavgTime( int processes[], int n, int bt[])
{
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
    findWaitingTime(processes, n, bt, wt);
    findTurnAroundTime(processes, n, bt, wt, tat);
    printf("Processes   Burst time   Waiting time   Turn around time\n");
   
    for (int  i=0; i<n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        printf("   %d ",(i+1));
        printf("       %d ", bt[i] );
        printf("       %d",wt[i] );
        printf("       %d\n",tat[i] );
    }
    int s=(float)total_wt / (float)n;
    int t=(float)total_tat / (float)n;
    printf("Average waiting time = %d",s);
    printf("\n");
    printf("Average turn around time = %d ",t);
}
int main()
{
    display_name();
    int n,processes[100],burst_time[100];
    //int processes[] = { 1, 2, 3};
    printf("\n enter number of Processes\n");
    scanf("%d",&n);
    printf("\n enter process number");
    for (int i=0; i<n; i++){
        scanf("%d",&processes[i]);
    }
    //int n = sizeof processes / sizeof processes[0];
    printf("\n enter burst time:");
    for (int i=0; i<n; i++){
        scanf("%d",&burst_time[i]);
    }
    //int  burst_time[] = {10, 5, 8};
    findavgTime(processes, n,  burst_time);
    return 0;
}