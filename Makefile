# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/02 22:02:13 by kallard           #+#    #+#              #
#    Updated: 2020/10/07 12:51:47 by kallard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a

SRCS =	ft_strlen.s \
		ft_strcpy.s \
		ft_strcmp.s \
		ft_write.s \
		ft_read.s \
		ft_strdup.s

OBJS = $(SRCS:.s=.o)

%.o	: %.s
	@nasm -f macho64 $<

all: $(NAME)

$(NAME): $(OBJS) 
	ar -rc $(NAME) $(OBJS)
	ranlib $(NAME)

test: all
	touch test.txt
	chmod a+rw test.txt
	gcc main.c libasm.a
	./a.out

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	rm -f a.out
	rm -f test.txt

re: fclean all

.PHONY:	all clean fclean re test 