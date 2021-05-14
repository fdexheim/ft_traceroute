/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_size_t_hex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdexheim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 12:29:37 by fdexheim          #+#    #+#             */
/*   Updated: 2019/08/14 12:31:12 by fdexheim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void				ft_put_size_t_hex(const size_t src)
{
	const char		hexa[] = "0123456789abcdef";

	if (src >= 16)
		ft_put_size_t_hex(src / 16);
	ft_putchar(hexa[src % 16]);
}
