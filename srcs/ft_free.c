/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguemazi <aguemazi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:06:52 by tvanbael          #+#    #+#             */
/*   Updated: 2023/02/17 10:53:47 by aguemazi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] || (tab[i] != NULL))
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_exit(t_cub *cub, int index, char **tab, int error)
{
	int	i;

	i = 0;
	while (tab && tab[i] && i <= index)
	{
		free(tab[i]);
		i++;
	}
	if (error == 2)
		free_tab(cub->map->map_tab);
	mlx_destroy_window(cub->mlx, cub->win);
	exit(0);
}

void	ft_free_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
}

int	destroy_window(t_cub *cub)
{
	mlx_destroy_window(cub->mlx, cub->win);
	exit(0);
}

void	exit_error(t_cub *cub)
{
	write(2, "Error : Map !\n", 25);
	ft_free_tab(cub->map->map_tab);
	exit (0);
}
