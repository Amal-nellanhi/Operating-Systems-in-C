/* PROGRAM TO IMPLEMENT FCFS */
# include <stdio.h>
# include <stdlib.h>
double avg_tat = 0 , avg_wt = 0;

typedef struct Process{
    int id , arrival_time , burst_time, waiting_time,turn_around_time,completion_time, comp,priority;
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

void priorityScheduling(Process p[] , int n){
    int current_time = 0, completed = 0, shortest ;
    while(completed < n){
        int found = 0 , min = 9999;
        for(int i = 0 ; i < n ; i++){
            if(p[i].arrival_time <= current_time && p[i].comp == 0 && p[i].priority < min){
                min = p[i].priority;
                shortest = i;
                found = 1;
            }
        }
        if(!found){
            current_time ++;
            continue;
        }
        current_time += p[shortest].burst_time;
        p[shortest].comp = 1;
        p[shortest].completion_time = current_time;
        p[shortest].turn_around_time = p[shortest].completion_time - p[shortest].arrival_time;
        p[shortest].waiting_time = p[shortest].turn_around_time - p[shortest].burst_time;
        completed++;
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
        printf("Enter arrival time and burst time (AT BT Priority):\n");
        p[i].id = i+1; p[i].comp = 0;
        scanf("%d%d%d",&p[i].arrival_time , &p[i].burst_time,&p[i].priority);
    }
    sortByArrivaltime(p,n);
    priorityScheduling(p,n);
    displayProcesses(p,n);
    printf("Avergae waiting time = %.2f\n",avg_wt/n);
    printf("Avergae turn around time = %.2f\n",avg_tat/n);
    return 0;
}


