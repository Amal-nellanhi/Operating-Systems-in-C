/* PROGRAM TO IMPLEMENT PROCESS SYNCHRONIZATION */
// Output : PCCSL407 Operating Systems Lab
// Child prints PCCSL407
// Parent prints Operating Systems Lab

# include <stdio.h>
# include <sys/types.h>
# include <unistd.h>
# include <sys/wait.h>
int main(){
    pid_t pid = fork();
    if(fork < 0){
        printf("Forking Failed !!\n");
    }
    else if(pid == 0){
        printf("PCCSL407 ");
    }
    else{
        wait(NULL);
        printf("Operating Systems Lab\n");
    }
    return 0;
}