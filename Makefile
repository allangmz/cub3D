# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/02 13:26:06 by tvanbael          #+#    #+#              #
#    Updated: 2023/02/17 09:51:45 by tvanbael         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	srcs/draw.c \
					srcs/cub3d_utils.c \
					srcs/image.c \
					main.c \
					srcs/check.c \
					srcs/ft_free.c \
					srcs/init.c \
					srcs/init_map.c \
					srcs/input.c \
					srcs/checker_map.c \
					srcs/checker_map_utils.c \
					srcs/mini_map.c \
					srcs/ft_mouse.c \
					srcs/loading.c \
					srcs/init_tab.c \
					

OBJS			= $(SRCS:.c=.o)

BONUS			=	

BONUS_OBJS		=	$(BONUS:.c=.o)

GCC				=	gcc

RM				=	rm -rf

#SANIT			=	-fsanitize=address

FLAGS			=	-Wall -Wextra -Werror -Imlx -g3

CURSE			=	-lcurses

NAME			=	cub3D

BONUS_NAME		=

LIBFT			=	libft.a

INCLUDE			=	-I./includes

.c.o:
			@$(GCC) $(FLAGS) $(SANIT) -c $(INCLUDE) $< -o ${<:.c=.o}

MLX				=	-lmlx -framework OpenGL -framework AppKit

$(NAME):	$(OBJS)
				@echo '\033[1;36mcompilation of additional component!';
				@$(MAKE) -C ./mlx/
				@echo '\033[0;32m-compilation of Mlx Complete!';
				@$(MAKE) -C ./libft/
				@echo '\033[0;32m-compilation of Libft Complete!';
				@echo '\033[1;36mMoving File libft.a & mlx in Folder Root!';
				@cp ./libft/libft.a .
				@cp ./mlx/libmlx.a .
				@$(GCC) $(FLAGS) $(MLX) $(SANIT) $(CURSE) $(OBJS) $(LIBFT) -o $(NAME)
				@echo '\033[0;32m-cub3D created!\033[0m';

all:		$(NAME)

clean:
			@$(RM) $(OBJS) $(BONUS_OBJS)
				@$(MAKE) clean -C ./mlx
				@$(MAKE) clean -C ./libft
				@echo '\033[0;32mClean Complete!';

fclean:		clean
				@$(RM) $(NAME) $(LIBFT) $(BONUS_NAME)
				@$(RM) libmlx.a
				@$(MAKE) fclean -C ./libft
				@echo '\033[0;32mFullClean Complete!';

re:			fclean all
				@echo '\033[0;32mMake-Re Complete!\033[0m';

.PHONY:		all clean fclean re