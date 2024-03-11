/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 15:27:18 by aguemazi          #+#    #+#             */
/*   Updated: 2023/02/07 13:58:39 by tvanbael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	load_texture(t_cub *cub, t_data *tex, char *path)
{
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		write(2, "Asset not found: /CUB3D/assets/\n", 33);
		exit(1);
	}
	close(fd);
	tex->img = mlx_xpm_file_to_image(cub->mlx, path, &tex->width,
			&tex->heigth);
	tex->addr = mlx_get_data_addr(tex->img, &tex->bpp, &tex->line_length,
			&tex->endian);
	return ;
}

void	load_images(t_cub *cub)
{
	load_texture(cub, &cub->map->wall_n, cub->map->no_map);
	load_texture(cub, &cub->map->wall_s, cub->map->so_map);
	load_texture(cub, &cub->map->wall_e, cub->map->es_map);
	load_texture(cub, &cub->map->wall_w, cub->map->we_map);
}
