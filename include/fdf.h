#ifndef FDF
#define FDF

#include "../minilibx/mlx.h"
#include "libft.h"
#include <unistd.h>
#include <math.h>
#include <stdio.h>
#include <math.h>

typedef struct s_color
{
	unsigned char r;
	unsigned char g;
	unsigned char b;
}				t_color;

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
	int		color;
	int		r;
	int		g;
	int		b;
	int		diff;
}				t_corr;

typedef struct	s_window
{
	void		*mlx_ptr;
	void		*win_ptr;
}				t_window;

typedef struct	s_info
{
	int		height;
	int		width;
	t_corr		***corr;
	t_corr		***v_corr;
	t_window win;
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
	int		color;	
}					t_info;

int		read_n_arr		(t_info *info, char *argv);
void	corr_malloc		(t_info *info);
void	store_z			(t_info *info, char *argv);
void	ft_init			(t_info *info, char **argv);
void	gap_calc		(t_info *info);
void	init_pt			(t_info *info);
void	ft_draw			(t_info *info, int color);
void	ft_vdraw		(t_info *info, int color);
void	plot_line_ligh	(t_window *win, t_corr *start, t_corr *end, int color);
void	plot_line_low	(t_window *win, t_corr *start, t_corr *end, int color);
void	plot_line		(t_window *win, t_corr *start, t_corr *end, int color);

int		deal_key		(int key, t_info *info);

void	window_message	(t_info *info);
int		key_info		(int key, t_info *info);
void	subrender		(t_corr *c, t_info *o, int i, int j);
void	render			(t_info *o);
void	master_window	(t_info *info);
int		key_color		(int key, t_info *in);
void	reset_color		(t_corr *o);
void	init_color		(t_corr *o);
void	ft_error		(void);

void	smooth			(t_info *info, float x0, float y0, float x1, float y1);
void	cleanup			(t_info *info);
void	corr_save		(t_info *o);
int		check_for_arg	(char *arg);
void	invalid_error	(void);

#endif