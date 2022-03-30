#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	printf("Argument count is %d \n", argc);

	int i = 0;
	printf ("Argument list\n");
	for (i = 0; i < argc; i++)
		printf("<%d> : %s \n", i , argv[i]);
	return 0;
}
