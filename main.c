/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 10:02:52 by tvanbael          #+#    #+#             */
/*   Updated: 2023/02/17 09:33:17 by tvanbael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3D.h"

static void	run(t_cub *cub)
{
	ft_display(cub);
	mlx_hook(cub->win, 2, 1L << 0, key_hook, cub);
	mlx_loop_hook(cub->mlx, ft_mouse, cub);
	mlx_hook(cub->win, 17, 1L << 17, destroy_window, cub);
	mlx_loop(cub->mlx);
}

int	main(int ac, char **av)
{
	t_cub	cub;
	t_map	map;
	t_mini	mini;
	t_data	data;

	cub.map = &map;
	cub.mini = &mini;
	cub.data = &data;
	if (ac != 2)
		return (write(2, "ERROR, to few arguments\n", 25));
	if (!ft_check_valid_map(&cub, av))
		return (write(2, "ERROR, Map invalid\n", 19));
	ft_init(&cub, av);
	cub.mlx = mlx_init();
	load_images(&cub);
	cub.win = mlx_new_window(cub.mlx, SIZE_X, SIZE_Y, "Cub3D");
	cub.img.img = mlx_new_image(cub.mlx, SIZE_X, SIZE_Y);
	cub.img.addr = mlx_get_data_addr(cub.img.img, &cub.img.bpp,
			&cub.img.line_length, &cub.img.endian);
	mlx_mouse_move(cub.win, SIZE_X / 2, SIZE_Y / 2);
	run(&cub);
	return (0);
}
