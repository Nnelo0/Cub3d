/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebroudic <ebroudic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 13:17:09 by ebroudic          #+#    #+#             */
/*   Updated: 2025/03/17 13:31:24 by ebroudic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

void	print_error(char *colors, char *msg)
{
	printf("\033[1;31mError\n%s%s\n" RESET, colors, msg);
}

int	verif_textures(t_cub *cub)
{
	int	type;
	
	type = 0;
	if (!cub->face_NO)
	{
		print_error(GREEN, "Missing <NORTH> textures\n\033[1;33m<usage>: NO ./path_to_the_north_texture");
		type = -1;
	}
	if (!cub->face_SO)
	{	
		print_error(GREEN, "Missing <SOUTH> textures\n\033[1;33m<usage>: SO ./path_to_the_south_texture");
		type = -1;
	}
	if (!cub->face_EA)
	{
		print_error(GREEN, "Missing <EAST> textures\n\033[1;33m<usage>: EA ./path_to_the_east_texture");
		type = -1;
	}
	if (!cub->face_WE)
	{
		print_error(GREEN, "Missing <WEST> textures\n\033[1;33m<usage>: WE ./path_to_the_west_texture");
		type = -1;
	}
	return (type);
}

int	verif(t_cub *cub)
{
	if (verif_textures(cub) == -1)
		return (-1);
	// if (verif_colors(cub) == -1)
	// 	return (-1);
	// if (verif_map(cub) == -1)
	// 	return (-1);
	return (0);
}