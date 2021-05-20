#include "../inc/libft.h"
#include <stdio.h>

//------------------------------------------------------------------------------
bool						ft_check_nb_args_required(char **args, uint32_t nb_arg)
{
	for (uint32_t i = 1; i <= nb_arg; i++)
	{
		if (args[i] == NULL)
		{
			printf("Missing arguments for arg '%s', expecting %d, got %d\n",
				args[0], nb_arg, i - 1);
			return (false);
		}
	}
	return (true);
}
