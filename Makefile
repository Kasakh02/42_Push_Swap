# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/03 14:23:46 by hcorrea-          #+#    #+#              #
#    Updated: 2023/01/18 11:44:39 by hcorrea-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN		=	\033[0;32m
RED			=	\033[0;31m
YELLOW		=	\033[0;33m
END			=	\033[0m

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -I$(INC_DIR) -I$(LIBFT_DIR) -I$(PRINFT_DIR)
RM			=	rm -rf

NAME		=	libpushswap.a

LIBFT_DIR	=	Libft
PRINFT_DIR	=	Printf
INC_DIR		=	inc

SRC			=	src/main.c					\
				src/stack_utils.c			\
				src/check_input.c			\
				src/check_input_utils.c		\
				src/push.c					\
				src/rev_rotate.c			\
				src/rotate.c				\
				src/swap.c					\
				src/general_utils.c			\
				src/stack_utils2.c			\
				src/sort_3.c				\
				src/sort.c					\
				src/position.c				\
				src/stack_utils3.c			\
				src/cost.c					\

BONUS		=	bonus/src/main.c			\
				bonus/src/push.c			\
				bonus/src/rev_rotate.c		\
				bonus/src/stack_utils.c		\
				bonus/src/swap.c			\

OBJ		=	$(SRC:src/%.c=$(OBJ_DIR)/%.o)
OBJ_B	=	$(BONUS:bonus/src/%.c=$(OBJ_DIR)/%.o)
OBJ_DIR	=	obj
OBJF	=	.cache_exists

$(NAME):		$(OBJ)
				@echo "$(YELLOW)Compiling Push_Swap...$(END)"
				@ar rcs $(NAME) $(OBJ)
				@make -C $(LIBFT_DIR) bonus
				@make -C $(PRINFT_DIR)
				@echo "$(GREEN)Push_Swap succesfully compiled!$(END)"

all:			$(NAME)

$(OBJ_DIR)/%.o:	src/%.c | $(OBJF)
				@$(CC) $(CFLAGS) -c $(^) -o $(@)

$(OBJ_DIR)/%.o:	bonus/src/%.c | $(OBJF)
				@$(CC) $(CFLAGS) -c $(^) -o $(@)

$(OBJF):
				@mkdir -p $(OBJ_DIR)

clean:	
				@$(RM) $(OBJ_DIR)
				@make -C $(LIBFT_DIR) clean
				@make -C $(PRINFT_DIR) clean
				@echo "$(RED)Push_Swap objects deleted!$(END)"

fclean:			clean
				@$(RM) $(NAME)
				@make -C $(LIBFT_DIR) fclean
				@make -C $(PRINFT_DIR) fclean
				@echo "$(RED)Push_Swap lib deleted!$(END)"

bonus:			$(NAME) $(OBJ_B)
				@echo "$(YELLOW)Compiling Push_Swap bonus...$(END)"
				@ar rcs $(NAME) $(OBJ_B)
				@echo "$(GREEN)Push_Swap bonus succesfully compiled!$(END)"

re:				fclean all