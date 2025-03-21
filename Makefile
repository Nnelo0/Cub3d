MAKEFLAGS += --silent

NAME = cub3D

CC = cc
CFLAGS = -Wall -Werror -Wextra -g

MLXFLAGS = -I./minilibx-linux -L./minilibx-linux -lmlx -lXext -lX11 -lm

PARSDIR = parsing
OBJDIR = obj
LIBFTDIR = libft
MINILIBXDIR = minilibx-linux

SRCS = $(PARSDIR)/main.c $(PARSDIR)/read_files.c $(PARSDIR)/split_tab_space.c \
$(PARSDIR)/verif.c $(PARSDIR)/verif_wall.c $(PARSDIR)/verif_textures.c \
$(PARSDIR)/verif_colors.c $(PARSDIR)/parsing_utils.c $(PARSDIR)/verif_colors_utils.c \
$(PARSDIR)/read_files_utils.c $(PARSDIR)/verif_player.c $(PARSDIR)/verif_positions.c \


OBJS = $(SRCS:$(PARSDIR)/%.c=$(OBJDIR)/%.o)

LIBFT = $(LIBFTDIR)/libft.a

MINILIBX = $(MINILIBXDIR)/libmlx.a

all: $(LIBFT) $(MINILIBX) $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MINILIBX)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLXFLAGS) $(LIBFT)
	@echo "\033[32m✔ Compilation completed\033[0m"

$(OBJDIR)/%.o: $(PARSDIR)/%.c | $(OBJDIR)
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
