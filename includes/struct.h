/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:06:50 by tvanbael          #+#    #+#             */
/*   Updated: 2023/02/09 11:12:38 by tvanbael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	int		heigth;
	int		width;
}				t_data;

typedef struct s_pos
{
	char	orient_player;
	float	x;
	float	y;
	float	dx;
	float	dy;
	float	angle;
}				t_pos;

typedef struct s_map
{
	char			*path;
	char			*map_tab[10000];
	int				map_len[10000];
	char			*inf[40];
	char			no_map[100];
	char			so_map[100];
	char			es_map[100];
	char			we_map[100];
	t_data			wall_n;
	t_data			wall_s;
	t_data			wall_e;
	t_data			wall_w;
	char			fl_clrs[40];
	unsigned int	clr_fl;
	char			sk_clrs[40];
	unsigned int	clr_sk;
	int				start_map;
	int				max_len;
	int				max_all;
	int				fd;
	char			*line;
	int				tab_x;
	int				tab_y;
	int				mem[2];
	int				next_y;
	int				next_x;
	int				bool;
	int				valid;
	int				chem;
	int				i;
	int				j;

}				t_map;

typedef struct s_mini
{
	float	x;
	float	x1;
	float	y;
	float	y1;
}				t_mini;

typedef struct s_cub
{
	t_data			img;
	t_data			*data;
	t_map			*map;
	t_mini			*mini;
	void			*mlx;
	void			*win;
	t_pos			pos;
	int				bool;
	int				valid;
	int				backtrack;
	int				linevalid;
	int				i;
	int				j;
	int				my;
	int				mx;
	int				dof;
	int				side;
	float			vx;
	float			vy;
	float			rx;
	float			ry;
	float			ra;
	float			xo;
	float			yo;
	float			disv;
	float			dish;
	char			wall_pos;
	unsigned int	color;
	float			r;
	float			shade;
	float			ty;
	float			tx;
	float			atan;
	int				ca;
	int				lineh;
	int				lineoff;
	int				tmp_x;
	int				tmp_y;
	float			x1;
	float			y1;
	float			x2;
	float			y2;
	float			dx;
	float			dy;
	int				error;
	unsigned int	out;
	double			ii;
	double			aangle;
	double			xx1;
	double			yy1;
	double			tempy;
	double			tempx;
}					t_cub;

typedef struct s_tab
{
	char		*tab;
	int			len;

}				t_tab;

#endif
