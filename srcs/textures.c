/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebroudic <ebroudic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 15:26:19 by lelanglo          #+#    #+#             */
/*   Updated: 2025/03/27 12:40:32 by ebroudic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_img	load_texture(void *mlx, char *path)
{
	t_img	img;

	img.img_ptr = mlx_xpm_file_to_image(mlx, path, &img.width, &img.height);
	img.data = (int *)mlx_get_data_addr(img.img_ptr, &img.bpp, &img.size_line,
			&img.endian);
	return (img);
}

int	what_texture(t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->step_x > 0)
			return (2);
		else
			return (3);
	}
	else
	{
		if (ray->step_y > 0)
			return (1);
		else
			return (0);
	}
}
