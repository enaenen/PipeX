/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchae <wchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 16:50:39 by wchae             #+#    #+#             */
/*   Updated: 2022/04/03 16:55:29 by wchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *src, int len)
{
	int		i;
	char	*dup;

	i = 0;
	dup = malloc(sizeof(*src) * (len + 1));
	if (!dup)
		return (NULL);
	while (i < len)
	{
		*(dup + i) = src[i];
		i++;
	}
	*(dup + i) = 0;
	return (dup);
}
