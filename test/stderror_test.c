#include <string.h>
#include <stdio.h>

int main(void)
{
	char *err;

	printf(" * * * 에러 메세지 * * * \n");
	for (int i = 0; i <= 100; i++)
	{
		err = strerror(i);
		printf("[%d]: %s \n", i, err);
	}
}
