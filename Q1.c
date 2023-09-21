#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
  pid_t pid;
  int status;
  int x;

  x = 100;
  pid = fork();

  if(pid == 0) {
    // This code executes in the child process
    printf("Child Process - Value of x = %d\n", x);
    x = 200;
    printf("Child Process - New Value of x = %d\n", x);
    exit(0); // Terminate the child process
  }

  else if(pid > 0) {
    // This code executes in the parent process
    wait(&status); // Wait for the child process to finish
    printf("Parent Process - Value of x = %d\n", x);
    x = 300;
    printf("Parent Process - New Value of x = %d\n", x);
    exit(0); // Terminate the parent process
  }

  else {
    // Fork failed
    printf("Fork failed\n");
    exit(1);
  }
}
