/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_or_directory_exists.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdexheim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 13:42:59 by fdexheim          #+#    #+#             */
/*   Updated: 2019/08/22 13:43:01 by fdexheim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

bool			ft_file_or_directory_exists(char *access)
{
	if (ft_file_exists(access) || ft_directory_exists(access))
		return (true);
	return (false);
}
