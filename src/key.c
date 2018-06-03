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
#include "mlx.h"

int		deal_key(int key, t_info *info)
{
	if (key == 53)
	{
		mlx_destroy_window(info->mlx_ptr, info->win_ptr);
	}
	return (0);
}

	// if (key == 38) // up
	// if (key == 40) // down
	// if (key == 39) // right
	// if (key == 37) // left
