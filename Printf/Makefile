# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/18 11:07:37 by hcorrea-          #+#    #+#              #
#    Updated: 2023/01/13 11:56:18 by hcorrea-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN	=	\033[0;32m
RED		=	\033[0;31m
YELLOW	=	\033[0;33m
END		=	\033[0m

NAME 		=	ibftprintf.a
SRC 		=	src/ft_printf.c			\
				src/ft_var.c			\
				src/ft_put_c.c			\
				src/ft_put_s.c			\
				src/ft_put_p.c			\
				src/ft_put_nbr.c		\
				src/ft_put_u.c			\
				src/ft_put_hex.c		\
				src/ft_strchr.c			\

OBJ 		=	$(SRC:src/%.c=$(OBJ_DIR)/%.o)
INC_DIR		=	inc
OBJ_DIR		=	obj


OBJF		=	.cache_exists

CC 			=	gcc
CFLAGS 		=	-Wall -Wextra -Werror -I$(INC_DIR)

all: 			$(NAME)

$(NAME):		$(OBJ)
				@echo "$(YELLOW)Compiling Printf...$(END)"
				@ar rcs $(NAME) $(OBJ)
				@echo "$(GREEN)Printf succesfully compiled!$(END)"

$(OBJ_DIR)/%.o:	src/%.c | $(OBJF)
				@$(CC) $(CFLAGS) -c $(^) -o $(@)

$(OBJF):
				@mkdir -p $(OBJ_DIR)

clean: 		
				@rm -rf $(OBJ_DIR)
				@echo "$(RED)Printf objects deleted!$(END)"

fclean: 		clean
				@rm -rf $(NAME)
				@echo "$(RED)Printf lib deleted!$(END)"

re: 			fclean all

.PHONY:		all clean fclean re bonus
