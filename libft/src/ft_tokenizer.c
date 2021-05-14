#include "../inc/libft.h"

uint64_t		arg_len(char *src)
{
	char		*end;
	uint64_t	ret;

	if (ft_is_quote(*src) && ((end = ft_valid_quote(src)) != NULL))
	{
		ret = (end - src) + 1;
	}
	else
	{
		end = src;
		while (*end != ' ' && *end != '\0')
			end++;
		ret = end - src;
	}
	return (ret);
}

uint32_t		count_args(char *src)
{
	char		*ptr;
	uint32_t	ret;
	bool		in_word;

	ret = 0;
	while (*src != '\0')
	{
		if (*src != ' ' && in_word == false)
		{
			in_word = true;
			src--;
			ret++;
		}
		else if (in_word == true && *src != ' ')
		{
			if (ft_is_quote(*src) && ((ptr = ft_valid_quote(src)) != NULL))
			{
				src = ptr;
			}
		}
		else
			in_word = false;
		src++;
	}
	return (ret);
}

char			*copy_substr(char *start, uint32_t len)
{
	char		*ret;
	uint32_t	j = 0;

	ret = malloc(len + 1);
	for (uint32_t i = 0; i < len; i++)
	{
		if (!ft_is_quote(start[i]))
		{
			ret[j] = start[i];
			j++;
		}
	}
	ret[j] = '\0';
	return (ret);
}

void			fill_ret(char **allocated, char *src, uint32_t arg_count)
{
	uint32_t	word_copied;
	uint64_t	len_cpy;

	word_copied = 0;
	while (word_copied < arg_count)
	{
		while (*src == ' ')
			src++;
		len_cpy = arg_len(src);
		allocated[word_copied] = copy_substr(src, len_cpy);
		word_copied++;
		src += len_cpy;
		if (len_cpy == 0)
			src++;
	}
}

char			**ft_tokenizer(char *src)
{
	uint32_t	arg_count;
	char		**ret;

	arg_count = count_args(src);
	ret = (char **)malloc(sizeof(char**) * arg_count + 1);
	ret[arg_count] = NULL;
	fill_ret(ret, src, arg_count);
	return (ret);
}
