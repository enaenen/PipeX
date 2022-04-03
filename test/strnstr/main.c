#include <stdlib.h>
#include <stdio.h>

char	*ft_strnstr(const char *, const char *, size_t);

int main(void)
{
	char *str;
	char *src = "ABCDEFG";

	str = ft_strnstr(src, "BA", 10);
	printf("%s\n", str);
}
