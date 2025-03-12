NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror 

SRCS = main.c \
	   get_next_line/get_next_line.c \
       get_next_line/get_next_line_utils.c \
       valid_map.c \
	   utils.c \
	   fill_help.c \
	   ft_move_player.c \
	   key_move.c \
	   free.c 

OBJS = $(SRCS:.c=.o)

LDFLAGS = -L ./mlx -lmlx -lXext -lX11

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)

%.o: %.c so_long.h
	$(CC) $(CFLAGS)  -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) clean

re: fclean all
