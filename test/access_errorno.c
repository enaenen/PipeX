#include <string.h>
#include <stdio.h>
#include <unistd.h>

int main(void)
{

	printf("txt 실행 %d\n", access("./test.txt", X_OK));
	printf("%s\n", strerror(13));

	printf("\n존재하지 않는 파일 : %d\n",access("./none", R_OK));
	printf("%s\n", strerror(2));
}
