/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 10:42:28 by tvanbael          #+#    #+#             */
/*   Updated: 2023/02/17 09:35:33 by tvanbael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	orientation_player(char dir, t_cub *cub)
{
	if (!dir || (dir != 'N' && dir != 'S' && dir != 'E' && dir != 'W'))
		exit_error(cub);
	if (dir == 'N')
		return (90);
	else if (dir == 'S')
		return (270);
	else if (dir == 'E')
		return (0);
	else if (dir == 'W')
		return (180);
	return (-1);
}

void	init_pos_player(t_cub *cub, char dir, int x, int y)
{
	cub->pos.x = ((x + 1) * 64) + 32;
	cub->pos.y = (y * 64) + 32;
	cub->pos.orient_player = dir;
	cub->pos.angle = orientation_player(dir, cub);
	cub->map->map_tab[y][x] = '0';
	cub->pos.dx = cos(deg_to_rad(cub->pos.angle));
	cub->pos.dy = -sin(deg_to_rad(cub->pos.angle));
}

void	ft_init_structure(t_cub *cub, char **av)
{
	cub->i = 0;
	cub->bool = 0;
	cub->valid = 0;
	cub->linevalid = 0;
	cub->j = 0;
	cub->r = 0;
	cub->map->next_x = 0;
	cub->map->next_y = 0;
	cub->map->tab_y = 0;
	cub->map->path = av[1];
	cub->map->valid = 0;
	cub->map->bool = 0;
	cub->map->mem[0] = -1;
	cub->map->mem[1] = -1;
	cub->mini->x = 0;
	cub->mini->y = 0;
	cub->mini->x1 = 0;
	cub->mini->y1 = 0;
	cub->map->map_tab[1] = NULL;
	cub->pos.angle = 999;
}

static void	init_hex_to_str(t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	if (cub->pos.angle == 999)
		exit_error(cub);
	if (!cub->map->map_tab[2])
		return (exit_error(cub));
	while (cub->map->map_tab[i])
	{
		j = 0;
		while (cub->map->map_tab[i][j])
		{
			if (!ft_isset(cub->map->map_tab[i][j], "01"))
				exit_error(cub);
			j++;
		}
		i++;
	}
	cub->map->clr_sk = get_hex_from_str(cub->map->sk_clrs);
	cub->map->clr_fl = get_hex_from_str(cub->map->fl_clrs);
}

void	ft_init(t_cub *cub, char **av)
{
	ft_init_structure(cub, av);
	cub->map->fd = open(av[1], O_RDONLY);
	if (cub->map->fd == -1)
	{
		ft_putstr_fd("Can't open the map file\n", 2);
		exit(-1);
	}
	verif_file(cub, av);
	init_map(cub);
	init_tab(cub);
	init_hex_to_str(cub);
	if (cub->map->line)
		free(cub->map->line);
	cub->map->max_all = cub->map->tab_y;
	if (cub->map->tab_x > cub->map->tab_y)
		cub->map->max_all = cub->map->tab_x;
	if (close(cub->map->fd) == -1)
	{
		free_tab(cub->map->map_tab);
		ft_putstr_fd("Can't closed the map file\n", 2);
		exit(-1);
	}
	return ;
}
