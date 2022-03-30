#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define SIZE 128

int main (int argc, char *argv[])
{
  char usrInput;       
  char outBuffer[SIZE];
  int fd;
  int count = 1;

  fd = open(argv[1], O_WRONLY | O_TRUNC | O_CREAT, 0644); // O_TRUNC clears contents of file if it is not empty

  
  int stdio_var = dup(1); // checks whats currently in stdout


  //Waiting for user input
  while (1) {
    scanf(" %c", &usrInput); // take usr input

    if (usrInput == 'f' || usrInput == 'F') { 
      dup2(fd,1); // changes fd to point to outbuffer 
    }

    if (usrInput == 's' | usrInput == 'S') {
      dup2(stdio_var, 1); // changes stdout to point to outbuffer
    }

    if (usrInput == '0') {
      dup2(stdio_var, 1);
      printf("Exiting...");
      break;
    }

    sprintf(outBuffer, "Nights spend maidenless %d\n", count);
    write(1, outBuffer, strlen(outBuffer));  
    count++;
  }
  close(fd);
  return 0;
}
