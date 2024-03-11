/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguemazi <aguemazi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:43:32 by aguemazi          #+#    #+#             */
/*   Updated: 2023/02/16 16:03:15 by aguemazi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static void	put_frame(t_cub *cub)
{
	cub->i = -1;
	while (++cub->i <= 5)
	{
		cub->j = -1;
		while (++cub->j <= ZOOM * 10)
			my_mlx_pixel_put(&cub->img, cub->j, cub->i, M_GOLD);
	}
	cub->i--;
	while (++cub->i <= ((ZOOM * 10) - 5))
	{
		cub->j = -1;
		while (++cub->j <= ZOOM * 10)
		{
			if ((cub->j >= 0 && cub->j <= 5)
				|| ((cub->j >= ((ZOOM * 10)) - 6) && cub->j <= ZOOM * 10))
				my_mlx_pixel_put(&cub->img, cub->j, cub->i, M_GOLD);
		}
	}
	cub->i--;
	while (++cub->i <= ZOOM * 10)
	{
		cub->j = -1;
		while (++cub->j <= ZOOM * 10)
			my_mlx_pixel_put(&cub->img, cub->j, cub->i, M_GOLD);
	}
}

static void	map_utils(t_cub *cub)
{
	while (cub->mini->y <= 9)
	{
		cub->mini->x = 0;
		cub->mini->x1 = ((cub->pos.x / 64.0 - 5));
		while (cub->mini->x <= 9)
		{
			cub->tempx = cub->mini->x * (float)ZOOM;
			cub->tempy = cub->mini->y * (float)ZOOM;
			print_square(cub, (float)ZOOM, M_SL, &cub->img);
			if ((cub->mini->x1 >= 0 && cub->mini->x1 <= cub->map->tab_x + 1)
				&& (cub->mini->y1 >= 0 && cub->mini->y1 <= cub->map->tab_y + 1))
			{
				if (cub->map->map_tab[(int)cub->mini->y1]
					[(int)cub->mini->x1] == '1')
					print_square(cub, (float)ZOOM, M_MR, &cub->img);
				else if (cub->map->map_tab[(int)cub->mini->y1]
					[(int)cub->mini->x1] == '0')
					print_square(cub, (float)ZOOM, M_SL, &cub->img);
			}
			cub->mini->x += 0.2;
			cub->mini->x1 += 0.2;
		}
		cub->mini->y += 0.2;
		cub->mini->y1 += 0.2;
	}
}

int	map_view_2d(t_cub *cub)
{
	cub->mini->y = 0;
	while (cub->mini->y < (9 * ZOOM))
	{
		cub->mini->x = 0;
		while (cub->mini->x < (9 * ZOOM))
		{
			my_mlx_pixel_put(&cub->img, cub->mini->x, cub->mini->y, M_BK);
			cub->mini->x++;
		}
		cub->mini->y++;
	}
	cub->mini->y = 0;
	cub->mini->y1 = ((cub->pos.y / 64.0 - 5));
	map_utils(cub);
	cub->tempx = ((ZOOM * 10) / 2) - SIZE_PERSO / 2;
	cub->tempy = ((ZOOM * 10) / 2) - SIZE_PERSO / 2;
	print_square(cub, SIZE_PERSO, M_P, &cub->img);
	put_frame(cub);
	return (0);
}

void	pixel(t_cub *cub)
{
	int	tmp;

	tmp = cub->lineoff + 10;
	while (tmp <= cub->lineh + cub->lineoff)
	{
		my_mlx_pixel_put(&cub->img, (int)cub->r, tmp,
			get_color(cub, (tmp - cub->lineoff)));
		tmp ++;
	}
}
