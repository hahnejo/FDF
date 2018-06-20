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
	float xx;
	float yy;
	float zz;
	double x0;
	double x1;
	double x2;
	double y0;
	double y1;
	double y2;
	double z0;
}				t_corr;

typedef struct	s_info
{
	int		height;
	int		width;
	t_corr		***corr;
	t_corr		***v_corr;
	void		*mlx_ptr;
	void		*win_ptr;
	float		gap;
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
	int		deltaZ;
	int		move_x;
	int		move_y;
	int		zweee;
	int		color;
}					t_info;

void	read_n_arr		(t_info *info, char *argv);
void	corr_malloc		(t_info *info);
void	store_z			(t_info *info, char *argv);
void	ft_init			(t_info *info, char **argv);
void	gap_calc		(t_info *info);
void	init_pt			(t_info *info);
void	ft_draw			(t_info *info);
void	ft_vdraw		(t_info *info);
void	plot_line_ligh	(void *mlx_ptr, void *win_ptr, t_corr *start, t_corr *end);
void	plot_line_low	(void *mlx_ptr, void *win_ptr, t_corr *start, t_corr *end);
void	plot_line		(void *mlx_ptr, void *win_ptr, t_corr *start, t_corr *end);

int		deal_key	(int key, t_info *info);
// void	rotate_x		(t_info *info);
// void	rotate_y		(t_info *info);
// void	rotate_z		(t_info *info);
// void	rotator			(int key, t_info *info);

void	window_message	(t_info *info);
int		key_info		(int key, t_info *info);
void	subrender(t_corr *c, t_info *o, int i, int j);
void	render(t_info *o);
void	master_window	(t_info *info);

void	mover			(int key, t_info *info);
void	vertical_plue	(t_info *info);
void	vertical_minus	(t_info *info);
void	horizontal_plus	(t_info *info);
void	horizontal_minus(t_info *info);
void	smooth(t_info *info, float x0, float y0, float x1, float y1);
void	cleanup(t_info *info);





#endif