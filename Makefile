MAKEFLAGS += --silent
NAME = cub3D

CC = cc
CFLAGS = -Wall -Werror -Wextra -g

MLXFLAGS = -I./minilibx-linux -L./minilibx-linux -lmlx -lXext -lX11 -lm

SRCDIR = parsing
OBJDIR = obj
LIBFTDIR = libft

SRCS = $(SRCDIR)/main.c $(SRCDIR)/map.c
OBJS = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
LIBFT = $(LIBFTDIR)/libft.a

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLXFLAGS) $(LIBFT)
	@echo "\033[32m✔ Compilation completed\033[0m"

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

clean:
	$(RM) -r $(OBJDIR)
	$(MAKE) -C $(LIBFTDIR) clean
	@echo "\033[33m✔ $(OBJDIR) and libft.a suppressed\033[0m"

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFTDIR) fclean
	@echo "\033[31m✔ $(NAME) and libft.a suppressed\033[0m"

re: fclean all
