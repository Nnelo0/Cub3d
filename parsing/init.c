/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnelo <nnelo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 21:51:48 by nnelo             #+#    #+#             */
/*   Updated: 2025/03/21 22:21:15 by nnelo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

int	verif_cub(char **argv)
{
	int		n;

	n = ft_strlen(argv[1]);
	if (n < 4)
		return (1);
	n -= 4;
	if (argv[1][n] != '.')
		return (1);
	n++;
	if (argv[1][n] != 'c')
		return (1);
	n++;
	if (argv[1][n] != 'u')
		return (1);
	n++;
	if (argv[1][n] != 'b')
		return (1);
	return (0);
}

int	init_cub(t_cub *cub, char **argv)
{
	cub->face_no = NULL;
	cub->face_so = NULL;
	cub->face_we = NULL;
	cub->face_ea = NULL;
	cub->img_no = NULL;
	cub->img_so = NULL;
	cub->img_we = NULL;
	cub->img_ea = NULL;
	cub->colors_celling = NULL;
	cub->colors_floor = NULL;
	cub->colors_c = 0;
	cub->colors_f = 0;
	cub->split_file = NULL;
	cub->player = NULL;
	cub->line_in_file = count_lines(argv[1], 1);
	if (cub->line_in_file == -1)
		return (-1);
	cub->map = malloc(sizeof(char *) * (cub->line_in_file + 1));
	if (!cub->map)
		return (printf("Error\n Malloc failed"), -1);
	cub->data = malloc(sizeof(t_data));
	if (!cub->data)
		return (printf("Error\n Malloc failed for cub->data"), -1);
	cub->data->mlx = mlx_init();
	return (0);
}

void	free_all(t_cub *cub)
{
	free_array(cub->file);
	free_array(cub->map);
	free(cub->face_no);
	free(cub->face_so);
	free(cub->face_we);
	free(cub->face_ea);
	free(cub->colors_floor);
	free(cub->colors_celling);
	if (cub->player)
		free(cub->player);
	if (cub->img_no)
		mlx_destroy_image(cub->data->mlx, cub->img_no);
	if (cub->img_so)
		mlx_destroy_image(cub->data->mlx, cub->img_so);
	if (cub->img_we)
		mlx_destroy_image(cub->data->mlx, cub->img_we);
	if (cub->img_ea)
		mlx_destroy_image(cub->data->mlx, cub->img_ea);
	mlx_destroy_display(cub->data->mlx);
	free(cub->data->mlx);
}
