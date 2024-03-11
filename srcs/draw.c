/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguemazi <aguemazi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 15:13:32 by tvanbael          #+#    #+#             */
/*   Updated: 2023/02/16 16:11:34 by aguemazi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static int	four(t_cub *cub)
{
	while (cub->dof < 100)
	{
		cub->mx = (int)(cub->rx) >> 6;
		cub->my = (int)(cub->ry) >> 6;
		if ((cub->mx >= 0 && cub->my >= 0) && cub->my <= cub->map->tab_y
			&& cub->mx < cub->map->map_len[cub->my]
			&& cub->map->map_tab[cub->my][cub->mx] == '1')
		{
			cub->dof = 100;
			cub->dish = cos(deg_to_rad(cub->ra)) * (cub->rx - cub->pos.x)
				- sin(deg_to_rad(cub->ra)) * (cub->ry - cub->pos.y);
		}
		else
		{
			cub->rx += cub->xo;
			cub->ry += cub->yo;
			cub->dof += 1;
		}
	}
	cub->wall_pos = 'H';
	return (1);
}

static int	third(t_cub *cub)
{
	if (sin(deg_to_rad(cub->ra)) > 0.001)
	{
		cub->ry = ((((int)cub->pos.y >> 6) << 6) - 0.0001);
		cub->rx = ((cub->pos.y - cub->ry) * cub->atan + cub->pos.x);
		cub->yo = -64;
		cub->xo = -cub->yo * cub->atan;
	}
	else if (sin(deg_to_rad(cub->ra)) < -0.001)
	{
		cub->ry = (((int)cub->pos.y >> 6) << 6) + 64;
		cub->rx = (cub->pos.y - cub->ry) * cub->atan + cub->pos.x;
		cub->yo = 64;
		cub->xo = -cub->yo * cub->atan;
	}
	else
	{
		cub->rx = cub->pos.x;
		cub->ry = cub->pos.y;
		cub->dof = 100;
	}
	return (four(cub));
}

static int	second(t_cub *cub)
{
	while (cub->dof < 100)
	{
		cub->mx = (int)(cub->rx) >> 6;
		cub->my = (int)(cub->ry) >> 6;
		if ((cub->mx >= 0 && cub->my > 0) && cub->my <= cub->map->tab_y
			&& cub->mx <= cub->map->map_len[cub->my]
			&& cub->map->map_tab[cub->my][cub->mx] == '1')
		{
			cub->dof = 100;
			cub->disv = cos(deg_to_rad(cub->ra)) * (cub->rx - cub->pos.x)
				- sin(deg_to_rad(cub->ra)) * (cub->ry - cub->pos.y);
		}
		else
		{
			cub->rx += cub->xo;
			cub->ry += cub->yo;
			cub->dof += 1;
		}
	}
	cub->vx = cub->rx;
	cub->vy = cub->ry;
	cub->dof = 0;
	cub->dish = 100000;
	cub->atan = 1 / cub->atan;
	return (third(cub));
}

static int	first(t_cub *cub)
{
	cub->dof = 0;
	cub->side = 0;
	cub->disv = 100000;
	cub->atan = tan(deg_to_rad(cub->ra));
	if (cos(deg_to_rad(cub->ra)) > 0.001)
	{
		cub->rx = (((int)(cub->pos.x) >> 6) << 6) + 64;
		cub->ry = (cub->pos.x - cub->rx) * cub->atan + cub->pos.y;
		cub->xo = 64;
		cub->yo = -cub->xo * cub->atan;
	}
	else if (cos(deg_to_rad(cub->ra)) < -0.001)
	{
		cub->rx = (((int)(cub->pos.x) >> 6) << 6) - 0.0001;
		cub->ry = (cub->pos.x - cub->rx) * cub->atan + cub->pos.y;
		cub->xo = -64;
		cub->yo = -cub->xo * cub->atan;
	}
	else
	{
		cub->rx = cub->pos.x;
		cub->ry = cub->pos.y;
		cub->dof = 8;
	}
	return (second(cub));
}

void	drawrays(t_cub *cub)
{
	cub->ra = fix_ang(cub->pos.angle + 30);
	cub->r = 0;
	while ((cub->r < SIZE_X) && first(cub))
	{
		if (cub->disv < cub->dish)
		{
			cub->wall_pos = 'V';
			cub->rx = cub->vx;
			cub->ry = cub->vy;
			cub->dish = cub->disv;
		}
		cub->ca = fix_ang(cub->pos.angle - cub->ra);
		cub->dish = cub->dish * cos(deg_to_rad(cub->ca));
		cub->lineh = (SIZE_X) * 64 / (cub->dish);
		cub->lineoff = ((SIZE_X / 2) - (cub->lineh >> 1));
		pixel(cub);
		cub->ra = fix_ang(cub->ra - (60 / SIZE_X));
		cub->r += 1;
	}
}
