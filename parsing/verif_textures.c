/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebroudic <ebroudic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 14:40:32 by ebroudic          #+#    #+#             */
/*   Updated: 2025/03/28 09:09:35 by ebroudic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

int	verif_no(t_cub *cub, t_data *data)
{
	int	type;
	int	width;
	int	height;

	type = 0;
	if (!cub->face_no)
	{
		print_error(GREEN, "",
			"Missing <NORTH> textures \033[1;33m<usage>: NO ./path_to_the_north\
_texture", "");
		return (type = -1);
	}
	cub->img_no = mlx_xpm_file_to_image(data->mlx, cub->face_no,
			&width, &height);
	if (!cub->img_no)
	{
		print_error(CYAN, cub->face_no, " PATH not found for ", "<NO>");
		free(cub->face_no);
		cub->face_no = NULL;
		type = -1;
	}
	return (type);
}

int	verif_so(t_cub *cub, t_data *data)
{
	int	type;
	int	width;
	int	height;

	type = 0;
	if (!cub->face_so)
	{
		print_error(GREEN, "",
			"Missing <SOUTH> textures \033[1;33m<usage>: SO ./path_to_the_south\
_texture", "");
		return (type = -1);
	}
	cub->img_so = mlx_xpm_file_to_image(data->mlx, cub->face_so,
			&width, &height);
	if (!cub->img_so)
	{
		print_error(CYAN, cub->face_so, " PATH not found for ", "<SO>");
		free(cub->face_so);
		cub->face_so = NULL;
		type = -1;
	}
	return (type);
}

int	verif_we(t_cub *cub, t_data *data)
{
	int	type;
	int	width;
	int	height;

	type = 0;
	if (!cub->face_we)
	{
		print_error(GREEN, "",
			"Missing <WEST> textures \033[1;33m<usage>: WE ./path_to_the_west\
_texture", "");
		return (type = -1);
	}
	cub->img_we = mlx_xpm_file_to_image(data->mlx, cub->face_we,
			&width, &height);
	if (!cub->img_we)
	{
		print_error(CYAN, cub->face_we, " PATH not found for ", "<WE>");
		free(cub->face_we);
		cub->face_we = NULL;
		type = -1;
	}
	return (type);
}

int	verif_ea(t_cub *cub, t_data *data)
{
	int	type;
	int	width;
	int	height;

	type = 0;
	if (!cub->face_ea)
	{
		print_error(GREEN, "",
			"Missing <EAST> textures \033[1;33m<usage>: EA ./path_to_the_east\
_texture", "");
		return (type = -1);
	}
	cub->img_ea = mlx_xpm_file_to_image(data->mlx, cub->face_ea,
			&width, &height);
	if (!cub->img_ea)
	{
		print_error(CYAN, cub->face_ea, " PATH not found for ", "<EA>");
		free(cub->face_ea);
		cub->face_ea = NULL;
		type = -1;
	}
	return (type);
}
