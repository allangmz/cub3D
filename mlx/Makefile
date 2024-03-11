#
#

NOM				=	libmlx.a

SRCS			=	mlx_shaders.c \
					mlx_new_window.m \
					mlx_init_loop.m \
					mlx_new_image.m \
					mlx_xpm.c \
					mlx_int_str_to_wordtab.c \
					mlx_png.c \
					mlx_mouse.m \

OBJ1			= $(SRCS:.c=.o)

OBJS			= $(OBJ1:.m=.o)

RM				= rm -rf

# add to match string put with X11 in size and position
# CFLAGS			= -02 -DSTRINGPUTX11

all: 		$(NOM)

$(NOM):		$(OBJS)
				@ar -r $(NOM) $(OBJS)
				@ranlib $(NOM)

clean:
			@$(RM) $(NOM) $(OBJS) *~
				@$(RM) mlx_app

re: clean all
