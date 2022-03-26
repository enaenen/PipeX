#include <stdio.h>
#include <unistd.h>

int main(void)
{
	char *is_txt = "./test.txt";
	char *is_exe = "./a.exe";

	printf("txt읽기 : %d\n", access(is_txt, R_OK));
	printf("txt쓰기 : %d\n", access(is_txt, W_OK));
	printf("txt실행 : %d\n", access(is_txt, X_OK));
	printf("txt존재 : %d\n", access(is_txt, F_OK));
	
	printf("exe읽기 : %d\n", access(is_exe, R_OK));
	printf("exe쓰기 : %d\n", access(is_exe, W_OK));
	printf("exe실행 : %d\n", access(is_exe, X_OK));
	printf("exe존재 : %d\n", access(is_exe, F_OK));
}
