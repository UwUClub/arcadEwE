##
## EPITECH PROJECT, 2022
## SFMLgame
## File description:
## Makefile
##

# -----------------------------------------------------------
# Target

NAME = Game

#------------------------------------------------------------
# COLOUR

CYAN = '\033[1;36m'
GREEN = '\033[1;32m'
RED = '\033[1;31m'
BLUE = '\033[1;34m'

RESET = '\033[0m'

#------------------------------------------------------------
# IN-MAKEFILE

CURR_RULE = all
#CC := gcc	# Uncomment this line if you want to use gcc
CC := g++  # Uncomment this line if you want to use g++

#------------------------------------------------------------
# SRC

SRCDIR := src/

SRC := main.cpp

SRC := $(addprefix $(SRCDIR),$(SRC))

FILE := %.cpp #replace with "%.c" if you want to use gcc

OBJ := $(SRC:%.cpp=%.o) #replace with "%.c" if you want to use gcc

#------------------------------------------------------------
# FLAGS

CFLAGS = -I./include/ -Wall -Wextra -Wpedantic -lsfml-system -lsfml-window -lsfml-graphics -lsfml-audio -g3

#------------------------------------------------------------
# MAIN

%.o: $(FILE)
	@$(CC) $(CFLAGS) $^ -c -o $@
	@echo -e $(BLUE)'compil : $(notdir $^) -> $(notdir $@)'$(RESET)

#------------------------------------------------------------
# Make the name

.PHONY: all
all: CURR_RULE = all
all: init $(OBJ)
	@$(MAKE) $(NAME) -s
	@echo -e $(GREEN)'-> [finished]: $(NAME): all'$(RESET)

$(NAME): CURR_RULE = $(NAME)
$(NAME): init $(OBJ)
	@$(CC) $(OBJ) $(MAIN_OBJ) -o $(NAME) $(CFLAGS)
	@echo -e $(GREEN)'-> [finished]: $(NAME): $(NAME)'$(RESET)

#------------------------------------------------------------
# Clean

.PHONY : clean
clean:
	@$(RM) $(OBJ) $(TOBJ)
	@$(RM) $(TOBJ:.o=.gcno) $(TOBJ:.o=.gcda) $(OBJ:.o=.gcno) $(OBJ:.o=.gcda)
	@$(RM) vgcore.*

#------------------------------------------------------------
# fclean

.PHONY: fclean
fclean: CURR_RULE = fclean
fclean: init clean
	@$(RM) $(NAME) $(TNAME)
	@echo -e $(GREEN)'-> [finished]: $(NAME): $(CURR_RULE)'$(RESET)

#------------------------------------------------------------
# Re

.PHONY: re
re:		CURR_RULE = re
re:		init
	@$(MAKE) fclean -s
	@$(MAKE) all -s
	@echo -e $(GREEN)'-> [finished]: $(NAME): $(CURR_RULE)'$(RESET)

#------------------------------------------------------------
# Print

.PHONY: init
init:
	@echo -e $(CYAN)'-> [starting]: $(NAME): make $(CURR_RULE)'$(RESET)