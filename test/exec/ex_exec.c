#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		printf("Usage : %s <exec path>" , "[arg0, arg1, arg2, ...]");
		return 1;
	}

	pid_t pid = fork();
	if (pid < 0)
	{
		perror("fork error");
		return 1;

	}
	if (pid == 0)
		wait(0);
	else
	{
		execv(argv[1], argv + 1);
		return 0;
	}
	return 0;
}
