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
		25, 0x66C2FF, "[ q, w, e, s ] : Camera");
	mlx_string_put(info->win.mlx_ptr, info->win.win_ptr, 5,
		45, 0x66C2FF, "[arrow keys ] : Move");
	mlx_string_put(info->win.mlx_ptr, info->win.win_ptr, 5,
		65, 0x66c2ff, "[ r, g, b, p] : Change color");
}

void	ft_error(void)
{
	ft_putendl("Try with this : ./fdf <filename> <width> <height>\n"
		"width and height must be greater than 300");
}

void	invalid_error(void)
{
	ft_putendl("Please put a valid test file");
}

int		check_for_arg(char *arg)
{
	int i;

	i = 0;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (0);
		i++;
	}
	return (1);
}
