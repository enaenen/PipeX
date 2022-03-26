#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>

int main(void)
{
	pid_t	pid;
	pid_t	wait_res;
	int	status;

	pid = fork();
	if (pid == 0)
	{
		printf("\n****자식프로세스****\n");
		sleep(2);
		printf("자식프로세스 종료\n");
	}
	else
	{
		wait_res = wait(&status);
		printf("\n****부모프로세스****\n");
		sleep(1);
		printf("부모프로세스 종료\n");
		printf("wait 인자값 : %d\nwait 반환값 : %d\n", status, wait_res);
		printf("자식pid : %d\n", pid);
	}
}
