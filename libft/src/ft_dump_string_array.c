#include "../inc/libft.h"

void			ft_dump_string_array(char **array)
{
	char		**ptr;

	ptr = array;
	while (*ptr != NULL)
	{
		write(1, "'", 1);
		ft_putstr(*ptr);
		write(1, "'\n", 2);
		ptr++;
	}
}
