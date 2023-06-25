/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fayan <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 15:00:02 by fayan             #+#    #+#             */
/*   Updated: 2022/04/22 15:00:06 by fayan            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	animation_enemy_right(t_game *game)
{
	int	x;
	int	y;

	find_w(game);
	game->img.enemy = mlx_xpm_file_to_image(game->mlx,
			"./img/enemyright.xpm", &x, &y);
	if (game->map[game->erowplace][game->ecolumnplace + 1] != '1'
	&& game->map[game->erowplace][game->ecolumnplace + 1] != 'C'
	&& game->map[game->erowplace][game->ecolumnplace + 1] != 'E'
	&& game->map[game->erowplace][game->ecolumnplace + 1] != 'W')
	{
		if (game->map[game->erowplace][game->ecolumnplace + 1] == 'P')
		{
			ft_putstr("You Lost!\n");
			close_frame(game);
		}
		game->map[game->erowplace][game->ecolumnplace] = '0';
		game->map[game->erowplace][game->ecolumnplace + 1] = 'W';
	}
	else
		game->z = 1001;
}

void	animation_enemy_left(t_game *game)
{
	int	x;
	int	y;

	find_w(game);
	game->img.enemy = mlx_xpm_file_to_image(game->mlx,
			"./img/enemyleft.xpm", &x, &y);
	if (game->map[game->erowplace][game->ecolumnplace - 1] != '1'
		&& game->map[game->erowplace][game->ecolumnplace - 1] != 'C'
		&& game->map[game->erowplace][game->ecolumnplace - 1] != 'E'
		&& game->map[game->erowplace][game->ecolumnplace - 1] != 'W')
	{
		if (game->map[game->erowplace][game->ecolumnplace - 1] == 'P')
		{
			ft_putstr("You Lost!\n");
			close_frame(game);
		}
		game->map[game->erowplace][game->ecolumnplace] = '0';
		game->map[game->erowplace][game->ecolumnplace - 1] = 'W';
	}
	else
		game->z = 1;
}

int	animation(t_game *game)
{
	int	x;
	int	y;

	if (game->z >= 1 && game->z <= 1000)
	{
		game->img.octopusopen = mlx_xpm_file_to_image(game->mlx,
				"./img/eyesopen.xpm", &x, &y);
		animation_enemy_right(game);
	}
	else if (game->z >= 1001 && game->z <= 2000)
	{
		game->img.octopusopen = mlx_xpm_file_to_image(game->mlx,
				"./img/eyesclose.xpm", &x, &y);
		animation_enemy_left(game);
	}
	if (game->z >= 2001)
		game->z = 0;
	maprender(game, game->k);
	game->z++;
	return (0);
}

void	find_w(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i] != 0)
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			if (game->map[i][j] == 'W')
			{
				game->erowplace = i;
				game->ecolumnplace = j;
				return ;
			}
			j++;
		}
		i++;
	}
}
