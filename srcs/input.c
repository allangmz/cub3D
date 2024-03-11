/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 09:48:25 by tvanbael          #+#    #+#             */
/*   Updated: 2023/02/17 09:35:51 by tvanbael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	player_up(t_cub *cub)
{
	if (cub->map->map_tab[(int)(cub->pos.y / 64.0)]
		[(int)((cub->pos.x + cub->pos.dx * 10.0) / 64.0)] != '1')
		cub->pos.x += cub->pos.dx * 5.0;
	if (cub->map->map_tab[(int)((cub->pos.y + cub->pos.dy * 10.0) / 64.0)]
		[(int)(cub->pos.x / 64.0)] != '1')
		cub->pos.y += cub->pos.dy * 5.0;
}

void	player_down(t_cub *cub)
{
	if (cub->map->map_tab[(int)(cub->pos.y / 64.0)]
		[(int)((cub->pos.x - cub->pos.dx * 10.0) / 64.0)] != '1')
		cub->pos.x -= cub->pos.dx * 5.0;
	if (cub->map->map_tab[(int)((cub->pos.y - cub->pos.dy * 10) / 64.0)]
		[(int)(cub->pos.x / 64.0)] != '1')
		cub->pos.y -= cub->pos.dy * 5.0;
}

void	player_left(t_cub *cub, int i)
{
	if (i == 0)
	{
		cub->pos.dx = cos(deg_to_rad(fix_ang(cub->pos.angle - 90)));
		cub->pos.dy = -sin(deg_to_rad(fix_ang(cub->pos.angle - 90)));
		if (cub->map->map_tab[(int)(cub->pos.y / 64.0)]
		[(int)((cub->pos.x - cub->pos.dx * 10.0) / 64.0)] != '1')
			cub->pos.x -= cub->pos.dx * 5.0;
		if (cub->map->map_tab[(int)((cub->pos.y - cub->pos.dy * 10.0) / 64.0)]
		[(int)(cub->pos.x / 64.0)] != '1')
			cub->pos.y -= cub->pos.dy * 5.0;
	}
	else
	{
		cub->pos.angle += 5.0;
		cub->pos.angle = fix_ang(cub->pos.angle);
		cub->pos.dx = cos(deg_to_rad(cub->pos.angle));
		cub->pos.dy = -sin(deg_to_rad(cub->pos.angle));
	}
}

void	player_right(t_cub *cub, int i)
{
	if (i == 0)
	{
		cub->pos.dx = cos(deg_to_rad(fix_ang(cub->pos.angle + 90)));
		cub->pos.dy = -sin(deg_to_rad(fix_ang(cub->pos.angle + 90)));
		if (cub->map->map_tab[(int)(cub->pos.y / 64.0)]
			[(int)((cub->pos.x - cub->pos.dx * 10.0) / 64.0)] != '1')
			cub->pos.x -= cub->pos.dx * 5.0;
		if (cub->map->map_tab[(int)((cub->pos.y - cub->pos.dy * 10) / 64.0)]
			[(int)(cub->pos.x / 64.0)] != '1')
			cub->pos.y -= cub->pos.dy * 5.0;
	}
	else
	{
		cub->pos.angle -= 5.0;
		cub->pos.angle = fix_ang(cub->pos.angle);
		cub->pos.dx = cos(deg_to_rad(cub->pos.angle));
		cub->pos.dy = -sin(deg_to_rad(cub->pos.angle));
	}
}

int	key_hook(int keycode, void *cub)
{
	if (keycode == ESC)
	{
		destroy_window(cub);
		exit (0);
	}
	if (keycode == W || keycode == HAUT)
		player_up(cub);
	if (keycode == S || keycode == BAS)
		player_down(cub);
	if (keycode == A || keycode == GAUCHE || keycode == D || keycode == DROITE)
	{
		if (keycode == GAUCHE)
			player_left(cub, 1);
		if (keycode == A)
			player_left(cub, 0);
		if (keycode == DROITE)
			player_right(cub, 1);
		if (keycode == D)
			player_right(cub, 0);
	}
	ft_display(cub);
	return (0);
}
