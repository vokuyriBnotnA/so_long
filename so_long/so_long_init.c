/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klemongr <klemongr@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 22:47:00 by klemongr          #+#    #+#             */
/*   Updated: 2022/03/10 22:54:40 by klemongr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	so_long_init(t_long *so_long)
{
	so_long->mlx = mlx_init();
	so_long->coin_char = 0;
	so_long->height = 0;
	so_long->width = 0;
	so_long->i_position = 0;
	so_long->j_position = 0;
	so_long->steps = 0;
	so_long->i_win = 0;
	so_long->j_win = 0;
	so_long->big_size = 0;
	so_long->dophin_img = "images/dolphin/dolphin_up.xpm";
	so_long->width_of_line = 0;
	so_long->exit_char = 0;
	so_long->player_start_char = 0;
}
