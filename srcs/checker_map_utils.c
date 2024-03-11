/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_map_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 09:25:09 by tvanbael          #+#    #+#             */
/*   Updated: 2023/02/17 09:26:37 by tvanbael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	ft_isset(char c, char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		if (c != set[i])
			i++;
	}
	return (0);
}

int	long_line(t_cub *cub)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = cub->map->map_len[0];
	while (cub->map->map_len[i] != -1)
	{
		if (tmp < cub->map->map_len[i])
			tmp = cub->map->map_len[i];
		i++;
	}
	return (tmp);
}

char	*ft_strcpy2(char *dest, const char *src)
{
	size_t	i;

	i = 0;
	if (!src)
		return (0);
	dest = malloc(sizeof(char) * (ft_strlen(src) + 1));
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
