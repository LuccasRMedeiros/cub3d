# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/14 15:24:43 by lrocigno          #+#    #+#              #
#    Updated: 2021/07/16 14:31:58 by lrocigno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BIN = cub3D

RULE = all

MAKE_EXT = make --no-print-directory -C $(MAKEFILE) $(RULE)

MSG_DONE = echo " -- Done!"

define CUBED

	                           ***
	                        ***###***
	                     ***#++:::++#***
	                  ***+::         ::+***
	               ***:.                 .:***
	               |++***               ***++|
	               |#+++:***         ***:+++#|
	               |#+++::..***   ***..::+++#|
	               |#+++::..   ***   ..::+++#|
	               |#+++:::..   |   ..:::+++#|
	               |#+++:::..   |   ..:::+++#|
	               ***++:::...  |  ...:::++***
	                  ***+::..  |  ..::+***
	                     ***::. | .::***
	                        ***.|.***
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

CC = clang

FLAGS = -Wall -Wextra -Werror

LIBFT =	./src/libs/libft

MLBX = 	./src/libs/minilibx-linux

INCLUDES =	-I src/libs/libft/headers \
			-I src/libs/minilibx-linux \
			-I src/core \
			-I src/error \
			-I src/draw \
			-I src/structs \
			-I src/world \

LIBS =  -L$(LIBFT) -lft \
		-L$(MLBX) -lmlx_Linux \
		-lX11 \
		-lXext \
		-lm \
		-lz \

ROOT_SRC = ./src

ROOT_OBJ = ./obj

SRC = 	$(addprefix core/, $(notdir $(wildcard ./src/core/*.c))) \
		$(addprefix draw/, $(notdir $(wildcard ./src/draw/*.c))) \
		$(addprefix error/, $(notdir $(wildcard ./src/error/*.c))) \
		$(addprefix structs/, $(notdir $(wildcard ./src/structs/*.c))) \
		$(addprefix world/, $(notdir $(wildcard ./src/world/*.c))) \

SRC_FULL = $(addprefix $(ROOT_SRC)/, $(SRC))

OBJ = $(SRC:%.c=%.o)

OBJ_FULL = $(addprefix $(ROOT_OBJ)/, $(OBJ))

all: $(BIN)
	@echo "$$CUBED"
	@$(MSG_DONE)

$(BIN): makeft makemlx
	@echo "\n"
	@echo "Generating excutable $(BIN)"
	@$(CC) $(FLAGS) ./src/cub3d.c $(SRC_FULL) $(INCLUDES) $(LIBS) -o $(BIN)
	@echo "To use it call ./$(BIN) maps/map.cub"
	@echo "\n"

makeft: MAKEFILE = $(LIBFT)

makeft:
	@echo "Making dependencies 1/2"
	@$(MAKE_EXT)

makemlx: MAKEFILE = $(MLBX)

makemlx: RULE = all

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
	@echo "Removing objects"
	@echo "NOTE: Both source code and executable will be preserved"
	@rm -rf $(ROOT_OBJ)
	@$(MSG_DONE)

debug: RULE = debug

debug: FLAGS += -g

debug: fclean $(BIN)
	@echo "Generated new excutable $(BIN) with -g flag"
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
	@echo "Removing objects and executable"
	@echo "NOTE: Source code will be preserved"
	@rm -rf $(ROOT_OBJ)
	@rm -f $(BIN)
	@$(MSG_DONE)

re: fclean all

.PHONY: all clean cleanft cleanmlx fclean fcleanft fcleanmlx makeft makemlx re
