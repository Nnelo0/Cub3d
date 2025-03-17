/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_tab_space.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebroudic <ebroudic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 10:29:59 by ebroudic          #+#    #+#             */
/*   Updated: 2025/03/17 14:45:45 by ebroudic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

char	**ft_split_tab_space(char const *s)
{
	char	**dsa;
	int		i;
	int		len;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] == ' ' || s[i] == '\t')
		i++;
	len = 0;
	while (s[i + len] && s[i + len] != ' ' && s[i + len] != '\t')
		len++;
	dsa = malloc(sizeof(char *) * 3);
	if (!dsa)
		return (NULL);
	dsa[0] = ft_strndup(s + i, len);
	if (!dsa[0])
		return (free(dsa), NULL);
	i += len;
	while (s[i] == ' ' || s[i] == '\t')
		i++;
	dsa[1] = ft_strdup(s + i);
	if (!dsa[1])
		return (free(dsa[0]), free(dsa), NULL);
	return (dsa[2] = NULL, dsa);
}

// int main()
// {
// 	char *s;
// 	char **res;
// 	int	i;

// 	s = "EA ./path_to_the_east_texture		ddwada";
// 	res = ft_split_tab_space(s);
// 	i = 0;
// 	while (res[i] != NULL)
// 	{
// 		printf("Segment %d : \"%s\"\n", i, res[i]);	
// 		free(res[i]);
// 		i++;
// 	}
// 	free(res);
// 	return 0;
// }
