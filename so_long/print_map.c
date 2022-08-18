/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klemongr <klemongr@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 00:10:58 by klemongr          #+#    #+#             */
/*   Updated: 2022/03/10 23:56:55 by klemongr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_map_image(t_long *so_long, int height, int witdth, char sym)
{
	int	x;
	int	y;

	so_long->mlx_img = mlx_xpm_file_to_image(so_long->mlx,
			"images/wall.xpm", &x, &y);
	mlx_put_image_to_window(so_long->mlx, so_long->mlx_window,
		so_long->mlx_img, witdth, height);
	if (sym == '1')
		so_long->mlx_img = mlx_xpm_file_to_image(so_long->mlx,
				"images/trees.xpm", &x, &y);
	if (sym == 'P')
		so_long->mlx_img = mlx_xpm_file_to_image(so_long->mlx,
				"images/shark.xpm", &x, &y);
	if (sym == 'C')
		so_long->mlx_img = mlx_xpm_file_to_image(so_long->mlx,
				"images/coin.xpm", &x, &y);
	if (sym == 'V')
		so_long->mlx_img = mlx_xpm_file_to_image(so_long->mlx,
				"images/enemy.xpm", &x, &y);
	if (sym == 'E')
		so_long->mlx_img = mlx_xpm_file_to_image(so_long->mlx,
				"images/exit.xpm", &x, &y);
	mlx_put_image_to_window(so_long->mlx, so_long->mlx_window,
		so_long->mlx_img, witdth, height);
}

void	print_map(t_long *so_long)
{
	int	i;
	int	j;
	int	height;
	int	witdth;

	i = so_long->i_win;
	height = 0;
	while (so_long->map[i] && i <= so_long->i_win + 26)
	{
		j = so_long->j_win;
		witdth = 0;
		while (so_long->map[i][j] && j <= so_long->j_win + 40)
		{
			print_map_image(so_long, height, witdth, so_long->map[i][j]);
			if (so_long->map[i][j] == 'P')
			{
				so_long->i_position = i;
				so_long->j_position = j;
			}
			witdth += 40;
			j++;
		}
		height += 40;
		i++;
	}
}
