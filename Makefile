NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBS = -lmlx -framework OpenGL -framework AppKit

SRCS = main.c \
       get_next_line/get_next_line.c \
       get_next_line/get_next_line_utils.c \
       valid_map.c \
	   utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
