#include "../inc/libft.h"

void		ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*c;

	i = 0;
	c = (char *)s;
	while (i < n)
	{
		*c = 0;
		i++;
		c++;
	}
	return ;
}
