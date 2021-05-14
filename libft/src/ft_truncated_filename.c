/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_truncated_filename.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdexheim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 12:39:40 by fdexheim          #+#    #+#             */
/*   Updated: 2019/09/06 11:33:17 by fdexheim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char				*ft_truncated_filename(char *path)
{
	int				i;

	i = ft_strlen(path);
	if (i == 0)
	{
		return (NULL);
	}
	while (i > 1 && path[i - 1] != '/')
	{
		i--;
	}
	if (i == 1 && path[0] != '/')
		i = 0;
	return (&path[i]);
}
