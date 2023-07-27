# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nminotte <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/03 14:00:01 by nminotte          #+#    #+#              #
#    Updated: 2023/07/27 13:42:21 by nminotte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a

CONV=./convert
GNL=./gnl
LST=./lst
MEM=./mem
PRINT=./print
STACK=./stack
STR=./str
TSTR=./test_str

SRC = $(CONV)/ft_atoi.c \
	$(CONV)/ft_atoi_color.c \
	$(CONV)/ft_itoa.c \
	$(CONV)/ft_tolower.c \
	$(CONV)/ft_toupper.c \
	$(GNL)/get_next_line.c \
	$(GNL)/get_next_line_utils.c \
	$(GNL)/get_line.c \
	$(LST)/ft_lstadd_back.c \
	$(LST)/ft_lstadd_front.c \
	$(LST)/ft_lstclear.c \
	$(LST)/ft_lstdelone.c \
	$(LST)/ft_lstiter.c \
	$(LST)/ft_lstlast.c \
	$(LST)/ft_lstmap.c \
	$(LST)/ft_lstnew.c \
	$(LST)/ft_lstsize.c \
	$(MEM)/ft_bzero.c \
	$(MEM)/ft_calloc.c \
	$(MEM)/ft_memchr.c \
	$(MEM)/ft_memcmp.c \
	$(MEM)/ft_memcpy.c \
	$(MEM)/ft_memmove.c \
	$(MEM)/ft_memset.c \
	$(PRINT)/ft_printf.c \
	$(PRINT)/ft_putaddress.c \
	$(PRINT)/ft_putbase.c \
	$(PRINT)/ft_putchar_fd.c \
	$(PRINT)/ft_putendl_fd.c \
	$(PRINT)/ft_putnbr_fd.c \
	$(PRINT)/ft_putnbr_unsign.c \
	$(PRINT)/ft_putstr_fd.c \
	$(STACK)/ft_push.c \
	$(STACK)/ft_stackdelone.c \
	$(STACK)/ft_stackclear.c \
	$(STACK)/ft_stackfind.c \
	$(STACK)/ft_stacklast.c \
	$(STACK)/ft_stacknew.c \
	$(STACK)/ft_stackreverse_rotate.c \
	$(STACK)/ft_stackrotate.c \
	$(STACK)/ft_stacksize.c \
	$(STACK)/ft_stackswap.c \
	$(STR)/ft_split.c \
	$(STR)/ft_strchr.c \
	$(STR)/ft_strdup.c \
	$(STR)/ft_striteri.c \
	$(STR)/ft_strjoin.c \
	$(STR)/ft_strlcat.c \
	$(STR)/ft_strlcpy.c \
	$(STR)/ft_strlen.c \
	$(STR)/ft_strmapi.c \
	$(STR)/ft_strncmp.c \
	$(STR)/ft_strnstr.c \
	$(STR)/ft_strrchr.c \
	$(STR)/ft_strrchr_pipex.c \
	$(STR)/ft_strtrim.c \
	$(STR)/ft_substr.c \
	$(STR)/ft_freestrs.c \
	$(TSTR)/ft_isalnum.c \
	$(TSTR)/ft_isalpha.c \
	$(TSTR)/ft_isascii.c \
	$(TSTR)/ft_isdigit.c \
	$(TSTR)/ft_isprint.c \
	$(TSTR)/ft_to_find.c \
	$(TSTR)/ft_char_in_set.c \

OBJS = $(SRC:.c=.o)

CC = clang

CFLAGS = -Wall -Werror -Wextra -g

all : ${NAME}

$(NAME) : $(OBJS)
	ar rc $(NAME) $(OBJS)

clean :
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean re fclean
