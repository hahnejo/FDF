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
	info->width = 1;
	info->win_x = ft_atoi(argv[2]);
	info->win_y = ft_atoi(argv[3]);
	info->xAng = 0;
	info->yAng = 0;
	info->zAng = 0;
	info->zweee = 0;
	info->deltaZ = 1;
}

void	master_window(t_info *info)
{
	mlx_clear_window(info->mlx_ptr, info->win_ptr);
	window_message(info);
	render(info);
	mlx_hook(info->win_ptr, 2, 2, deal_key, info);
	mlx_loop(info->mlx_ptr);
}

void	cleanup(t_info *info)
{
	int i;
	int j;

	i = -1;
	while(++i < info->height)
	{
		j = -1;
		while (++j < info->width)
			free(info->corr[i][j]);
		free(info->corr[i]);
	}
	i = -1;
	while(++i < info->width)
	{
		j = -1;
		while (++j < info->height)
			free(info->v_corr[i][j]);
		free(info->v_corr[i]);
	}
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
		gap_calc(&info);
		init_pt(&info);
		info.mlx_ptr = mlx_init();
		info.win_ptr = mlx_new_window(info.mlx_ptr, info.win_x, info.win_y, "mlx 42");
		master_window(&info);
		cleanup(&info);
		// sleep(15);
	}
	return (0);
}
