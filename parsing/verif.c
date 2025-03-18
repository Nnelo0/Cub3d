/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebroudic <ebroudic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 13:17:09 by ebroudic          #+#    #+#             */
/*   Updated: 2025/03/18 15:33:23 by ebroudic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

void	print_error(char *colors, char *extra, char *msg, char *extra2)
{
	printf("\033[1;31mError\n%s%s%s%s\n" RESET, colors, extra, msg, extra2);
}

int	verif_textures_exists(t_cub *cub, char *path, char *img, char *index)
{
	int	width;
	int	height;
	
	img = mlx_xpm_file_to_image(cub->mlx_ptr, path, &width, &height);
	if (!img)
	{
		print_error(CYAN, path, " not found for ", index);
		return (-1);
	}
	return (0);
}

int verif_no(t_cub *cub)
{
	int	type;

	type = 0;
	if (!cub->face_no)
	{
		print_error(GREEN,"",
			"Missing <NORTH> textures\n\033[1;33m<usage>: NO ./path_to_the_north_texture", "");
		return (type = -1);
	}
	if (verif_textures_exists(cub, cub->face_no, cub->img_no, "<NO>") == -1)
		type = -1;
	return (type);
}

int verif_so(t_cub *cub)
{
	int	type;

	type = 0;
	if (!cub->face_so)
	{
		print_error(GREEN, "",
			"Missing <SOUTH> textures\n\033[1;33m<usage>: SO ./path_to_the_south_texture", "");
		return (type = -1);
	}
	if (verif_textures_exists(cub, cub->face_so, cub->img_so, "<SO>") == -1)
		type = -1;
	return (type);
}

int verif_we(t_cub *cub)
{
	int	type;

	type = 0;
	if (!cub->face_we)
	{
		print_error(GREEN, "",
			"Missing <WEST> textures\n\033[1;33m<usage>: WE ./path_to_the_west_texture", "");
		return (type = -1);
	}
	if (verif_textures_exists(cub, cub->face_we, cub->img_we, "<WE>") == -1)
		type = -1;
	return (type);
}

int verif_ea(t_cub *cub)
{
	int	type;

	type = 0;
	if (!cub->face_ea)
	{
		print_error(GREEN, "",
			"Missing <EAST> textures\n\033[1;33m<usage>: EA ./path_to_the_east_texture", "");
		return (type = -1);
	}
	if (verif_textures_exists(cub, cub->face_ea, cub->img_ea, "<EA>") == -1)
		type = -1;
	return (type);
}

// int	verif_result(int i, char *extra ,char *index)
// {
// 	int type;
	
// 	if (i > 255 || i < 0)
// 	{
// 		printf()
// 		type = -1;
// 	}
// }
// int	init_colors(char *colors, char *index, int type)
// {
// 	char	**tmp;
// 	int		r;
// 	int		g;
// 	int		b;

// 	tmp = ft_split(colors, ",");
// 	if (!tmp || !tmp[0] || !tmp[1] || !tmp[2])
// 		return (print_error(GREEN, "", "We need <R> <G> <B> for", index), -1);
// 	r = ft_atoi(tmp[0]);
// 	if (verif_result(r, "<R>", index) == -1)
// 		type = -1;
// 	g = ft_atoi(tmp[1]);
// 	if (verif_result(g, "<G>", index) == -1)
// 		type = -1;
// 	b = ft_atoi(tmp[2]);
// 	if (verif_result(b, "<B>", index) == -1)
// 		type = -1;
// 	return (type);
// } a finir
int verif_c(t_cub *cub)
{
	int	type;

	type = 0;
	if (!cub->colors_celling)
	{
		print_error(GREEN,"", "Missing <CELLING> colors\n\033[1;33m<usage>: C <R>, \
<G>, <B>", "");
		return (type = -1);
	}
	// if (init_colors(cub->colors_celling, "{C}", 0))
	// 	type = -1;
	return (type);
}

int verif_f(t_cub *cub)
{
	int	type;

	type = 0;
	if (!cub->colors_floor)
	{
		print_error(GREEN,"", "Missing <FLOOR> colors\n\033[1;33m<usage>: F <R>,\
<G>, <B>", "");
		return (type = -1);
	}
	return (type);
}

int	verif_textures(t_cub *cub)
{
	int	type;

	type = 0;
	if (verif_no(cub) == -1)
		type = -1;
	if (verif_so(cub) == -1)
		type = -1;
	if (verif_ea(cub) == -1)
		type = -1;
	if (verif_we(cub) == -1)
		type = -1;
	return (type);
}

int	verif_colors(t_cub *cub)
{
	int	type;

	type = 0;
	if (verif_c(cub) == -1)
		type = -1;
	if (verif_f(cub) == -1)
		type = -1;
	return (type);
}

int	verif_caracter(t_cub *cub)
{
	int	i;
	int	j;
	int	type;

	i = 0;
	type = 0;
	while (cub->map[i])
	{
		j = 0;
		while (cub->map[i][j])
		{
			if (cub->map[i][j] != '1' && cub->map[i][j] != '0' && cub->map[i][j] != ' ' &&
				cub->map[i][j] != 'N' && cub->map[i][j] != 'S' && cub->map[i][j] != 'E' &&
				cub->map[i][j] != 'W')
				{
					printf("\033[1;31mError\n\033[1;35m{%c} in \033[1;34m<y>: %d \033[1;35mand \033[1;34m<x>: %d \033[1;35mnot allowed in map file \033[1;33monly [1] [0] [ ] [N] [S] [E] [W] is allowed\n", cub->map[i][j], i + 1, j + 1);
					type = -1;
				}
			j++;
		}
		i++;
	}
	return (type);
}

int	verif_wall(t_cub *cub)
{
	int	i;
	int	j;
	int	type;

	i = 0;
	type = 0;
	while (cub->map[i])
	{
		j = 0;
		while (cub->map[i][j + 1])
			j++;
		if (cub->map[i][j] != '1')
		{
			printf("\033[1;31mError\n\033[1;35m{%c} in \033[1;34m<y>: %d \033[1;35mand \033[1;34m<x>: %d \033[1;35mmust be a [1] \033[1;33mmap must be surround by wall\n", cub->map[i][j], i + 1, j + 1);
			type = -1;
		}
		j = 0;
		while (cub->map[i][j] == ' ')
			j++;
		if (cub->map[i][j] != '1')
		{
			printf("\033[1;31mError\n\033[1;35m{%c} in \033[1;34m<y>: %d \033[1;35mand \033[1;34m<x>: %d \033[1;35mmust be a [1] \033[1;33mmap must be surround by wall\n", cub->map[i][j], i + 1, j + 1);
			type = -1;
		}
		i++;
	}
	return (type);
}

int	verif_one_player(t_cub *cub)
{
	int	i;
	int	j;
	int	type;
	int	player;

	i = 0;
	type = 0;
	player = 0;
	while (cub->map[i])
	{
		j = 0;
		while (cub->map[i][j])
		{
			if (cub->map[i][j] == 'W' || cub->map[i][j] == 'E' || cub->map[i][j] == 'S' || cub->map[i][j] == 'N')
			{
				if (player)
				{
					printf("\033[1;31mError\n\033[1;35m{%c} in \033[1;34m<y>: %d \033[1;35mand \033[1;34m<x>: %d \033[1;35mone player is allowed in map file \033[1;33m<usage>: [N] or [S] or [W] or [E] for according the player to the orientation\n", cub->map[i][j], i + 1, j + 1);
					type = -1;
				}
				player = 1;
				cub->player_x = j;
				cub->player_y = i;
			}
			j++;
		}
		i++;
	}
	if (!player)
	{
		printf("\033[1;31mError\n\033[1;35mneed a player in map file \033[1;33m<usage>: [N] or [S] or [W] or [E] for according the player to the orientation\n");
		type = -1;
	}
	return (type);
}

int	caract(char c)
{
	if (!c || c == ' ')
		return (1);
	return (0);
}

int	valid_positions(t_cub *cub, int y, int x)
{
	int	type;

	type = 0;
	if (caract(cub->map[y][x + 1]))
	{
		printf("\033[1;31mError\n\033[1;36m{%c}\033[1;35m in \033[1;34my:<%d> \033[1;35mand \033[1;34mx<%d> \033[1;35mof \033[1;36m{%c} \033[1;35min \033[1;34my:<%d> \033[1;35mand \033[1;34mx:<%d>\033[1;35m map is not playable \033[1;33m<usage>: [0] must be surround by valid caracter : [0] [1] [N] [S] [W] [E]\n", cub->map[y][x + 1], y + 1, x + 2, cub->map[y][x], y + 1, x + 1);
		type = -1;
	}
	if (caract(cub->map[y][x - 1]))
	{
		printf("\033[1;31mError\n\033[1;36m{%c}\033[1;35m in \033[1;34my:<%d> \033[1;35mand \033[1;34mx<%d> \033[1;35mof \033[1;36m{%c} \033[1;35min \033[1;34my:<%d> \033[1;35mand \033[1;34mx:<%d>\033[1;35m map is not playable \033[1;33m<usage>: [0] must be surround by valid caracter : [0] [1] [N] [S] [W] [E]\n", cub->map[y][x - 1], y + 1, x, cub->map[y][x], y + 1, x + 1);
		type = -1;
	}
	if (caract(cub->map[y + 1][x]))
	{
		printf("\033[1;31mError\n\033[1;36m{%c}\033[1;35m in \033[1;34my:<%d> \033[1;35mand \033[1;34mx<%d> \033[1;35mof \033[1;36m{%c} \033[1;35min \033[1;34my:<%d> \033[1;35mand \033[1;34mx:<%d>\033[1;35m map is not playable \033[1;33m<usage>: [0] must be surround by valid caracter : [0] [1] [N] [S] [W] [E]\n", cub->map[y + 1][x], y + 2, x + 1, cub->map[y][x], y + 1, x + 1);
		type = -1;
	}
	if (caract(cub->map[y - 1][x]))
	{
		printf("\033[1;31mError\n\033[1;36m{%c}\033[1;35m in \033[1;34my:<%d> \033[1;35mand \033[1;34mx<%d> \033[1;35mof \033[1;36m{%c} \033[1;35min \033[1;34my:<%d> \033[1;35mand \033[1;34mx:<%d>\033[1;35m map is not playable \033[1;33m<usage>: [0] must be surround by valid caracter : [0] [1] [N] [S] [W] [E]\n", cub->map[y - 1][x], y, x + 1, cub->map[y][x], y + 1, x + 1);
		type = -1;
	}
	if (caract(cub->map[y - 1][x - 1]))
	{
		printf("\033[1;31mError\n\033[1;36m{%c}\033[1;35m in \033[1;34my:<%d> \033[1;35mand \033[1;34mx<%d> \033[1;35mof \033[1;36m{%c} \033[1;35min \033[1;34my:<%d> \033[1;35mand \033[1;34mx:<%d>\033[1;35m map is not playable \033[1;33m<usage>: [0] must be surround by valid caracter : [0] [1] [N] [S] [W] [E]\n", cub->map[y - 1][x - 1], y, x, cub->map[y][x], y + 1, x + 1);
		type =-1;
	}
	if (caract(cub->map[y - 1][x + 1]))
	{
		printf("\033[1;31mError\n\033[1;36m{%c}\033[1;35m in \033[1;34my:<%d> \033[1;35mand \033[1;34mx<%d> \033[1;35mof \033[1;36m{%c} \033[1;35min \033[1;34my:<%d> \033[1;35mand \033[1;34mx:<%d>\033[1;35m map is not playable \033[1;33m<usage>: [0] must be surround by valid caracter : [0] [1] [N] [S] [W] [E]\n", cub->map[y - 1][x + 1], y, x + 2, cub->map[y][x], y + 1, x + 1);
		type =-1;
	}
	if (caract(cub->map[y + 1][x + 1]))
	{
		printf("\033[1;31mError\n\033[1;36m{%c}\033[1;35m in \033[1;34my:<%d> \033[1;35mand \033[1;34mx<%d> \033[1;35mof \033[1;36m{%c} \033[1;35min \033[1;34my:<%d> \033[1;35mand \033[1;34mx:<%d>\033[1;35m map is not playable \033[1;33m<usage>: [0] must be surround by valid caracter : [0] [1] [N] [S] [W] [E]\n", cub->map[y + 1][x + 1], y + 2, x + 2, cub->map[y][x], y + 1, x + 1);
		type =-1;
	}
	if (caract(cub->map[y + 1][x - 1]))
	{
		printf("\033[1;31mError\n\033[1;36m{%c}\033[1;35m in \033[1;34my:<%d> \033[1;35mand \033[1;34mx<%d> \033[1;35mof \033[1;36m{%c} \033[1;35min \033[1;34my:<%d> \033[1;35mand \033[1;34mx:<%d>\033[1;35m map is not playable \033[1;33m<usage>: [0] must be surround by valid caracter : [0] [1] [N] [S] [W] [E]\n", cub->map[y + 1][x - 1], y + 2, x, cub->map[y][x], y + 1, x + 1);
		type = -1;
	}
	return (type);
}

int	verif_is_playable(t_cub *cub)
{
	int		y;
	int		x;
	int		type;

	y = 0;
	type = 0;
	while (cub->map[y])
	{
		x = 0;
		while (cub->map[y][x])
		{	
			if (cub->map[y][x] == '0' || cub->map[y][x] == 'N' || cub->map[y][x] == 'S' || cub->map[y][x] == 'E' || cub->map[y][x] == 'W')
			{
				if (valid_positions(cub, y, x) == -1)
					type = -1;
			}
			x++;
		}
		y++;
	}
	return (type);
}

int	verif_map(t_cub *cub)
{
	int	type;

	type = 0;
	if (!cub->map || !cub->map[0])
	{
		print_error(GREEN, "", "Missing <MAP>\n\033[1;33m<usage>: 1 for wall, \
0 for empty spaces, [N][S][E][W] for player", "");
		return (type = -1);
	}
	if (verif_caracter(cub) == -1)
		type = -1;
	if (verif_wall(cub) == -1)
		type = -1;
	if (verif_one_player(cub) == -1)
		type = -1;
	if (verif_is_playable(cub) == -1)
		type = -1;
	return (type);
}

int	verif(t_cub *cub)
{
	int type;

	type = 0;
	if (verif_textures(cub) == -1)
		type = -1;
	if (verif_colors(cub) == -1)
		type = -1;
	if (verif_map(cub) == -1)
		type = -1;
	return (type);
}
