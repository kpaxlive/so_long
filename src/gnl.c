/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fayan <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 15:00:37 by fayan             #+#    #+#             */
/*   Updated: 2022/04/22 15:00:44 by fayan            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*get_next_line(int fd)
{
	char	buff;
	char	*line;
	int		ret;
	int		i;

	i = 0;
	ret = 1;
	line = (char *)malloc(sizeof(char) * 9999);
	buff = 0;
	while (ret > 0)
	{
		ret = read(fd, &buff, 1);
		if (ret <= 0)
			break ;
		line[i++] = buff;
	}
	line[i] = 0;
	if (!*line)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
