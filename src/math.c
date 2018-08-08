/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 17:13:09 by hjo               #+#    #+#             */
/*   Updated: 2018/06/26 17:13:10 by hjo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	gap_calc(t_info *info)
{
	if (info->win_x > info->win_y)
	{
		info->larger_win = info->win_x;
		info->smaller_win = info->win_y;
	}
	else
	{
		info->larger_win = info->win_y;
		info->smaller_win = info->win_x;
	}
	info->largerhw = (info->width >= info->height ? info->width : info->height);
	info->gap = info->smaller_win / 2 / (info->largerhw);
	info->start_x = (info->win_x / 4);
	info->start_y = (info->win_y / 4);
}

void	subrender(t_corr *c, t_info *o, int i, int j)
{
	c->x2 = c->x1 * cos(o->zAng) + c->y1 * sin(o->zAng);
	c->y2 = c->y1 * cos(o->zAng) - c->x1 * sin(o->zAng);
	o->corr[i][j]->x = (c->x2 * o->gap + (o->win_x / 2)) + o->move_x;
	o->corr[i][j]->y = (c->y2 * o->gap + (o->win_y / 2)) + o->move_y;
}

void	corr_save(t_info *o)
{
	int i;
	int j;

	i = -1;
	while (++i < o->width)
	{
		j = -1;
		while (++j < o->height)
		{
			o->v_corr[i][j]->x = o->corr[j][i]->x;
			o->v_corr[i][j]->y = o->corr[j][i]->y;
		}
	}
}

void	render(t_info *o)
{
	int		i;
	int		j;
	t_corr	*c;

	i = -1;
	c = malloc(sizeof(t_corr));
	while (++i < o->height)
	{
		j = -1;
		while (++j < o->width)
		{
			c->x0 = o->corr[i][j]->xx - (o->width / 2);
			c->y0 = (o->corr[i][j]->yy - (o->height / 2)) * cos(o->xAng) +
				(o->corr[i][j]->z * o->deltaZ) * sin(o->xAng);
			c->z0 = (o->corr[i][j]->z * o->deltaZ) * cos(o->xAng) -
				(o->corr[i][j]->y - (o->height / 2)) * sin(o->xAng);
			c->x1 = c->x0 * cos(o->yAng) - c->z0 * sin(o->yAng);
			c->y1 = c->y0;
			subrender(c, o, i, j);
		}
	}
	corr_save(o);
	free(c);
	ft_draw(o, o->color);
	ft_vdraw(o, o->color);
}

void	init_pt(t_info *info)
{
	int i;
	int j;

	i = -1;
	while (++i < info->height)
	{
		j = -1;
		while (++j < info->width)
		{
			info->corr[i][j]->xx = (float)(j);
			info->corr[i][j]->yy = (float)(i);
		}
	}
	i = -1;
}
