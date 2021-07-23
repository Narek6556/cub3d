SRCS			= src/cub3d.c \
					src/tools.c \
					src/parsing.c \
					src/get_next_line.c \
					src/screen.c \
					src/screen_tools.c \
 					src/keys.c \
# 					src/bitmap.c \
# 					src/check_parse.c \
# 					

# 					

# 					src/sprite.c \
					

# 					src/map_parsing.c \


OBJS			= $(SRCS:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -O3 -Wall -Wextra -Werror -I.
LIBS			= -Lmlx -lmlx -framework OpenGL -framework AppKit\
													./libft/libft.a
MLX				= libmlx.dylib

NAME			= cub3D

all:			$(NAME)

$(NAME):		$(MLX) $(OBJS)
				@(make re -C libft/)
				@(gcc ${CFLAGS} -o ${NAME} ${OBJS} ${LIBS})
				

$(MLX):
				@$(MAKE) -C mlx
				@(mv mlx/$(MLX) .)

clean:
				@$(MAKE) -C mlx clean
				@(make clean -C ./libft/)
				@$(RM) $(OBJS) $(BONUS_OBJS)

fclean:			clean
				@(make clean -C ./libft/)
				@$(RM) $(NAME) $(MLX)

re:				fclean $(NAME)

.PHONY:			all clean fclean re





#-------------------------------------------------------------------------------
# NAME = cub3d
# CC = gcc
# CFLAGS = -Wall -Werror -Wextra 
# MLX = libmlx.dylib
# MLXFLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit -lm
# #HEADER = cub3d.h
# SRC = 	cub3d \
# 		bitmap \
# 		check_parse \
# 		key \
# 		get_next_line \
# 		map_parsing \
# 		parsing \
# 		screen \
# 		screen_tools \
# 		sprite \
# 		tools \

# FILES = $(addsuffix .c, $(addprefix src/, $(SRC)), $(SRC))

# OBJS = $(FILES:.c=.o)

# BIN = $(addsuffix .o, $(SRC))

# all: $(NAME)

# $(NAME): $(OBJS)
# 		 $(CC) -o $(NAME) $(MLXFLAGS) $(OBJS)

# $(MLX):
# 				@$(MAKE) -C mlx
# 				@mv mlx/$(MLX) .

# clean: 
# 		rm -rf $(OBJS)
# 		rm -f bitmap.bmp

# fclean: fclean
# 		rm -rf $(NAME)

# re: fclean all

# # norm:
# # 	norminette $(FILES) includes/$(HEADER)

# .PHONY: all clean fclean re test sqr bmp err inv norm
