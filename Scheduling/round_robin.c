# include <stdio.h>
# include <stdlib.h>
typedef struct Process{
    int id, arrival_time , burst_time, waiting_time , turn_time,remaining_time,completion_time;
} Process;

float avg_tat = 0 , avg_wt = 0 ;

void sortByArrivaltime(Process p[] , int n){
    for(int i = 0 ; i < n-1 ; i ++){
        for(int j = 0 ; j < n-i-1 ; j++){
            if(p[j].arrival_time > p[j+1].arrival_time){
                Process temp = p[j];
                p[j] = p [j+1];
                p[j+1] = temp;
            }
        }
    }
}

void roundr_Scheduling(Process p[],int n ,int tq){
    int completed = 0 ,current_time = 0;
    while(completed < n){
        int found = 0;
        for(int i = 0 ; i< n ; i++){
            if(p[i].arrival_time <= current_time && p[i].remaining_time > 0){
                found = 1;
                if(p[i].remaining_time > tq){
                    p[i].remaining_time -= tq;
                    current_time += tq;
                }
                else{
                    current_time += p[i].remaining_time;
                    p[i].completion_time = current_time;
                    p[i].remaining_time = 0;
                    completed ++;
                    p[i].turn_time = p[i].completion_time - p[i].arrival_time;
                    p[i].waiting_time = p[i].turn_time - p[i].burst_time;

                }
            }
        }
        if(!found){
            current_time ++;
        }
    }

}

void displayProcesses(Process p[] , int n){
    printf("Process\tAT\tBt\tTAT\tCT\tWT\n");
    for(int i = 0 ; i < n ; i ++){
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t\n",p[i].id,p[i].arrival_time,p[i].burst_time,p[i].turn_time,p[i].completion_time,p[i].waiting_time);
        avg_tat += p[i].turn_time;
        avg_wt += p[i].waiting_time;
    }
}

int main(){
    int n,tq;
    printf("Enter the number of processes : ");
    scanf("%d",&n);
    Process p[n];
    printf("Enter the AT and BT of processes : ");
    for(int i = 0 ; i < n ; i++){
        scanf("%d%d",&p[i].arrival_time,&p[i].burst_time);
        p[i].id = i+1;
        p[i].remaining_time = p[i].burst_time;
    }
    printf("Enter the time quantum: ");
    scanf("%d",&tq);
     sortByArrivaltime(p,n);
     roundr_Scheduling(p,n,tq);
     displayProcesses(p,n);
     printf("Avergae waiting time = %.2f\n",avg_wt/n);
    printf("Avergae turn around time = %.2f\n",avg_tat/n);
    return 0;
}