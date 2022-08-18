/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klemongr <klemongr@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 21:47:27 by klemongr          #+#    #+#             */
/*   Updated: 2022/03/10 23:05:44 by klemongr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_false_sym(char sym)
{
	if (sym != '0' && sym != '1' && sym != 'V' && sym != 'C' && sym != 'E'
		&& sym != 'P')
		return (0);
	return (1);
}

int	check_sym(t_long *so_long, int i, int j)
{
	if (!check_false_sym(so_long->map[i][j]))
		return (0);
	if (so_long->map[i][j] == 'C')
		so_long->coin_char++;
	if (so_long->map[i][j] == 'E')
		so_long->exit_char++;
	if (so_long->map[i][j] == 'P')
	{
		so_long->i_position = i;
		so_long->j_position = j;
		so_long->player_start_char++;
	}
	if ((i == 0 || j == 0) && so_long->map[i][j] != '1')
		return (0);
	return (1);
}

int	check_wall(t_long *so_long, int i, int j)
{
	if (so_long->map[i][j - 1] != '1')
		return (0);
	if (i == 0)
		so_long->width_of_line = j;
	else if (so_long->width_of_line != j)
		return (0);
	return (1);
}

int	check_down_wall(t_long *so_long, int i)
{
	int	j;

	j = 0;
	while (so_long->map[i - 1][j])
	{
		if (so_long->map[i - 1][j] != '1')
			return (0);
		j++;
	}
	return (1);
}

int	check_map(t_long *so_long)
{
	int	i;
	int	j;

	i = 0;
	while (so_long->map[i])
	{
		j = 0;
		while (so_long->map[i][j])
		{
			if (!check_sym(so_long, i, j))
				return (0);
			j++;
		}
		if (!check_wall(so_long, i, j))
			return (0);
		i++;
		if (!so_long->map[i] && !check_down_wall(so_long, i))
			return (0);
	}
	if (so_long->coin_char == 0 || so_long->exit_char == 0
		|| so_long->player_start_char != 1)
		return (0);
	so_long->width = j;
	so_long->height = i;
	return (1);
}
