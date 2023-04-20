#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[], char* envp[])
{
    pid_t p = fork();
    if (p > 0)
    {
		int i = 0;
		for(; i < 1000; i++)
		{
			printf("%d\n", i);
		}
    }
	if (p == 0)
	{
		execvp(argv[1], argv + 1);
	}
    return 0;
}
