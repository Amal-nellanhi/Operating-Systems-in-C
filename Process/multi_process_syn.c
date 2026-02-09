/* MULTIPLE PROCESS SYNCHRONIZATION */
/***
 * Output
 * CS
 * Operating
 * Systems
 * Lab
 */

# include <stdio.h>
# include <sys/types.h>
# include <unistd.h>
# include <sys/wait.h>
# include <stdlib.h>
int main(){
    pid_t pid;
    printf("CS\n");
    pid = fork();
    if(pid == 0){
        printf("Operating\n");
        pid = fork();
        if(pid == 0){
            printf("Systems\n");
            pid = fork();
            if(pid == 0){
                printf("Lab\n");
                exit(0);
            }
            wait(NULL);
            exit(0);
        }
        wait(NULL);
        exit(0);   
    }
    wait(NULL);
    return 0;
}