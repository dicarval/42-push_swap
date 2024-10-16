# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/18 10:55:34 by dicarval          #+#    #+#              #
#    Updated: 2024/10/16 11:42:11 by dicarval         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 				= checker

# Directories
SRCS_CHK_DIR		= ./srcs/
OBJS_CHK_DIR		= ./objects/

SRCS_PS_DIR			= ../push_swap/srcs/
OBJS_PS_DIR			= ./ps_objects/
GNL_DIR				= ./gnl/

# Compiler and CFlags
CC 					= cc
CFLAGS 				= -Wall -Wextra -Werror
HEADER				= -Iheader
MAKE_LIB 			= ar -rcs
RM					= rm -f

# Source files
SRCS_CMD			= $(SRCS_PS_DIR)commands/command_utils.c $(SRCS_PS_DIR)commands/push.c $(SRCS_PS_DIR)commands/rev_rotate.c \
					$(SRCS_PS_DIR)commands/rotate.c $(SRCS_PS_DIR)commands/sort_stacks.c $(SRCS_PS_DIR)commands/sort_three.c \
					$(SRCS_PS_DIR)commands/swap.c

SRCS_STACK			= $(SRCS_PS_DIR)stack/error_handling.c $(SRCS_PS_DIR)stack/prep_a_to_b.c $(SRCS_PS_DIR)stack/prep_b_to_a.c \
					$(SRCS_PS_DIR)stack/push_swap.c $(SRCS_PS_DIR)stack/stack_initialzt.c $(SRCS_PS_DIR)stack/stack_utils.c

# Concatenate all source files
SRCS_CHK			= $(SRCS_CHK_DIR)checker.c $(SRCS_CHK_DIR)checker_utils.c
SRCS_PS				= $(SRCS_STACK) $(SRCS_CMD)
SRCS_GNL			= $(GNL_DIR)get_next_line.c $(GNL_DIR)get_next_line_utils.c

# Object files / libraries
ARC_PRINTF			= libftprintf.a
ARCHIVE				= libchecker.a
OBJS_CHK			= $(patsubst $(SRCS_CHK_DIR)%.c, $(OBJS_CHK_DIR)%.o, $(SRCS_CHK))
OBJS_PS				= $(patsubst $(SRCS_PS_DIR)%.c, $(OBJS_PS_DIR)%.o, $(SRCS_PS))
OBJS_GNL			= $(SRCS_GNL:.c=.o)

# Build
all:				$(NAME)
					@echo "Checker - All set"

$(ARC_PRINTF):
					@make -s -C ../push_swap/ft_printf
					@cp ../push_swap/ft_printf/libftprintf.a ./
					@$(RM) ../push_swap/ft_printf/*.o

$(ARCHIVE):			$(OBJS_CHK) $(OBJS_PS) $(OBJS_GNL)
					@echo "Checker - Object files created"
					@$(MAKE_LIB) $(ARCHIVE) $^
					@echo "Checker - Archive file created"

$(NAME):			$(ARCHIVE) $(ARC_PRINTF)
					@$(CC) $(CFLAGS) $^ -o $@
					@echo "Checker - Executable created"

# Compile object files from source files
$(GNL_DIR)%.o:		$(GNL_DIR)%.c
					@$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_CHK_DIR)%.o:	$(SRCS_CHK_DIR)%.c
					@mkdir -p $(@D)
					@$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

$(OBJS_PS_DIR)%.o:	$(SRCS_PS_DIR)%.c
					@mkdir -p $(@D)
					@$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

clean:
					@$(RM) -r $(OBJS_PS)
					@$(RM) -r $(OBJS_PS_DIR)
					@$(RM) -r $(OBJS_CHK)
					@$(RM) -r $(OBJS_CHK_DIR)
					@$(RM) -r $(OBJS_GNL)
					@echo "Checker - Object files deleted"

fclean: 			clean
					@$(RM) $(NAME)
					@echo "Checker - Executable file deleted"
					@$(RM) $(ARCHIVE) $(ARC_PRINTF)
					@echo "Checker - Archives files deleted"
					@echo "Checker - All clean"

re: 				fclean all

# Phony targets represent actions not files
.PHONY: 			all clean fclean re


