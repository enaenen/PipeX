#include <unistd.h>

int main(int argc, char **argv)
{
	char *envp[] = {0};

	execve("/bin/mv", argv, envp);
	return (0);
}
