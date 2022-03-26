#include <stdio.h>
#include <unistd.h>

int main(void)
{
	int fd[2];

	pipe(fd);
	dup2(fd[1], 2);
	perror("ERROR!");

}
