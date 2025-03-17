/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelanglo <lelanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 09:01:29 by lelanglo          #+#    #+#             */
/*   Updated: 2025/03/17 15:25:25 by lelanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	put_pixel(t_data *data, int x, int y, int color)
{
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
		data->img_data[y * (data->size_line / 4) + x] = color;
}

static void	init_raycast_vars(t_data *data, int x, double *ray_dir_x, 
		double *ray_dir_y)
{
	double	camera_x;

	camera_x = 2 * x / (double)WIDTH - 1;
	*ray_dir_x = data->player.dir_x + data->player.plane_x * camera_x;
	*ray_dir_y = data->player.dir_y + data->player.plane_y * camera_x;
}

void	cast_rays(t_data *data)
{
	int		x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		color;

	x = -1;
	while (++x < WIDTH)
	{
		init_raycast_vars(data, x, &ray_dir_x, &ray_dir_y);
		color = 0x008000;
		for (int y = HEIGHT / 4; y < HEIGHT * 3 / 4; y++)
			put_pixel(data, x, y, color);
	}
}

int	render(t_data *data)
{
	mlx_clear_window(data->mlx, data->win);
	cast_rays(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}

int	handle_close(t_data *data)
{
	int	i;

	i = 0;
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	while (data->map[i])
		free(data->map[i++]);
	free(data->map);
	exit(0);
	return (0);
}

int	handle_key(int keycode, t_data *data)
{
	if (keycode == 65307)
		handle_close(data);
	return (0);
}

int	read_map(t_data *data)
{
	int		fd;
	ssize_t	bytes_read;
	char	buffer[4096];
	int		y;
	int		x;

	fd = open("map.cub", O_RDONLY);
	if (fd < 0)
		return (0);
	bytes_read = read(fd, buffer, 4096);
	if (bytes_read <= 0)
	{
		close(fd);
		return (0);
	}
	buffer[bytes_read] = '\0';
	data->map = ft_split(buffer, '\n');
	close(fd);
	y = -1;
	while (data->map[++y])
	{
		x = -1;
		while (data->map[y][++x])
		{
			if (data->map[y][x] == 'P')
			{
				data->player.x = x + 0.5;
				data->player.y = y + 0.5;
				data->map[y][x] = '0';
				return (1);
			}
		}
	}
	return (0);
}

int	main(void)
{
	t_data	data;

	if (!read_map(&data))
	{
		write(2, "Error: Could not read map or find player\n", 40);
		return (1);
	}
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "Cub3D");
	data.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	data.img_data = (int *)mlx_get_data_addr(data.img, &data.bpp,
			&data.size_line, &data.endian);
	data.player.dir_x = 0;
	data.player.dir_y = -1;
	data.player.plane_x = 0.66;
	data.player.plane_y = 0;
	mlx_hook(data.win, 17, 0, handle_close, &data);
	mlx_key_hook(data.win, handle_key, &data);
	mlx_loop_hook(data.mlx, render, &data);
	mlx_loop(data.mlx);
	return (0);
}
