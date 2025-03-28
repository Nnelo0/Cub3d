/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnelo <nnelo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 09:01:29 by lelanglo          #+#    #+#             */
/*   Updated: 2025/03/28 23:16:51 by nnelo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	init_destroy(t_data *data, t_cub *cub)
{
	if (cub->img_no)
		mlx_destroy_image(data->mlx, cub->img_no);
	if (cub->img_so)
		mlx_destroy_image(data->mlx, cub->img_so);
	if (cub->img_we)
		mlx_destroy_image(data->mlx, cub->img_we);
	if (cub->img_ea)
		mlx_destroy_image(data->mlx, cub->img_ea);
	free_array(cub->file);
	free(cub->colors_celling);
	free(cub->colors_floor);
	data->map = NULL;
	data->map = cub->map;
	data->c = cub->colors_c;
	data->f = cub->colors_f;
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Cub3D");
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->img_data = (int *)mlx_get_data_addr(data->img, &data->bpp,
			&data->size_line, &data->endian);
}

static void	orientation_e(t_data *data)
{
	data->player.dir_x = 1;
	data->player.dir_y = 0;
	data->player.plane_x = 0;
	data->player.plane_y = 0.66;
}

static void	orientation_player(t_cub *cub, t_data *data)
{
	if (cub->player[0] == 'N')
	{
		data->player.dir_x = 0;
		data->player.dir_y = -1;
		data->player.plane_x = 0.66;
		data->player.plane_y = 0;
	}
	else if (cub->player[0] == 'S')
	{
		data->player.dir_x = 0;
		data->player.dir_y = 1;
		data->player.plane_x = -0.66;
		data->player.plane_y = 0;
	}
	else if (cub->player[0] == 'W')
	{
		data->player.dir_x = -1;
		data->player.dir_y = 0;
		data->player.plane_x = 0;
		data->player.plane_y = -0.66;
	}
	else if (cub->player[0] == 'E')
		orientation_e(data);
}

static void	init_tex(t_data *data, t_cub *cub)
{
	free(cub->player);
	data->textures[0] = load_texture(data->mlx, cub->face_no);
	data->textures[1] = load_texture(data->mlx, cub->face_so);
	data->textures[2] = load_texture(data->mlx, cub->face_ea);
	data->textures[3] = load_texture(data->mlx, cub->face_we);
	free(cub->face_no);
	free(cub->face_so);
	free(cub->face_ea);
	free(cub->face_we);
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_cub	cub;

	if (argc != 2)
		return (printf(RED "Error\nusage: %s./cub3D filename\n"RESET, GREEN)
			, 2);
	data.mlx = mlx_init();
	if (!data.mlx)
		return (printf(RED "Error\n%smlx_init failed\n"RESET, GREEN), 2);
	if (parsing(&cub, &data, argv) == -1)
		return (2);
	init_destroy(&data, &cub);
	(orientation_player(&cub, &data), init_tex(&data, &cub), init_keys(&data));
	mlx_hook(data.win, 2, 1L << 0, key_press, &data);
	mlx_hook(data.win, 3, 1L << 1, key_release, &data);
	return (mlx_loop_hook(data.mlx, update, &data), (mlx_hook(data.win, 17,
				0, handle_close, &data), mlx_loop(data.mlx)), 0);
}
