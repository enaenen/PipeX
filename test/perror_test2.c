#include <stdio.h>
#include <unistd.h>

int main(void)
{
	int fd[2];
	char buffer[30];

	pipe(fd);
	dup2(fd[1], 2);
	perror("ERROR");
	read(fd[0], buffer, 30);
	printf("%s", buffer);
}
