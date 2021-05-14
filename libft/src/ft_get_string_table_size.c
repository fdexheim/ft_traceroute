/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_string_table_size.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdexheim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 11:25:09 by fdexheim          #+#    #+#             */
/*   Updated: 2019/08/14 11:26:30 by fdexheim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

size_t				ft_get_string_table_size(char **table)
{
	int				i;

	i = 0;
	while (*table != NULL)
	{
		i++;
		table++;
	}
	return (i);
}
