#include "fdf.h"


// 	info->corr[i][j]->x
// 	r = 
// }

// void	rotatePointZ(t_corr *corr, int win_x, int win_y, float theta)
// {
// 	corr->x -= win_x / 2;
// 	corr->y -= win_y / 2;
// 	corr->x = win_x * cos(theta) - win_y * sin(theta);
// 	corr->y = win_x * sin(theta) - win_y * cos(theta);

// }

// void	rotatePointY(t_corr *corr, int win_x, int win_y, float theta)
// {
// 	corr->x -= win_y / 2;
// 	corr->x = win_x * cos(theta) - win_y * sin(theta);
// 	corr->z = z * cos(theta) - x * sin(theta);
// }

// void	rotatePointX(t_corr *corr, int win_x, int win_y, float theta)
// {
// 	corr->y -= win_y / 2;
// 	corr->y = y * cos(theta) - z * sin(theta);
// 	corr->z = y * sin(theta) + z * cos(theta);
// }

// void	rotate_x(t_info *info)	
// {
// 	float y;
// 	float z;
// 	int i;
// 	int j;
	
// 	i = -1;
// 	while (++i < info->width)
// 	{
// 		j = -1;
// 		while (++j < info->height)
// 		{
// 			y = info->corr[j][i]->y;
// 			z = info->corr[j][i]->z;
// 			info->corr[j][i]->y = (y * cos(info->xAng)) - (z * sin(info->xAng) / 2);
// 			info->corr[j][i]->z = (y * sin(info->xAng)) + (z * cos(info->xAng) / 2);
// 			y = info->v_corr[i][j]->y;
// 			z = info->v_corr[i][j]->z;
// 			info->v_corr[i][j]->y = (y * cos(info->xAng)) - (z * sin(info->xAng) / 2);
// 			info->v_corr[i][j]->z = (y * sin(info->xAng)) + (z * cos(info->xAng) / 2);
// 			printf("z is %f", z);
// 		}
// 	}
// 	// printf("rotate x is called %d\n", 1);
// }

// void	rotate_y(t_info *info)
// {
// 	float x;
// 	float z;
// 	int i;
// 	int j;

// 	i = -1;
// 	while (++i < info->width)
// 	{
// 		j = -1;
// 		while (++j < info->height)
// 		{
// 			x = info->corr[j][i]->x;
// 			z = info->corr[j][i]->z;
// 			info->corr[j][i]->x = (z * sin(info->yAng)) + (x * cos(info->yAng));
// 			info->corr[j][i]->z = (z * cos(info->yAng)) - (x * sin(info->yAng));
// 			x = info->v_corr[i][j]->x;
// 			z = info->v_corr[i][j]->z;
// 			info->v_corr[i][j]->x = (z * sin(info->yAng)) + (x * cos(info->yAng));
// 			info->v_corr[i][j]->z = (z * cos(info->yAng)) - (x * sin(info->yAng));
// 		}
// 	}
// 	// printf("rotate y is called %d\n", 1);
// }

// void	rotate_z(t_info *info)
// {
// 	float x;
// 	float y;
// 	int i;
// 	int j;

// 	i = -1;
// 	while (++i < info->width)
// 	{
// 		j = -1;
// 		while (++j < info->height)
// 		{
// 			x = info->corr[j][i]->x;
// 			y = info->corr[j][i]->y;
// 			info->corr[j][i]->x = (x * cos(info->zAng)) - (y * sin(info->zAng));
// 			info->corr[j][i]->y = (x * sin(info->zAng)) + (y * cos(info->zAng));
// 			x = info->v_corr[i][j]->x;
// 			y = info->v_corr[i][j]->y;
// 			info->v_corr[i][j]->x = (x * cos(info->zAng)) - (y * sin(info->zAng));
// 			info->v_corr[i][j]->y = (x * sin(info->zAng)) + (y * cos(info->zAng));
// 			// printf("info->corr[%d][%d]->x and info->corr[%d][%d]->y are : %f, %f\n ",i, j, i, j, info->corr[i][j]->x, info->corr[i][j]->y);
// 		}
// 	}
// 	// printf("rotate z is called %d\n", 1);
// }

// void	rotator(int key, t_info *info)
// {
// 	key == 0 ? info->xAng -= 0.5 : 0;
// 	key == 2 ? info->xAng += 0.5 : 0;
// 	key == 1 ? info->yAng -= 0.5 : 0;
// 	key == 13 ? info->yAng += 0.5 : 0;
// 	key == 12 ? info->zAng -= 0.5 : 0;
// 	key == 14 ? info->zAng += 0.5 : 0;
// 	(key == 0 || key == 2) ? rotate_x(info) : 0;
// 	(key == 1 || key == 13) ? rotate_y(info) : 0;
// 	(key == 12 || key == 14) ? rotate_z(info) : 0;
// }