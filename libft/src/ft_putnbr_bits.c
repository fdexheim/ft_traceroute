/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_bits.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdexheim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 12:32:44 by fdexheim          #+#    #+#             */
/*   Updated: 2019/08/14 12:32:50 by fdexheim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void				ft_putnbr_bits(size_t src, const uint8_t bits)
{
	size_t			tmp;
	size_t			cmp;

	tmp = bits;
	cmp = 1;
	while (tmp > 1)
	{
		cmp = cmp * 2;
		tmp--;
	}
	tmp = bits;
	while (tmp > 0)
	{
		if (cmp <= src)
		{
			write(1, "1", 1);
			src -= cmp;
		}
		else
			write(1, "0", 1);
		cmp = cmp / 2;
		tmp--;
	}
}
