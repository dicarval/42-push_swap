# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/18 10:55:34 by dicarval          #+#    #+#              #
#    Updated: 2024/09/16 16:13:01 by dicarval         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 				= checker
ARCHIVE				= libchecker.a
ARC_PRINTF			= ../push_swap/ft_printf/libftprintf.a
SRCS_PS_DIR			= ../push_swap/srcs/
OBJS_PS_DIR			= ./push_swap_o/
GNL_DIR				= ./gnl/

# Compiler and CFlags
CC 					= cc
CFLAGS 				= -Wall -Wextra -Werror
MAKE_LIB 			= ar -rcs
RM					= rm -f

# Source Files

SRCS_CMD	= $(SRCS_PS_DIR)commands/command_utils.c $(SRCS_PS_DIR)commands/push.c $(SRCS_PS_DIR)commands/rev_rotate.c \
				$(SRCS_PS_DIR)commands/rotate.c $(SRCS_PS_DIR)commands/sort_stacks.c $(SRCS_PS_DIR)commands/sort_three.c \
				$(SRCS_PS_DIR)commands/swap.c

SRCS_STACK		= $(SRCS_PS_DIR)stack/error_handling.c $(SRCS_PS_DIR)stack/prep_a_to_b.c $(SRCS_PS_DIR)stack/prep_b_to_a.c \
				$(SRCS_PS_DIR)stack/push_swap.c $(SRCS_PS_DIR)stack/stack_initialzt.c $(SRCS_PS_DIR)stack/stack_utils.c

# Concatenate all source files
SRCS				= checker.c $(GNL_DIR)get_next_line_utils.c $(GNL_DIR)get_next_line.c
SRCS_PS				= $(SRCS_STACK) $(SRCS_CMD)

# Object Files
OBJS				= $(SRCS:.c=.o)
OBJS_PS				= $(patsubst $(SRCS_PS_DIR)%.c, $(OBJS_PS_DIR)%.o, $(SRCS_PS))

# Build
all:				$(NAME)

$(ARC_PRINTF):
					@make -s -C ../push_swap/ft_printf

$(ARCHIVE):			$(OBJS) $(OBJS_PS)
					@$(MAKE_LIB) $(ARCHIVE) $^

$(NAME):			$(ARCHIVE) $(ARC_PRINTF)
					@$(CC) $(CFLAGS) $^ -o $@
					@echo "Checker - Object files created"
					@echo "Checker - Executable created"

# Compile object files from source files
%.o:				%.c
					@$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_PS_DIR)%.o:	$(SRCS_PS_DIR)%.c
					@mkdir -p $(@D)
					@$(CC) $(CFLAGS) -c $< -o $@

clean:
					@$(RM) $(OBJS) -r $(OBJS_PS_DIR)
					@$(RM) ../push_swap/ft_printf/*.o
					@echo "Checker - Object files deleted"

fclean: 			clean
					@$(RM) $(NAME)
					@$(RM) $(ARCHIVE) $(ARC_PRINTF)
					@echo "Checker - Executable file deleted"
					@echo "Checker - Archives files deleted"
re: 				fclean all

# Phony targets represent actions not files
.PHONY: 			all clean fclean re


