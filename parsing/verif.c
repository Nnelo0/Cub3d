/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnelo <nnelo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 13:17:09 by ebroudic          #+#    #+#             */
/*   Updated: 2025/03/17 21:47:13 by nnelo            ###   ########.fr       */
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

int verif_NO(t_cub *cub)
{
	int	type;

	type = 0;
	if (!cub->face_NO)
	{
		print_error(GREEN,"",
			"Missing <NORTH> textures\n\033[1;33m<usage>: NO ./path_to_the_north_texture", "");
		return (type = -1);
	}
	if (verif_textures_exists(cub, cub->face_NO, cub->img_NO, "<NO>") == -1)
		type = -1;
	return (type);
}

int verif_SO(t_cub *cub)
{
	int	type;

	type = 0;
	if (!cub->face_SO)
	{
		print_error(GREEN, "",
			"Missing <SOUTH> textures\n\033[1;33m<usage>: SO ./path_to_the_south_texture", "");
		return (type = -1);
	}
	if (verif_textures_exists(cub, cub->face_SO, cub->img_SO, "<SO>") == -1)
		type = -1;
	return (type);
}

int verif_WE(t_cub *cub)
{
	int	type;

	type = 0;
	if (!cub->face_WE)
	{
		print_error(GREEN, "",
			"Missing <WEST> textures\n\033[1;33m<usage>: WE ./path_to_the_west_texture", "");
		return (type = -1);
	}
	if (verif_textures_exists(cub, cub->face_WE, cub->img_WE, "<WE>") == -1)
		type = -1;
	return (type);
}

int verif_EA(t_cub *cub)
{
	int	type;

	type = 0;
	if (!cub->face_EA)
	{
		print_error(GREEN, "",
			"Missing <EAST> textures\n\033[1;33m<usage>: EA ./path_to_the_east_texture", "");
		return (type = -1);
	}
	if (verif_textures_exists(cub, cub->face_EA, cub->img_EA, "<EA>") == -1)
		type = -1;
	return (type);
}

int verif_C(t_cub *cub)
{
	int	type;

	type = 0;
	if (!cub->colors_celling)
	{
		print_error(GREEN,"", "Missing <CELLING> colors\n\033[1;33m<usage>: C <R>, \
<G>, <B>", "");
		return (type = -1);
	}
	return (type);
}

int verif_F(t_cub *cub)
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
	if (verif_NO(cub) == -1)
		type = -1;
	if (verif_SO(cub) == -1)
		type = -1;
	if (verif_EA(cub) == -1)
		type = -1;
	if (verif_WE(cub) == -1)
		type = -1;
	return (type);
}

int	verif_colors(t_cub *cub)
{
	int	type;

	type = 0;
	if (verif_C(cub) == -1)
		type = -1;
	if (verif_F(cub) == -1)
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

int	verif_is_playable(t_cub *cub)
{
	int		i;
	char	**map_copy;

	i = 0;
	map_copy = malloc(sizeof(char *) * (cub->line_in_file + 1));
	if (!map_copy)
		return (printf("Error\nmalloc error\n"), -1);
	while (cub->map[i])
	{
		map_copy[i] = ft_strdup(cub->map[i]);
		i++;
	}
	map_copy[i] = NULL;
	//flood_fill(map_copy, cub->player_x, cub->player_y, &valid);
	free_array(map_copy);
	return (0);
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
