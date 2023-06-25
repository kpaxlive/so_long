/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fayan <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 15:00:22 by fayan             #+#    #+#             */
/*   Updated: 2022/04/22 15:00:24 by fayan            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	invalid_map(void)
{
	ft_putstr("Invalid Map!\n");
	return (0);
}

int	check_map_name(char *str)
{
	char	*i;
	char	*x;

	x = ".ber";
	i = ft_strrchr(str, '.');
	if (!i)
		return (0);
	if (ft_strncmp(i, x, ft_strlen(str)))
		return (0);
	return (1);
}

int	check_p(char *str)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (str[i] != '\0')
	{
		if (str[i] == 'P')
			x++;
		i++;
	}
	if (x != 1)
		return (0);
	return (1);
}
