/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnelo <nnelo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 09:01:29 by lelanglo          #+#    #+#             */
/*   Updated: 2025/03/21 22:29:28 by nnelo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	while (data->map[i])
		free(data->map[i++]);
	free(data->map);
	exit(0);
	return (0);
}

int	read_map_tmp(t_data *data)
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

int	copy_map(t_data *data, t_cub *cub)
{
	int	i;

	i = 0;
	data->map = malloc(sizeof(char *) * cub->line_in_file + 1);
	if (!data->map)
		return (printf("Error\n malloc failed\n"), -1);
	while (cub->map[i])
	{
		data->map[i] = ft_strdup(cub->map[i]);
		i++;
	}
	data->map[i] = NULL;
	for (int i = 0; data->map[i]; i++)
		printf("%s\n", data->map[i]);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_cub	cub;

	if (argc == 2)
	{
		if (verif_cub(argv))
			return (printf(RED "Error\nfilename must be finish with %s.cub\n" RESET
					, GREEN), 2);
		if (read_file(argv[1], &cub) == -1)
			return (2);
		if (init_cub(&cub, argv) == -1)
			return (2);
		read_textures_colors(&cub, 0, 0, 0);
		if (verif(&cub) == -1)
			return (free_all(&cub), 2);
		if (copy_map(&data, &cub) == -1)
			return (-1);
		data.mlx = mlx_init();
		data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "Cub3D");
		data.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
		data.img_data = (int *)mlx_get_data_addr(data.img, &data.bpp,
				&data.size_line, &data.endian);
		data.player.dir_x = 0;
		data.player.dir_y = -1;
		data.player.plane_x = 0.66;
		data.player.plane_y = 0;
		init_keys(&data);
		mlx_hook(data.win, 2, 1L << 0, key_press, &data);
		mlx_hook(data.win, 3, 1L << 1, key_release, &data);
		mlx_loop_hook(data.mlx, update, &data);
		mlx_hook(data.win, 17, 0, handle_close, &data);
		mlx_loop(data.mlx);
	}
	else
		return (printf(RED"Error\nusage: %s./cub3D filename\n"RESET, GREEN), 2);
	
	return (0);
}
