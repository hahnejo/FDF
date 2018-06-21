/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   storage.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 18:32:03 by hjo               #+#    #+#             */
/*   Updated: 2018/05/31 18:32:04 by hjo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	free_string(char	**str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	corr_malloc(t_info *info)
{
	int i;
	int j;

	info->corr = ft_memalloc(sizeof(t_corr**) * info->height);
	i = -1;
	while (++i < info->height)
	{
		j = -1;
		info->corr[i] = ft_memalloc(sizeof(t_corr*) * (info->width));
		while (++j < info->width)
		{
			info->corr[i][j] = ft_memalloc(sizeof(t_corr));
			// printf("%p %d\n", info->corr[i][j], j);
		}
	}
	info->v_corr = ft_memalloc(sizeof(t_corr**) * info->width);
	i = -1;
	while (++i < info->width)
	{
		j = -1;
		info->v_corr[i] = ft_memalloc(sizeof(t_corr*) * info->height);
		while (++j < info->height)
			info->v_corr[i][j] = ft_memalloc(sizeof(t_corr));
	}
	// i = -1;
	// info->color[i] = (int)ft_memalloc(sizeof(int) * info->height);
}

void	store_z(t_info *info, char *argv)
{
	int fd;
	int i;
	int j;
	char *line;
	char **z_val;

	i = 0;
	fd = open(argv, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		j = -1;
		z_val = ft_strsplit(line, ' ');
		while (++j < info->width - 1)
		{
			// printf("i = %d, j = %d\n", i, j);
			// printf("ft_atoi(z_val[%d]) = %d\n", i, ft_atoi(z_val[j]));
			printf("%p %p %p\n", info->corr, info->corr[i], info->corr[i][j]);
			info->corr[i][j]->z = ft_atoi(z_val[j]);
		}
		i++;
		free(line);
		free_string(z_val);
	}
	close(fd);
}

void	read_n_arr(t_info *info, char *argv)
{
	int fd;
	char *line;
	int i;
	int j;

	i = 0;
	j = 0;
	line = NULL;
	fd = open(argv, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		while (info->height == 0 && line[i + 1] != '\0')
		{
			if (line[i] == ' ' && line[i + 1] != ' ')
				info->width++;
			i++;
		}
		free(line);
		line = NULL;
		info->height++;
	}
	close(fd);
	printf("width and height are %d and %d respectively\n", info->width, info->height);
	corr_malloc(info);
	store_z(info, argv);
	// printf("after malloc and store, width and height are %d %d\n", info->width, info->height);
}
