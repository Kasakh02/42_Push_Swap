# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/03 14:23:46 by hcorrea-          #+#    #+#              #
#    Updated: 2023/07/25 14:35:57 by hcorrea-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN		=	\033[0;32m
RED			=	\033[0;31m
YELLOW	=	\033[0;33m
END			=	\033[0m

PUSH_SWAP		=	push_swap
CHECKER			=	checker

SRC_DIR					=	src
OBJ_DIR 				=	obj
CHECKER_OBJ_DIR	=	obj_checker
CHECKER_DIR			=	checker_src
INC_DIR 				= inc
OP							=	src/operations

SRC     =	$(shell find $(SRC_DIR) -name '*.c')
CHECKER_SRC	=	$(shell find $(CHECKER_DIR) -name '*.c') $(shell find $(OP) -name '*.c') src/push_swap/init.c src/utils/free.c src/utils/stack.c
OBJ     =	$(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))
CHECKER_OBJ	=$(patsubst $(CHECKER_DIR)/%.c,$(CHECKER_OBJ_DIR)/%.o,$(CHECKER_SRC))

CC			=	gcc
CFLAGS	=	-Wall -Wextra -Werror -I./inc -fsanitize=address
LDFLAGS	=	-L./mlx -lmlx -framework OpenGL -framework AppKit

RM				=	rm -rf
MKDIR			=	mkdir -p
MAKE			=	make -C
ERRIGNORE		=	2>/dev/null

LIBFT_DIR			=	Libft
LIBFT_HEADER	=	$(LIBFT_DIR)/inc/libft.h
LIBFT_LIB			=	libft.a
LIBFT_FILE		:=	$(LIBFT_DIR)/$(LIBFT_LIB)

PRINTF_DIR		=	Printf
PRINTF_HEADER	=	$(PRINTF_DIR)/inc/printf.h
PRINTF_FILE		=	Printf/libftprintf.a

all:			$(PUSH_SWAP)

norminette:
					@echo "$(YELLOW)Checking Norminette...$(END)"
					@norminette $(SRC_DIR) $(LIBFT_DIR) $(CHECKER_DIR) $(PRINTF_DIR) $(INC) > norminette_output.txt; \
					RESULT=$$?; \
					if [ $$RESULT -eq 0 ]; then \
						echo "$(GREEN)Norminette check passed!$(END)"; \
						sleep 0.5; \
						clear; \
					else \
						grep -E "Error|Warning:" norminette_output.txt; \
						echo "$(RED)Norminette check failed!$(END)"; \
						rm -f norminette_output.txt; \
						exit 1; \
					fi; \
					rm -f norminette_output.txt
					
$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c $(INC_DIR)/*.h | $(OBJ_DIR)
								@$(MKDIR) $(dir $@)
								@$(CC) $(CFLAGS) -c $< -o $@

$(CHECKER_OBJ_DIR)/%.o: $(CHECKER_DIR)/%.c $(INC_DIR)/*.h | $(CHECKER_OBJ_DIR)
								@$(MKDIR) $(dir $@)
								@$(CC) $(CFLAGS) -c $< -o $@

$(PUSH_SWAP):	$(OBJ)
					@$(MAKE) $(LIBFT_DIR)
					@clear
					@echo "$(YELLOW)Compiling Push_Swap...$(END)"
					@$(CC) $(OBJ) $(CFLAGS) $(LIBFT_FILE) $(PRINTF_FILE) -o $@
					@echo "$(GREEN)Push_Swap successfully compiled!$(END)"
					@sleep 0.5
					@clear

$(CHECKER):	all $(CHECKER_OBJ)
					@clear
					@echo "$(YELLOW)Compiling Checker...$(END)"
					@$(CC) $(CHECKER_OBJ) $(CFLAGS) $(LIBFT_FILE) $(PRINTF_FILE) -o $@
					@echo "$(GREEN)Checker successfully compiled!$(END)"
					@sleep 0.5
					@clear

$(OBJ_DIR):
					@$(MKDIR) $(OBJ_DIR)

$(CHECKER_OBJ_DIR):
					@$(MKDIR) $(CHECKER_OBJ_DIR)

%.o:			%.c | $(OBJ_DIR)
					@$(CC) $(CFLAGS) -I $(INC_DIR) -I $(LIBFT_HEADER) -I $(PRINTF_HEADER) -c $< -o $@		

checker:	$(CHECKER) $(PUSH_SWAP)

clean:
					@$(RM) $(OBJ_DIR) $(CHECKER_OBJ_DIR)
					@$(MAKE) $(LIBFT_DIR) clean
					@clear
					@echo "$(RED)All objects deleted!$(END)"

fclean:				clean
					@$(RM) $(PUSH_SWAP) $(CHECKER)
					@$(MAKE) $(LIBFT_DIR) fclean
					@echo "$(RED)All executables deleted!$(END)"
					@sleep 0.5
					@clear

re:				fclean all

.PHONY:		all clean fclean re checker norminette