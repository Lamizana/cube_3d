NAME = cub3D 

############ SOURCE #########################

INIT :=			src/structure_init/texture_init.c	\

EXIT_CLEAR :=	src/exit_clear/close_map.c			\

PARSING :=		src/parsing/parsing.c				\
				src/parsing/parse_map.c				\
				src/parsing/wall_around.c		\
				src/parsing/parse_texture.c			\
				src/parsing/texture_cmds.c			\
				src/parsing/texture_path.c			\
				src/parsing/texture_colors.c		\
				src/parsing/texture_utils.c			\
		
EXIT_CLEAR :=	src/exit_clear/close_map.c			\
				
ERROR :=		src/error/msg_err_parsing.c			\

SRC = src/main.c									\
		${INIT}										\
		${PARSING}									\
		${EXIT_CLEAR}								\
		${ERROR}									\

################## FLAGS #########################

FLAG = -Wall -Werror -Wextra -g

OBJ = $(SRC:.c=.o)

################## COLORS #########################

RED		= \033[38;5;9m
GREEN	= \033[38;5;76m
ORANGE	= \033[38;5;11m

%.o: %.c
	@clang $(FLAG) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft -s && echo "$(GREEN)libft compiled"
	@clang $(FLAG) $(OBJ) libft/libft.a -o $(NAME) \
	| echo "$(ORANGE)XXXXXXXXXXXXXXXX\n \
	cub3d COMPILED\n\
	XXXXXXXXXXXXXXXX"

clean:
	@rm -f $(OBJ)
	@make clean -C libft -s && echo "$(YELLOW)object files cleaned"

fclean: clean
	@rm -f $(NAME)
	@make fclean -C libft -s && echo "$(RED)all clean"

re: fclean all

.PHONY : all clean fclean re
