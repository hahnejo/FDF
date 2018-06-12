/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 18:31:37 by hjo               #+#    #+#             */
/*   Updated: 2018/05/31 18:31:39 by hjo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw(t_info *info)
{
	int i;
	int j;
	float x0;
	float y0;

	i = -1;
	while (++i < info->height)
	{
		j = -1;
		while (++j < info->width - 1)
		{
			x0 = info->corr[i][j].x;
			y0 = info->corr[i][j].y;
			// printf("j[%d][%d].x = %f	j+1x = %f\n", i, j, info->corr[i][j].x, info->corr[i][j + 1].x);
			while (j + 1 < info->width && x0 < info->corr[i][j + 1].x)
			{
				mlx_pixel_put(info->mlx_ptr, info->win_ptr, x0, ((info->corr[i][j + 1].y - info->corr[i][j].y) /
					(info->corr[i][j + 1].x - info->corr[i][j].x)) * (x0 - info->corr[i][j].x) + info->corr[i][j].y, 0x00FFFF);
				x0++;
			}
			while (j + 1 < info->width && y0 < info->corr[i][j + 1].y)
			{
				mlx_pixel_put(info->mlx_ptr, info->win_ptr, (y0 - info->corr[i][j].y) / 
				(info->corr[i][j + 1].y - info->corr[i][j].y) * (info->corr[i][j + 1].x 
				- info->corr[i][j].x) + info->corr[i][j].x, y0, 0x00FFFF);
				y0++;
			}
		}
	}
}

void	ft_vdraw(t_info *info)
{
	int i;
	int j;
	float y0;
	float x0;

	i = -1;
	while (++i < info->width)
	{
		j = -1;
		while (++j < info->height)
		{
			y0 = info->v_corr[i][j].y;
			x0 = info->v_corr[i][j].x;
			while (j + 1 < info->height && y0 < info->v_corr[i][j + 1].y)
			{
				mlx_pixel_put(info->mlx_ptr, info->win_ptr, (y0 - info->v_corr[i][j].y) / 
				(info->v_corr[i][j + 1].y - info->v_corr[i][j].y) * (info->v_corr[i][j + 1].x 
				- info->v_corr[i][j].x) + info->v_corr[i][j].x, y0, 0x7FFFD4);
				y0++;
			}
			while (j + 1 < info->height && x0 < info->v_corr[i][j + 1].x)
			{
				mlx_pixel_put(info->mlx_ptr, info->win_ptr, x0, ((info->v_corr[i][j + 1].y - info->v_corr[i][j].y) /
					(info->v_corr[i][j + 1].x - info->v_corr[i][j].x)) * (x0 - info->v_corr[i][j].x) + info->v_corr[i][j].y, 0x7FFFD4);
				x0++;
			}
		}
	}
}
