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
	   algorithms/disorder.c utils/extra_utils.c operations/bench.c \
	   algorithms/print_bench.c algorithms/medium.c algorithms/medium_utils.c
SRCS_BONUS = operations/push.c operations/swap.c operations/rotate.c \
			 operations/rrotate.c parse/parse.c parse/parse_utils.c parse/ft_split.c \
			 utils/utils.c operations/bench.c
OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)
MANDATORY = main.o
BONUS = bonus/utils_bonus.o bonus/main_bonus.o 
CHECKER = checker

MAKE_PRINTF = $(MAKE) -C utils/ft_printf

all: $(NAME)

bonus: $(CHECKER)

$(CHECKER): $(OBJS_BONUS) $(BONUS)
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(BONUS) -o $(CHECKER)

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
