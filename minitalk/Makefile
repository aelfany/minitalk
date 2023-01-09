# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abelfany <abelfany@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/03 12:23:16 by abelfany          #+#    #+#              #
#    Updated: 2023/01/07 19:52:12 by abelfany         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = server
HEADER = minitalk.h
SRCS_S = server.c \
		ft_itoa.c \
		ft_putnbr.c \
		ft_atoi.c 

SRCS_C = client.c \
		ft_itoa.c \
		ft_atoi.c

OBJS_S = $(SRCS_S:.c=.o)
OBJS_C = $(SRCS_C:.c=.o)
CFLAGS = -Wall -Werror -Wextra -g
RM = rm -rf
AR = @ar -rc

all: $(NAME) client
		@echo "╔═╦═╗╔══╗╔═╦╗╔══╗╔══╗╔══╗╔╗─╔╦╗"
		@echo "║║║║║╚║║╝║║║║╚║║╝╚╗╔╝║╔╗║║║─║╔╝"
		@echo "║║║║║╔║║╗║║║║╔║║╗─║║─║╠╣║║╚╗║╚╗"
		@echo "╚╩═╩╝╚══╝╚╩═╝╚══╝─╚╝─╚╝╚╝╚═╝╚╩╝"
$(NAME):$(OBJS_S)
	gcc $(CFLAGS) $(OBJS_S) -o $(NAME)
	
client:$(OBJS_C)
	gcc $(CFLAGS) $(OBJS_C) -o $@

# bonus:$(B_OBJS)
# 	gcc $(CFLAGS) $(B_OBJS) -o client

%.o : %.c $(HEADER)
	cc $(CFLAGS) -c $< -I $(HEADER)

clean:
	$(RM) $(OBJS_S) $(OBJS_C)

fclean:clean
	@$(RM) $(NAME) client

re: fclean all

.PHONY: all re fclean clean