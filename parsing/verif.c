/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebroudic <ebroudic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 13:17:09 by ebroudic          #+#    #+#             */
/*   Updated: 2025/03/19 13:12:25 by ebroudic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

void	print_error(char *colors, char *extra, char *msg, char *extra2)
{
	printf("\033[1;31mError\n%s%s%s%s\n" RESET, colors, extra, msg, extra2);
}

int verif_no(t_cub *cub)
{
	int	type;
	int	width;
	int	height;

	type = 0;
	if (!cub->face_no)
	{
		print_error(GREEN,"",
			"Missing <NORTH> textures\n\033[1;33m<usage>: NO ./path_to_the_north_texture", "");
		return (type = -1);
	}
	cub->img_no = mlx_xpm_file_to_image(cub->mlx_ptr, cub->face_no, &width, &height);
	if (!cub->img_no)
	{
		print_error(CYAN, cub->face_no, " not found for ", "<NO>");
		type = -1;
	}
	return (type);
}

int verif_so(t_cub *cub)
{
	int	type;
	int	width;
	int	height;

	type = 0;
	if (!cub->face_so)
	{
		print_error(GREEN, "",
			"Missing <SOUTH> textures\n\033[1;33m<usage>: SO ./path_to_the_south_texture", "");
		return (type = -1);
	}
	cub->img_so = mlx_xpm_file_to_image(cub->mlx_ptr, cub->face_so, &width, &height);
	if (!cub->img_so)
	{
		print_error(CYAN, cub->face_so, " not found for ", "<SO>");
		type = -1;
	}
	return (type);
}

int verif_we(t_cub *cub)
{
	int	type;
	int	width;
	int	height;

	type = 0;
	if (!cub->face_we)
	{
		print_error(GREEN, "",
			"Missing <WEST> textures\n\033[1;33m<usage>: WE ./path_to_the_west_texture", "");
		return (type = -1);
	}
	cub->img_we = mlx_xpm_file_to_image(cub->mlx_ptr, cub->face_we, &width, &height);
	if (!cub->img_we)
	{
		print_error(CYAN, cub->face_we, " not found for ", "<WE>");
		type = -1;
	}
	return (type);
}

int verif_ea(t_cub *cub)
{
	int	type;
	int	width;
	int	height;

	type = 0;
	if (!cub->face_ea)
	{
		print_error(GREEN, "",
			"Missing <EAST> textures\n\033[1;33m<usage>: EA ./path_to_the_east_texture", "");
		return (type = -1);
	}
	cub->img_ea = mlx_xpm_file_to_image(cub->mlx_ptr, cub->face_ea, &width, &height);
	if (!cub->img_ea)
	{
		print_error(CYAN, cub->face_ea, " not found for ", "<EA>");
		type = -1;
	}
	return (type);
}

int	ft_isdigit_s(char *s, char *extra, char *index)
{
	int	i;
	int	type;

	i = 0;
	type = 0;
	while (s[i])
	{
		if (!('0' <= s[i] && '9' >= s[i]))
		{
			printf(RED "ERROR\n\033[1;32m[%c] \033[1;34min \033[1;32m%s \033[1;34mof \033[1;32m%s \033[1;33mmust be a digit in 0 and 255\n", s[i], extra, index);
			type = -1;
		}
		i++;
	}
	return (type);
}

int	verif_result(int i, char *extra ,char *index)
{
	int type;
	
	type = 0;
	if (i > 255 || i < 0)
	{
		printf(RED "ERROR\n\033[1;32m[%d] \033[1;34mof \033[1;32m%s \033[1;34min \033[1;32m%s \033[1;33mmust be in 0 and 255\n", i, extra ,index);
		type = -1;
	}
	return (type);
}

int	init_colors(t_cub *cub, char *colors, char *index, int type)
{
	char	**tmp;
	int		r;
	int		g;
	int		b;

	tmp = ft_split(colors, ',');
	if (!tmp || !tmp[0] || !tmp[1] || !tmp[2])
		return (free_array(tmp), print_error(GREEN, "", "We need <R> <G> <B> for ", index), -1);
	if (ft_isdigit_s(tmp[0], "<R>", index) == -1)
		 type = -1;
	if (ft_isdigit_s(tmp[1], "<G>", index) == -1)
		 type = -1;
	if (ft_isdigit_s(tmp[2], "<B>", index) == -1)
		type = -1;
	if (type == -1)
		return (free_array(tmp), type);
	r = ft_atoi(tmp[0]);
	if (verif_result(r, "<R>", index) == -1)
		type = -1;
	g = ft_atoi(tmp[1]);
	if (verif_result(g, "<G>", index) == -1)
		type = -1;
	b = ft_atoi(tmp[2]);
	if (verif_result(b, "<B>", index) == -1)
		type = -1;
	if (ft_strcmp(index, "{C}") == 0)
		cub->colors_c = ((r << 24) | (g << 16) | (b << 8) | 0xff);
	else
		cub->colors_f = ((r << 24) | (g << 16) | (b << 8) | 0xff);
	free_array(tmp);
	return (type);
}

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
	if (init_colors(cub, cub->colors_celling, "{C}", 0))
		type = -1;
	return (type);
}

int verif_f(t_cub *cub)
{
	int	type;

	type = 0;
	if (!cub->colors_floor)
	{
		print_error(GREEN,"", "Missing <FLOOR> colors\n\033[1;33m<usage>: F <R>, \
<G>, <B>", "");
		return (type = -1);
	}
	if (init_colors(cub, cub->colors_floor, "{F}", 0))
		type = -1;
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
			printf("\033[1;31mError\n\033[1;35m{%c} in \033[1;34m<y>: %d \033[1;35mand \033[1;34m<x>: %d \033[1;35mmust be a [1] \033[1;33m<usage>: map must be surround by wall\n", cub->map[i][j], i + 1, j + 1);
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
		printf("\033[1;31mError\n\033[1;35m map is not playable : \033[1;36m{%c}\033[1;35m in \033[1;34my:<%d> \033[1;35mand \033[1;34mx<%d> \033[1;35mof \033[1;36m{%c} \033[1;35min \033[1;34my:<%d> \033[1;35mand \033[1;34mx:<%d> \033[1;33m<usage>: [0] must be surround by valid caracter : [0] [1] [N] [S] [W] [E]\n", cub->map[y][x + 1], y + 1, x + 2, cub->map[y][x], y + 1, x + 1);
		type = -1;
	}
	if (caract(cub->map[y][x - 1]))
	{
		printf("\033[1;31mError\n\033[1;35m map is not playable : \033[1;36m{%c}\033[1;35m in \033[1;34my:<%d> \033[1;35mand \033[1;34mx<%d> \033[1;35mof \033[1;36m{%c} \033[1;35min \033[1;34my:<%d> \033[1;35mand \033[1;34mx:<%d>\033[1;33m<usage>: [0] must be surround by valid caracter : [0] [1] [N] [S] [W] [E]\n", cub->map[y][x - 1], y + 1, x, cub->map[y][x], y + 1, x + 1);
		type = -1;
	}
	if (caract(cub->map[y + 1][x]))
	{
		printf("\033[1;31mError\n\033[1;35m map is not playable : \033[1;36m{%c}\033[1;35m in \033[1;34my:<%d> \033[1;35mand \033[1;34mx<%d> \033[1;35mof \033[1;36m{%c} \033[1;35min \033[1;34my:<%d> \033[1;35mand \033[1;34mx:<%d> \033[1;33m<usage>: [0] must be surround by valid caracter : [0] [1] [N] [S] [W] [E]\n", cub->map[y + 1][x], y + 2, x + 1, cub->map[y][x], y + 1, x + 1);
		type = -1;
	}
	if (caract(cub->map[y - 1][x]))
	{
		printf("\033[1;31mError\n\033[1;35m map is not playable : \033[1;36m{%c}\033[1;35m in \033[1;34my:<%d> \033[1;35mand \033[1;34mx<%d> \033[1;35mof \033[1;36m{%c} \033[1;35min \033[1;34my:<%d> \033[1;35mand \033[1;34mx:<%d> \033[1;33m<usage>: [0] must be surround by valid caracter : [0] [1] [N] [S] [W] [E]\n", cub->map[y - 1][x], y, x + 1, cub->map[y][x], y + 1, x + 1);
		type = -1;
	}
	if (caract(cub->map[y - 1][x - 1]))
	{
		printf("\033[1;31mError\n\033[1;35m map is not playable : \033[1;36m{%c}\033[1;35m in \033[1;34my:<%d> \033[1;35mand \033[1;34mx<%d> \033[1;35mof \033[1;36m{%c} \033[1;35min \033[1;34my:<%d> \033[1;35mand \033[1;34mx:<%d> \033[1;33m<usage>: [0] must be surround by valid caracter : [0] [1] [N] [S] [W] [E]\n", cub->map[y - 1][x - 1], y, x, cub->map[y][x], y + 1, x + 1);
		type =-1;
	}
	if (caract(cub->map[y - 1][x + 1]))
	{
		printf("\033[1;31mError\n\033[1;35m map is not playable : \033[1;36m{%c}\033[1;35m in \033[1;34my:<%d> \033[1;35mand \033[1;34mx<%d> \033[1;35mof \033[1;36m{%c} \033[1;35min \033[1;34my:<%d> \033[1;35mand \033[1;34mx:<%d> \033[1;33m<usage>: [0] must be surround by valid caracter : [0] [1] [N] [S] [W] [E]\n", cub->map[y - 1][x + 1], y, x + 2, cub->map[y][x], y + 1, x + 1);
		type =-1;
	}
	if (caract(cub->map[y + 1][x + 1]))
	{
		printf("\033[1;31mError\n\033[1;35m map is not playable : \033[1;36m{%c}\033[1;35m in \033[1;34my:<%d> \033[1;35mand \033[1;34mx<%d> \033[1;35mof \033[1;36m{%c} \033[1;35min \033[1;34my:<%d> \033[1;35mand \033[1;34mx:<%d> \033[1;33m<usage>: [0] must be surround by valid caracter : [0] [1] [N] [S] [W] [E]\n", cub->map[y + 1][x + 1], y + 2, x + 2, cub->map[y][x], y + 1, x + 1);
		type =-1;
	}
	if (caract(cub->map[y + 1][x - 1]))
	{
		printf("\033[1;31mError\n\033[1;35m map is not playable : \033[1;36m{%c}\033[1;35m in \033[1;34my:<%d> \033[1;35mand \033[1;34mx<%d> \033[1;35mof \033[1;36m{%c} \033[1;35min \033[1;34my:<%d> \033[1;35mand \033[1;34mx:<%d> \033[1;33m<usage>: [0] must be surround by valid caracter : [0] [1] [N] [S] [W] [E]\n", cub->map[y + 1][x - 1], y + 2, x, cub->map[y][x], y + 1, x + 1);
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
