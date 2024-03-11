/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:03:52 by tvanbael          #+#    #+#             */
/*   Updated: 2023/01/25 15:25:27 by tvanbael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*/\*/


#ifndef DEFINE_H
# define DEFINE_H

# define RESET "\e[0m"

# define BK "\e[0;30m"
# define RD "\e[0;31m"
# define GN "\e[0;32m"
# define YW "\e[0;33m"
# define BE "\e[0;34m"
# define MA "\e[0;35m"
# define CN "\e[0;36m"
# define WE "\e[0;37m"
# define BEG "\e[01;34m"
# define RDS "\e[4;31m"
# define GNF "\e[1;92m"
# define CNF "\e[1;96m"

# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2
# define HAUT 126
# define BAS 125
# define GAUCHE 123
# define DROITE 124
# define BONUS 1

# define PI 3.1415926535
# define ZOOM (MAP_SIZE_XY / 9)
# define SIZE_PERSO 7.0
# define M_P 0x2A4FCB
# define M_HM 0x80FF00
# define M_SL 0xCB2A2A
# define M_MR 0xFFFFFF
# define M_BK 0x000000
# define M_GOLD 0xD8CF05
# define CLR_CIEL 0x06B9E5 
# define CLR_RAYON 0x2CCB2A

# define SIZE_X 800.0
# define SIZE_Y 800.0

# define MAP_SIZE_XY (SIZE_X / 6)
# define MAP_SIZE_Y (SIZE_XY / 6)

#endif
/*\/*/