/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnelo <nnelo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 09:01:29 by ebroudic          #+#    #+#             */
/*   Updated: 2025/03/21 21:51:31 by nnelo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

// au cas ou pour ouvrir une fenetre : a mettre dans le main if (window(&cub) == -1) return (2);mlx_loop(cub.mlx_ptr); 
// int	close_window(t_cub *cub)
// {
// 	mlx_destroy_window(cub->mlx_ptr, cub->win_ptr);
// 	mlx_destroy_display(cub->mlx_ptr);
// 	return (0);
// }

// int	window(t_cub *cub)
// {
// 	cub->win_ptr = mlx_new_window(cub->mlx_ptr, 920, 720, "cub3D");
// 	if (!cub->win_ptr)
// 		return (free(cub->mlx_ptr), -1);
// 	mlx_hook(cub->win_ptr, 17, 0, close_window, cub);
// 	return (0);
// }

void	display_parsing(t_cub *cub)
{
	printf(RED "\n\n--------------------ALL_FILE--------------------\n\n" RESET);
	for (int i = 0; cub->file[i]; i++)
		printf("%s", cub->file[i]);
	printf(RED "\n\n-----------------TEXTURE_COLORS-----------------\n\n" RESET);
	printf("NO: %s\n", cub->face_no);
	printf("SO: %s\n", cub->face_so);
	printf("WE: %s\n", cub->face_we);
	printf("EA: %s\n", cub->face_ea);
	printf("FLOOR: %s\n", cub->colors_floor);
	printf("CELL: %s\n", cub->colors_celling);
	printf(RED "\n\n------------------MAP(pas de \\n)---------------\n\n" RESET);
	for (int i = 0; cub->map[i]; i++)
		printf("%s\n", cub->map[i]);
	printf(RED "\n\n-----------------------ERROR--------------------\n\n" RESET);
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
		mlx_destroy_image(cub->mlx_ptr, cub->img_no);
	if (cub->img_so)
		mlx_destroy_image(cub->mlx_ptr, cub->img_so);
	if (cub->img_we)
		mlx_destroy_image(cub->mlx_ptr, cub->img_we);
	if (cub->img_ea)
		mlx_destroy_image(cub->mlx_ptr, cub->img_ea);
	mlx_destroy_display(cub->mlx_ptr);
	free(cub->mlx_ptr);
}

int	main(int argc, char **argv)
{
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
		display_parsing(&cub);
		if (verif(&cub) == -1)
			return (free_all(&cub), 2);
		printf("c in hex: %x\n", cub.colors_c);
		printf("FLOOR in hex: %x\n", cub.colors_f);
		printf("player_x: %d\n", cub.player_x);
		printf("player_y: %d\n", cub.player_y);
		printf("player: %s\n", cub.player);
		free_all(&cub);
		return (0);
	}
	else
		return (printf(RED"Error\nusage: %s./cub3D filename\n"RESET, GREEN), 2);
	return (0);
}
