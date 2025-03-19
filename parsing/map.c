/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebroudic <ebroudic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:46:02 by ebroudic          #+#    #+#             */
/*   Updated: 2025/03/19 14:52:16 by ebroudic         ###   ########.fr       */
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

char	*ft_super_strtrim(char *str)
{
	char	*tmp;

	tmp = str;
	str = ft_strtrim(str, "\n \t");
	free(tmp);
	return (str);
}

char	*read_path(char *str, t_cub *cub, int *j)
{
	str = ft_strdup(cub->split_file[1]);
	str = ft_super_strtrim(str);
	free_array(cub->split_file);
	cub->split_file = NULL;
	(*j) = 1;
	return (str);
}

void	has_textures(t_cub *cub, int *j)
{
	if (ft_strcmp(cub->split_file[0], "NO") == 0 && !cub->face_no)
	{
		cub->face_no = read_path(cub->face_no, cub, j);
	}
	else if (ft_strcmp(cub->split_file[0], "SO") == 0 && !cub->face_so)
	{
		cub->face_so = read_path(cub->face_so, cub, j);
	}
	else if (ft_strcmp(cub->split_file[0], "EA") == 0 && !cub->face_ea)
	{
		cub->face_ea = read_path(cub->face_ea, cub, j);
	}
	else if (ft_strcmp(cub->split_file[0], "WE") == 0 && !cub->face_we)
	{
		cub->face_we = read_path(cub->face_we, cub, j);
	}
	else if (ft_strcmp(cub->split_file[0], "C") == 0 && !cub->colors_celling)
	{
		cub->colors_celling = read_path(cub->colors_celling, cub, j);
	}
	else if (ft_strcmp(cub->split_file[0], "F") == 0 && !cub->colors_floor)
	{
		cub->colors_floor = read_path(cub->colors_floor, cub, j);
	}
}

int	read_textures_colors(t_cub *cub, int i, int k, int j)
{
	char	*tmp;

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
		has_textures(cub, &j);
		if (!j && ft_strchr(cub->split_file[0], '1'))
		{
			cub->map[k] = ft_strdup(cub->file[i]);
			tmp = cub->map[k];
			cub->map[k] = ft_strtrim(cub->map[k], "\n");
			free(tmp);
			k++;
		}
		if (cub->split_file && cub->split_file[0])
			free_array(cub->split_file);
		i++;
	}
	return (cub->map[k] = NULL, 0);
}
