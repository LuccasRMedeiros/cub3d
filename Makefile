# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/14 15:24:43 by lrocigno          #+#    #+#              #
#    Updated: 2021/05/18 18:24:06 by lrocigno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BIN = cub3D

RULE = all

MAKE_EXT = make -C $(MAKEFILE) $(RULE)

MSG_DONE = echo " -- Done!"

define CUBED

                         ***
                      ***   ***
                   ***         ***
                ***               ***
             ***                     ***
             |#+***               ***++|
             |#+++:***         ***:::++|
             |#+++:::.***   ***...:::++|
             |#+++:::... ***   ...:::++|
             |#+++:::...  |    ...:::++|
             |#+++:::...  |    ...:::++|
             ***++:::...  |    ...:::***
                ***::...  |    ...***
                   ***..  |    ***
                      *** | ***
                         ***

  ______    __    __    ______     _______     _______
 ///////|  ///|  ///|  ///////\   ////////\   ////////\\
/  ____|/  | ||  | ||  |  _  \|   |____  \/   |  __  \/
| ||       | ||  | ||  | |/| |\     ///\ /|   | || \ ||
| ||____   | ||__| ||  |  __ \/|   _|__  |/\  | ||_| ||
| |/////|  | |///| |/  | |//| |/  //////  \/  | |/// |/
\______|/  \_______/   |______/   |_______/   |______/

endef
export CUBED

CC = clang

FLAGS = -Wall -Wextra -Werror

INCLUDES =	-I src/libs/libft/headers \
			-I src/libs/minilibx-linux \
			-I src/core \
			-I src/error \
			-I src/draw \

LIBFT =	./src/libs/libft

MLBX = 	./src/libs/minilibx-linux

LIBS =  -L$(LIBFT) -lft \
		-L$(MLBX) -lmini_Linux \

SRC = 	$(addprefix core/, $(notdir $(wildcard ./src/core/*.c))) \
		$(addprefix core/structs/, $(notdir $(wildcard ./src/core/structs/*.c))) \
		$(addprefix draw/, $(notdir $(wildcard ./src/draw/*.c))) \
		$(addprefix error/, $(notdir $(wildcard ./src/error/*.c))) \

OBJ = $(SRC:%.c=%.o)

SRC_FULL = $(addprefix ./src/, $(SRC))

OBJ_FULL = $(addprefix ./out/, $(OBJ))

all: $(BIN)
	@echo "$$CUBED"
	@$(MSG_DONE)

$(BIN): makedeps makeft makemlx
	@echo "Generating excutable $(BIN)"
	$(CC) $(FLAGS) $(INCLUDES) $(LIBS) -o $(BIN) $(OBJ_FULL) -c ./src/cub3d.c $(SRC_FULL)
	@echo "To use it call ./$(BIN) maps/map.cub"

makedeps:
	@echo "Creating 'out' folder and its subdirectories"
	@mkdir -p ./out
	@echo "Creating 'core' sub directory"
	@mkdir -p ./out/core
	@echo "Creating 'core/structs' sub directory"
	@mkdir -p ./out/core/structs
	@echo "Creating 'draw' sub directory"
	@mkdir -p ./out/draw
	@echo "Creating 'error' sub directory"
	@mkdir -p ./out/error
	@$(MSG_DONE)


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
	@echo "Removing object files"
	@rm -rf ./out

fcleanft: MAKEFILE = $(LIBFT)

fcleanft: RULE = fclean

fcleanft:
	@echo "Removing dependencies 1/2"
	@$(MAKE_EXT)

fcleanmlx: MAKEFILE = $(MLBX)

fcleanmlx: RULE = fclean

fcleanmlx:
	@echo "Removing dependencies 1/2"
	@$(MAKE_EXT)

fclean: RULE = fclean

fclean: fcleanft fcleanmlx
	@echo "Removing object files"
	@rm -rf ./out
	@echo "Removing executable"
	@echo "Source code will be preserved"
	@rm -f $(BIN)

re: fclean all

.PHONY: all clean cleanft cleanmlx fclean fcleanft fcleanmlx makeft makemlx re
