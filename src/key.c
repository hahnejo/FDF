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

// void	cleanupp(t_info *info)
// {
// 	int i;

// 	i = -1;
// 	while(++i < info->height)
// 		free(info->corr[i]);
// 	i = -1;
// 	while(++i < info->width)
// 		free(info->v_corr[i]);
// 	// printf("Size after: %f", info->v_corr[0]);
// 	free(info->corr);
// 	free(info->v_corr);
// }

int		key_info(int key, t_info *info)
{
	key == 53 ? exit(0) : 0;
	// c and v
	key == 8 ? info->zweee += 2.5 : 0;
	key == 9 ? info->zweee -= 2.5 : 0;
	// regular direction key
	key == 123 ? info->move_x -= 2 : 0;
	key == 124 ? info->move_x += 2 : 0;
	key == 125 ? info->move_y += 2 : 0;
	key == 126 ? info->move_y -= 2 : 0;
	//z and x
	key == 6 ? info->deltaZ += 0.1 : 1;
	key == 7 ? info->deltaZ -= 0.1 : 1;
	// a and d rotation around x axis
	key == 2 ? info->xAng += 0.005 : 0;
	key == 0 ? info->xAng -= 0.005 : 0;
	// s and w rotate around y axis
	key == 13 ? info->yAng += 0.005 : 0;
	key == 1 ? info->yAng -= 0.005 : 0;
	// q and e
	key == 12 ? info->zAng += 0.005 : 0;
	key == 14 ? info->zAng -= 0.005 : 0;
	// (key == 125 || key == 126 || key == 123 || key == 124) ? mover(key, info) : 0;
	// gapCalc(info);
	mlx_clear_window(info->mlx_ptr, info->win_ptr);
	return (key);
}

int		deal_key(int key, t_info *info)
{
	key == 53 ? key_info(key, info) : 0;
	(key == 123 || key == 124 || key == 125 || key == 126) ? key_info(key, info) : 0;
	(key == 8 || key == 9) ? key_info(key, info) : 0;
	(key == 6 || key == 7) ? key_info(key, info) : 0;
	(key == 2 || key == 0) ? key_info(key, info) : 0;
	(key == 13 || key == 1) ? key_info(key, info) : 0;
	(key == 12 || key == 14) ? key_info(key, info) : 0;
	window_message(info);
	render(info);
	return (0);
}

	// {
	// 	mlx_destroy_window(info->mlx_ptr, info->win_ptr);
	// }

	// if (key == 38) // up
	// if (key == 40) // down
	// if (key == 39) // right
	// if (key == 37) // left

