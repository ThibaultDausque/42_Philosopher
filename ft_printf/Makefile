# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdausque <tdausque@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/24 16:25:54 by tdausque          #+#    #+#              #
#    Updated: 2024/10/27 09:50:12 by tdausque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

# compilateur c
CC = cc

SRCS = ft_printf.c \
	ft_print_unbr.c \
	ft_print_str.c \
	ft_print_ptr.c \
	ft_print_nbr.c \
	ft_print_hex.c \
	ft_print_char.c	

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

all : $(NAME)

# definit comment creer NAME 
# depend de la creation des fichiers objets
$(NAME) : $(OBJS)
# ar pour creer une archive static (bibliotheque .a)
	ar -rcs $(NAME) $(OBJS)

# compile le fichier .c en fichier objet .o
# pour chaque .c il creera .o
%.o: %.c
# $(CC) compile .c ($^) en fichier .o ($@)
# affiche un message pour chaque compilation
	@$(CC) -o $@ $(CFLAGS) -c $^
	@echo "\033[32mCopiling $^ to $@!\033[0m"

clean :
	$(RM) $(OBJS)

fclean :	clean
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re
	



