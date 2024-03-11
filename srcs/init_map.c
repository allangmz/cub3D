/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:31:51 by tvanbael          #+#    #+#             */
/*   Updated: 2023/02/17 09:34:38 by tvanbael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static int	remove_nl(t_cub *cub)
{
	while (cub->map->line[0] == '\n')
	{
		free(cub->map->line);
		cub->map->line = get_next_line(cub->map->fd, 0);
	}
	if (cub->map->line[0] != '\n')
		return (1);
	return (0);
}

static void	cpy_path(t_cub *cub, char *path, char *dest)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (path[i] && path[i] != ' ')
		i++;
	i++;
	while (path[i] && path[i] != '\n')
	{
		dest[j] = path[i];
		i++;
		j++;
	}
	dest[i] = '\0';
	free(cub->map->line);
}

int	ft_havenumandspace(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] && line[i] == ' ')
			i++;
		if (ft_isset(line[i], "NSEW01"))
			return (1);
		i++;
	}
	return (0);
}

void	init_map(t_cub *cub)
{
	int	i;

	while (cub->map->line && cub->map->line[0] != '\0'
		&& cub->map->line[0] != ' '
		&& !(ft_isset(cub->map->line[0], "NSEW01")
			&& !ft_isset(cub->map->line[1], "OSE")))
	{
		i = 0;
		if (ft_strncmp(cub->map->line, "NO", 2) == 0)
			cpy_path(cub, cub->map->line, cub->map->no_map);
		else if (ft_strncmp(cub->map->line, "SO", 2) == 0)
			cpy_path(cub, cub->map->line, cub->map->so_map);
		else if (ft_strncmp(cub->map->line, "ES", 2) == 0)
			cpy_path(cub, cub->map->line, cub->map->es_map);
		else if (ft_strncmp(cub->map->line, "WE", 2) == 0)
			cpy_path(cub, cub->map->line, cub->map->we_map);
		else if (ft_strncmp(cub->map->line, "F ", 2) == 0)
			cpy_path(cub, cub->map->line, cub->map->fl_clrs);
		else if (ft_strncmp(cub->map->line, "C ", 2) == 0)
			cpy_path(cub, cub->map->line, cub->map->sk_clrs);
		else if (cub->map->line[0] == '\n')
			i = remove_nl(cub);
		if (!i || !ft_havenumandspace(cub->map->line))
			cub->map->line = get_next_line(cub->map->fd, 0);
	}
}

void	ft_alloc_tab(t_cub *cub, int size, int index)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = 0;
	y = 0;
	cub->map->map_tab[index] = malloc(sizeof(char) * (size));
	if (!cub->map->map_tab[index])
		free_exit(cub, index, cub->map->map_tab, 1);
	while (cub->map->line && (cub->map->line[i] != '\n'
			&& cub->map->line[i] != '\0'))
	{
		if (ft_isspace(cub->map->line[i]))
				cub->map->map_tab[index][i] = '0';
		else if (cub->map->line[i] == 'N' || cub->map->line[i] == 'S'
			|| cub->map->line[i] == 'E' || cub->map->line[i] == 'W')
			init_pos_player(cub, cub->map->line[i], i, index);
		else
			cub->map->map_tab[index][i] = cub->map->line[i];
		i++;
	}
	cub->map->map_tab[index][i] = '\0';
}
