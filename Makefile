NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = main.c \
	   get_next_line/get_next_line.c \
       get_next_line/get_next_line_utils.c \
       valid_map.c \
	   utils.c \
	   flood_fill.c

OBJS = $(SRCS:.c=.o)

MLX_FLAGS = -L ./mlx -lmlx  -lXext -lX11

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS)  -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
