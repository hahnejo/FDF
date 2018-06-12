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

void	cleanupp(t_info *info)
{
	int i;

	i = -1;
	while(++i < info->height)
		free(info->corr[i]);
	i = -1;
	while(++i < info->width)
		free(info->v_corr[i]);
	// printf("Size after: %f", info->v_corr[0]);
	free(info->corr);
	free(info->v_corr);
}

int		key_info(int key, t_info *info)
{
	if (key == 53)
	{
		cleanupp(info);
		printf("Cleaned up!\n");
		//sleep(15);
		exit(0);
	}
	(key == 0 || key == 2 || key == 1 || key == 13 || key == 12 || key == 14) ? rotator(key, info) : 0;
	(key == 125 || key == 126 || key == 123 || key == 124) ? mover(key, info) : 0;
	mlx_clear_window(info->mlx_ptr, info->win_ptr);
	windowMessage(info);
	ft_draw(info);
	ft_vdraw(info);
	return (key);
}

// int		deal_key(int key, t_info *info)
// {
// 	key_info(key, info);
// 	ft_draw(info);
// 	ft_vdraw(info);
// 	return (0);
// }

	// {
	// 	mlx_destroy_window(info->mlx_ptr, info->win_ptr);
	// }

	// if (key == 38) // up
	// if (key == 40) // down
	// if (key == 39) // right
	// if (key == 37) // left

