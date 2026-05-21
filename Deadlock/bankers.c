# include <stdio.h>
int main(){
    int n , m ,count =0,found;
    printf("Enter the number of processes : ");
    scanf("%d",&n);
    printf("Enter the number of resource types : ");
    scanf("%d",&m);
    int max[n][m],need[n][m],alloc[n][m],avail[m],finish[n],safeseq[n];
    for(int i = 0 ; i < n ; i++)
        finish[i] = 0;
    printf("Enter the Maximum matrix: \n");
    for(int i = 0 ; i < n ; i ++){
        for(int j = 0 ; j < m ; j++){
            scanf("%d",&max[i][j]);
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
    
    // calculate need matrix
    for(int i = 0 ; i < n ; i ++){
        for(int j = 0 ; j < m ; j++){
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }
    while(count < n){
        found = 0;
        for(int i = 0 ; i < n ; i++){
            if(!finish[i]){
                int flag = 1;
                for(int j = 0 ; j < m ; j++){
                    if(need[i][j] > avail[j]){
                        flag = 0;
                        break;
                    }
                }
                if(flag == 1){
                    for(int k = 0 ; k < m ; k++){
                        avail[k] += alloc[i][k];
                    }
                    safeseq[count] = i;
                    count ++;
                    finish[i] = 1;
                    found = 1;    
                    }
                }
            }
        if(found == 0){
            break;
        }
    }
    if(count == n){
        printf("The system is in safe state\n");
        printf("The safe sequence\n");
        for(int i = 0 ; i < count ; i++){
            printf("P%d  ",safeseq[i]);
        }
    }
    else
        printf("The system is not in safe state");
    return 0;

}