#include <stdio.h>

int main(int argc, char **envp)
{
	int i;
	
	i = 0;
	while (i < 80)
	{
		printf("<%d> %s\n", i, envp[i]);
		i++;
	}
}
