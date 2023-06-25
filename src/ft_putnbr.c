/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fayan <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 15:02:25 by fayan             #+#    #+#             */
/*   Updated: 2022/04/22 15:02:29 by fayan            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		str = "(null)";
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(int x)
{
	char	*a;
	int		l;

	if (x == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	if (x == -2147483648)
	{
		ft_putstr("-2147483648");
		return (11);
	}
	l = 0;
	a = ft_itoa(x);
	l = ft_putstr(a);
	write(1, "\n", 1);
	free (a);
	return (l);
}
