/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fayan <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 15:01:35 by fayan             #+#    #+#             */
/*   Updated: 2022/04/22 15:02:01 by fayan            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_elements(char *str)
{
	int		i;
	int		x;
	int		y;
	char	store[3];

	i = 0;
	x = 0;
	while (str[i] != '\0')
	{
		if (str[i] == 'P' && !ft_strchr(store, 'P'))
			store[x++] = str[i];
		else if (str[i] == 'C' && !ft_strchr(store, 'C'))
			store[x++] = str[i];
		else if (str[i] == 'E' && !ft_strchr(store, 'E'))
			store[x++] = str[i];
		else if (str[i] == 'W' && !ft_strchr(store, 'W'))
			store[x++] = str[i];
		i++;
	}
	store[x] = '\0';
	y = ft_strlen(store);
	if (y != 4)
		return (0);
	return (1);
}

int	check_borders(t_game *game)
{
	int	i;
	int	x;
	int	size;

	size = ft_strlen(game->map[0]);
	i = 0;
	while (game->map[0] && i != size)
		if (game->map[0][i++] != '1')
			return (0);
	i = 0;
	while (game->map[game->rowcount / 64 - 1] && i != size)
		if (game->map[game->rowcount / 64 - 1][i++] != '1')
			return (0);
	x = 0;
	while (game->map[x])
		if (game->map[x++][0] != '1')
			return (0);
	x = 0;
	while (game->map[x])
		if (game->map[x++][size - 1] != '1')
			return (0);
	return (1);
}

int	check_shape(t_game *game)
{
	int	x;
	int	y;
	int	i;

	y = 0;
	x = ft_strlen(game->map[0]);
	while (game->map[y])
		y++;
	if (x == y)
		return (0);
	i = 0;
	while (game->map[i] && i < row_count(game->allmap) - 1)
	{
		if (ft_strlen(game->map[i]) != ft_strlen(game->map[i + 1]))
			return (0);
		i++;
	}
	return (1);
}

int	check_units(char *allmap)
{
	int	i;

	i = 0;
	while (allmap[i] != '\0')
	{
		if (allmap[i] != '0' && allmap[i] != '1' && allmap[i] != 'P'
			&& allmap[i] != 'E' && allmap[i] != 'C' && allmap[i] != 'W'
			&& allmap[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

int	checkmap(t_game *game)
{
	if (!game->map)
		return (invalid_map());
	if (!check_elements(game->allmap))
		return (invalid_map());
	if (!check_borders(game))
		return (invalid_map());
	if (!check_shape(game))
		return (invalid_map());
	if (!check_units(game->allmap))
		return (invalid_map());
	if (!check_p(game->allmap))
		return (invalid_map());
	return (1);
}
