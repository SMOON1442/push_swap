CC = cc
CFLAGS = -Wall -Wextra -Werror -I./includes
NAME = push_swap
FT_PRINTF = utils/ft_printf/libftprintf.a
SRCS = algorithms/simple.c utils/utils.c \
	   operations/push.c operations/swap.c \
	   operations/rotate.c operations/rrotate.c\
	   parse/parse.c algorithms/complex.c \
	   parse/ft_split.c parse/parse_utils.c \
	   algorithms/complex_utils.c algorithms/complex_exec.c \
	   parse/disorder.c utils/extra_utils.c operations/bench.c \
	   algorithms/print_bench.c algorithms/medium.c algorithms/medium_utils.c
OBJS = $(SRCS:.c=.o)
MANDATORY = main.o
BONUS = bonus.o
CHECKER = checker

MAKE_PRINTF = $(MAKE) -C utils/ft_printf

all: $(NAME)

bonus: $(CHECKER)

$(CHECKER): $(FT_PRINTF) $(OBJS) $(BONUS)
	$(CC) $(CFLAGS) $(OBJS) $(BONUS) $(FT_PRINTF) -o $(CHECKER)

$(NAME): $(FT_PRINTF) $(OBJS) $(MANDATORY)
	$(CC) $(CFLAGS) $(OBJS) $(MANDATORY) $(FT_PRINTF) -o $@

$(FT_PRINTF):
	$(MAKE_PRINTF) all

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE_PRINTF) clean
	rm -f $(OBJS) $(FT_PRINTF) $(BONUS) $(MANDATORY)

fclean: clean
	$(MAKE_PRINTF) fclean
	rm -f $(NAME) && rm -rf $(CHECKER)

re: fclean all

.PHONY: all fclean clean re bonus
