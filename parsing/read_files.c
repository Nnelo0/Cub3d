/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnelo <nnelo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:46:02 by ebroudic          #+#    #+#             */
/*   Updated: 2025/03/21 18:05:12 by nnelo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

int	read_file(char *filename, t_cub *cub)
{
	int		j;
	int		i;
	int		fd;
	char	*line;

	j = count_lines(filename, 1);
	if (j == -1)
		return (-1);
	fd = open(filename, O_RDONLY);
	cub->file = malloc(sizeof(char *) * (j + 1));
	if (!cub->file)
		return (-1);
	i = 0;
	while (i < j)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		cub->file[i] = ft_strdup(line);
		free(line);
		i++;
	}
	cub->file[i] = NULL;
	close (fd);
	return (0);
}

int	has_textures_utils(t_cub *cub, int *j)
{
	if (ft_strcmp(cub->split_file[0], "WE") == 0)
	{
		if (cub->face_we)
			return (print_duplicate("WE"));
		cub->face_we = read_path(cub->face_we, cub, j);
	}
	else if (ft_strcmp(cub->split_file[0], "C") == 0)
	{
		if (cub->colors_celling)
			return (print_duplicate("C"));
		cub->colors_celling = read_path(cub->colors_celling, cub, j);
	}
	else if (ft_strcmp(cub->split_file[0], "F") == 0)
	{
		if (cub->colors_floor)
			return (print_duplicate("F"));
		cub->colors_floor = read_path(cub->colors_floor, cub, j);
	}
	return (0);
}

int	has_textures(t_cub *cub, int *j)
{
	if (ft_strcmp(cub->split_file[0], "NO") == 0)
	{
		if (cub->face_no)
			return (print_duplicate("NO"));
		cub->face_no = read_path(cub->face_no, cub, j);
	}
	else if (ft_strcmp(cub->split_file[0], "SO") == 0)
	{
		if (cub->face_so)
			return (print_duplicate("SO"));
		cub->face_so = read_path(cub->face_so, cub, j);
	}
	else if (ft_strcmp(cub->split_file[0], "EA") == 0)
	{
		if (cub->face_ea)
			return (print_duplicate("EA"));
		cub->face_ea = read_path(cub->face_ea, cub, j);
	}
	if ((*j))
		return (0);
	if (has_textures_utils(cub, j) == -1)
		return (-1);
	return (0);
}

void	read_map(t_cub *cub, int *k, int j, int i)
{
	char	*tmp;

	if (!j && ft_strchr(cub->split_file[0], '1'))
	{
		cub->map[(*k)] = ft_strdup(cub->file[i]);
		tmp = cub->map[(*k)];
		cub->map[(*k)] = ft_strtrim(cub->map[(*k)], "\n");
		free(tmp);
		(*k)++;
	}
}

int	read_textures_colors(t_cub *cub, int i, int k, int j)
{
	int		type;

	type = -1;
	while (cub->file[i])
	{
		j = 0;
		cub->split_file = ft_split_tab_space(cub->file[i]);
		if (!cub->split_file || !cub->split_file[0])
		{
			i++;
			free_array(cub->split_file);
			continue ;
		}
		if (has_textures(cub, &j) == -1)
			type = -1;
		read_map(cub, &k, j, i);
		if (cub->split_file && cub->split_file[0])
			free_array(cub->split_file);
		i++;
	}
	return (cub->map[k] = NULL, type);
}
