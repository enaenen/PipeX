/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchae <wchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 16:55:39 by wchae             #+#    #+#             */
/*   Updated: 2022/04/03 21:49:27 by wchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_cnt(const char *s, char c)
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
			len ++;
		else
			i++;
	}
	return (len);
}

static void	find_word(const char *s, char c, int *i)
{
	while (s[*i] && s[*i] != c)
		(*i)++;
}

static int	is_alloc_failed(char ***ret, int len)
{
	int	i;
	int	error;

	i = 0;
	error = 0;
	while (i < len)
	{
		if ((*ret)[i] == NULL)
			error = 1;
		i++;
	}
	if (!error)
		return (error);
	i = 0;
	while (i < len)
	{
		if ((*ret)[i] != NULL)
			free((*ret)[i]);
		i++;
	}
	free(*ret);
	return (error);
}

char	**ft_split(const char *s, char c)
{
	int		i;
	int		j;
	int		k;
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
		find_word(s, c, &i);
		if (i - j > 0)
			ret[k++] = ft_strndup(s + i, i - j);
		else
			i++;
	}
	ret[k] = NULL;
	if (is_alloc_failed(&ret, k))
		return (NULL);
	return (ret);
}
