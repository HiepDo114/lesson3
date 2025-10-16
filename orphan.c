#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid;
    pid = fork();
    
    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    }
    else if (pid == 0) {
        
        printf(" PID = %d, PPID  = %d\n", getpid(), getppid());
        sleep(50);
        printf(" PPID  = %d\n", getppid());
        exit(0);
    }
    else {
        exit(0);
    }
    return 0;
}
// PPID sau khi cha chết  = 1
// zombie giúp hệ điều hành truyền thông tin trạng thái tiến trình con cho tiến trình cha 
// kiểm soát tài nguyên
// orphan đảm bảo mọi tiến trình đều có cha quản lí khi còn sống , tránh tính trạng 
// tài nguyên bị dư khi tiến trình con kết thúc