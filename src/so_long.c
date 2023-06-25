/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fayan <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 14:48:15 by fayan             #+#    #+#             */
/*   Updated: 2022/04/22 14:48:56 by fayan            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	mapread(t_game *game, char *a)
{
	int	fd;

	fd = open(a, O_RDWR);
	if (fd == -1)
		return (invalid_map());
	game -> allmap = get_next_line(fd);
	if (!(game->allmap))
		return (invalid_map());
	game->map = ft_split(game->allmap, '\n');
	return (1);
}

void	imgcevir(t_game *game)
{
	int	x;
	int	y;

	game->img.wall = mlx_xpm_file_to_image(game->mlx,
			"./img/wall.xpm", &x, &y);
	game->img.water = mlx_xpm_file_to_image(game->mlx,
			"./img/water.xpm", &x, &y);
	game->img.worm = mlx_xpm_file_to_image(game->mlx,
			"./img/worm.xpm", &x, &y);
	game->img.octopusopen = mlx_xpm_file_to_image(game->mlx,
			"./img/eyesopen.xpm", &x, &y);
	game->img.enemy = mlx_xpm_file_to_image(game->mlx,
			"./img/enemyleft.xpm", &x, &y);
	game->img.exit = mlx_xpm_file_to_image(game->mlx,
			"./img/shell.xpm", &x, &y);
}

int	controller(int key, t_game *game)
{
	static int	a;
	int			c;

	c = a;
	mlx_clear_window(game->mlx, game->mlx_win);
	pplace(game);
	if (key == 0 || key == 1 || key == 2 || key == 13 || key == 53)
	{
		game->k = key;
		game->b = move(game, key);
	}
	a = game->b;
	if (c != a)
		ft_putnbr(game->b);
	maprender(game, key);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	game.z = 0;
	game.b = 0;
	if (!mapread(&game, argv[1]))
		return (0);
	if (argc != 2)
		return (invalid_map());
	if (!check_map_name(argv[1]))
		return (invalid_map());
	game.rowcount = row_count(game.allmap) * 64;
	game.columncount = ft_strlen(game.map[0]) * 64;
	if (!checkmap(&game))
		return (0);
	game.mlx = mlx_init();
	game.mlx_win = mlx_new_window(game.mlx, game.columncount,
			game.rowcount, "BALIK");
	imgcevir(&game);
	maprender(&game, 0);
	mlx_hook(game.mlx_win, 2, (1L << 0), controller, &game);
	mlx_hook(game.mlx_win, 17, 0, close_frame, &game);
	mlx_loop_hook(game.mlx, animation, &game);
	mlx_loop(game.mlx);
}
