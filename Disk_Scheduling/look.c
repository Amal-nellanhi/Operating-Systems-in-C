# include <stdio.h>
# include <stdlib.h>
int main(){
    int cylinders,head,n,count = 0,seek_time,pos;
    int dir;
    printf("Enter the number of cylinders: ");
    scanf("%d",&cylinders);
    printf("Enter the seek time per cylinder: ");
    scanf("%d",&seek_time);
    printf("Enter the direction of servicing: \n 1. L -> R \n 2. R -> L\n 1 or 2 ? \n");
    scanf("%d",&dir);
    if(dir != 2 && dir != 1){
        printf("Input error !");
        return 1;
    }
    printf("Enter the number of requests: ");
    scanf("%d",&n);
    int request[n];
    printf("Enter the requests in order: \n");
    for(int i = 0 ; i < n ; i++){
        scanf("%d",&request[i]);
        if(request[i] < 0 || request[i] > cylinders -1){
            printf("Invalid request !!");
            exit(1);
        }
    }
    printf("Enter the initial head position: ");
    scanf("%d",&head);
    printf("Order of service \n");
    printf("%d",head);
    // Sort the requests using bubble sort
    for(int i = 0 ; i < n -1 ; i++){
        for(int j = 0 ; j < n-i-1 ; j++){
            if(request[j] > request[j+1]){
                int temp = request[j+1];
                request[j+1] = request[j];
                request[j] = temp;
            }
        }
    } 

    // Finding the position (Request > head)
    for(int i = 0 ; i < n ; i++){
        if(request[i] > head){
            pos = i;
            break;
        }
    }

    if(dir == 1){
    // Servicing requests in LOOK (L -> R)
        for(int i = pos ; i < n ; i ++){
            count += abs(request[i] - head);
            head = request[i];
            printf(" -> %d",head);
        }

        for(int i = pos-1 ; i >=0 ; i --){
            count += abs(request[i] - head);
            head = request[i];
            printf(" -> %d",head);
        }
    }
    if(dir == 2){
        for(int i = pos-1 ; i >=0 ; i --){
            count += abs(request[i] - head);
            head = request[i];
            printf(" -> %d",head);
        }
        for(int i = pos ; i < n ; i ++){
            count += abs(request[i] - head);
            head = request[i];
            printf(" -> %d",head);
        }
    }
    printf("\nThe total no of head movements = %d ",count);
    printf("Total seek time = %d",count * seek_time);
    
    return 0;
}