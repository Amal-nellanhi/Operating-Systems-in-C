/* ARRAY PROCESSING USING PIPE */
# include<stdio.h>
# include<unistd.h>
# include<sys/types.h>
# include<sys/wait.h>
int main(){
    int fd[2] , n;
    printf("Enter the size of the array :\n");
    scanf("%d",&n);
    int sum , arr[n];
    if(pipe(fd) == -1){
        printf("Error in pipe creation !!\n");
        return 1;
    }
    if(fork() == 0 ){
        read(fd[0],&arr,sizeof(arr));
        close(fd[0]);
        for(int i = 0 ; i < n ; i ++){
            sum += arr[i];
        }
        write(fd[1],&sum,sizeof(sum));
        close(fd[1]);
    }
    else{
        printf("Enter the array elements :\n");
        for(int i = 0 ; i < n ; i ++ ){
            scanf("%d",&arr[i]);
        }
        write(fd[1],&arr,sizeof(arr));
        close(fd[1]);
        wait(NULL);
        read(fd[0],&sum,sizeof(sum));
        close(fd[0]);
        printf("The sum is %d\n",sum);
    }
    return 0;
}