/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klemongr <klemongr@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 00:02:43 by klemongr          #+#    #+#             */
/*   Updated: 2022/03/10 19:33:46 by klemongr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	windows_size(t_long *so_long)
{
	int	i;
	int	j;

	i = so_long->i_win;
	j = so_long->j_win;
	so_long->i_win = 0;
	so_long->j_win = 0;
	so_long->big_size = 1;
	if (so_long->i_position >= 26 / 2)
	{
		so_long->i_win = so_long->i_position - 26 / 2;
		if (so_long->i_win + 27 > so_long->height)
			so_long->i_win = so_long->height - 27;
	}
	if (so_long->j_position >= 40 / 2)
	{
		so_long->j_win = so_long->j_position - 40 / 2;
		if (so_long->j_win + 41 > so_long->width)
			so_long->j_win = so_long->width - 41;
	}
	if (i != so_long->i_win || j != so_long->j_win)
		return (1);
	return (0);
}
