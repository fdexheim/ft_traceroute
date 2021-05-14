/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdexheim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 11:27:30 by fdexheim          #+#    #+#             */
/*   Updated: 2019/08/14 12:39:16 by fdexheim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int					ft_strncmp(const char *s1, const char *s2, size_t size)
{
	size_t			i;

	i = 0;
	while ((s1[i] || s2[i]) && i < size)
	{
		if (s1[i] != s2[i])
			return (ft_strcmp(s1, s2));
		i++;
	}
	return (0);
}
