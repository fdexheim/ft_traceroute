/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdexheim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 16:05:05 by fdexheim          #+#    #+#             */
/*   Updated: 2019/08/22 10:20:47 by fdexheim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char		*ft_strdup(const char *src)
{
	char	*ret;
	int		len;
	int		i;

	if (src == NULL)
		return (NULL);
	len = ft_strlen(src);
	if ((ret = (char *)malloc(len + 1)) == NULL)
		return (NULL);
	ret[len] = '\0';
	i = 0;
	while (i < len)
	{
		ret[i] = src[i];
		i++;
	}
	return (ret);
}
