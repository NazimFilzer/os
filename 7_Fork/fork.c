#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){

    int pid;
    pid=fork();

    if (pid<0){
        
        printf("fork failed");
    }
    else if(pid==0){
        printf("Inside Child Process!\n");
        printf("Successfully forked process\n");
        printf("PID: %d\n", getpid());
        exit(0);
    }
    else{
        printf("Process Id: %d\n", getpid());
        exit(0);
    }
    
}
