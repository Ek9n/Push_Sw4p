NAME		= push_swap
NAME_BONUS  = checker
LIBFT		= ./tempLibft/libft.a
PRINTF		= ./tempLibft/ft_printf/libftprintf.a

SRCS		= $(wildcard ./src/*.c)
OBJS		= $(addprefix ./obj/,$(notdir $(SRCS:.c=.o)))

BONUS_SRCS	= $(wildcard ./my_checker/*.c)
BONUS_OBJS	= $(BONUS_SRCS:.c=.o)

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f
MKDIR		= mkdir -p

.PHONY:		all clean fclean re

all:		$(LIBFT) $(NAME)

$(NAME):    $(OBJS)
	        $(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(PRINTF)

$(LIBFT):
			$(MAKE) -C ./tempLibft/

./obj/%.o:	./src/%.c
			$(MKDIR) $(dir $@)
			$(CC) $(CFLAGS) -c $< -o $@

clean:
			$(MAKE) -C ./tempLibft/ clean
			$(RM) $(OBJS) $(BONUS_OBJS)

fclean:		
			$(MAKE) -C ./tempLibft/ fclean
			$(MAKE) clean
			$(RM) $(NAME) $(NAME_BONUS) $(LIBFT) $(PRINTF)

re:	
			$(MAKE) fclean
			$(MAKE) all

bonus:		$(BONUS_OBJS)
			# $(MAKE) all
			$(CC) $(CFLAGS) -o $(NAME_BONUS) $(BONUS_OBJS) $(LIBFT) $(PRINTF)