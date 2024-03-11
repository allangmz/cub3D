/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:33:31 by tvanbael          #+#    #+#             */
/*   Updated: 2023/02/17 09:29:54 by tvanbael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static void	put_line(char *dest, char *strtmp, int size)
{
	int	i;
	int	j;

	j = 0;
	dest[0] = '1';
	i = 1;
	while (strtmp[j])
	{
		dest[i] = strtmp[j];
		i++;
		j++;
	}
	while (i < size)
	{
		dest[i] = '1';
		i++;
	}
	dest[i] = '\0';
}

static void	protect_tab2(t_cub *cub, int i, int size)
{
	i = 0;
	cub->map->tab_y += 1;
	cub->map->map_tab[cub->map->tab_y] = malloc(sizeof(char) * size + 1);
	while (i < size)
	{
		cub->map->map_tab[0][i] = '1';
		cub->map->map_tab[cub->map->tab_y][i] = '1';
		i++;
	}
	cub->map->map_tab[0][i] = '\0';
	cub->map->map_tab[cub->map->tab_y][i] = '\0';
	cub->map->map_len[cub->map->tab_y] = size;
	cub->map->tab_x = size;
}

void	protect_tab(t_cub *cub)
{
	int		size;
	char	*strtmp;
	int		i;

	i = 0;
	strtmp = NULL;
	size = long_line(cub) + 2;
	while (cub->map->map_tab[i])
	{
		strtmp = ft_strcpy2(strtmp, cub->map->map_tab[i]);
		free(cub->map->map_tab[i]);
		cub->map->map_tab[i] = malloc(sizeof(char) * (size));
		if (!cub->map->map_tab[i])
			free_exit(cub, i, cub->map->map_tab, 1);
		put_line(cub->map->map_tab[i], strtmp, size);
		free(strtmp);
		cub->map->map_len[i] = size;
		i++;
	}
	protect_tab2(cub, i, size);
}
