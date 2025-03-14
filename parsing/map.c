/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebroudic <ebroudic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:46:02 by ebroudic          #+#    #+#             */
/*   Updated: 2025/03/14 16:41:30 by ebroudic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

int	count_lines(char *filename)
{
	int		bit;
	int		count;
	int		fd;
	char	c;
	int		has_newline;

	fd = open(filename, O_RDONLY);
	count = 0;
	bit = 1;
	has_newline = 0;
	c = 0;
	while (bit)
	{
		bit = read(fd, &c, 1);
		if (bit == -1)
			return (ft_printf("Error\nCan't read the file\n"), close(fd), -1);
		if (c == '\n')
		{
			count++;
			has_newline = 1;
		}
		else
			has_newline = 0;
	}
	if (!has_newline)
		count++;
	return (close(fd), count);
}

int	read_file(char *filename, t_cub *cub)
{
	int		j;
	int		i;
	int		fd;
	char	*line;

	j = count_lines(filename);
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
void	has_textures(t_cub *cub)
{
	if (ft_strcmp(cub->split_file[0], "NO") == 0 && !cub->face_NO)
	{	
		cub->face_NO = ft_strdup(cub->split_file[1]);
		free_array(cub->split_file);
		cub->split_file = NULL;
	}
	else if (ft_strcmp(cub->split_file[0], "SO") == 0 && !cub->face_SO)
	{	
		cub->face_SO = ft_strdup(cub->split_file[1]);
		free_array(cub->split_file);
		cub->split_file = NULL;
	}
	else if (ft_strcmp(cub->split_file[0], "EA") == 0 && !cub->face_EA)
	{	
		cub->face_EA = ft_strdup(cub->split_file[1]);
		free_array(cub->split_file);
		cub->split_file = NULL;
	}
	else if (ft_strcmp(cub->split_file[0], "WE") == 0 && !cub->face_WE)
	{	
		cub->face_WE = ft_strdup(cub->split_file[1]);
		free_array(cub->split_file);
		cub->split_file = NULL;
	}
	else if (ft_strcmp(cub->split_file[0], "C") == 0 && !cub->colors_celling)
	{	
		cub->colors_celling = ft_strdup(cub->split_file[1]);
		free_array(cub->split_file);
		cub->split_file = NULL;
	}
	else if (ft_strcmp(cub->split_file[0], "F") == 0 && !cub->colors_floor)
	{	
		cub->colors_floor = ft_strdup(cub->split_file[1]);
		free_array(cub->split_file);
		cub->split_file = NULL;
	}
}

int	read_textures_colors(t_cub *cub)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (cub->file[i])
	{
		cub->split_file = ft_split_tab_space(cub->file[i]);
		if (!cub->split_file || !cub->split_file[0])
		{
			i++;
			continue ;
		}
		has_textures(cub);
		if (!cub->split_file || !cub->split_file[0])
		{
			i++;
			continue ;
		}
		i++;
	}
	return (0);
}

// int	read_map(t_cub *cub)
// {
// 	int	i;

// 	i = 0;
// 	while (cub->file[i])
// }