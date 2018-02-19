# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: aberneli <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2017/11/29 11:52:07 by aberneli     #+#   ##    ##    #+#        #
#    Updated: 2017/11/29 11:53:14 by aberneli    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = fillit

SRCS = ft_showit.c map.c utils_three.c conformity.c lst_clear.c utils.c \
	  utils_two.c fillit.c

OBJS = $(SRCS:.c=.o)

HEAD = fillit.h types.h

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS) $(HEAD)
	gcc $(FLAGS) $(OBJS) -o $(NAME)

./%.o: ./%.c
	gcc $(FLAGS) -o $@ -c $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
