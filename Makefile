# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tditse <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/20 15:08:36 by tditse            #+#    #+#              #
#    Updated: 2018/08/25 12:15:02 by tditse           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Wextra -Werror
AR = ar rc
NAME = libftprintf.a
HEADER = libftprintf.h
FILES = ft_printf.c convert.c get.c print.c error.c set.c max.c\
	ft_memdel.c ft_bzero.c \
	ft_strnew.c ft_strlen.c ft_strindexof.c ft_strdup.c \
	ft_atoi.c ft_strcount.c \
	ft_putwchar.c ft_putwstr.c ft_wstrlen.c \
	ft_putlenstr.c ft_putnchar.c ft_putchar.c \
	ft_isdigit.c ft_power.c ft_itoa_base.c ft_uitoa_base.c \
	
OBJ = $(FILES:.c=.o)
TMP = Makefile~  $(F_DIR)/header.h~ $(NAME)~ $(FILES:.c=.c~)

all : $(NAME)

$(NAME) :
	@echo Project : $(NAME)
	@echo "\t"- Compiler : $(CC)
	@echo "\t"- Flags : $(FLAGS)
	@$(CC) $(FLAGS) -c $(FILES) 
	@$(AR) $(NAME) $(OBJ)
	@ranlib $(NAME)

clean :
	@rm -f $(TMP) $(OBJ)

fclean : clean
	@echo fclean :"\n\t" $(NAME) deleted
	@rm -f $(NAME)

test :
	@$(CC) -o ze_printf $(FILES) main.c -I $(HEADER) && ./ze_printf

re : fclean all
