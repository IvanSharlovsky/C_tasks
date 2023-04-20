#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[], char* envp[])
{
    int i = 0;
    for (; i < argc; i++)
    {
    	printf(" %s", argv[i]);
    }
    if (i < argc)
    {
	printf(" %s\n", argv[i]);
    }
    if (argc == 1)
    {
	printf("\n");
    }
    return 0;
}
