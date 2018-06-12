/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 18:31:56 by hjo               #+#    #+#             */
/*   Updated: 2018/05/31 18:31:57 by hjo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_init(t_info *info, char **argv)
{
	int i;

	i = 0;
	info->height = 0;
	info->width = 0;
	info->win_x = ft_atoi(argv[2]);
	info->win_y = ft_atoi(argv[3]);
	info->xAng = 0;
	info->yAng = 0;
	info->zAng = 0;
}

void	gapCalc(t_info *info)
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
	info->gap = info->smaller_win / 2 / info->largerhw;
	info->start_x = (info->win_x / 4);
	info->start_y = (info->win_y / 4);
}

// as number at the end goes up, height goes down.

void	initPt(t_info *info)
{
	int i;
	int j;

	i = -1;
	while (++i < info->height)
	{
		j = -1;
		while (++j < info->width)
		{
			info->corr[i][j]->x = (float)(info->start_x + j * info->gap + info->corr[i][j]->z * info->gap / 5);
			info->corr[i][j]->y = (float)(info->start_y + i * info->gap - info->corr[i][j]->z * info->gap / 5);
		}
	}
	i = -1;
	while (++i < info->width)
	{
		j = -1;
		while (++j < info->height)
		{
			info->v_corr[i][j]->x = info->corr[j][i]->x;
			info->v_corr[i][j]->y = info->corr[j][i]->y;
		}
	}
}

void	masterWindow(t_info *info)
{
	mlx_clear_window(info->mlx_ptr, info->win_ptr);
	windowMessage(info);
	ft_draw(info);
	ft_vdraw(info);
	mlx_hook(info->win_ptr, 2, 2, key_info, info);
	mlx_loop(info->mlx_ptr);
}

void	cleanup(t_info *info)
{
	int i;
	int j;

	i = -1;
	while(++i < info->height)
	{
		while (++j < info->height)
		{
			
		}
		free(info->corr[i]);
	}
	i = -1;
	while(++i < info->width)
		free(info->v_corr[i]);
	free(info->corr);
	free(info->v_corr);
}

int		main(int argc, char **argv)
{
	t_info	info;

	if (argc != 4)
		return (1);
	if (argc == 4)
	{
		ft_init(&info, argv);
		read_n_arr(&info, argv[1]);
		gapCalc(&info);
		initPt(&info);
		info.mlx_ptr = mlx_init();
		info.win_ptr = mlx_new_window(info.mlx_ptr, info.win_x, info.win_y, "mlx 42");
		masterWindow(&info);
		cleanup(&info);
		sleep(15);
	}
	return (0);
}
