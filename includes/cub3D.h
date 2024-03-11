/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:03:58 by tvanbael          #+#    #+#             */
/*   Updated: 2023/02/17 09:27:30 by tvanbael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../includes/define.h"
# include "../includes/struct.h"
# include "../Libft/libft.h"
# include "../mlx/mlx.h"
# include <math.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <errno.h>

void			ft_init(t_cub *cub, char **av);
int				checker_map(t_cub *cub);
void			protect_tab(t_cub *cub);
int				full_check2(t_cub *cub, int row, int col, int path);
int				change_value(t_cub *cub, int y, int x, char set);
int				check_start(t_cub *cub, int y, int x);
void			verif_file(t_cub *cub, char **av);
int				value_checker(t_cub *cub, int row, int col, int path);
void			init_tab(t_cub *cub);
void			ft_free_tab(char **tab);
void			exit_error(t_cub *cub);
void			init_map(t_cub *cub);
void			load_images(t_cub *cub);
void			free_map(char *tab);
void			free_tab(char **tab);
void			free_exit(t_cub *cub, int index, char **tab, int error);
int				destroy_window(t_cub *cub);
int				key_hook(int keycode, void *cub);
int				ft_mouse(t_cub *cub);
char			**max_len_tab(t_cub *cub, char **tmp_tab);
void			ft_put_in_tab(t_cub *cub, char **tmp_tab);
void			init_pos_player(t_cub *cub, char dir, int x, int y);
int				ft_check_valid_map(t_cub *cub, char **av);

void			ft_back_ground(t_cub *cub);
int				map_view_2d(t_cub *cub);
void			drawline(t_cub *cub);
void			print_square(t_cub *cub, float size, int color, t_data *img);
void			pixel(t_cub *cub);
int				ft_set_texture(t_cub *cub);
unsigned int	get_hex_from_str(char *str);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
float			deg_to_rad(float a);
float			fix_ang(float a);
void			drawrays(t_cub *cub);
void			ft_display(t_cub *cub);
unsigned int	get_color(t_cub *cub, int y);
int				ft_isset(char c, char *set);
void			init_tab(t_cub *cub);
void			ft_alloc_tab(t_cub *cub, int size, int index);
char			*ft_strcpy2(char *dest, const char *src);
int				long_line(t_cub *cub);
int				ft_isset(char c, char *set);

#endif