/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebroudic <ebroudic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 13:17:09 by ebroudic          #+#    #+#             */
/*   Updated: 2025/03/17 15:54:28 by ebroudic         ###   ########.fr       */
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
		type = -1;
	}
	// free(cub->face_NO);
	// cub->face_NO = ft_strdup("./textures/pizza.xpm");
	if (verif_textures_exists(cub, cub->face_NO, cub->img_NO, "NO") == -1)
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
		type = -1;
	}
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
		type = -1;
	}
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
		type = -1;
	}
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
		type = -1;
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
		type = -1;
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

int	verif_map(t_cub *cub)
{
	int	type;

	type = 0;
	if (!cub->map || !cub->map[0])
	{
		print_error(GREEN, "", "Missing <MAP>\n\033[1;33m<usage>: 1 for wall, \
0 for empty spaces, [N][S][E][W] for player", "");
		type = -1;
	}
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
		return (-1);
	return (type);
}