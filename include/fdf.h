#ifndef FDF
#define FDF

#include "../minilibx/mlx.h"
#include "libft.h"
#include <unistd.h>
#include <math.h>
#include <stdio.h>
#include <math.h>

typedef struct s_corr
{
	float x;
	float y;
	float z;
}				t_corr;

typedef struct	s_info
{
	int		height;
	int		width;
	t_corr	**corr;
	t_corr	**v_corr;
	void	*mlx_ptr;
	void	*win_ptr;
	float	gap;
	int		start_x;
	int		start_y;
	int		win_x;
	int		win_y;
	int		larger_win;
	int		smaller_win;
	int		largerhw;
	float		xAng;
	float		yAng;
	float		zAng;
}				t_info;

void	read_n_arr	(t_info *info, char *argv);
void	corrMalloc	(t_info *info);
void	storeZ		(t_info *info, char *argv);
void	ft_init		(t_info *info, char **argv);
void	gapCalc		(t_info *info);
void	initPt		(t_info *info);
void	ft_draw		(t_info *info);
void	ft_vdraw	(t_info *info);

// int		deal_key	(int key, t_info *info);
void	rotate_x	(t_info *info);
void	rotate_y	(t_info *info);
void	rotate_z	(t_info *info);
void	rotator		(int key, t_info *info);

void	windowMessage(t_info *info);
int		key_info(int key, t_info *info);

void	mover(int key, t_info *info);
void	vertical_plue(t_info *info);
void	vertical_minus(t_info *info);
void	horizontal_plus(t_info *info);
void	horizontal_minus(t_info *info);



#endif