/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdexheim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 12:38:24 by fdexheim          #+#    #+#             */
/*   Updated: 2019/08/14 12:38:55 by fdexheim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

size_t				ft_strlen(const char *str)
{
	size_t			ret;

	ret = 0;
	if (str == NULL)
		return (0);
	while (*str)
	{
		ret++;
		str++;
	}
	return (ret);
}
