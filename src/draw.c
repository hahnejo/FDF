#include "fdf.h"

void	ft_draw(t_info *info)
{
	int i;
	int j;
	float x0;

	i = -1;
	while (++i < info->height)
	{
		j = -1;
		while (++j < info->width)
		{
			x0 = info->corr[i][j].x;
			// printf("i = %d	j = %d\n", i, j);
			while (j + 1 < info->width && x0 < info->corr[i][j + 1].x)
			{
				mlx_pixel_put(info->mlx_ptr, info->win_ptr, x0, ((info->corr[i][j + 1].y - info->corr[i][j].y) /
				(info->corr[i][j + 1].x - info->corr[i][j].x)) * (x0 - info->corr[i][j].x) + info->corr[i][j].y, 0xFFFFFF);
				x0++;
			}
		}
	}
}

void	ft_vdraw(t_info *info)
{
	int i;
	int j;
	float y0;

	i = -1;
	// printf("height = %d	width = %d\n", info->height, info->width);
	while (++i < info->width)
	{
		j = -1;
		while (++j < info->height)
		{
			y0 = info->v_corr[i][j].y;
			// printf("i = %d	j = %d\n", i, j);
			while (j + 1 < info->height && y0 < info->v_corr[i][j + 1].y)
			{
				mlx_pixel_put(info->mlx_ptr, info->win_ptr, (y0 - info->v_corr[i][j].y) / 
				(info->v_corr[i][j + 1].y - info->v_corr[i][j].y) * (info->v_corr[i][j + 1].x 
				- info->v_corr[i][j].x) + info->v_corr[i][j].x, y0, 0xFFFFFF);
				y0++;
			}
		}
	}
}