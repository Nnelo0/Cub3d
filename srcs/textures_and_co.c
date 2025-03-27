/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_and_co.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelanglo <lelanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 15:26:19 by lelanglo          #+#    #+#             */
/*   Updated: 2025/03/27 14:10:50 by lelanglo         ###   ########.fr       */
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

int	render(t_data *data)
{
	if (!data->img)
	{
		data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
		data->img_data = (int *)mlx_get_data_addr(data->img, &data->bpp,
				&data->size_line, &data->endian);
	}
	cast_rays(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}

int	handle_close(t_data *data)
{
	int	i;

	i = 0;
	mlx_destroy_image(data->mlx, data->img);
	while (i < 4)
		mlx_destroy_image(data->mlx, data->textures[i++].img_ptr);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free_array(data->map);
	exit(0);
	return (0);
}
