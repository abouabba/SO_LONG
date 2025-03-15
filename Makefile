CC = cc
CFLAGS = -Wall -Wextra -Werror 

NAME = so_long

BONUS_NAME = so_long_bonus

SRC = 	mandatory/main.c mandatory/get_next_line/get_next_line.c mandatory/get_next_line/get_next_line_utils.c mandatory/valid_map.c \
	   mandatory/utils.c mandatory/fill_help.c mandatory/ft_move_player.c mandatory/key_move.c mandatory/free.c \

BONUS = bonus/main_bonus.c bonus/get_next_line/get_next_line_bonus.c bonus/get_next_line/get_next_line_utils_bonus.c bonus/valid_map_bonus.c \
	   bonus/utils_bonus.c bonus/fill_help_bonus.c bonus/ft_move_player_bonus.c bonus/key_move_bonus.c bonus/free_bonus.c bonus/string_to_put_bonus.c \
	   bonus/ft_itoa_bonus.c \

OBJ = ${SRC:.c=.o}
BONUS_OBJ = ${BONUS:.c=.o}

HEADER = so_long.h

HEADER_BONUS = so_long_bonus.h

LDFLAGS = -L ./mlx -lmlx -lXext -lX11

all :${NAME}

${NAME} : ${OBJ}
	${CC} ${CFLAGS} ${OBJ} ${LDFLAGS} -o ${NAME}

bonus : ${BONUS_OBJ}
	${CC} ${CFLAGS} ${BONUS_OBJ} ${LDFLAGS}  -o ${BONUS_NAME}

%.o:%.c  ${HEADER}
	${CC} ${CFLAGS} -c $< -o $@

%.o:%.c  ${HEADER_BONUS}
	${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -f ${OBJ} ${BONUS_OBJ}

fclean :clean   
	rm -f ${NAME} ${BONUS_NAME}

re : fclean all
