#include "fdf.h"

void	windowMessage(t_info *info)
{
	mlx_string_put(info->mlx_ptr, info->win_ptr, 5, 5, 0x66C2FF, "[ esc ] : Exit");
	mlx_string_put(info->mlx_ptr, info->win_ptr, 5, 25, 0x66C2FF, "[ + ] : Zoon in");
	mlx_string_put(info->mlx_ptr, info->win_ptr, 5, 45, 0x66C2FF, "[ - ] : Zoom out");
	mlx_string_put(info->mlx_ptr, info->win_ptr, 5, 65, 0x66C2FF, "[ arrow keys ] : Move");
	// 43 = +
	// 45 = -
}