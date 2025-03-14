/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_tab_space.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebroudic <ebroudic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 10:29:59 by ebroudic          #+#    #+#             */
/*   Updated: 2025/03/14 16:03:37 by ebroudic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

#include "../includes/parsing.h"
#include <stdio.h>
#include <stdlib.h>

static int	count_word(char const *s)
{
	int		i;
	int		count;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
			i++;
		else
		{
			count++;
			while (s[i] != '\0' && s[i] != ' ' && s[i] != '\t' && s[i] != '\n')
				i++;
		}
	}
	return (count);
}

static int	dup_word(char **dsa, const char *s, int *i)
{
	int	j;

	j = 0;
	while (s[j] != '\0' && s[j] != ' ' && s[j] != '\t' && s[j] != '\n')
		j++;
	dsa[*i] = ft_strndup(s, j);
	if (!dsa[*i])
	{
		while (*i > 0)
			free(dsa[--(*i)]);
		free(dsa);
		return (0);
	}
	(*i)++;
	return (1);
}

static int	copy_word(char **dsa, const char *s)
{
	int		i;

	i = 0;
	while (*s != '\0')
	{
		if (*s != ' ' && *s != '\t' && *s != '\n')
		{
			if (!dup_word(dsa, s, &i))
				return (0);
			while (*s != '\0' && *s != ' ' && *s != '\t' && *s != '\n')
				s++;
		}
		else
			s++;
	}
	dsa[i] = NULL;
	return (1);
}

char	**ft_split_tab_space(char const *s)
{
	char	**dsa;

	if (s == NULL)
		return (NULL);
	dsa = malloc(sizeof(char *) * (count_word(s) + 1));
	if (dsa == NULL)
		return (NULL);
	if (!copy_word(dsa, s))
	{
		free(dsa);
		return (NULL);
	}
	return (dsa);
}

/* int main()
{
	char *s;
	char **res;
	int	i;
	
	s = "	\n\td	d ";
	res = ft_split_tab_space(s);
	i = 0;
	while (res[i] != NULL)
	{
		printf("Segment %d : \"%s\"\n", i, res[i]);	
		free(res[i]);
		i++;
	}
	free(res);
	return 0;
} */
