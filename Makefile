# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jealves- <jealves-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/19 22:40:23 by jealves-          #+#    #+#              #
#    Updated: 2023/10/21 19:32:36 by jealves-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
SRC =	src/utils/util.c\
 		src/utils/init.c\
		src/utils/msg.c\
		src/utils/validate.c\
		src/utils/time.c\
		src/philo.c\
		
PROJECT = <$(GREEN)$(NAME)$(RESET)>
			
INCLUDES = include

CFLAGS = -g -Wall -I $(INCLUDES) -Wextra -Werror #-fsanitize=address 
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