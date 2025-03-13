/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelanglo <lelanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 09:01:29 by lelanglo          #+#    #+#             */
/*   Updated: 2025/03/13 12:20:49 by lelanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	handle_close(t_data *data)
{
	int	i;

	i = 0;
	mlx_destroy_window(data->mlx, data->window);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	while(data->map[i])
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
	char	buffer[1024];

	fd = open("map.cub", O_RDONLY);
	if (fd < 0)
		return (0);
	bytes_read = read(fd, buffer, 1024);
	buffer[bytes_read] = '\0';
	data->map = ft_split(buffer, '\n');
	close(fd);
	return (1);
}

int	main(void)
{
	t_data	data;

	read_map(&data);
	data.mlx = mlx_init();
	data.window = mlx_new_window(data.mlx, 1800, 900, "cube3d");
	mlx_hook(data.window, 17, 0, handle_close, &data);
	mlx_key_hook(data.window, handle_key, &data);
	mlx_loop(data.mlx);
	return (0);
}
