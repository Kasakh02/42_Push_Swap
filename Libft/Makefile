# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hcorrea- <hcorrea-@student.42lisboa.pt>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/11 17:36:38 by hcorrea-          #+#    #+#              #
#    Updated: 2022/11/24 10:34:07 by hcorrea-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror

NAME 	= 	libft.a

SRC 	= 	ft_memset ft_bzero ft_memcpy ft_memmove ft_memchr\
			ft_memcmp ft_strlen ft_strlcpy ft_strlcat ft_strchr ft_strrchr\
			ft_substr ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd\
			ft_strnstr ft_strncmp ft_atoi ft_isalpha ft_isdigit ft_isalnum\
			ft_isascii ft_isprint ft_toupper ft_tolower ft_calloc ft_strdup\
			ft_strjoin ft_strtrim ft_strmapi ft_striteri ft_itoa ft_split\

BONUS 	= 	ft_lstnew ft_lstadd_front ft_lstsize ft_lstlast ft_lstadd_back\
			ft_lstdelone ft_lstclear ft_lstiter ft_lstmap\

RM 		=	rm -rf

all:		$(NAME)

$(NAME): 	$(SRC:=.o)
			ar -rcs $(NAME) $(SRC:=.o)
			
clean:
			$(RM)	$(SRC:=.o) $(BONUS:=.o)
	
fclean: 	clean
			$(RM) $(NAME)

re:			fclean	all

bonus:		$(SRC:=.o)	$(BONUS:=.o)
			ar rc $(NAME) $(SRC:=.o) $(BONUS:=.o)

.PHONY:		all clean fclean re bonus
