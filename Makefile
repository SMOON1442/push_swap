CC = cc
CFLAGS = -Wall -Wextra -Werror -I./includes
NAME = push_swap
FT_PRINTF = utils/ft_printf/libftprintf.a
SRCS = algorithms/simple.c utils/utils.c \
	   operations/push.c operations/swap.c \
	   operations/rotate.c operations/rrotate.c\
	   parse/parse.c algorithms/complex.c main.c \
	   utils/ft_split.c utils/utils_string.c
OBJS = $(SRCS:.c=.o)

MAKE_PRINTF = $(MAKE) -C utils/ft_printf

all: $(NAME)

$(NAME): $(FT_PRINTF) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(FT_PRINTF) -o $@

$(FT_PRINTF):
	$(MAKE_PRINTF) all

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE_PRINTF) clean
	rm -f $(OBJS) $(FT_PRINTF)

fclean: clean
	$(MAKE_PRINTF) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all fclean clean re
