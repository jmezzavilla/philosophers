# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jealves- <jealves-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/19 22:40:23 by jealves-          #+#    #+#              #
#    Updated: 2023/11/01 16:59:40 by jealves-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
SRC =	src/util.c\
 		src/init.c\
		src/time.c\
		src/routine.c\
		src/philo.c\
		src/clean.c\
		
PROJECT = <$(GREEN)$(NAME)$(RESET)>
			
INCLUDES = include

CFLAGS = -g -lpthread -Wall -I $(INCLUDES) -Wextra -Werror #-fsanitize=thread
RM= @rm -rf

OBJ = $(patsubst %.c,%.o,$(SRC))

%.o: %.c
	@printf "$(PROJECT) compiling $(BLUE)$<$(RESET)\n"
	@$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@printf "$(PROJECT) $(GREEN)compiled$(RESET)!\n"
	@make -s clean

clean :
	$(RM) $(OBJ)
	
fclean : clean
	$(RM) $(NAME)
	@printf "$(PROJECT) $(YELLOW) deleting $(NAME) $(RESET)!\n"

norm:
	norminette
		
re : fclean all

.PHONY : all clean fclean bonus re

### COLORS ###

RED = \033[0;31m
GREEN = \033[0;92m
YELLOW = \033[93m
BLUE = \033[0;34m
MAGENTA = \033[0;35m
CYAN = \033[96m
RESET = \033[0m