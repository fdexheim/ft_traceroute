/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_quote.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdexheim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 11:26:36 by fdexheim          #+#    #+#             */
/*   Updated: 2019/08/14 13:02:15 by fdexheim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

#include <stdio.h>

char				*ft_valid_quote(char *s)
{
	char			quote;
	char			*ret;

	quote = *s;
	s += 1;
	while (*s != quote && (*(s + 1) != ' ' || *(s + 1) != '\0'))
	{
		s++;
		if (*s == '\0')
		{
			return (NULL);
		}
	}
	ret = s;
	return (ret);
}
