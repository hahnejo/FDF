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

void	corrMalloc(t_info *info)
{
	int i;
	int j;

	info->corr = ft_memalloc(sizeof(t_corr**) * info->height + 1);
	i = -1;
	while (++i < info->height)
	{
		j = -1;
		info->corr[i] = ft_memalloc(sizeof(t_corr*) * (info->width));
		while (++j < info->height)
			info->corr[i][j] = ft_memalloc(sizeof(t_corr));
	}
	info->v_corr = ft_memalloc(sizeof(t_corr**) * info->width + 1);
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

void	storeZ(t_info *info, char *argv)
{
	int fd;
	int i;
	int j;
	char *line;
	char **zVal;

	j = 0;
	fd = open(argv, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		i = -1;
		zVal = ft_strsplit(line, ' ');
		while (++i < info->width)
		{
			// printf("i = %d\n", i);
			info->corr[j][i]->z = ft_atoi(zVal[i]);
			free(zVal[i]);
		}
		j++;
		free(line);
	}
	close(fd);
}

void		read_n_arr(t_info *info, char *argv)
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
	close(fd);
	printf("width and height are %d and %d respectively\n", info->width, info->height);
	corrMalloc(info);
	storeZ(info, argv);
	printf("after malloc and store, width and height are %d %d\n", info->width, info->height);
}
