#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        // This code executes in the child process
        printf("Child Process - Executing /bin/ls using various exec variants:\n");

        // Variant 1: execl() - List of arguments
        execl("/bin/ls", "ls", "-l", NULL);

        // Variant 2: execle() - List of arguments with environment
        char* env[] = { "PATH=/bin", NULL };
        execle("/bin/ls", "ls", "-l", NULL, env);

        // Variant 3: execlp() - List of arguments with PATH lookup
        execlp("ls", "ls", "-l", NULL);

        // Variant 4: execv() - Array of arguments
        char* args[] = { "ls", "-l", NULL };
        execv("/bin/ls", args);

        // Variant 5: execvp() - Array of arguments with PATH lookup
        execvp("ls", args);

        // Variant 6: execvpe() - Array of arguments with environment and PATH lookup
        char* envp[] = { "PATH=/bin", NULL };
        execvpe("ls", args, envp);

        // If any of the exec variants fail, print an error
        perror("Exec failed");
        exit(1);
    } 
    
    else if (pid > 0) {
        // This code executes in the parent process
        printf("Parent Process - Child process is executing /bin/ls.\n");
    } 
    
    else {
        // Fork failed
        fprintf(stderr, "Fork failed\n");
        return 1;
    }

    return 0;
}
