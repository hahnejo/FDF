/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 17:10:50 by hjo               #+#    #+#             */
/*   Updated: 2018/06/26 17:10:51 by hjo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	window_message(t_info *info)
{
	mlx_string_put(info->win.mlx_ptr, info->win.win_ptr, 5,
		5, 0x66C2FF, "[ esc ] : Exit");
	mlx_string_put(info->win.mlx_ptr, info->win.win_ptr, 5,
		25, 0x66C2FF, "[ z, x ] : Height change");
	mlx_string_put(info->win.mlx_ptr, info->win.win_ptr, 5,
		45, 0x66C2FF, "[ q, w, e, a, s, d ] : Camera");
	mlx_string_put(info->win.mlx_ptr, info->win.win_ptr, 5,
		65, 0x66C2FF, "[arrow keys ] : Move");
	mlx_string_put(info->win.mlx_ptr, info->win.win_ptr, 5,
		85, 0x66c2ff, "[ r, g, b ] : Change color");
}

void	ft_error(void)
{
	ft_putendl("Try with this : ./fdf <filename> <width> <height>");
}
