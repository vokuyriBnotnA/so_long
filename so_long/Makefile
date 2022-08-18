# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: klemongr <klemongr@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/07 17:00:34 by klemongr          #+#    #+#              #
#    Updated: 2022/03/11 00:07:01 by klemongr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long.a

SRCS =	ft_split.c				\
		ft_strjoin.c			\
		ft_strlen.c				\
		ft_strcmp.c				\
		so_long_init.c			\
		window_size.c			\
		print_map.c				\
		gameplay.c				\
		gameplay_checkers.c		\
		steps_print.c			\
		read_map.c				\
		check_map.c				\
		main.c					\

OBJSFD = temporary

OBJ = $(addprefix $(OBJSFD)/,$(SRCS:.c=.o))

CC = cc

CFLAGC = -Wall -Wextra -Werror -Imlx$(HEDEAR)

.PHONY : all clean fclean re

all: $(NAME)

$(OBJSFD):
	mkdir $@

$(OBJSFD)/%.o: %.c | $(OBJSFD)
	gcc -g $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJ) $(HEDEAR)
	$(CC) $(OBJ)  -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o : %.c $(HEDEAR)
	$(CC) $(CFLAGC) -c $< -o $@

clean:
	@rm -f $(OBJ) $(OBJ_B)
fclean: clean
	@rm -f $(NAME)
re: fclean all