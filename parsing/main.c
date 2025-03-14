/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebroudic <ebroudic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 09:01:29 by ebroudic          #+#    #+#             */
/*   Updated: 2025/03/14 17:18:21 by ebroudic         ###   ########.fr       */
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

void	free_array(char **arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		free(arg[i]);
		i++;
	}
	free(arg);
}

int	main(int argc, char **argv)
{
	t_cub	cub;

	if (argc == 2)
	{
		if (verif_cub(argv))
			return (printf(RED "filename must be finish with %s.cub\n" RESET
					, GREEN), 2);
		if (read_file(argv[1], &cub) == -1)
			return (2);
		printf(RED "\n\n--------------------ALL_FILE--------------------\n\n" RESET);	
		for (int i = 0; cub.file[i]; i++)
			printf("%s", cub.file[i]);
		printf(RED "\n\n-----------------TEXTURE_COLORS-----------------\n\n" RESET);
		cub.face_NO = NULL;
		cub.face_SO = NULL;
		cub.face_WE = NULL;
		cub.face_EA = NULL;
		cub.colors_celling = NULL;
		cub.colors_floor = NULL;
		read_textures_colors(&cub);
		printf("NO: %s\n", cub.face_NO);
		printf("SO: %s\n", cub.face_SO);
		printf("WE: %s\n", cub.face_WE);
		printf("EA: %s\n", cub.face_EA);
		printf("FLOOR: %s\n", cub.colors_floor);
		printf("CELL: %s\n", cub.colors_celling);
		printf(RED "\n\n-----------------------MAP----------------------\n\n" RESET);
		int	j;
		j = count_lines(argv[1]);
		if (j == -1)
			return (-1);
		cub.map = malloc(sizeof(char *) * (j + 1));
		read_map(&cub);
		for (int i = 0; cub.map[i]; i++)
			printf("%s", cub.map[i]);
		free_array(cub.file);
		return (0);
	}
	else
		return (printf(RED "Error\nusage: %s./cub3D filename\n" RESET, GREEN), 2);
	return (0);
}
