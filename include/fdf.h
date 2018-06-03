#ifndef FDF
#define FDF

#include "../minilibx/mlx.h"
#include "libft.h"
#include <unistd.h>
#include <math.h>
#include <stdio.h>

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
	int		max_x;
	int		max_y;
	int		max_z;
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
}				t_info;

void	read_n_arr	(t_info *info, char *argv);
void	corrMalloc	(t_info *info);
void	storeZ		(t_info *info, char *argv);
void	ft_init		(t_info *info, char **argv);
void	gapCalc		(t_info *info);
void	initPt		(t_info *info);
void	ft_draw		(t_info *info);
void	ft_vdraw	(t_info *info);

int		deal_key	(int key, t_info *info);

#endif