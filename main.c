/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelanglo <lelanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 09:01:29 by lelanglo          #+#    #+#             */
/*   Updated: 2025/03/13 10:33:40 by lelanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	handle_close(t_data *data)
{
	mlx_destroy_window(data->mlx, data->window);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
	return (0);
}

int handle_key(int keycode, t_data *data)
{
	if (keycode == 65307)
		handle_close(data);
	return (0);
}

int main()
{
	t_data data;
	
	data.mlx = mlx_init();
	data.window = mlx_new_window(data.mlx, 1800, 900, "cube3d");
	mlx_hook(data.window, 17, 0, handle_close, &data);
	mlx_key_hook(data.window, handle_key, &data);
	mlx_loop(data.mlx);
	return (0);
}