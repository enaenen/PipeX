#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int	main(void)
{
	int fd1, ret;
	char message[32] = {"STDERR from fd1\n"};

	fd1 = open ("made_by_fd1", O_RDWR | O_CREAT , S_IRUSR | S_IWUSR);
	if (fd1 < 0)
	{
		printf("File open Error\n");
		exit(0);
	}
	printf("File open \n");

	//STDOUT IS NOW FD1
	ret = dup2(fd1, STDOUT_FILENO);
	printf("fd1 : %d, ret : %d\n", fd1, ret);

	//fd1 IS NOW STDERR_FILENO(3)
	ret = dup2(STDERR_FILENO, fd1);
	write(fd1, message, strlen(message));

	printf("Using printf But writing on File\n");
	close(fd1);
}
