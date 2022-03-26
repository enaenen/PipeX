#include <unistd.h>
#include <stdio.h>

int main(void)
{
	int fd[2];
	int fd2[2];
	int temp_fd;
	char buffer[6];
	char buffer2[6];

	pipe(fd);
	pipe(fd2);
	printf("before : fd[1] = %d , fd2[1] = %d\n",fd[1], fd2[1]); 
	temp_fd = dup2(fd[1], fd2[1]);
	printf("temp_fd: %d\nfd[1] : %d\nfd2[1] : %d\n", temp_fd, fd[1], fd2[1]);
	write(fd2[1], "hello", 6);
	read(fd[0], buffer, 6);
	read(fd2[0], buffer2, 6);

	printf("\nfd[0] : %s\nfd2[0] : %s\n", buffer, buffer2);
}
