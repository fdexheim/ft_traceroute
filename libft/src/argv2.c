/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdexheim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 10:47:00 by fdexheim          #+#    #+#             */
/*   Updated: 2019/09/18 14:46:00 by fdexheim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void				advance_quote(char **s)
{
	char			quote;

	quote = **s;
	*s += 1;
	while (**s != quote && **s != '\0')
	{
		*s += 1;
	}
}

void				advance_word(char **s)
{
	while (**s != ' ' && **s != '\0')
	{
		*s += 1;
	}
}

void				advance_argv(char **s)
{
	if (ft_is_quote(**s) == true)
	{
		advance_quote(s);
	}
	else
	{
		advance_word(s);
	}
}

int					wordlen_quote(const char *s)
{
	int				ret;
	char			quote;

	ret = 0;
	quote = *s;
	s++;
	while (*s != quote && *s != '\0')
	{
		ret++;
		s++;
	}
	return (ret);
}

int					wordlen_word(const char *s)
{
	int				ret;

	ret = 0;
	while (*s != '\0' && *s != ' ')
	{
		ret++;
		s++;
	}
	return (ret);
}
