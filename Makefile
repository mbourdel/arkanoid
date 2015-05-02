# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/02 13:17:21 by mbourdel          #+#    #+#              #
#    Updated: 2015/05/02 15:50:23 by mbourdel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = arkanoid

SRC = ./src/xxxxx.c
SRC += ./src/yyyyyy.c

OBJ += 

LIBFT = ./libft/libft.a

GLFW = ./glfw/src/libglfw3.a

LIBRARY = $(LIBFT) $(GLFW)

FRAM = -framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo

GCC = gcc -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	@git submodule init
	@git submodule update
	@cd glfw; CMake CMakeLists.txt; cd src; $(MAKE) -f Makefile
	@cd libft; $(MAKE) -f Makefile
	@$(GCC) $(FRAM) -o $(NAME) $(SRC) $(LIBFT) $(GLFW)

clean:
	@rm $(OBJ)

fclean: clean
	@rm $(NAME)
