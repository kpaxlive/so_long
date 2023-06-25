/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fayan <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 15:01:07 by fayan             #+#    #+#             */
/*   Updated: 2022/04/22 15:01:09 by fayan            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_a(t_game *game, int a, int i)
{
	if (game->map[game->prowplace][game->pcolumnplace - 1] == 'E')
	{
		a = collect(game);
		if (a == 0)
		{
			ft_putstr("You Won!\n");
			close_frame(game);
		}
	}
	else if (game->map[game->prowplace][game->pcolumnplace - 1] == 'W')
	{
		ft_putstr("You Lost!\n");
		close_frame(game);
	}
	else
	{
		game->map[game->prowplace][game->pcolumnplace - 1] = 'P';
		game->map[game->prowplace][game->pcolumnplace] = '0';
		i++;
	}
	return (i);
}

int	key_s(t_game *game, int a, int i)
{
	if (game->map[game->prowplace +1][game->pcolumnplace] == 'E')
	{
		a = collect(game);
		if (a == 0)
		{
			ft_putstr("You Won!\n");
			close_frame(game);
		}
	}
	else if (game->map[game->prowplace +1][game->pcolumnplace] == 'W')
	{
		ft_putstr("You Lost!\n");
		close_frame(game);
	}
	else
	{
		game->map[game->prowplace + 1][game->pcolumnplace] = 'P';
		game->map[game->prowplace][game->pcolumnplace] = '0';
		i++;
	}
	return (i);
}

int	key_d(t_game *game, int a, int i)
{
	if (game->map[game->prowplace][game->pcolumnplace + 1] == 'E')
	{
		a = collect(game);
		if (a == 0)
		{
			ft_putstr("You Won!\n");
			close_frame(game);
		}
	}
	else if (game->map[game->prowplace][game->pcolumnplace + 1] == 'W')
	{
		ft_putstr("You Lost!\n");
		close_frame(game);
	}
	else
	{
		game->map[game->prowplace][game->pcolumnplace + 1] = 'P';
		game->map[game->prowplace][game->pcolumnplace] = '0';
		i++;
	}
	return (i);
}

int	key_w(t_game *game, int a, int i)
{
	if (game->map[game->prowplace - 1][game->pcolumnplace] == 'E')
	{
		a = collect(game);
		if (a == 0)
		{
			ft_putstr("You Won!\n");
			close_frame(game);
		}
	}
	else if (game->map[game->prowplace - 1][game->pcolumnplace] == 'W')
	{
		ft_putstr("You Lost!\n");
		close_frame(game);
	}
	else
	{
		game->map[game->prowplace -1][game->pcolumnplace] = 'P';
		game->map[game->prowplace][game->pcolumnplace] = '0';
		i++;
	}
	return (i);
}

int	move(t_game *game, int key)
{
	static int	s;
	int			a;
	int			i;

	a = 0;
	i = 0;
	if (key == 0 && game->map[game->prowplace][game->pcolumnplace - 1] != '1')
		s += key_a(game, a, i);
	else if (key == 1
		&& game->map[game->prowplace +1][game->pcolumnplace] != '1')
		s += key_s(game, a, i);
	else if (key == 2
		&& game->map[game->prowplace][game->pcolumnplace + 1] != '1')
		s += key_d(game, a, i);
	else if (key == 13
		&& game->map[game->prowplace - 1][game->pcolumnplace] != '1')
		s += key_w(game, a, i);
	else if (key == 53)
		close_frame(game);
	return (s);
}
