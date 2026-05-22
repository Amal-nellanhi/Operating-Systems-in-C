# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <math.h>
int a [5] = {10,20,30,40,50} , n = 5;
float mean , median ,std;

void* find_mean(void * arg){
    int sum = 0;
    for(int i = 0 ; i < n ; i++){
        sum += a[i];
        mean = (float)sum /n;
    }
    pthread_exit(NULL);
}

void* find_median(void *arg){
    int temp;
    for(int i = 0 ;i < n-1 ; i++){
        for(int j = 0 ; j < n-i-1 ; j++){
            if(a[j] > a[j+1]){
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    if(n%2 == 0){
        median = (float)(a[n/2] + a[(n/2)-1]) /2;
    }
    else{
        median = a[n/2];
    }
    pthread_exit(NULL);
}

void* find_std(void *arg){
    int sum = 0;
    for(int i = 0 ; i < n ; i++){
        sum += (a[i] - mean) * (a[i] - mean);
    }
    std = sqrt(sum/n);
    pthread_exit(NULL);
}

int main(){
    pthread_t t1,t2,t3;
    pthread_create(&t1,NULL,find_mean,NULL);
    pthread_join(t1,NULL);
    pthread_create(&t2,NULL,find_median,NULL);
    pthread_join(t2,NULL);
    pthread_create(&t3,NULL,find_std,NULL);
    pthread_join(t3,NULL);
    printf("The mean = %0.2f\n",mean);
    printf("The median = %0.2f\n",median);
    printf("The std = %0.2f",std);
    return 0;
}