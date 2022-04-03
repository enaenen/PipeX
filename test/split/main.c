#include <stdio.h>
char **ft_split(const char *, char);
int	main(int argc, char **argv)
{
	char **splited_word;
	int	i;
	int	j;

	i = 0;
	j = i;
	splited_word = ft_split("!!A!!BC!DEF!G!!!!", '!');
	while (splited_word[i])
	{
		printf("%s \n", splited_word[i]);
		i++;
	}

}
