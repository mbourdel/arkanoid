# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/02 14:04:17 by jbahus            #+#    #+#              #
#    Updated: 2015/05/02 21:11:49 by mbourdel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = arkanoid

SRC = arkanoid.c
SRC += draw_form.c

OBJ = $(SRC:.c=.o)

LIBFT = ./libft/libft.a

GLFW = ./glfw/src/libglfw3.a

LIBRARY = $(LIBFT) $(GLFW)

FRAM = -framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo

GCC = gcc -Wall -Werror -Wextra

all: $(NAME)

$(NAME):$(OBJ)
	@git submodule init
	@git submodule update
	@cd glfw; CMake CMakeLists.txt; cd src; $(MAKE) -f Makefile
	@cd libft; $(MAKE) -f Makefile
	@$(GCC) $(FRAM) -o $(NAME) $(OBJ) $(LIBRARY)
	@echo "[=================]"
	@echo "|     succes !    |"
	@echo "|     arkanoid    |"
	@echo "|   was summoned  |"
	@echo "[=================]"

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
