# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hstein <hstein@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/01 14:44:34 by hstein            #+#    #+#              #
#    Updated: 2023/04/19 23:24:21 by hstein           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := cc
CFLAGS := -Wall -Wextra -Werror
NAME := libftprintf.a
NAMELFT := libft.a
sources :=  ft_printf.c ft_printf_utils_A.c ft_printf_utils_B.c
objects := $(sources:.c=.o)
LIBDIR := libft
all: $(NAME)
$(NAME): $(objects)
	make -C $(LIBDIR)
	cp -v $(LIBDIR)/$(NAMELFT) $(NAME)
	ar cr $@ $^
# cp -v (verbose = explain what is being dong)
$(objects): %.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<
clean:
	$(RM) $(objects)
	$(RM) *.o $(LIBDIR)/*.o
fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIBDIR)/$(NAMELFT)
re: fclean all
.PHONY: all clean fclean re
