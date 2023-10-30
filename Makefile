# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: isbraz-d <isbraz-d@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/11 14:45:58 by isbraz-d          #+#    #+#              #
#    Updated: 2023/08/22 16:27:28 by isbraz-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = client

NAME2 = server

SRCS = client.c utils.c utils2.c

SRCS2 = server.c utils.c utils2.c

OBJS = $(SRCS:.c=.o)

OBJS2 = $(SRCS2:.c=.o)

CFLAGS = -Wall -Werror -Wextra

all: server client

server: $(OBJS2)
	$(CC) $(CFLAGS) $(OBJS2) -o $(NAME2)

client: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS) $(OBJS2)

fclean: clean
	rm -f $(NAME) $(NAME2)

re: fclean all

