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

void	plot_line_low(void *mlx_ptr, void *win_ptr, t_corr *start, t_corr *end)
{
	t_corr	dp;
	float	yi;
	t_corr	p;

	dp.x = end->x - start->x;
	dp.y = end->y - start->y;
	yi = 1;
	if (dp.y < 0 && (yi = -1) == -1)
		dp.y = -dp.y;
	p.z = 2 * dp.x - dp.y;
	p.x = start->x;
	p.y = start->y;
	while (p.x < end->x)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, p.x, p.y, 0xFFFFFF);
		if (p.z > 0)
		{
			p.y += yi;
			p.z -= 2 * dp.x;
		}
		p.z += 2 * dp.y;
		p.x++;
	}
}

void	plot_line_high(void *mlx_ptr, void *win_ptr, t_corr *start, t_corr *end)
{
	t_corr	dp;
	float	xi;
	t_corr	p;

	dp.x = end->x - start->x;
	dp.y = end->y - start->y;
	xi = 1;
	if (dp.x < 0 && (xi = -1) == -1)
		dp.x = -dp.x;
	p.z = 2 * dp.x - dp.x;
	p.x = start->x;
	p.y = start->y;
	while (p.y <= end->y)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, p.x, p.y, 0xFFFFFF);
		if (p.z > 0)
		{
			p.x += xi;
			p.z -= 2 * dp.y;
		}
		p.z += 2 * dp.x;
		p.y++;
	}
}

// put win_ptr, mlx_ptr, start pointer, end pointer

void	plot_line(void *mlx_ptr, void *win_ptr, t_corr *start, t_corr *end)
{
	if (fabsf(end->y - start->y) < fabsf(end->x - start->x))
	{
		if (start->x > end->x)
			plot_line_low(mlx_ptr, win_ptr, end, start);
		else
			plot_line_low(mlx_ptr, win_ptr, start, end);
	}
	else
	{
		if (start->y > end->y)
			plot_line_high(mlx_ptr, win_ptr, end, start);
		else
			plot_line_high(mlx_ptr, win_ptr, start, end);
	}
}

void	ft_draw(t_info *info)
{
	int i;
	int j;

	i = -1;
	while (++i < info->height)
	{
		j = -1;
		while (++j < info->width - 1)
			plot_line(info->mlx_ptr, info->win_ptr, info->corr[i][j], info->corr[i][j + 1]);
	}
}

void	ft_vdraw(t_info *info)
{
	int i;
	int j;

	i = -1;
	while (++i < info->width)
	{
		j = -1;
		while (++j < info->height - 1)
			plot_line(info->mlx_ptr, info->win_ptr, info->v_corr[i][j], info->v_corr[i][j + 1]);
	}
}