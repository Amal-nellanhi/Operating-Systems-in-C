# include <stdio.h>
int main(){
    int n , m ,count =0,found;
    printf("Enter the number of processes : ");
    scanf("%d",&n);
    printf("Enter the number of resource types : ");
    scanf("%d",&m);
    int req[n][m],alloc[n][m],avail[m],finish[n],safeseq[n];
    for(int i = 0 ; i < n ; i++)
        finish[i] = 0;
    printf("Enter the Request matrix: \n");
    for(int i = 0 ; i < n ; i ++){
        for(int j = 0 ; j < m ; j++){
            scanf("%d",&req[i][j]);
        }
    }
    printf("Enter the Allocation matrix: \n");
    for(int i = 0 ; i < n ; i ++){
        for(int j = 0 ; j < m ; j++){
            scanf("%d",&alloc[i][j]);
        }
    }
    printf("Enter the Available matrix: \n");
    for(int i = 0 ; i < m ; i++)
        scanf("%d",&avail[i]);
    count = 1;
    while(count){
        count = 0;
        for(int i = 0 ; i < n ; i++){
            if(!finish[i]){
                int flag = 1;
                for(int j = 0 ; j < m ; j++){
                    if(req[i][j] > avail[j]){
                        flag = 0;
                        break;
                    }
                }
                if(flag == 1){
                    for(int k = 0 ; k < m ; k++){
                        avail[k] += alloc[i][k];
                    }
                    finish[i] = 1;
                    count = 1;    
                    }
                }
            }
    }
    int deadlock = 0;
    for(int i = 0 ; i < n ; i++){
        if(finish[i]== 0){
            deadlock = 1;
            printf("Process P%d is in deadlock\n",i);
        }}
    if(!deadlock){
        printf("No deadlock detected\n");
    }
    return 0;


}