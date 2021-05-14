/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_full_input.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdexheim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 10:45:49 by fdexheim          #+#    #+#             */
/*   Updated: 2019/09/18 14:48:30 by fdexheim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static char			*get_full_input_loop(char *input)
{
	char			*ret;
	char			*longstr;
	int				rd;

	ret = NULL;
	while ((rd = read(1, input, GFI_BUFF_SIZE - 1)) == GFI_BUFF_SIZE - 1)
	{
		input[rd] = '\0';
		longstr = ret;
		ret = ft_strjoin(ret, input);
		if (longstr != NULL)
			free(longstr);
	}
	if (rd < 0)
		return (NULL);
	input[rd] = '\0';
	if (ret == NULL)
		ret = input;
	else
		free(input);
	return (ret);
}

char				*ft_get_full_input(void)
{
	char			*input;
	char			*ret;

	if ((input = (char *)malloc(GFI_BUFF_SIZE)) == NULL)
		return (NULL);
	ret = get_full_input_loop(input);
	return (ret);
}
