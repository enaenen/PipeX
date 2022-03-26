#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>

int	main(void)
{
	pid_t wait_res;
	pid_t pid;
	int status;

	pid = fork();

	if (pid == 0)
	{
		printf("\n****자식 프로세스****\n");
		sleep(4);
		printf("자식프로세스 종료\n");
	}
	else
	{
		wait_res = waitpid(pid, &status, WNOHANG);
		printf("\n****부모프로세스****\n");
		sleep(1);
		printf("부모프로세스 종료\n");
		printf("\nwaitpid인자값: %d\nwaitpid반환값: %d\n", status, wait_res);
	}
}
