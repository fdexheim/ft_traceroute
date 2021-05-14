/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdexheim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 13:06:11 by fdexheim          #+#    #+#             */
/*   Updated: 2019/09/18 11:14:15 by fdexheim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int			ft_atoi(char *str)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	if (str[i] == '\033')
		return (0);
	while ((str[i] > 0 && str[i] <= 32) || str[i] == 127)
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (ft_isdigit(str[i]))
	{
		if (k != 0)
			k = k * 10;
		k = k + str[i] - '0';
		i++;
	}
	i--;
	while (ft_isdigit(str[i]))
		i--;
	if (str[i] == '-')
		return (-k);
	return (k);
}
