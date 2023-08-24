NAME = cub3D 

###################  SOURCE  ########################

INIT :=			src/init/texture_init.c				\
				src/init/init_param.c				\

EXIT_CLEAR :=	src/exit_clear/close_map.c			\

PARSING :=		src/parsing/parsing.c				\
				src/parsing/parse_map.c				\
				src/parsing/wall_around.c			\
				src/parsing/parse_texture.c			\
				src/parsing/texture_cmds.c			\
				src/parsing/texture_path.c			\
				src/parsing/texture_colors.c		\
				src/parsing/texture_utils.c			\
		
EXIT_CLEAR :=	src/exit_clear/close_map.c			\
				
ERROR :=		src/error/msg_err_parsing.c			\

GRAPH :=		src/graphic/ft_mlx.c				\
				src/graphic/create_img.c			\
				src/graphic/3d/move.c					\
				

SRC = src/main.c									\
		${INIT}										\
		${PARSING}									\
		${EXIT_CLEAR}								\
		${ERROR}									\
		${GRAPH}									\

##################### FLAGS #########################

FLAG = -Wall -Werror -Wextra -g

FLAGMLX = -Iinclude -ldl -lglfw -pthread -lm

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
	@make -C MLX42/build -s && echo "$(GREEN)MINILIBX compiled"
	@clang $(FLAG) $(OBJ) libft/libft.a MLX42/build/libmlx42.a $(FLAGMLX) -o $(NAME) \
	| echo "$(ORANGE)XXXXXXXXXXXXXXXX\n \
	cub3d COMPILED\n\
	XXXXXXXXXXXXXXXX"

clean:
	@rm -f $(OBJ)
	@make clean -C libft -s && echo "$(YELLOW)object files cleaned"
	@-rm -f MLX42/build/libmlx42.a 
	
fclean: clean
	@rm -f $(NAME)
	@make fclean -C libft -s && echo "$(RED)all clean"
	@rm -f  MLX42/build/libmlx42.a 
re: fclean all

.PHONY : all clean fclean re
