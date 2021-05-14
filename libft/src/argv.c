/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdexheim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 11:24:37 by fdexheim          #+#    #+#             */
/*   Updated: 2019/09/18 14:45:50 by fdexheim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static int			wordcount_argv(char *s)
{
	int				ret;

	ret = 0;
	while (*s != '\0')
	{
		while (*s == ' ')
			s++;
		if (ft_is_quote(*s) && ft_valid_quote(s))
		{
			ret++;
			advance_quote(&s);
		}
		else if (*s != '\0')
		{
			ret++;
			advance_word(&s);
		}
		if (*s == '\0')
			return (ret);
		s++;
	}
	return (ret);
}

static char			*strsub_argv(const char *src, unsigned int start,
		size_t len)
{
	int				i;
	char			*ret;

	if (!src)
		return (NULL);
	i = 0;
	ret = (char *)malloc(len + 1);
	if (!ret)
		return (NULL);
	while (len--)
		ret[i++] = src[start++];
	ret[i] = '\0';
	return (ret);
}

static char			**fill_argv(char **allocated, char *src)
{
	char			**ret;

	ret = allocated;
	while (*src)
	{
		while (*src == ' ')
			src++;
		if (*src == '\0')
			return (ret);
		if (ft_is_quote(*src) && ft_valid_quote(src))
		{
			*allocated = strsub_argv(src, 1, wordlen_quote(src));
			allocated++;
		}
		else
		{
			*allocated = strsub_argv(src, 0, wordlen_word(src));
			allocated++;
		}
		advance_argv(&src);
	}
	return (ret);
}

char				**build_argv(char *src)
{
	char			**ret;
	int				wdcnt;

	wdcnt = wordcount_argv(src);
	ret = (char **)malloc((sizeof(char *) * (wdcnt + 1)));
	if (ret == NULL)
		return (NULL);
	ret[wdcnt] = 0;
	ret = fill_argv(ret, src);
	return (ret);
}
