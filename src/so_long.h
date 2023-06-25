/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fayan <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 15:01:20 by fayan             #+#    #+#             */
/*   Updated: 2022/04/22 15:01:22 by fayan            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <unistd.h>
# include <fcntl.h>

typedef struct s_img
{
	void	*wall;
	void	*water;
	void	*fishright;
	void	*fishleft;
	void	*fishup;
	void	*fishdown;
	void	*worm;
	void	*enemy;
	void	*exit;
	void	*octopusopen;
}t_img;
typedef struct s_game
{
	void	*mlx;
	void	*mlx_win;
	char	**map;
	char	*allmap;
	int		prowplace;
	int		pcolumnplace;
	int		erowplace;
	int		ecolumnplace;
	int		row;
	int		column;
	int		rowcount;
	int		columncount;
	int		z;
	int		k;
	int		b;
	int		a;
	int		q;
	t_img	img;
}t_game;

char	*get_next_line(int fd);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *tutucu, char const *str);
size_t	ft_strlen(const char *s);
int		ft_putstr(char *str);
int		ft_putnbr(int x);
int		close_frame(t_game *game);
int		pplace(t_game *game);
int		columnc(t_game *game);
int		collect(t_game *game);
int		key_a(t_game *game, int a, int i);;
int		key_s(t_game *game, int a, int i);
int		key_d(t_game *game, int a, int i);
int		key_w(t_game *game, int a, int i);
int		move(t_game *game, int key);
void	renderhelp(t_game *game, int i, int j);
void	renderhelp2(t_game *game, int i, int j);
void	renderfonk(t_game *game, int i, int j);
void	maprender(t_game *game, int key);
void	find_w(t_game *game);
int		animation(t_game *game);
void	animation_enemy_left(t_game *game);
void	animation_enemy_right(t_game *game);
int		checkmap(t_game *game);
int		check_units(char *allmap);
int		check_shape(t_game *game);
int		check_borders(t_game *game);
int		check_elements(char *str);
int		invalid_map(void);
int		check_p(char *str);
int		check_map_name(char *str);
int		row_count(char *str);

#endif
