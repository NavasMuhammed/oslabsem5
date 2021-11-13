#include <stdio.h>

void calculateWaitings(int arr[],int n, int bt[],int wt[]){
    wt[0] = 0;
    for(int i=1;i<n;i++){
        wt[i]= wt[i-1]+bt[i-1];
    }
}
void calculateTurnAroundTime(int arr[] , int n , int bt[], int wt[],int tat[]){
    for(int i=0;i<n;i++){
        tat[i]= wt[i]+bt[i];
    }
}
void calculateAvgTime(int arr[] , int n , int bt[]){
    int tat[100],wt[100],totalwt=0,totaltat=0;
    calculateWaitings(arr,n,bt,wt);
    calculateTurnAroundTime(arr,n,bt,wt,tat);
    printf("printing the waiting time");
    for(int i=0;i<n;i++){
        printf("\n %d",wt[i]);
    }
    printf("printing the turn around time");
    for(int i=0;i<n;i++){
        printf("\n %d",tut[i])
    }
}

void main() {
    int n, arr[100],bt[100];
    printf("Enter the number of processes");
    scanf("%d",&n);
    printf("Enter the process ids");
    for(int i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter the burst time for each process");
    for(int i=0;i<n;i++){
        scanf("%d",&bt[i]);
    }
    calculateAvgTime(arr,n,bt);
}