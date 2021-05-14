/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_uint64.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdexheim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 11:30:37 by fdexheim          #+#    #+#             */
/*   Updated: 2019/09/18 14:48:46 by fdexheim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static int8_t		num_len(uint64_t src)
{
	int8_t			ret;

	ret = 0;
	while (src >= 10)
	{
		ret++;
		src /= 10;
	}
	ret++;
	return (ret);
}

char				*ft_itoa_uint64(uint64_t src)
{
	int8_t			len;
	char			*ret;

	len = num_len(src);
	ret = (char *)malloc(len + 1);
	ret[len] = 0;
	len--;
	while (len >= 0)
	{
		ret[len] = (src % 10) + '0';
		src /= 10;
		len--;
	}
	return (ret);
}
