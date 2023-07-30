NAME = cub3D 

############ SOURCE #########################

INIT :=	\

EXIT_CLEAR :=	src/exit_clear/close_map.c	\

PARSING :=		src/parsing/parsing.c				\
				src/parsing/parse_texture.c			\
				src/parsing/path_texture.c			\
				src/parsing/parse_map.c				\
				src/parsing/wall_around.c		\
		
EXIT_CLEAR :=	src/exit_clear/close_map.c			\
				
ERROR :=		src/error/msg_err_parsing.c			\

SRC = src/main.c									\
		${INIT}										\
		${PARSING}									\
		${EXIT_CLEAR}								\
		${ERROR}									\

############ FLAGS #########################

FLAG = -Wall -Werror -Wextra -g

OBJ = $(SRC:.c=.o)

############ colors #########################

RED		= \033[38;5;9m
GREEN	= \033[38;5;76m
ORANGE	= \033[38;5;11m

%.o: %.c
	@clang $(FLAG) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft -s && echo "$(GREEN)libft compiled"
	@clang $(FLAG) $(OBJ) libft/libft.a -o $(NAME) \
	| echo "$(ORANGE)XXXXXXXXXXXXXXXXXX\n \
	cub3d COMPILED\n\
	XXXXXXXXXXXXXXXXXX"

clean:
	@rm -f $(OBJ)
	@make clean -C libft -s && echo "$(YELLOW)object files cleaned"

fclean: clean
	@rm -f $(NAME)
	@make fclean -C libft -s && echo "$(RED)all clean"

re: fclean all

.PHONY : all clean fclean re
