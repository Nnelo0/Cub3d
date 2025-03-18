/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shifting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelanglo <lelanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 13:29:11 by lelanglo          #+#    #+#             */
/*   Updated: 2025/03/18 14:56:02 by lelanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	destroy_image(t_data *data)
{
	if (data->img)
	{
		mlx_destroy_image(data->mlx, data->img);
		data->img = NULL;
	}
}

void	turn(t_data *data, int sens)
{
	double	old_dirx;
	double	old_planex;

	destroy_image(data);
	old_dirx = data->player.dir_x;
	data->player.dir_x = data->player.dir_x * cos((double)ROTATE * sens)
		- data->player.dir_y * sin((double)ROTATE * sens);
	data->player.dir_y = old_dirx * sin((double)ROTATE * sens)
		+ data->player.dir_y * cos((double)ROTATE * sens);
	old_planex = data->player.plane_x;
	data->player.plane_x = data->player.plane_x * cos((double)ROTATE * sens)
		- data->player.plane_y * sin((double)ROTATE * sens);
	data->player.plane_y = old_planex * sin((double)ROTATE * sens)
		+ data->player.plane_y * cos((double)ROTATE * sens);
}

void	move(t_data *data, int sens)
{
	destroy_image(data);
	data->player.x += data->player.dir_x * (double)SPEED * sens;
	data->player.y += data->player.dir_y * (double)SPEED * sens;
}

void	left_right(t_data *data, int sens)
{
	destroy_image(data);
	data->player.x += data->player.plane_x * (double)SPEED * sens;
	data->player.y += data->player.plane_y * (double)SPEED * sens;
}
