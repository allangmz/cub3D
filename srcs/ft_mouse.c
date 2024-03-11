/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:09:18 by aguemazi          #+#    #+#             */
/*   Updated: 2023/01/24 13:19:38 by tvanbael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	ft_mouse(t_cub *cub)
{
	int	x;
	int	y;

	if (BONUS == 1)
	{
		mlx_mouse_hide();
		mlx_mouse_get_pos(cub->win, &x, &y);
		cub->pos.angle -= ((x - SIZE_X / 2) / 15);
		cub->pos.angle = fix_ang(cub->pos.angle);
		cub->pos.dx = cos(deg_to_rad(cub->pos.angle));
		cub->pos.dy = -sin(deg_to_rad(cub->pos.angle));
		mlx_mouse_move(cub->win, SIZE_X / 2, SIZE_Y / 2);
		ft_display(cub);
	}
	return (0);
}
