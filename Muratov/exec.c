#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[], char* envp[])
{
    execvp(argv[1], argv + 1);
    return 0;
}
