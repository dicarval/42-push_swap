# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dicarval <dicarval@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/10 17:26:39 by dicarval          #+#    #+#              #
#    Updated: 2024/07/23 16:08:08 by dicarval         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= push_swap

# Directories
PRINTF			= ./ft_printf/libftprintf.a
HEADER			= header/
SRC_DIR			= srcs/
OBJ_DIR			= obj/

# Compiler and CFlags
CC				= cc
CFLAGS			= -Wall -Werror -Wextra -I
RM				= rm -f

# Source Files
COMMANDS_DIR	=	$(wildcard srcs/commands/*.c)
STACK_DIR		=	$(wildcard srcs/stack/*.c)

# Concatenate all source files
SRCS 			= $(COMMANDS_DIR) $(STACK_DIR)

# Apply the pattern substitution to each source file in SRC and produce a corresponding list of object files in the OBJ_DIR
OBJ 			= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

# Build
all: 			$(NAME)

$(PRINTF):
				@make -s -C ./ft_printf

$(NAME): 		$(OBJ) $(PRINTF)
				@$(CC) $(CFLAGS) $(HEADER) $(OBJ) $(PRINTF) -o $(NAME)
				@echo "Push Swap - Object files created"
				@echo "Push Swap - Executable created"

# Compile object files from source files
$(OBJ_DIR)%.o:	$(SRC_DIR)%.c
				@mkdir -p $(@D)
				@$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

# Bonus
BNAME			= ../checker/checker

bonus:			$(BNAME)

$(BNAME):
				@make -s -C ../checker

# Clean
clean:
				@$(RM) -r $(OBJ_DIR)
				@make clean -s -C ./ft_printf
				@echo "Push Swap - Object files deleted"

fclean: 		clean
				@$(RM) $(NAME)
				@$(RM) $(PRINTF)
				@echo "Push Swap - Executable deleted"
				@cd ../checker && make fclean -s

re: 			fclean all

# Phony targets represent actions not files
.PHONY: 		all clean fclean re
