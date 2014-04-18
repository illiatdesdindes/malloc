# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svachere <svachere@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/19 12:04:58 by svachere          #+#    #+#              #
#    Updated: 2014/04/18 14:51:43 by svachere         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME = libft_malloc_$(HOSTTYPE).so
NAMELN = libft_malloc.so
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
SRCSFILES = malloc.c
SRCSDIR = srcs/
SRCS = $(addprefix $(SRCSDIR), $(SRCSFILES))
OBJSDIR = objs/
OBJSFILES = $(SRCSFILES:.c=.o)
OBJS = $(addprefix $(OBJSDIR), $(OBJSFILES))
HEADERS = srcs/malloc.h libft/libft.h libft/libftprintf.h
HEADERFLAGS = $(addprefix -I, $(dir $(HEADERS)))
LIBS = libft/libft.a
LDFLAGS = -L libft/ -lft

all: $(NAME)

$(NAME): env_vars objs $(LIBS) $(OBJS)
	$(CC) -shared -o $(NAME) $(OBJS) $(LDFLAGS)

env_vars:
	ln -s $(NAME) $(NAMELN)
	export DYLD_LIBRARY_PATH=.
	export DYLD_INSERT_LIBRARIES=$(NAMELN)
	export DYLD_FORCE_FLAT_NAMESPACE=1

objs:
	mkdir -p objs

$(LIBS):
	$(MAKE) -C $(dir $@)

$(OBJSDIR)%.o: $(SRCSDIR)%.c $(HEADERS)
	$(CC) $(CFLAGS) $(HEADERFLAGS) -c -o $@ $<

clean:
	$(MAKE) -C libft/ $@
	#$(MAKE) -C printf/ $@
	/bin/rm -f $(OBJS)

fclean: clean
	$(MAKE) -C libft/ $@
	#$(MAKE) -C printf/ $@
	/bin/rm -f $(NAME)

re: fclean all

libftinstall:
	mkdir libft
	$(MAKE) libftupdate

libftupdate:
	cp ../libft/* libft
	$(MAKE) -C libft/ prepare

.PHONY: clean fclean re
