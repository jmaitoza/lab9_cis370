#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

#define SIZE 128

int main (int argc, char *argv[])
{
  pid_t pid;
  int pipeFD[2];
  char buffer[SIZE];
  int fd1, fd2; // file 1 input file, file 2 output file
  int nread1, nread2;

  pipe(pipeFD); // set up pipe

  if (argc != 3) {
    printf("Not enough arguments!\n");
    exit(-1);
  }

  if (fork() == 0) { // Child Process
    fd2 = open(argv[2], O_WRONLY); //open output file
    if (fd2 == -1) {
      printf("Error could not open the file\n");
      return -1;
    }
    nread2 = read(pipeFD[0], buffer, SIZE); // read data from downstream end of pipe
    write(fd2, buffer, nread2); // write to output file

    close(pipeFD[0]); ///close downstream
    exit(0);
  }

  // Parent Process
  fd1 = open(argv[1], O_RDONLY); 
  if (fd1 == -1) {
    printf("Error could not open the file\n");
    return -1;
  }

  nread1 = read(fd1, buffer, SIZE); // read input file
  write(pipeFD[1], buffer, nread1); // write data to upstream end of pipe
  close(pipeFD[1]); //close upstream
  wait(NULL); //wait for child

  exit(0); 
  
  return 0;
}
