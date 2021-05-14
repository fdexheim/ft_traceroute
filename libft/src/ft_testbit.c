/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_testbit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdexheim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 12:39:35 by fdexheim          #+#    #+#             */
/*   Updated: 2019/08/14 12:39:37 by fdexheim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

bool				ft_testbit(uint32_t value, uint8_t const bit_number)
{
	if ((value) & (1 << (bit_number)))
		return (true);
	return (false);
}
