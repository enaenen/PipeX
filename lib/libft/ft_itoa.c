/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchae <wchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 18:16:17 by wchae             #+#    #+#             */
/*   Updated: 2022/03/07 10:53:12 by wchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	digit_count(int n, int *size)
{
	if (n != 0)
	{
		digit_count(n / 10, size);
		*size += 1;
	}
}

static int	set_itoa(long long n, char *ret, int size)
{
	if (n < 10)
	{
		ret[size] = '0' + n;
		return (0);
	}
	else
	{
		set_itoa(n / 10, ret, size - 1);
		ret[size] = '0' + n % 10;
		return (1);
	}
}

char	*ft_itoa(int n)
{
	int			size;
	int			flag;
	char		*ret;
	long long	num;

	flag = 0;
	num = n;
	size = 0;
	digit_count(n, &size);
	if (n <= 0)
		size++;
	ret = malloc(sizeof(char) * (size + 1));
	if (!ret)
		return (NULL);
	if (n < 0)
	{
		ret[0] = '-';
		num *= -1;
		flag = 1;
	}
	set_itoa(num, ret, size - 1);
	ret[size] = 0;
	return (ret);
}
