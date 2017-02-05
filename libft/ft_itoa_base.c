/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 14:47:41 by thou              #+#    #+#             */
/*   Updated: 2016/11/21 16:29:44 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_nb_base(int value, int base)
{
	int		i;

	i = 1;
	if (base == 10 && value < 0)
		i++;
	while (value / base != 0)
	{
		i++;
		value = value / base;
	}
	return (i);
}

char		*ft_itoa_base(int value, int base)
{
	int		i;
	long	n;
	char	*c;
	char	*b;

	b = "0123456789ABCDEF";
	c = (char*)malloc(sizeof(char) * (ft_nb_base(value, base) + 1));
	if (!c)
		return (NULL);
	i = ft_nb_base(value, base);
	c[i--] = 0;
	n = value;
	if (value < 0)
	{
		n = -n;
		if (base == 10)
			c[0] = '-';
	}
	while (n / base != 0)
	{
		c[i--] = *(b + (n % base));
		n = n / base;
	}
	c[i] = *(b + (n % base));
	return (c);
}
