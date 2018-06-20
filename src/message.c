#include "fdf.h"

void	window_message(t_info *info)
{
	mlx_string_put(info->mlx_ptr, info->win_ptr, 5, 5, 0x66C2FF, "[ esc ] : Exit");
	mlx_string_put(info->mlx_ptr, info->win_ptr, 5, 25, 0x66C2FF, "[ c, v ] : Zoom in and out");
	mlx_string_put(info->mlx_ptr, info->win_ptr, 5, 45, 0x66C2FF, "[ z, x ] : Height change");
	mlx_string_put(info->mlx_ptr, info->win_ptr, 5, 65, 0x66C2FF, "[ q, w, e, a, s, d ] : Camera");
	mlx_string_put(info->mlx_ptr, info->win_ptr, 5, 85, 0x66C2FF, "[arrow keys ] : Move");
}