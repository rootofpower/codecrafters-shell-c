#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool is_echo_command(const char *command);

int main(int argc, char *argv[]) {
  // Flush after every printf
  setbuf(stdout, NULL);

  
  char command[1024];

  while(1) {
    printf("$ ");
    fgets(command, sizeof(command), stdin);
    command[strcspn(command, "\n")] = 0; 
    if (strcmp(command, "exit") == 0) {
      break;
    }

    if(is_echo_command(command)) {
      printf("%s\n", command + 5);
      continue;
    }

    



    printf("%s: command not found\n", command);
  }
  return 0;
}

bool is_echo_command(const char *command) {
  return strncmp(command, "echo ", 5) == 0;
}