/* EXPRESSION EVALUATION USING PIPE */
# include<stdio.h>
# include<unistd.h>
# include<math.h>
# include<sys/types.h>
int main(){
    int fd[2];
    int a,b,c,four_ac,b_square;
    double result;
    printf("Enter the values of a , b , c :\n");
    scanf("%d%d%d",&a,&b,&c);
    if(pipe(fd) == -1){
        printf("Error in pipe creation !!\n");
        return 1;
    }
    if(fork() == 0 ){
        close(fd[0]);
        four_ac = 4*a*c;
        write(fd[1],&four_ac,sizeof(four_ac));
        close(fd[1]);
    }
    else{
        close(fd[1]);
        b_square = b * b;
        read(fd[0],&four_ac,sizeof(four_ac));
        close(fd[0]);
        result = sqrt(b_square - four_ac);
        printf("The result is %.2lf\n",result);
    }
    return 0;
}