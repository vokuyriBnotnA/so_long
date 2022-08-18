/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klemongr <klemongr@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 00:15:46 by klemongr          #+#    #+#             */
/*   Updated: 2022/03/11 00:02:14 by klemongr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_img(t_long *so_long, t_paint paint, int index)
{
	int		x;
	int		y;

	so_long->mlx_img = mlx_xpm_file_to_image(so_long->mlx, "images/wall.xpm",
			&x, &y);
	mlx_put_image_to_window(so_long->mlx, so_long->mlx_window,
		so_long->mlx_img, paint.witdth, paint.height);
	if (so_long->map[paint.i][paint.j] == '1')
		so_long->mlx_img = mlx_xpm_file_to_image(so_long->mlx,
				"images/trees.xpm", &x, &y);
	if (so_long->map[paint.i][paint.j] == 'P')
		so_long->mlx_img = mlx_xpm_file_to_image(so_long->mlx,
				direction_dolphin(index), &x, &y);
	if (so_long->map[paint.i][paint.j] == 'C')
		so_long->mlx_img = mlx_xpm_file_to_image(so_long->mlx,
				"images/coin.xpm", &x, &y);
	if (so_long->map[paint.i][paint.j] == 'E')
		so_long->mlx_img = mlx_xpm_file_to_image(so_long->mlx,
				"images/exit.xpm", &x, &y);
	if (so_long->map[paint.i][paint.j] == 'V')
		so_long->mlx_img = mlx_xpm_file_to_image(so_long->mlx,
				"images/enemy.xpm", &x, &y);
	if (check_false_sym(so_long->map[paint.i][paint.j]))
		mlx_put_image_to_window(so_long->mlx, so_long->mlx_window,
			so_long->mlx_img, paint.witdth, paint.height);
}

char	check_change(int index, t_long *so_long, t_paint *paint)
{
	if (paint->change_size)
	{
		if (direction_key(index) == 'w' && paint->i <= so_long->i_win + 26)
			return (so_long->map[paint->i + 1][paint->j]);
		if (direction_key(index) == 's' && paint->i > 0)
			return (so_long->map[paint->i - 1][paint->j]);
		if (direction_key(index) == 'a' && paint->j <= so_long->j_win + 40)
			return (so_long->map[paint->i][paint->j + 1]);
		if (direction_key(index) == 'd' && paint->j > 0)
			return (so_long->map[paint->i][paint->j - 1]);
	}
	else
	{
		if (direction_key(index) == 'w' && paint->i > 0)
			return (so_long->map[paint->i - 1][paint->j]);
		if (direction_key(index) == 's' && paint->i < so_long->height - 1)
			return (so_long->map[paint->i + 1][paint->j]);
		if (direction_key(index) == 'a' && paint->j > 0)
			return (so_long->map[paint->i][paint->j - 1]);
		if (direction_key(index) == 'd' && paint->j < so_long->j_win + 40)
			return (so_long->map[paint->i][paint->j + 1]);
	}
	return (0);
}

void	paint_map(t_long *so_long, int index)
{
	t_paint		paint;

	if (so_long->big_size)
		paint.change_size = windows_size(so_long);
	else
		paint.change_size = 0;
	paint.i = so_long->i_win;
	paint.height = 0;
	while (so_long->map[paint.i] && paint.i <= so_long->i_win + 26)
	{
		paint.j = so_long->j_win;
		paint.witdth = 0;
		while (so_long->map[paint.i][paint.j] && paint.j <= so_long->j_win + 40)
		{
			paint.change = check_change(index, so_long, &paint);
			if (paint.change != so_long->map[paint.i][paint.j]
					&& paint.change != 0)
				print_img(so_long, paint, index);
			paint.witdth += 40;
			paint.j++;
		}
		paint.height += 40;
		paint.i++;
	}
}

void	change_position(int index, t_long *so_long)
{
	if (direction_key(index) == 'e')
		close_window(so_long);
	if (direction_key(index) == 'w')
	{
		so_long->map[so_long->i_position][so_long->j_position] = '0';
		so_long->map[--so_long->i_position][so_long->j_position] = 'P';
	}
	if (direction_key(index) == 's')
	{
		so_long->map[so_long->i_position][so_long->j_position] = '0';
		so_long->map[++so_long->i_position][so_long->j_position] = 'P';
	}
	if (direction_key(index) == 'a')
	{
		so_long->map[so_long->i_position][so_long->j_position] = '0';
		so_long->map[so_long->i_position][--so_long->j_position] = 'P';
	}
	if (direction_key(index) == 'd')
	{
		so_long->map[so_long->i_position][so_long->j_position] = '0';
		so_long->map[so_long->i_position][++so_long->j_position] = 'P';
	}
}

int	game_play(int index, t_long *so_long)
{
	int		x;
	int		y;
	char	*steps;

	if (check_crash(index, so_long))
		return (0);
	so_long->dophin_img = direction_dolphin(index);
	change_position(index, so_long);
	paint_map(so_long, index);
	so_long->steps++;
	steps_print(so_long);
	return (0);
}
