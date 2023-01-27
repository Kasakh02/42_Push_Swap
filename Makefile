# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/03 14:23:46 by hcorrea-          #+#    #+#              #
#    Updated: 2023/01/23 18:11:13 by hcorrea-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN			=	\033[0;32m
RED				=	\033[0;31m
YELLOW			=	\033[0;33m
END				=	\033[0m

PUSH_SWAP 		=	push_swap

PROJECTDIR		=	src
INC 			=	inc
OBJ_DIR			=	obj
PUSH_SWAP_DIR	=	push_swap
LIBFT_DIR		=	$(PROJECTDIR)/Libft
HEADER			=	$(INC)/push_swap.h
LIBFT_HEADER	=	$(LIBFT_DIR)/$(INC)/libft.h	

LIBFT_LIB		=	libft.a
CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror

SRC				=	main.c					\
					check_input.c			\
					get_biggest_nbr.c		\
					sort_5.c				\
					sort_100.c				\
					push.c					\
					stack_utils.c			\
					reverse_rotate.c		\
					swap_rotate.c			\
					sort_list.c				\
					sort_10.c				\
					sort_3.c				\

OBJ				:=	$(addprefix $(OBJ_DIR)/$(PUSH_SWAP_DIR)/, $(SRC:.c=.o))
LIBFT_FILE		:=	$(LIBFT_DIR)/$(LIBFT_LIB)

RM				=	rm -rf
MKDIR			=	mkdir -p
MAKE			=	make -C
ERRIGNORE		=	2>/dev/null

.PHONY:				all clean fclean re norminette

all:				$(PUSH_SWAP)
					@echo "$(GREEN)Push_Swap succesfully compiled!$(END)"
					@sleep 2
					@clear

ft_libft:
					@clear
					@$(MAKE) $(LIBFT_DIR)
					@echo "$(YELLOW)Compiling Push_Swap...$(END)"

$(PUSH_SWAP):		ft_libft $(OBJ)
					@$(CC) -I $(HEADER) -I $(LIBFT_HEADER) $(OBJ) $(LIBFT_DIR)/$(LIBFT_LIB) -o $@

$(OBJ_DIR)/%.o:		$(PROJECTDIR)/%.c $(HEADER)
					@$(MKDIR) $(dir $@)
					@$(CC) $(CFLAGS) -I $(HEADER) -I $(LIBFT_HEADER) -o $@ -c $<
										
%.o:				%.c
					@$(CC) $(CFLAGS) -I $(HEADER) -I $(LIBFT_HEADER) -o $@ -c $<
					
clean:
					@$(RM) $(OBJ_DIR) $(ERRIGNORE)
					@$(MAKE) $(LIBFT_DIR) clean
					@clear
					@echo "$(RED)All objects deleted!$(END)"
					
fclean:				clean
					@$(RM) $(PUSH_SWAP)
					@$(MAKE) $(LIBFT_DIR) fclean
					@echo "$(RED)All libraries deleted!$(END)"
					@sleep 2
					@clear

re:					fclean all

norminette:			
					norminette
					@clear
					@echo "$(GREEN)Norminette check!$(END)"