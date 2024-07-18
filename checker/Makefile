# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dicarval <dicarval@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/18 10:55:34 by dicarval          #+#    #+#              #
#    Updated: 2024/07/18 18:31:53 by dicarval         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= checker
ARCHIVE			= libchecker.a
PUSH_SWAP_EXEC	= ../push_swap/push_swap
ARC_PRINTF		= ../push_swap/ft_printf/libftprintf.a

# Compiler and CFlags
CC 				= @cc
CFLAGS 			= -Wall -Wextra -Werror -g
MAKE_LIB 		= ar -rcs
RM				= rm -f
RM_EXTERNAL		= rm -f $(OBJS_PS) $(OBJS_FTPF) $(PUSH_SWAP_EXEC) \
						 $(ARC_PRINTF)

# Source Files
SRCS_CHECKER	= $(wildcard *.c)
SRCS_GNL		= $(wildcard gnl/*.c)
SRCS_STACK		= $(wildcard ../push_swap/srcs/stack/*.c)
SRCS_CMD		= $(wildcard ../push_swap/srcs/commands/*.c)
SRCS_FTPF		= $(wildcard ../push_swap/ft_printf/*.c)

# Concatenate all source files
SRCS			= $(SRCS_CHECKER) $(SRCS_GNL)
SRCS_PS			= $(SRCS_STACK) $(SRCS_CMD)

# Object Files
OBJS			= $(SRCS:.c=.o)
OBJS_PS			= $(SRCS_PS:.c=.o)
OBJS_FTPF		= $(SRCS_FTPF:.c=.o)

# Build
all:			$(NAME)

$(ARCHIVE):		$(OBJS_PS) $(OBJS_FTPF) $(OBJS)
				@make -s -C ../push_swap
				@$(MAKE_LIB) $(ARCHIVE) $^
				@$(RM_EXTERNAL)
				@$(RM) -r ../push_swap/obj

$(NAME):		$(ARCHIVE)
				@$(CC) $(CFLAGS) $< -o $@

# Compile object files from source files
$(OBJS):		$(SRCS)
				@$(CC) $(CFLAGS) -c $< -o $@

clean:
				@$(RM) $(OBJS)
				@echo "Object files cleaned"

fclean: 		clean
				@$(RM) $(NAME)
				@$(RM) $(ARCHIVE)
				@echo "Executables and archives cleaned"

re: 			fclean all

# Phony targets represent actions not files
.PHONY: 		all clean fclean re


