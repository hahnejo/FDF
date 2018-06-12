/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjo <hjo@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 21:44:17 by hjo               #+#    #+#             */
/*   Updated: 2018/03/10 21:44:38 by hjo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// int		ft_atoi(const char *str)
// {
// 	int res = 0;
// 	int sign = 1;
// 	int i = 0;

// 	if (str[0] == '-')
// 	{
// 		sign = -1;
// 		i++;
// 	}
// 	for (; str[i] != '\0'; ++i)
// 		res = res * 10 + str[i] - '0';
// 	return (sign * res);
// }

int		ft_atoi(const char *str)
{
	int i;
	int nbr;
	int negative;

	nbr = 0;
	negative = 0;
	i = 0;
	while ((str[i] == '\n') || (str[i] == '\t') || (str[i] == '\v') ||
			(str[i] == ' ') || (str[i] == '\f') || (str[i] == '\r'))
		i++;
	if (str[i] == '-')
		negative = 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] && (str[i] >= '0') && (str[i] <= '9'))
	{
		nbr *= 10;
		nbr += (int)str[i] - '0';
		i++;
	}
	if (negative == 1)
		return (-nbr);
	else
		return (nbr);
}
