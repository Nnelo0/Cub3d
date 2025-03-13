NAME = cub3D
CC = cc
CFLAGS = -Wall -Werror -Wextra -g
SRCS = parsing/*.c \
 
LIBFTDIR = libft
LIBFT = $(LIBFTDIR)/libft.a 

all: $(LIBFT) $(NAME)

$(NAME): $(SRCS) $(LIBFT)
	$(CC) -I. -I$(LIBFTDIR) $(SRCS) $(LIBFT) $(CFLAGS) -o $(NAME) -lreadline
	@echo "Compiled $(NAME) successfully!"

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

clean:
	$(MAKE) -C $(LIBFTDIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re