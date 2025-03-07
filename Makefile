# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdausque <tdausque@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/01 16:24:29 by thibault          #+#    #+#              #
#    Updated: 2025/03/07 13:06:23 by tdausque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -g -Wall -Wextra -Werror
NAME = philosopher

SRCS = philo/init.c \
		philo/main.c \
		philo/philo.c \
		philo/routine.c \
		philo/utils.c

OBJ_DIR = objs/
OBJ = $(SRCS:%.c=$(OBJ_DIR)/%.o)

PRINTF_A = $(PRINTF_DIR)/ft_printf.a

all: ft_printf $(NAME)
	@echo "Compilation of $(NAME) : \033[1;32mOK\033[0m"

$(NAME): $(OBJ)
	$make -C $(PRINTF_DIR)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(INCLUDE)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

PRINTF_DIR = ./ft_printf

ft_printf:
	@$(MAKE) -C $(PRINTF_DIR) --no-print-directory

clean_printf:
	@$(MAKE) -C $(PRINTF_DIR) clean --no-print-directory

fclean_printf:
	@$(MAKE) -C $(PRINTF_DIR) fclean --no-print-directory

re_printf:
	@$(MAKE) -C $(PRINTF_DIR) re --no-print-directory

clean:
	@rm -rf $(OBJ_DIR)
	@echo "Clean of $(NAME) : \033[1;32mOK\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "Fclean of $(NAME) : \033[1;32mOK\033[0m"

re: fclean all

.PHONY: all clean fclean

