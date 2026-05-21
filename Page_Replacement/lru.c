# include <stdio.h>
int main(){
    int page , frame , index =0 , found,hit = 0 , miss = 0,count = 0;
    printf("Enter the number of pages : ");
    scanf("%d",&page);
    printf("Enter the number of frames : ");
    scanf("%d",&frame);
    int frames[frame] , time[frame];
    for(int i = 0 ; i < frame ; i++){
        frames[i] = -1;
        time[i] = 0;
    }
    int pages[page];
    printf("Enter the reference string : \n");
    for(int i = 0 ; i < page ; i++){
        scanf("%d",&pages[i]);
    }
    printf("Reference\t Frames\t\tMiss/Hit\n");
    for(int i = 0 ; i < page ; i++){
        found = 0;
        for(int j = 0 ; j < frame ; j++){
            if(frames[j] == pages[i]){
                found = 1;
                hit ++; count ++;
                time[j] = count;
                break;
            }
        }
        if(found == 0){
            miss ++; 
            if(i<frame){
                frames[i] = pages[i];
                count ++;
                time[i] = count;
            }
            else{
                int lru = 0;
                for(int j = 1 ; j < frame ; j++){
                    if(time[j] < time[lru])
                        lru = j;
                }
                frames[lru] = pages[i];
                count ++;
                time[lru] = count;
            }
        }
        printf("%d\t\t",pages[i]);
        for(int j = 0 ; j < frame ; j ++){
            if(frames[j] == -1)
                printf(" - ");
            else
                printf(" %d ",frames[j]);
        }
        if(found)
            printf("\tHit");
        else
            printf("\tMiss");
        printf("\n");
    }

    printf("Number of page miss = %d\n",miss);
    printf("Number of page hit = %d\n",hit);
    printf("Hit rate = %.2f\n",(float)hit / page);
    printf("Miss rate = %.2f\n",(float)miss / page);

    return 0;
    
}