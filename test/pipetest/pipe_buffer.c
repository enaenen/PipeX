#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>

int main()
{
	int fd[2];
	int i;

	i = 0;
	pipe(fd);
	fcntl(fd[1], F_SETFL, O_NONBLOCK);
	while (write(fd[1], "x", 1) > 0)
		i++;
	if (errno == EAGAIN)
		printf("pipe buffer size : %d \n", i);
	else
		perror("write to pipe");

}
