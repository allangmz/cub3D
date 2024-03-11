/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguemazi <aguemazi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:42:44 by aguemazi          #+#    #+#             */
/*   Updated: 2023/02/16 14:40:23 by aguemazi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	fonction_pour_la_norminette(t_cub *cub, int size, int *index)
{
	while (cub->map->line && cub->map->line[0] != '\n')
	{
		size = ft_strlen(cub->map->line);
		ft_alloc_tab(cub, size, *index);
		cub->map->map_len[*index] = size - 1;
		if (cub->map->line[size - 1] != '\n')
			cub->map->map_len[*index] = size;
		cub->map->tab_y++;
		(*index) += 1;
		cub->map->line = get_next_line(cub->map->fd, 0);
	}
	return (size);
}

void	init_tab(t_cub *cub)
{
	int	index;
	int	size;
	int	i;

	i = 0;
	size = 0;
	index = 1;
	if (!cub->map->line)
		exit(write(2, "ERROR Map.cub invalid\n", 23));
	cub->map->map_tab[0] = malloc(sizeof(char) * 1);
	cub->map->map_tab[0][0] = '\0';
	size = fonction_pour_la_norminette(cub, size, &index);
	cub->map->map_tab[index] = NULL;
	while (i <= 30)
	{
		cub->map->map_len[index] = -1;
		index++;
		i++;
	}
	protect_tab(cub);
	cub->map->tab_x = size + 1;
}
