#include "fdf.h"

void	vertical_plus(t_info *info)
{
	int i;
	int j;

	i = -1;
	while (++i < info->width)
	{
		j = -1;
		while (++j < info->height)
		{
			info->corr[j][i].y += 5;
			info->v_corr[i][j].y += 5;
			info->corr[j][i].z += 5;
			info->v_corr[i][j].z += 5;
		}
	}
}

void	vertical_minus(t_info *info)
{
	int i;
	int j;

	i = -1;
	while (++i < info->width)
	{
		j = -1;
		while (++j < info->height)
		{
			printf("i and j are %d %d :\n", i, j);
			printf("width is %d and height is %d\n", info->width, info->height);
			printf("%p %p %p\n", info, info->corr, info->corr[j]);
			info->corr[j][i].y -= 5;
			info->v_corr[i][j].y -= 5;
			info->corr[j][i].z -= 5;
			info->v_corr[i][j].z -= 5;
		}
	}
}

void	horizontal_plus(t_info *info)
{
	int i;
	int j;

	i = -1;
	while (++i < info->width)
	{
		j = -1;
		while (++j < info->height)
		{
			info->corr[j][i].x += 5;
			info->v_corr[i][j].x += 5;
			info->corr[j][i].z += 5;
			info->v_corr[i][j].z += 5;
		}
	}
}

void	horizontal_minus(t_info *info)
{
	int i;
	int j;

	i = -1;
	while (++i < info->width)
	{
		j = -1;
		while (++j < info->height)
		{
			info->corr[j][i].x -= 5;
			info->v_corr[i][j].x -= 5;
			info->corr[j][i].z -= 5;
			info->v_corr[i][j].z -= 5;
		}
	}
}
void	mover(int key, t_info *info)
{
	key == 125 ? vertical_plus(info) : 0;
	key == 126 ? vertical_minus(info) : 0;
	key == 124 ? horizontal_plus(info) : 0;
	key == 123 ? horizontal_minus(info) : 0;
}
