/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_directory_exists.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdexheim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 13:41:03 by fdexheim          #+#    #+#             */
/*   Updated: 2019/09/18 14:47:23 by fdexheim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static char			*isolate_dir_path(char *path)
{
	int				i;
	char			*ret;

	ret = path;
	while (*ret)
	{
		if (*ret == '/')
			break ;
		ret++;
		if (*ret == '\0' || *path == '\0')
			return (ft_strdup("./"));
	}
	i = ft_strlen(path);
	ret = ft_strdup(path);
	while (i > 0)
	{
		if (ret[i] == '/' && i > 1)
		{
			ret[i] = '\0';
			return (ret);
		}
		i--;
	}
	return (ret);
}

static char			*isolate_filename(char *access)
{
	int				i;

	i = ft_strlen(access);
	while (i > 0)
	{
		if (access[i - 1] == '/')
			break ;
		i--;
	}
	return (ft_strdup(&access[i]));
}

static bool			navigate_dir(DIR *diredoo, char *cmp)
{
	struct dirent	*entry;

	while ((entry = readdir(diredoo)) != NULL)
	{
		if (!ft_strcmp(entry->d_name, cmp) && entry->d_type == DT_DIR)
		{
			return (true);
		}
	}
	return (false);
}

bool				ft_directory_exists(char *access)
{
	DIR				*diredoo;
	char			*parent_dir_path;
	char			*entry_cmp;
	bool			ret;

	if ((parent_dir_path = isolate_dir_path(access)) == NULL)
		return (false);
	if ((entry_cmp = isolate_filename(access)) == NULL)
	{
		free(parent_dir_path);
		return (false);
	}
	if ((diredoo = opendir(parent_dir_path)) == NULL)
	{
		free(parent_dir_path);
		free(entry_cmp);
		return (false);
	}
	ret = navigate_dir(diredoo, entry_cmp);
	free(parent_dir_path);
	free(entry_cmp);
	closedir(diredoo);
	return (ret);
}
