#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    
    setenv("MY_COMMAND", "ls", 1);
    pid_t pid;
    pid = fork();
    
    if (pid < 0) {
        perror("fork thất bại");
        exit(1);
    }
  
    else if (pid == 0) {
       char *command = getenv("MY_COMMAND");
         if (command != NULL) {
         execlp(command, command, "-l", NULL);
}
    }
    return 0;
}

//Sau khi exec() thành công, tiến trình vẫn giữ nguyên:​
//PID  không thay đổi
//PPID  không thay đổi
// không gian địa chỉ của tiến trình con bị thahy thế bởi chương chình mới