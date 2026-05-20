# include <stdio.h>
# include <stdlib.h>
int main(){
    int cylinders,head,n,count = 0,seek_time , dist ,idx;
    printf("Enter the number of cylinders: ");
    scanf("%d",&cylinders);
    printf("Enter the seek time per cylinder: ");
    scanf("%d",&seek_time);
    printf("Enter the number of requests: ");
    scanf("%d",&n);
    int request[n];
    int visited[n];
    printf("Enter the requests in order: \n");
    for(int i = 0 ; i < n ; i++){
        scanf("%d",&request[i]);
        visited[i] = 0;
        if(request[i] < 0 || request[i] > cylinders -1){
            printf("Invalid request !!");
            exit(1);
        }
    }
    printf("Enter the initial head position: ");
    scanf("%d",&head);
    printf("Order of service \n");
    printf("%d",head);
    // Servicing requests in SSTF order
    for(int i = 0 ; i < n ; i ++){
        int min_dist = 999999;
        for(int j = 0 ; j < n ; j++){
            if(!visited[j]){
                dist = abs(request[j] - head);
                if(dist < min_dist){
                    min_dist = dist;
                    idx = j;
                }
            }
        }
        visited[idx] = 1;
        head = request[idx];
        count += min_dist;
        printf(" -> %d",head);
    }
    printf("\nThe total no of head movements = %d ",count);
    printf("Total seek time = %d",count * seek_time);
    
    return 0;
}