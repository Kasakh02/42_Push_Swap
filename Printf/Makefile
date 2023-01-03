# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hcorrea- <hcorrea-@student.42lisboa.pt>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/18 11:07:37 by hcorrea-          #+#    #+#              #
#    Updated: 2022/11/10 16:26:24 by hcorrea-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 		= gcc

CFLAGS 	= -Wall -Wextra -Werror

NAME 	= libftprintf.a

SRC 	=	ft_printf.c			\
			ft_var.c			\
			ft_put_c.c			\
			ft_put_s.c			\
			ft_put_p.c			\
			ft_put_nbr.c		\
			ft_put_u.c			\
			ft_put_hex.c		\
			ft_strchr.c			\

OBJS 	= $(SRC:.c=.o)

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)

all: 		$(NAME)

clean: 		
			rm -rf $(OBJS)

fclean: 	clean
			rm -f $(NAME)

re: 		fclean all
