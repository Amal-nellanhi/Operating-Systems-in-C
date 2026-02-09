/* CHILD IS EXECUTING A DIFFERENT PROGRAM */
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>
# include <sys/wait.h>
 int main(int argc ,char * argv[]){
    pid_t pid;
    if(argc != 3){
        printf("Incorrect usage !! Usage -> %s [num1] [num2]",argv[0]);
        return 1;
    }
    pid = fork();
    if(pid < 0){
        printf("Forking Failed !!");
    }
    else if(pid == 0){
        char * args [] = {"./mymultiplier",argv[1],argv[2],NULL};
        printf("Child executing multiplier using execvp()\n");
        execvp(args[0],args);
        perror("execvp failed");
    }
    else{
        wait(NULL);
        printf("Parent: Child process completed !!\n");
    }
    return 0;
 }