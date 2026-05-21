# include <stdio.h>
int main(){
    int page , frame , index =0 , found,hit = 0 , miss = 0;
    int idx , position , farthest;
    printf("Enter the number of pages : ");
    scanf("%d",&page);
    printf("Enter the number of frames : ");
    scanf("%d",&frame);
    int frames[frame];
    for(int i = 0 ; i < frame ; i++){
        frames[i] = -1;
    }
    int pages[page];
    printf("Enter the reference string : \n");
    for(int i = 0 ; i < page ; i++){
        scanf("%d",&pages[i]);
    }
    printf("The reference string: \n");
    for(int i = 0 ; i < page ; i++){
        printf("%d  ",pages[i]);
    }

    printf("\n");
    printf("Reference\t Frames\t\tMiss/Hit\n");
    for(int i = 0 ; i < page ; i++){
        found = 0;
        for(int j = 0 ; j < frame ; j++){
            if(frames[j] == pages[i]){
                found = 1;
                hit ++;
                break;
            }
        }
        if(!found){
            miss ++;
            if(i < frame){
                frames[i] = pages[i];
            }
        else{
            position = -1 ; farthest = -1;
            for(int j = 0 ; j < frame ; j++){
                idx = -1;
                for(int k = i + 1 ; k < page ; k++){
                    if(frames[j] == pages[k]){
                        idx = k;
                        break;
                    }
                }
                if(idx == -1){
                    position = j;
                    break;
                }
                if(idx > farthest){
                    farthest = idx;
                    position = j;
                }
            }
            frames[position] = pages[i];
        }}
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