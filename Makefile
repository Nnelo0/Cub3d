MAKEFLAGS += --silent

NAME = cub3D

CC = cc
CFLAGS = -Wall -Werror -Wextra -g

MLXFLAGS = -I./minilibx-linux -L./minilibx-linux -lmlx -lXext -lX11 -lm

SRCDIR = parsing
OBJDIR = obj
LIBFTDIR = libft
MINILIBXDIR = minilibx-linux

SRCS = $(SRCDIR)/main.c $(SRCDIR)/read_files.c $(SRCDIR)/split_tab_space.c \
$(SRCDIR)/verif.c $(SRCDIR)/verif_map.c $(SRCDIR)/verif_textures.c \
$(SRCDIR)/verif_colors.c $(SRCDIR)/parsing_utils.c $(SRCDIR)/verif_colors_utils.c \

OBJS = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

LIBFT = $(LIBFTDIR)/libft.a

MINILIBX = $(MINILIBXDIR)/libmlx.a

all: $(LIBFT) $(MINILIBX) $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MINILIBX)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLXFLAGS) $(LIBFT)
	@echo "\033[32m✔ Compilation completed\033[0m"

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

$(MINILIBX):
	$(MAKE) -C $(MINILIBXDIR)

clean:
	$(RM) -r $(OBJDIR)
	$(MAKE) -C $(LIBFTDIR) clean
	@echo "\033[33m✔ $(OBJDIR) suppressed\033[0m"

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFTDIR) fclean
	$(MAKE) -C $(MINILIBXDIR) clean
	@echo "\033[31m✔ $(NAME), libft.a et libmlx.a suppressed\033[0m"

re: fclean all
