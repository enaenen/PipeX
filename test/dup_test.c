#include <unistd.h>
#include <stdio.h>

int	main(void)
{
	int fd[2];
	int fd_temp;
	char buffer[7];

	pipe(fd);
	fd_temp = dup(fd[1]);
	printf("fd[1] : %d \n fd_temp : %d \n",fd[1], fd_temp);

	write(fd_temp, "Hello\n", 7);
	read(fd[0], buffer, 7);
	printf("%s", buffer);

	close(fd[0]);
	close(fd[1]);
	close(fd_temp);
}
