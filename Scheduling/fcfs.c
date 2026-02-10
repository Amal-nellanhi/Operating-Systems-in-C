/* PROGRAM TO IMPLEMENT FCFS */
# include <stdio.h>
# include <stdlib.h>
double avg_tat = 0 , avg_wt = 0;

typedef struct Process{
    int id , arrival_time , burst_time, waiting_time,turn_around_time,completion_time;
}Process;

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

void fcfsScheduling(Process p[] , int n){
    int current_time = 0;
    for(int i = 0 ; i <n ; i++){
        if(current_time < p[i].arrival_time)
            current_time = p[i].arrival_time;
        p[i].completion_time = current_time + p[i].burst_time;
        p[i].turn_around_time = p[i].completion_time - p[i].arrival_time;
        p[i].waiting_time = p[i].turn_around_time - p[i].burst_time;
        current_time = p[i].completion_time;
    }
}

void displayProcesses(Process p[] , int n){
    printf("Process\tAT\tBt\tTAT\tCT\tWT\n");
    for(int i = 0 ; i < n ; i ++){
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t\n",p[i].id,p[i].arrival_time,p[i].burst_time,p[i].turn_around_time,p[i].completion_time,p[i].waiting_time);
        avg_tat += p[i].turn_around_time;
        avg_wt += p[i].waiting_time;
    }
}

int main(){
    int n;
    printf("Enter the number of processes : \n");
    scanf("%d",&n);
    Process p[n];
    for(int i = 0 ; i < n ; i++){
        printf("Enter arrival time and burst time (AT BT):\n");
        p[i].id = i+1;
        scanf("%d%d",&p[i].arrival_time , &p[i].burst_time);
    }
    sortByArrivaltime(p,n);
    fcfsScheduling(p,n);
    displayProcesses(p,n);
    printf("Avergae waiting time = %.2f\n",avg_wt/n);
    printf("Avergae turn around time = %.2f\n",avg_tat/n);
    return 0;
}


