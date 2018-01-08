# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdelhomm <sdelhomm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/10 14:43:54 by sdelhomm          #+#    #+#              #
#    Updated: 2018/01/08 13:40:51 by sdelhomm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = fdf

FLAGS = -Wall -Wextra -Werror

SRC =	main.c \
		draw_line.c \
		fill_cont_h.c \
		fill_cont_v.c \
		ft_events.c \
		ft_get_cont.c \
		ft_get_size.c \
		ft_stock_value.c \
		get_cont_size.c \
		check_map.c \
		ft_show_info.c

OBJ =	main.o \
		draw_line.o \
		fill_cont_h.o \
		fill_cont_v.o \
		ft_events.o \
		ft_get_cont.o \
		ft_get_size.o \
		ft_stock_value.o \
		get_cont_size.o \
		check_map.o \
		ft_show_info.o

all: $(NAME)

$(NAME):
	@make -C libft/
	@echo "\033[33;32m=== COMPILATION DE LA LIBFT ===\t\t\t\t[ ✓ ]"
	@gcc $(FLAGS) -I libft/ -c $(SRC)
	@echo "\033[33;32m=== CREATION DES OBJETS ===\t\t\t\t[ ✓ ]"
	@gcc -o $(NAME) $(OBJ) $(FLAGS) -L libft/ -lft -lmlx -framework OpenGL -framework AppKit
	@echo "\033[33;32m=== CREATION DE L'EXECUTABLE \"$(NAME)\" ===\t\t\t[ ✓ ]"

clean:
	@make -C libft/ clean
	@/bin/rm -f $(OBJ)

fclean: clean
	@make -C libft/ fclean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re