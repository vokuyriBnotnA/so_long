/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay_checkers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klemongr <klemongr@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 00:02:36 by klemongr          #+#    #+#             */
/*   Updated: 2022/03/11 00:02:43 by klemongr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	direction_key(int index)
{
	if (index == 53 || index == 17)
		return ('e');
	if (index == 13 || index == 126)
		return ('w');
	if (index == 1 || index == 125)
		return ('s');
	if (index == 0 || index == 123)
		return ('a');
	if (index == 2 || index == 124)
		return ('d');
	return (0);
}

int	check_point(char *point, int *coin_char)
{
	if (*point == '1')
		return (1);
	if (*point == 'C')
	{
		*point = '0';
		coin_char[0]--;
		return (0);
	}
	if ((*point == 'E' && *coin_char == 0) || *point == 'V')
		exit (0);
	else if (*point == 'E')
		return (1);
	return (0);
}

int	check_crash(int index, t_long *so_long)
{
	if (direction_key(index) == 'w')
		return (check_point(&so_long->map[so_long->i_position - 1]
				[so_long->j_position], &so_long->coin_char));
	if (direction_key(index) == 's')
		return (check_point(&so_long->map[so_long->i_position + 1]
				[so_long->j_position], &so_long->coin_char));
	if (direction_key(index) == 'a')
		return (check_point(&so_long->map[so_long->i_position]
				[so_long->j_position - 1], &so_long->coin_char));
	if (direction_key(index) == 'd')
		return (check_point(&so_long->map[so_long->i_position]
				[so_long->j_position + 1], &so_long->coin_char));
	return (0);
}

char	*direction_dolphin(int index)
{
	if (direction_key(index) == 'w')
		return ("images/dolphin/dolphin_up.xpm");
	if (direction_key(index) == 's')
		return ("images/dolphin/dolphin_down.xpm");
	if (direction_key(index) == 'a')
		return ("images/dolphin/dolphin_left.xpm");
	if (direction_key(index) == 'd')
		return ("images/dolphin/dolphin_right.xpm");
	return ("images/dolphin/dolphin_up.xpm");
}
