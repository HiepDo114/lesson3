#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    int status;
    

    pid = fork();
    
    if (pid < 0) {
        
        perror("Fork thất bại");
        exit(1);
    }
    else if (pid == 0) {
        
        printf("PID của tiến trình con: %d\n", getpid()); 
        sleep(2);
        exit(10); 
    }
    else {
        
       
        printf("PID của tiến trình cha: %d\n", getpid());
        printf("PID của tiến trình con : %d\n", pid);
        
        wait(&status);
    
        if (WIFEXITED(status)) {
            int exit_code = WEXITSTATUS(status);
            printf("Mã thoát của tiến trình con: %d\n", exit_code);
        }
        else {
            printf("Tiến trình con fail\n");
        }
        
        printf("\nTiến trình cha kết thúc.\n");
    }
    
    return 0;
}