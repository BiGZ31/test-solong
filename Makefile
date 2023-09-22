PROG    = so_long

SRCS     = main.c movement.c movement2.c draw_squares.c draw_read_cut-map.c functions.c animations.c counter_complete.c map_check.c player_movement.c coins_info.c
OBJS     = ${SRCS:.c=.o}
MAIN    = main.c

HEADER    = -Iinclude

CC         = gcc
CFLAGS     = -Wall -Wextra -Werror -g

.c.o:        %.o : %.c
	@gcc ${CFLAGS} ${HEADER} -Imlx -c $< -o $(<:.c=.o)

all:         ${PROG}

${PROG}:    ${OBJS}
						@echo "\033[33m----Compiling lib----"
						@$(CC) ${OBJS} -Lprintf -lftprintf -lmlx -lXext -lX11 -L mlx -o ${PROG}
						@echo "\033[32mSo Long Compiled!\n"

clean:
						@rm -f ${OBJS} ${OBJS_B}

fclean:     clean
						@rm -f $(NAME)
						@rm -f ${PROG}
						@echo "\n\033[31mDeleting EVERYTHING!\n"

re:            fclean all

.PHONY: all clean fclean re