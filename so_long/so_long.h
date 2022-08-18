/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klemongr <klemongr@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:22:12 by klemongr          #+#    #+#             */
/*   Updated: 2022/03/11 00:05:27 by klemongr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_long
{
	char	**map;
	void	*mlx;
	void	*mlx_window;
	void	*mlx_img;
	int		coin_char;
	int		height;
	int		width;
	int		i_position;
	int		j_position;
	int		steps;
	int		i_win;
	int		j_win;
	int		big_size;
	char	*dophin_img;
	int		width_of_line;
	int		exit_char;
	int		player_start_char;

}	t_long;

typedef struct s_paint_map
{
	int		i;
	int		j;
	int		height;
	int		witdth;
	int		x;
	int		y;
	char	change;
	int		change_size;

}	t_paint;

char	**ft_split(char *str, char c);
char	**free_split(char **str);
int		ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen_plus(char *str, char c);
int		ft_strcmp(char *s1, char *s2);
void	so_long_init(t_long *so_long);
char	**read_map(char *path_to_map);
int		check_map(t_long *so_long);
int		check_false_sym(char sym);
int		windows_size(t_long *so_long);
void	print_map(t_long *so_long);
int		game_play(int index, t_long *so_long);
char	direction_key(int index);
char	*direction_dolphin(int index);
int		check_point(char *point, int *coin_char);
int		check_crash(int index, t_long *so_long);
int		close_window(t_long *so_long);
void	steps_print(t_long *so_long);

#endif