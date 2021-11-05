NAME = so_long

SRCS = so_long.c gnl/get_next_line.c gnl/get_next_line_utils.c ft_strlen_for_game.c check_map.c check_map_pers.c so_long_render.c so_long_read_draw.c ft_itoa.c

INCLUDE = so_long.h

OBJS = $(SRCS:.c=.o)

CC = gcc 

CFLAGS = -Wall -Wextra -Werror

MLX = -framework OpenGL -framework AppKit -lmlx

all : $(NAME)

%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@  

$(NAME) : $(OBJS) $(INCLUDE)
	$(CC) $(CFLAGS) $(OBJS) -I./include $(MLX) libmlx.dylib -o $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY: clean fclean re all