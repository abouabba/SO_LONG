NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror 

SRCS = main.c \
	   get_next_line/get_next_line.c \
       get_next_line/get_next_line_utils.c \
       valid_map.c \
	   utils.c \
	   flood_fill.c \
	   ft_move_player.c \
	   key_move.c

OBJS = $(SRCS:.c=.o)

LDFLAGS = -L ./mlx -lmlx -lXext -lX11 -pie

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS)  -c $< -o $@

clean:
	rm -f *.o get_next_line/*.o $(NAME)

fclean: clean
	rm -f $(NAME)

re: fclean all
