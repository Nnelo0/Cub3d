MAKEFLAGS += --silent

NAME = cub3D

CC = cc
CFLAGS = -Wall -Werror -Wextra -g

MLXFLAGS = -I./minilibx-linux -L./minilibx-linux -lmlx -lXext -lX11 -lm

OBJDIR = obj
LIBFTDIR = libft
MINILIBXDIR = minilibx-linux

SRCS = parsing/read_files.c parsing/split_tab_space.c \
parsing/verif.c parsing/verif_wall.c parsing/verif_textures.c \
parsing/verif_colors.c parsing/parsing_utils.c parsing/verif_colors_utils.c parsing/init.c\
parsing/read_files_utils.c parsing/verif_player.c parsing/verif_positions.c \
srcs/keypress.c srcs/raycasting_utils.c srcs/raycasting.c srcs/shifting.c \
srcs/main.c srcs/textures.c

OBJS = $(SRCS:%.c=$(OBJDIR)/%.o)

LIBFT = $(LIBFTDIR)/libft.a

MINILIBX = $(MINILIBXDIR)/libmlx.a

all: $(LIBFT) $(MINILIBX) $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MINILIBX)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLXFLAGS) $(LIBFT)
	@echo "\033[32m✔ Compilation completed\033[0m"

$(OBJDIR)/%.o: %.c | $(OBJDIR)
	mkdir -p $(dir $@)  # Crée les sous-dossiers si nécessaire
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
