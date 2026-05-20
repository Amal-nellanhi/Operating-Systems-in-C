# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# define CYLINDER 5000
# define MAX 10
int main(int argc , char * argv[]){
    if(argc != 2){
        printf("Incorrect usage !");
        exit(1);
    }
    srand(time(NULL));
    int head = atoi(argv[1]),count = 0,seek_time;
    int request[MAX];
    printf("Enter the seek time per cylinder: ");
    scanf("%d",&seek_time);
    for(int i = 0 ; i < MAX ; i++){
        request[i] = rand() % CYLINDER;
    }
    printf("Order of service \n");
    printf("%d",head);
    // Servicing requests in FCFS order
    for(int i = 0 ; i < MAX ; i ++){
        count += abs(request[i] - head);
        head = request[i];
        printf(" -> %d",head);
    }
    printf("\nThe total no of head movements = %d ",count);
    printf("Total seek time = %d",count * seek_time);
    
    return 0;
}  