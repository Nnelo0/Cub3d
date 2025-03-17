/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnelo <nnelo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 09:12:28 by ebroudic          #+#    #+#             */
/*   Updated: 2025/03/17 21:45:59 by nnelo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../libft/libft/libft.h"
# include "../libft/printf/ft_printf.h"
# include "../minilibx-linux/mlx.h"

# define RESET   "\033[0m"
# define RED     "\033[1;31m"
# define GREEN   "\033[1;32m"
# define YELLOW  "\033[1;33m"
# define BLUE    "\033[1;34m"
# define MAGENTA "\033[1;35m"
# define CYAN    "\033[1;36m"

typedef struct s_cub
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	**file;
	char	**split_file;
	char	*face_NO;
	char	*face_SO;
	char	*face_EA;
	char	*face_WE;
	void	*img_NO;
	void	*img_SO;
	void	*img_EA;
	void	*img_WE;
	char	*colors_celling;
	char	*colors_floor;
	char	**map;
	int		player_x;
	int		player_y;
	int		line_in_file;
}				t_cub;

int		read_file(char *filename, t_cub *cub);
int		read_textures_colors(t_cub *cub);
void	free_array(char **arg);
char	**ft_split_tab_space(char const *s);
int		count_lines(char *filename);
int		verif(t_cub *cub);

#endif