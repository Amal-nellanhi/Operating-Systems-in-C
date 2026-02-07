/* Create a new process using a fork system call. Print the parent and child process IDs. Use the pstree command to
find the process tree for the child process starting from the initprocess.*/

# include <stdio.h>
# include <sys/types.h>
# include <unistd.h>

int main(){
    pid_t  pid;
    pid = fork();
    if(pid < 0){
        printf("Forking Failed !!");
    }
    else if(pid == 0){
        // CHILD PROCESS
        printf("Child process\n");
        printf("Child PID = %d\n",getpid());
        printf("Parent PID = %d\n",getppid());
        sleep(100);
    }
    else{
        // PARENT PROCESS
        printf("Parent process\n");
        printf("Child PID = %d\n",pid);
        printf("Parent PID = %d\n",getpid());
        sleep(100);
    }
    return 0;
}