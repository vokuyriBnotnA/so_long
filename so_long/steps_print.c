/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steps_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klemongr <klemongr@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 19:37:57 by klemongr          #+#    #+#             */
/*   Updated: 2022/03/11 00:01:13 by klemongr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	discharge_of_num(int num)
{
	int	res;

	res = -1;
	while (num > 0)
	{
		num /= 10;
		res++;
	}
	return (res);
}

char	*steps_to_char(int num)
{
	char	*result;
	int		tmp;
	int		i;
	int		j;

	result = malloc(12);
	if (!result)
		return (NULL);
	if (num == 0)
	{
		*result = '0';
		return (result);
	}
	i = discharge_of_num(num);
	result[i + 1] = 0;
	while (num > 0)
	{
		tmp = num % 10;
		num /= 10;
		result[i] = tmp + '0';
		i--;
	}
	return (result);
}

void	steps_print(t_long *so_long)
{
	int		x;
	int		y;
	char	*steps;

	if (so_long->steps == 999)
		so_long->steps = 998;
	so_long->mlx_img = mlx_xpm_file_to_image(so_long->mlx,
			"images/steps.xpm", &x, &y);
	mlx_put_image_to_window(so_long->mlx, so_long->mlx_window,
		so_long->mlx_img, 0, 7);
	steps = steps_to_char(so_long->steps);
	mlx_string_put(so_long->mlx, so_long->mlx_window, 5, 5, 0xFFFFFF, steps);
	free(steps);
}
