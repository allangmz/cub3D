/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:37:01 by tvanbael          #+#    #+#             */
/*   Updated: 2023/01/25 14:27:22 by tvanbael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

unsigned int	get_hex_from_str(char *str)
{
	char				**rgb;
	unsigned int		ret;
	int					r;
	int					g;
	int					b;

	rgb = ft_split(str, ',');
	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	if (r > 255 || g > 255 || b > 255
		|| r < 0 || g < 0 || b < 0)
	{
		printf("Invalid colors, using default values.\n");
		return (0);
	}
	ret = 0x00 + (1 << 24 | r << 16 | g << 8 | b);
	return (ret);
}

float	deg_to_rad(float a)
{
	return (a * M_PI / 180.0);
}

float	fix_ang(float a)
{
	if (a > 359)
		a -= 360;
	if (a < 0)
		a += 360;
	return (a);
}

unsigned int	get_color_texture(t_cub *cub, t_data *wall, float x, int y)
{
	t_cub			*ray;

	ray = cub;
	x = x * 64;
	y = 64 * y / (cub->lineh);
	cub->out = (*(unsigned int *)(wall->addr + (int)(y * (wall->width) + x)
				*(int)(wall->bpp / 8)));
	return (cub->out);
}

unsigned int	get_color(t_cub *cub, int y)
{
	float	rest;

	if (cub->wall_pos == 'H')
	{
		rest = ((int)(cub->rx / 64) - (cub->rx / 64));
		if (cub->ra < 180 && cub->ra > 0)
			cub->color = get_color_texture(cub, &cub->map->wall_n, rest, y);
		else
			cub->color = get_color_texture(cub, &cub->map->wall_s, rest, y);
	}
	else
	{
		rest = ((int)(cub->ry / 64) - (cub->ry / 64));
		if (cub->ra > 90 && cub->ra < 270)
			cub->color = get_color_texture(cub, &cub->map->wall_w, rest, y);
		else
			cub->color = get_color_texture(cub, &cub->map->wall_e, rest, y);
	}
	return (cub->color);
}
