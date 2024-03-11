/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:15:48 by tvanbael          #+#    #+#             */
/*   Updated: 2023/02/10 17:58:29 by tvanbael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (y < 0 || x < 0)
		return ;
	if (y >= SIZE_Y || x >= SIZE_X)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

void	print_square(t_cub *cub, float size, int color, t_data *img)
{
	int	i;
	int	j;

	j = 0;
	while (j < size - 0.2)
	{
		i = 0;
		while (i < size - 0.2)
		{
			my_mlx_pixel_put(img, i + cub->tempx, j + cub->tempy, color);
			i++;
		}
		j++;
	}
}

void	drawline(t_cub *cub)
{
	int	r;

	r = ZOOM;
	cub->ii = cub->pos.angle;
	{
		cub->aangle = cub->ii;
		r = 0;
		cub->xx1 = 0;
		cub->yy1 = 0;
		while (r < ZOOM)
		{
			cub->xx1 = +r * cos(cub->aangle);
			cub->yy1 = +r * sin(cub->aangle);
			my_mlx_pixel_put(&cub->img, ((MAP_SIZE_XY / 2) + (SIZE_PERSO / 2)
					+ cub->xx1 * 2), ((MAP_SIZE_XY / 2) + (SIZE_PERSO / 2)
					+ cub->yy1 * 2), CLR_RAYON);
			r++;
		}
		cub->ii += 0.01;
	}
}

void	ft_back_ground(t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	while (i < (SIZE_Y / 2))
	{
		j = 0;
		while (j < SIZE_X)
		{
			my_mlx_pixel_put(&cub->img, j, i, cub->map->clr_sk);
			j++;
		}
		i++;
	}
	while (i < (SIZE_Y))
	{
		j = 0;
		while (j < SIZE_X)
		{
			my_mlx_pixel_put(&cub->img, j, i, cub->map->clr_fl);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img.img, 0, 0);
}

void	ft_display(t_cub *cub)
{
	mlx_destroy_image(cub->mlx, cub->img.img);
	mlx_clear_window(cub->mlx, cub->win);
	cub->img.img = mlx_new_image(cub->mlx, SIZE_X, SIZE_X);
	cub->img.addr = mlx_get_data_addr(cub->img.img, &cub->img.bpp,
			&cub->img.line_length, &cub->img.endian);
	ft_back_ground(cub);
	drawrays(cub);
	map_view_2d(cub);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img.img, 0, 0);
}
