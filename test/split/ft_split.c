/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchae <wchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 16:41:40 by wchae             #+#    #+#             */
/*   Updated: 2022/04/03 17:27:02 by wchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	alloc_check(char ***ret, int ret_len)
{
	int	i;
	int	err;

	i = 0;
	err = 0;
	while (i < ret_len)
	{
		if ((*ret)[i] == NULL)
			err = 1;
		i++;
	}
	if (!err)
		return (err);
	i = 0;
	while (i < ret_len)
	{
		if ((*ret)[i] != NULL)
			free((*ret)[i]);
		i++;
	}
	free(*ret);
	return (err);
}
static char	*ft_strndup(const char *src, int len)
{
	int	i;
	char	*dup;

	dup = malloc(sizeof(*src) * (len + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (i < len)
	{
		*(dup + i) = src[i];
		i++;
	}
	*(dup + i) = 0;
	return (dup);
}

static int 	word_cnt(char const *s, char c)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = 0;
	while (s[i])
	{
		j = i;
		while (s[i] != c && s[i])
			i++;
		if (i - j > 0)
			len++;
		else
			i++;
	}
	return (len);
}

static void	ret_word_cnt(const char *s, char c, int *i)
{
	while (s[*i] != c && s[*i])
		(*i)++;
}

char	**ft_split(const char *s, char c)
{
	int	i;
	int	j;
	int	k;
	char	**ret;

	if (!s)
		return (NULL);
	i = 0;
	k = 0;
	ret = malloc(sizeof(*ret) * (word_cnt(s, c) + 1));
	if (!ret)
		return (NULL);
	while (s[i])
	{
		j = i;
		ret_word_cnt(s, c, &i);
		if (i - j > 0)
			ret[k++] = ft_strndup(s + j, i - j);
		else
			i++;

	}
	ret[k] = NULL;
	if (alloc_check(&ret, k))
		return (NULL);
	return (ret);
}
