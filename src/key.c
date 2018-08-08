/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 18:31:44 by hjo               #+#    #+#             */
/*   Updated: 2018/05/31 18:31:46 by hjo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_info(int key, t_info *info)
{
	key == 53 ? exit(0) : 0;
	key == 123 ? info->move_x -= 2 : 0;
	key == 124 ? info->move_x += 2 : 0;
	key == 125 ? info->move_y += 2 : 0;
	key == 126 ? info->move_y -= 2 : 0;
	key == 13 ? info->yAng += 0.005 : 0;
	key == 1 ? info->yAng -= 0.005 : 0;
	key == 12 ? info->zAng += 0.005 : 0;
	key == 14 ? info->zAng -= 0.005 : 0;
	mlx_clear_window(info->win.mlx_ptr, info->win.win_ptr);
	return (key);
}

int		key_color(int key, t_info *in)
{
	key == 15 ? in->color = 0xFF3333 : in->color;
	key == 5 ? in->color = 0x4AFF33 : in->color;
	key == 11 ? in->color = 0x334FFF : in->color;
	key == 35 ? in->color = 0xFFFFFF : in->color;
	mlx_clear_window(in->win.mlx_ptr, in->win.win_ptr);
	return (key);
}

int		deal_key(int key, t_info *info)
{
	key == 53 ? key_info(key, info) : 0;
	(key == 123 || key == 124 || key == 125 || key == 126)
		? key_info(key, info) : 0;
	(key == 13 || key == 1) ? key_info(key, info) : 0;
	(key == 12 || key == 14) ? key_info(key, info) : 0;
	(key == 15 || key == 5 || key == 11 || key == 35)
		? key_color(key, info) : 0;
	window_message(info);
	render(info);
	return (0);
}
