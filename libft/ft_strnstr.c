/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fayan <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 18:20:23 by fayan             #+#    #+#             */
/*   Updated: 2022/02/03 18:20:26 by fayan            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"
#include <stdio.h>

char	*ft_strnstr(const char *samanlik, const char *igne, size_t len)
{
	size_t	i;
	size_t	j;
	char	*sam;
	char	*ig;

	sam = (char *) samanlik;
	ig = (char *) igne;
	if (!*ig)
		return ((char *)samanlik);
	i = 0;
	while (sam[i] && i < len)
	{
		j = 0;
		if (sam[i] == ig[j])
		{
			while (sam[i + j] && i + j < len && sam[i + j] == ig[j])
				j++;
			if (ig[j] == '\0')
				return ((char *)(samanlik + i));
		}
		i++;
	}
	return (NULL);
}
