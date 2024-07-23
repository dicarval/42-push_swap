# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dicarval <dicarval@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/18 10:55:34 by dicarval          #+#    #+#              #
#    Updated: 2024/07/23 15:53:56 by dicarval         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 				= checker
ARCHIVE				= libchecker.a
ARC_PRINTF			= ../push_swap/ft_printf/libftprintf.a
SRCS_PS_DIR			= ../push_swap/srcs/
OBJS_PS_DIR			= ./push_swap_o/

# Compiler and CFlags
CC 					= @cc
CFLAGS 				= -Wall -Wextra -Werror
MAKE_LIB 			= ar -rcs
RM					= rm -f
RM_EXTERNAL			= rm -f $(wildcard ../push_swap/ft_printf/*.o)

# Source Files
SRCS_STACK			= $(wildcard ../push_swap/srcs/stack/*.c)
SRCS_CMD			= $(wildcard ../push_swap/srcs/commands/*.c)

# Concatenate all source files
SRCS				= checker.c $(wildcard ./gnl/*.c)
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

# Compile object files from source files
%.o:				%.c
					@$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_PS_DIR)%.o:	$(SRCS_PS_DIR)%.c
					@mkdir -p $(@D)
					@$(CC) $(CFLAGS) -c $< -o $@

clean:
					@$(RM) $(OBJS) -r $(OBJS_PS_DIR)
					@$(RM_EXTERNAL)

fclean: 			clean
					@$(RM) $(NAME)
					@$(RM) $(ARCHIVE) $(ARC_PRINTF)

re: 				fclean all

# Phony targets represent actions not files
.PHONY: 			all clean fclean re


