#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void) {
  char path[1000];
  while (1) {
    printf("Enter programs to run");
    if (fgets(path, sizeof(path), stdin) == NULL)
      break;

    path[strcspn(path, "\n")] = '\0';

    pid_t pid = fork();
    if (pid == 0) {
      execl(path, path, (char *)NULL);
      printf("Exec failure");
      return 1;
    }

    waitpid(pid, NULL, 0);
  }
  return 0;
}
