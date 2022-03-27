#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
char *pkt[2] = {
    "Hello there from CIS370",
    "Hope you have been enjoying the lab"};
int main(int argc, char *argv[])
{
    int pipeFD[2];
    int charCount;
    char buffer[32];
    pipe(pipeFD); /* set up pipe */
    if (fork() == 0)
    {

    }

    return 1;
}
