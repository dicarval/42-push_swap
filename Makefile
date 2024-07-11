# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dicarval <dicarval@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/10 17:26:39 by dicarval          #+#    #+#              #
#    Updated: 2024/07/11 17:08:20 by dicarval         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= push_swap

#Directories
PRINTF			= ./ft_printf/libftprintf.a
HEADER			= ./push_swap/header
SRCDIR			= ./push_swap/srcs
OBJDIR			= ./push_swap/obj

# Compiler and CFlags
CC				= cc
CFLAGS			= -Wall -Werror -Wextra -I
RM				= rm -f

# Source Files
COMMANDS_DIR	=	$(SRC_DIR)commands/command_utils.c \
					$(SRC_DIR)commands/push.c \
					$(SRC_DIR)commands/rev_rotate.c \
					$(SRC_DIR)commands/rotate.c \
					$(SRC_DIR)commands/sort_stacks.c \
					$(SRC_DIR)commands/sort_three.c \
					$(SRC_DIR)commands/swap.c

STACK_DIR		=	$(SRC_DIR)stack/error_handling.c \
					$(SRC_DIR)stack/prep_a_to_b.c \
					$(SRC_DIR)stack/prep_b_to_a.c \
					$(SRC_DIR)stack/main.c \
					$(SRC_DIR)stack/stack_initialzt.c \
					$(SRC_DIR)stack/stack_utils.c

# Concatenate all source files
SRCS 			= $(COMMANDS_DIR) $(STACK_DIR)

# Apply the pattern substitution to each source file in SRC and produce a corresponding list of object files in the OBJ_DIR
OBJ 			= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

# Build

all: 			$(NAME)

$(PRINTF):
				@make -C ./ft_printf

$(NAME): 		$(OBJ) $(PRINTF)
				@$(CC) $(CFLAGS) $(HEADER) $(OBJ) $(PRINTF) -o $(NAME)

# Compile object files from source files
$(OBJ_DIR)%.o:	$(SRC_DIR)%.c
				@mkdir -p $(@D)
				@$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

clean:
				@$(RM) -r $(OBJ_DIR)
				@make clean -C ./ft_printf

fclean: 		clean
				@$(RM) $(NAME)
				@$(RM) $(PRINTF)

re: 			fclean all

# Phony targets represent actions not files
.PHONY: 		all clean fclean re
