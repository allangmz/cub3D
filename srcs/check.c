/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 21:13:06 by tvanbael          #+#    #+#             */
/*   Updated: 2023/02/17 09:31:09 by tvanbael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	ft_check_valid_map(t_cub *cub, char **av)
{
	(void) cub;
	if ((av[1][ft_strlen(av[1]) - 1] == 'b')
		&& (av[1][ft_strlen(av[1]) - 2] == 'u')
		&& (av[1][ft_strlen(av[1]) - 3] == 'c')
		&& (av[1][ft_strlen(av[1]) - 4] == '.'))
		return (1);
	return (0);
}

static void	re_open_fd(t_cub *cub, char **av)
{
	while (cub->map->line)
		cub->map->line = get_next_line(cub->map->fd, 0);
	close(cub->map->fd);
	cub->map->fd = open(av[1], O_RDONLY);
	cub->map->line = get_next_line(cub->map->fd, 1);
}

void	verif_file(t_cub *cub, char **av)
{
	cub->map->line = get_next_line(cub->map->fd, 0);
	while (cub->map->line && cub->map->line[0] != '\0')
	{
		if (ft_strncmp(cub->map->line, "NO", 2) == 0)
			cub->bool++;
		else if (ft_strncmp(cub->map->line, "SO", 2) == 0)
			cub->bool++;
		else if (ft_strncmp(cub->map->line, "ES", 2) == 0)
			cub->bool++;
		else if (ft_strncmp(cub->map->line, "WE", 2) == 0)
			cub->bool++;
		else if (ft_strncmp(cub->map->line, "F ", 2) == 0)
			cub->bool++;
		else if (ft_strncmp(cub->map->line, "C ", 2) == 0)
			cub->bool++;
		if (!ft_isalnum(cub->map->line[0]) && cub->bool == 6)
		{
			re_open_fd(cub, av);
			break ;
		}
		cub->map->line = get_next_line(cub->map->fd, 0);
	}
	if ((!cub->map->line || cub->map->line[0] == '\0') && cub->bool != 6)
		exit(write(2, "ERROR Map.cub invalid\n", 23));
}
