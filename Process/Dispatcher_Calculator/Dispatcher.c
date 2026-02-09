/* DISPATCHER FOR COMMAND LINE CALCULATOR */
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>
# include <sys/wait.h>
# include <string.h>
int main(int argc, char * argv[]){
    if(argc != 4){
        printf("Usage error , Usage %s [operation] [num1] [num2]\n",argv[0]);
        return 1;
    }
    pid_t pid = fork();
    if(pid < 0){
        printf("Forking Failed !!");
    }
    else if(pid == 0){
        printf("Child Executing operation code\n");
        char * args[] = {"./dispatcher",argv[1],argv[2],argv[3],NULL};
        execvp(args[0],args);
        perror("execvp failed");
    }
    else{
        wait(NULL);
        printf("Operation %s completed by child %d\n",argv[1],pid);
    }
    return 0;
}