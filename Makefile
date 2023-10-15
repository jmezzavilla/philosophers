# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jealves- <jealves-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/05 00:18:43 by jealves-          #+#    #+#              #
#    Updated: 2023/10/15 19:16:55 by jealves-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
SRC =	src/lib/ft_atol.c\
		src/main.c\
		
PROJECT = <$(GREEN)$(NAME)$(RESET)>
			
INCLUDES = include

CFLAGS = -g -Wall -I $(INCLUDES) -Wextra -Werror #-fsanitize=address #-I $(INCLUDE_LIB) 
RM= @rm -rf

OBJ = $(patsubst %.c,%.o,$(SRC))

%.o: %.c
	@printf "$(PROJECT) compiling $(BLUE)$<$(RESET)\n"
	@$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)


$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@printf "$(PROJECT) $(GREEN)compiled$(RESET)!\n"

clean :
	$(RM) $(OBJ)
	@for file in $(OBJ); do \
        echo "$(PROJECT) deleting $(YELLOW) $$file $(RESET)!"; \
    done
	
fclean : clean
	$(RM) $(NAME)
	@printf "$(PROJECT) $(YELLOW) deleting $(NAME) $(RESET)!\n"
	
	
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