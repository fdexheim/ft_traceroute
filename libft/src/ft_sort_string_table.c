/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_table.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdexheim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 12:36:29 by fdexheim          #+#    #+#             */
/*   Updated: 2019/08/14 12:37:35 by fdexheim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void				ft_sort_string_table(char **table)
{
	size_t			table_size;
	size_t			i;
	size_t			tmp;

	table_size = ft_get_string_table_size(table);
	i = 0;
	while (i < table_size - 1)
	{
		if (ft_strcmp(table[i], table[i + 1]) > 0)
		{
			tmp = (size_t)table[i];
			table[i] = table[i + 1];
			table[i + 1] = (char *)tmp;
			ft_sort_string_table(table);
			return ;
		}
		i++;
	}
}
