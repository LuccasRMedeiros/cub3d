# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/14 15:24:43 by lrocigno          #+#    #+#              #
#    Updated: 2021/05/25 13:00:03 by lrocigno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BIN = cub3D

RULE = all

MAKE_EXT = make --no-print-directory -C $(MAKEFILE) $(RULE)

MSG_DONE = echo " -- Done!"

define CUBED

	                           ***
	                        ***   ***
	                     ***         ***
	                  ***               ***
	               ***                     ***
	               |++***               ***++|
	               |#+++:***         ***:+++#|
	               |#+++:...***   ***...:+++#|
	               |#+++::..   ***   ..::+++#|
	               |#+++:::..   |   ..:::+++#|
	               |#+++:::..   |   ..:::+++#|
	               ***++:::...  |  ...:::++***
	                  ***+:...  |  ...:+***
	                     ***::..|..::***
	                        ***+|+***
	                           ***
	  ______    __    __    _______     _______     _______
	 ///////|  ///|  ///|  ////////\   ////////\   /////////\\
	/  ____|/  | ||  | ||  |  __  \|   |____  \/   |  ___  \/
	| ||       | ||  | ||  | |//| |\     ///\ /|   | ||  \ ||
	| ||____   | ||__| ||  |  ___ \/|   _|__  |/\  | ||__| ||
	| |/////|  | |///| |/  | |///| |/  //////  \/  | |//// |/
	\______|/  \_______/   |_______/   |_______/   |_______/

endef
export CUBED

CC = gcc

FLAGS = -Wall -Wextra -Werror

LIBFT =	./src/libs/libft

MLBX = 	./src/libs/minilibx-linux

INCLUDES =	-I src/libs/libft/headers \
			-I src/libs/minilibx-linux \
			-I src/core \
			-I src/error \
			-I src/draw \
			-I src/world \

LIBS =  -L$(LIBFT) -lft \
		-L$(MLBX) -mlx_Linux \
		-lX11 \
		-lXext \

SRC = 	$(addprefix core/, $(notdir $(wildcard ./src/core/*.c))) \
		$(addprefix core/error/, $(notdir $(wildcard ./src/core/error/*.c))) \
		$(addprefix draw/, $(notdir $(wildcard ./src/draw/*.c))) \
		$(addprefix error/, $(notdir $(wildcard ./src/error/*.c))) \
		$(addprefix world/, $(notdir $(wildcard ./src/world/*.c))) \
		$(addprefix world/structs/, $(notdir $(wildcard ./src/world/structs/*.c))) \
		$(addprefix world/error/, $(notdir $(wildcard ./src/world/error/*.c))) \

SRC_FULL = $(addprefix ./src/, $(SRC))

all: $(BIN)
	@echo "$$CUBED"
	@$(MSG_DONE)

$(BIN): makeft makemlx
	@echo "Generating excutable $(BIN)"
	@$(CC) $(FLAGS) ./src/cub3d.c $(SRC_FULL) $(INCLUDES) $(LIBS) -o $(BIN)
	@echo "To use it call ./$(BIN) maps/map.cub"

makeft: MAKEFILE = $(LIBFT)

makeft:
	@echo "Making dependencies 1/2"
	@$(MAKE_EXT)

makemlx: MAKEFILE = $(MLBX)

makemlx:
	@echo "Making dependencies 2/2"
	@$(MAKE_EXT)

cleanft: MAKEFILE = $(LIBFT)

cleanft: RULE = clean

cleanft:
	@echo "Cleaning dependencies 1/2"
	@$(MAKE_EXT)

cleanmlx: MAKEFILE = $(MLBX)

cleanmlx: RULE = clean

cleanmlx:
	@echo "Cleaning dependencies 2/2"
	@$(MAKE_EXT)

clean: RULE = clean

clean: cleanft cleanmlx

debug: RULE = debug

debug: FLAGS += -g

debug: MAKEFILE = $(LIBFT)

debug:
	@echo "Preparing the program to debug"
	@$(MAKE_EXT)
	@echo "Removing executable"
	@rm -f $(BIN)
	@echo "Generating new excutable $(BIN) with -g flag"
	@$(CC) $(FLAGS) ./src/cub3d.c $(SRC_FULL) $(INCLUDES) $(LIBS) -o $(BIN)
	@echo "$$CUBED"
	@echo " -- Ready to debug!"

fcleanft: MAKEFILE = $(LIBFT)

fcleanft: RULE = fclean

fcleanft:
	@echo "Removing dependencies 1/2"
	@$(MAKE_EXT)

fcleanmlx: MAKEFILE = $(MLBX)

fcleanmlx: RULE = fclean

fclean: RULE = fclean

fclean: fcleanft cleanmlx
	@echo "Removing executable"
	@echo "Source code will be preserved"
	@rm -f $(BIN)
	@$(MSG_DONE)

re: fclean all

.PHONY: all clean cleanft cleanmlx fclean fcleanft fcleanmlx makeft makemlx re
