/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klemongr <klemongr@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 13:31:42 by klemongr          #+#    #+#             */
/*   Updated: 2022/03/10 23:49:00 by klemongr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_long *so_long)
{
	free_split(so_long->map);
	exit (0);
}

int	animation(t_long *so_long)
{
	int	x;
	int	y;

	so_long->mlx_img = mlx_xpm_file_to_image(so_long->mlx,
			"images/wall.xpm", &x, &y);
	mlx_put_image_to_window(so_long->mlx, so_long->mlx_window,
		so_long->mlx_img, so_long->j_position * 40, so_long->i_position * 40);
	usleep(10000);
	so_long->mlx_img = mlx_xpm_file_to_image(so_long->mlx,
			so_long->dophin_img, &x, &y);
	mlx_put_image_to_window(so_long->mlx, so_long->mlx_window,
		so_long->mlx_img, so_long->j_position * 40 + 2,
		so_long->i_position * 40 - 3);
	return (0);
}

void	create_map(t_long *so_long, char *map)
{
	if (!check_map(so_long))
	{
		write(2, "Wrong map!\n", 12);
		free_split(so_long->map);
		exit (1);
	}
	if (so_long->width > 40 || so_long->height > 26)
	{
		if (so_long->width > 40 && so_long->height > 26)
			so_long->mlx_window = mlx_new_window(so_long->mlx,
					41 * 40, 27 * 40, "./so_long.a");
		else if (so_long->width > 40)
			so_long->mlx_window = mlx_new_window(so_long->mlx,
					41 * 40, so_long->height * 40, "./so_long.a");
		else if (so_long->height > 26)
			so_long->mlx_window = mlx_new_window(so_long->mlx,
					so_long->width * 40, 27 * 40, "./so_long.a");
		windows_size(so_long);
	}
	else
		so_long->mlx_window = mlx_new_window(so_long->mlx,
				so_long->width * 40, so_long->height * 40, "./so_long.a");
}

int	main(int argc, char **argv)
{
	t_long	so_long;
	int		x;
	int		y;

	if (argc != 2)
	{
		write(2, "Use ./so_long.a {path_to_map}\n", 31);
		return (1);
	}
	so_long_init(&so_long);
	so_long.map = read_map(argv[1]);
	if (!so_long.map)
	{
		write(2, "Error read map\n", 16);
		exit (1);
	}
	create_map(&so_long, argv[1]);
	print_map(&so_long);
	steps_print(&so_long);
	if (!so_long.big_size)
		mlx_loop_hook(so_long.mlx, animation, &so_long);
	mlx_hook(so_long.mlx_window, 2, 1L << 0, game_play, &so_long);
	mlx_hook(so_long.mlx_window, 17, 0, close_window, &so_long);
	mlx_loop(so_long.mlx);
	return (0);
}
