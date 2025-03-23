# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdausque <tdausque@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/01 16:24:29 by thibault          #+#    #+#              #
#    Updated: 2025/03/23 12:57:38 by tdausque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -g -Wall -Wextra -Werror
NAME = philo

SRCS = time.c \
		main.c \
		philo.c \
		routine.c \
		reaper.c \
		utils.c \
		die_utils.c

OBJ_DIR = objs/
OBJ = $(SRCS:%.c=$(OBJ_DIR)/%.o)

PRINTF_A = $(PRINTF_DIR)/ft_printf.a
PRINTF_DIR = ../ft_printf

all: $(NAME) $(PRINTF_A)
	@echo "Compilation of $(NAME) : \033[1;32mOK\033[0m"

$(NAME): $(OBJ)
	@make -C $(PRINTF_DIR)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(PRINTF_A)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@


clean:
	@rm -rf $(OBJ_DIR)
	@echo "Clean of $(NAME) : \033[1;32mOK\033[0m"

fclean: clean
	@rm -f $(NAME)
	@cd $(PRINTF_DIR) && make fclean
	@echo "Fclean of $(NAME) : \033[1;32mOK\033[0m"

re: fclean all

.PHONY: all clean fclean

