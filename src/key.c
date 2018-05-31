#include "fdf.h"
#include "mlx.h"

int		deal_key(int key, t_info *info)
{
	if (key == 53)
	{
		mlx_destroy_window(info->mlx_ptr, info->win_ptr);
	}
	return (0);
}

	// if (key == 38) // up
	// if (key == 40) // down
	// if (key == 39) // right
	// if (key == 37) // left