/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_files_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnelo <nnelo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 18:05:22 by nnelo             #+#    #+#             */
/*   Updated: 2025/03/21 18:05:47 by nnelo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

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

int	print_duplicate(char *index)
{
	print_error(CYAN, "", "Duplicate path for \033[1; \
32m", index);
	return (-1);
}
