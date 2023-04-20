#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    pid_t p = fork();
    pid_t pp = getppid();
    if(p > 0)
    {
	printf("Main process parent id %d\n", getppid());
	printf("Main process id %d\n", getpid());
    }
    if(p == 0)
    {
	printf("Child process parent id %d\n", pp);
	printf("Child process id %d\n", getpid());
    }
    return 0;
}

