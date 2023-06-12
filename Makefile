# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anunes-c <anunesc-@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/12 15:18:55 by anunes-c          #+#    #+#              #
#    Updated: 2023/06/12 18:07:14 by anunes-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a
HEADER = get_next_line.h

CC = cc
CFLAGS = -D BUFFER_SIZE=42 -MMD 

RM = rm -f

SRCS = get_next_line.c get_next_line_utils.c
OBJS = $(SRCS:.c=.o)
DEPS = $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

%.o: %.c %.d
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re
