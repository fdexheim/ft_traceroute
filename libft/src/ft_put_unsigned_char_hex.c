/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsigned_char_hex.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdexheim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 11:03:47 by fdexheim          #+#    #+#             */
/*   Updated: 2019/08/14 12:56:15 by fdexheim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void				ft_put_unsigned_char_hex(const unsigned char c)
{
	const char		hexa[] = "0123456789abcdef";

	if (c <= 0xf)
	{
		write(1, "0", 1);
		ft_putchar(hexa[c % 16]);
	}
	else
	{
		ft_putchar(hexa[c / 16]);
		ft_putchar(hexa[c % 16]);
	}
}
