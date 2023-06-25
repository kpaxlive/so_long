/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maprender.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fayan <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 15:03:00 by fayan             #+#    #+#             */
/*   Updated: 2022/04/22 15:03:02 by fayan            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	renderhelp(t_game *game, int i, int j)
{
	if (game->map[i][j] == '1')
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->img.wall, game->column, game->row);
	else if (game->map[i][j] == '0')
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->img.water, game->column, game->row);
	else if (game->map[i][j] == 'P')
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->img.water, game->column, game->row);
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->img.octopusopen, game->column, game->row);
	}
}

void	renderhelp2(t_game *game, int i, int j)
{
	if (game->map[i][j] == 'C')
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->img.water, game->column, game->row);
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->img.worm, game->column, game->row);
	}
	else if (game->map[i][j] == 'E')
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->img.exit, game->column, game->row);
	else if (game->map[i][j] == 'W')
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->img.water, game->column, game->row);
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->img.enemy, game->column, game->row);
	}
}

void	renderfonk(t_game *game, int i, int j)
{
	if (game->map[i][j] == '1' || game->map[i][j] == '0'
			|| game->map[i][j] == 'P')
	{
		renderhelp(game, i, j);
		game->column += 64;
	}
	else if (game->map[i][j] == 'C' || game->map[i][j] == 'E'
			|| game->map[i][j] == 'W')
	{
		renderhelp2(game, i, j);
		game->column += 64;
	}
}

void	paintscreen(t_game *game)
{
	int		i;
	int		j;
	char	*str;
	char	*x;

	i = 10;
	j = 10;
	while (i <= 100)
	{
		while (j <= 35)
		{
			mlx_pixel_put(game->mlx, game->mlx_win, i, j, 900000000);
			j++;
		}
		j = 10;
		i++;
	}
	x = ft_itoa(game->b);
	str = ft_strjoin("Moves: ", x);
	mlx_string_put(game->mlx, game->mlx_win, 30, 30, 250, str);
	free (x);
	free (str);
}

void	maprender(t_game *game, int key)
{
	static int	tmp;

	game->a = 0;
	game->q = 0;
	if (key == 0 || key == 13 || key == 1 || key == 2)
		tmp = key;
	else
		key = tmp;
	game->row = 0;
	while (game->map[game->a] != 0)
	{
		game->column = 0;
		while (game->map[game->a][game->q] != '\0')
		{
			renderfonk(game, game->a, game->q);
			game->q++;
		}
		game->q = 0;
		game->row += 64;
		game->a++;
	}
	paintscreen(game);
}
