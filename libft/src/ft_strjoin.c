/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdexheim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 14:26:25 by fdexheim          #+#    #+#             */
/*   Updated: 2019/09/12 15:57:11 by fdexheim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char				*ft_strjoin(const char *s1, const char *s2)
{
	int				len;
	char			*ret;
	char			*tmp;

	len = ft_strlen(s1) + ft_strlen(s2);
	if ((ret = (char *)malloc(len + 1)) == NULL)
		return (NULL);
	tmp = ret;
	ret[len] = '\0';
	while (s1 != NULL && *s1 != '\0')
	{
		*tmp = *s1;
		tmp++;
		s1++;
	}
	while (s2 != NULL && *s2 != '\0')
	{
		*tmp = *s2;
		tmp++;
		s2++;
	}
	return (ret);
}
