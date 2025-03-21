/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnelo <nnelo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 09:12:28 by ebroudic          #+#    #+#             */
/*   Updated: 2025/03/21 22:20:04 by nnelo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../libft/libft/libft.h"
# include "../libft/printf/ft_printf.h"
# include "../minilibx-linux/mlx.h"
# include "cub3d.h"

# define RESET   "\033[0m"
# define RED     "\033[1;31m"
# define GREEN   "\033[1;32m"
# define YELLOW  "\033[1;33m"
# define BLUE    "\033[1;34m"
# define MAGENTA "\033[1;35m"
# define CYAN    "\033[1;36m"

typedef struct s_data	t_data;

typedef struct s_cub
{
	char	**file;
	char	**split_file;
	char	*face_no;
	char	*face_so;
	char	*face_ea;
	char	*face_we;
	void	*img_no;
	void	*img_so;
	void	*img_ea;
	void	*img_we;
	char	*colors_celling;
	char	*colors_floor;
	char	**map;
	int		player_x;
	int		player_y;
	char	*player;
	int		line_in_file;
	int		colors_c;
	int		colors_f;
	t_data	*data;
}			t_cub;

/*----------------init-----------------*/

int		verif_cub(char **argv);
int		init_cub(t_cub *cub, char **argv);
void	free_all(t_cub *cub);

/*-------------read-file---------------*/

int		read_file(char *filename, t_cub *cub);
int		read_textures_colors(t_cub *cub, int i, int k, int j);
char	*ft_super_strtrim(char *str);
char	*read_path(char *str, t_cub *cub, int *j);
int		print_duplicate(char *index);
/*---------------free------------------*/

void	free_array(char **arg);

/*---------------utils-----------------*/

char	**ft_split_tab_space(char const *s);
int		count_lines(char *filename, int bit);
int		caract(char c);
void	print_error(char *colors, char *extra, char *msg, char *extra2);

/*---------------verif-----------------*/

int		verif(t_cub *cub);
int		verif_map(t_cub *cub);

/*------------verif-map----------------*/

int		verif_caracter(t_cub *cub, int i, int j);
int		verif_wall(t_cub *cub, int i, int j);
int		verif_one_player(t_cub *cub, int i, int j, int player);
int		valid_positions(t_cub *cub, int y, int x);
int		verif_is_playable(t_cub *cub);

/*-----------verif-textures------------*/

int		verif_no(t_cub *cub);
int		verif_so(t_cub *cub);
int		verif_ea(t_cub *cub);
int		verif_we(t_cub *cub);

/*------------verif-colors-------------*/

int		ft_isdigit_s(char *s, char *extra, char *index);
int		verif_result(int i, char *extra, char *index);
int		init_colors(t_cub *cub, char *colors, char *index, int type);
int		verif_c(t_cub *cub);
int		verif_f(t_cub *cub);
int		is_digit(char **tmp, char *index);

#endif
