#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	printf("execute is\n");
	execl("/bin/ls", "ls","-al",NULL);
	printf("here-====================");
	return 0;
}
