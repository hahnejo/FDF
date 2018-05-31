#include "fdf.h"

void		read_n_arr(t_info *info, char *argv)
{
	int fd;
	char *line;
	int i;
	int j;
	char **zVal;

	i = 0;
	j = 0;
	line = NULL;
	fd = open(argv, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		while (info->height == 0 && line[i] != '\0')
		{
			if (line[i] == ' ' && line[i + 1] != ' ')
				info->width++;
			i++;
		}
		free(line);
		line = NULL;
		info->height++;
	}
	close (fd);
	info->corr = (t_corr**)malloc(sizeof(t_corr*) * info->height + 1);
	i = -1;
	while (++i < info->height)
		info->corr[i] = (t_corr*)malloc(sizeof(t_corr) * info->width + 1);
	info->v_corr = (t_corr**)malloc(sizeof(t_corr*) * info->width + 1);
	i = -1;
	while (++i < info->width)
		info->v_corr[i] = (t_corr*)malloc(sizeof(t_corr) * info->height + 1);
	fd = open(argv, O_RDONLY);
	// printf("info->width = %d	info->height = %d\n", info->width, info->height);
	while (get_next_line(fd, &line) > 0)
	{
		i = -1;
		zVal = ft_strsplit(line, ' ');
		while (++i < info->width)
		{
			printf("i = %d\n", i);
			info->corr[j][i].z = ft_atoi(zVal[i]);
			free(zVal[i]);
		}
		j++;
		free(line);
	}
}

void	ft_init(t_info *info, char **argv)
{
	int i;

	i = 0;
	info->height = 0;
	info->width = 1;
	info->win_x = ft_atoi(argv[2]);
	info->win_y = ft_atoi(argv[3]);
}

void	gapCalc(t_info *info)
{
	if (info->win_x > info->win_y)
	{
		info->larger_win = info->win_x;
		info->smaller_win = info->win_y;
	}
	else
	{
		info->larger_win = info->win_y;
		info->smaller_win = info->win_x;
	}
	info->largerhw = (info->width >= info->height ? info->width : info->height);
	info->gap = info->smaller_win / 2 / info->largerhw;
	info->start_x = (info->win_x / 4);
	info->start_y = (info->win_y / 4);
}

void	initPt(t_info *info)
{
	int i;
	int j;

	i = -1;
	while (++i < info->height)
	{
		j = -1;
		while (++j < info->width)
		{
			info->corr[i][j].x = (float)(info->start_x + j * info->gap + info->corr[i][j].z * info->gap / 2);
			info->corr[i][j].y = (float)(info->start_y + i * info->gap - info->corr[i][j].z * info->gap / 2);
		}
	}
	i = -1;
	while (++i < info->width)
	{
		j = -1;
		while (++j < info->height)
		{
			info->v_corr[i][j].x = info->corr[j][i].x;
			info->v_corr[i][j].y = info->corr[j][i].y;
		}
	}
}

int		main(int argc, char **argv)
{
	t_info	info;

	if (argc != 4)
		return (1);
	if (argc == 4)
	{
		ft_init(&info, argv);
		read_n_arr(&info, argv[1]);
		gapCalc(&info);
		initPt(&info);
		info.mlx_ptr = mlx_init();
		info.win_ptr = mlx_new_window(info.mlx_ptr, info.win_x, info.win_y, "mlx 42");
		ft_draw(&info);
		ft_vdraw(&info);
		mlx_key_hook(info.win_ptr, deal_key, &info);
		mlx_loop(info.mlx_ptr);
	}
	return (0);
}