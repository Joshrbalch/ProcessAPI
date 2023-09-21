#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        // This code executes in the child process
        printf("Child Process - PID: %d\n", getpid());
        sleep(2); // Simulate some work in the child process
    } 
    
    else if (pid > 0) {
        // This code executes in the parent process
        printf("Parent Process - PID: %d\n", getpid());

        int status;
        pid_t child_pid = wait(&status);

        printf("Parent Process - Child Process (PID %d) has finished.\n", child_pid);

        if (WIFEXITED(status)) {
            printf("Parent Process - Child exited with status: %d\n", WEXITSTATUS(status));
        } else if (WIFSIGNALED(status)) {
            printf("Parent Process - Child process terminated by signal: %d\n", WTERMSIG(status));
        }
    } 
    
    else {
        // Fork failed
        fprintf(stderr, "Fork failed\n");
        return 1;
    }

    return 0;
}
