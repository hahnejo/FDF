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

void	plot_line_low(t_window *win, t_corr *start, t_corr *end, int color)
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
		mlx_pixel_put(win->mlx_ptr, win->win_ptr, p.x, p.y, color);
		if (p.z > 0)
		{
			p.y += yi;
			p.z -= 2 * dp.x;
		}
		p.z += 2 * dp.y;
		p.x++;
	}
}

void	plot_line_high(t_window *win, t_corr *start, t_corr *end, int color)
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
		mlx_pixel_put(win->mlx_ptr, win->win_ptr, p.x, p.y, color);
		if (p.z > 0)
		{
			p.x += xi;
			p.z -= 2 * dp.y;
		}
		p.z += 2 * dp.x;
		p.y++;
	}
}

void	plot_line(t_window *win, t_corr *start, t_corr *end, int color)
{
	if (fabsf(end->y - start->y) < fabsf(end->x - start->x))
	{
		if (start->x > end->x)
			plot_line_low(win, end, start, color);
		else
			plot_line_low(win, start, end, color);
	}
	else
	{
		if (start->y > end->y)
			plot_line_high(win, end, start, color);
		else
			plot_line_high(win, start, end, color);
	}
}

void	ft_draw(t_info *info, int color)
{
	int i;
	int j;

	i = -1;
	while (++i < info->height)
	{
		j = -1;
		while (++j < info->width - 1)
			plot_line(&info->win, info->corr[i][j],
				info->corr[i][j + 1], color);
	}
}

void	ft_vdraw(t_info *info, int color)
{
	int i;
	int j;

	i = -1;
	while (++i < info->width)
	{
		j = -1;
		while (++j < info->height - 1)
			plot_line(&info->win, info->v_corr[i][j],
				info->v_corr[i][j + 1], color);
	}
}
