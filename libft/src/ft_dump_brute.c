#include "../inc/libft.h"
#include <stdio.h>

void				ft_dump_brute(void *data_start, uint32_t size)
{
	unsigned char *ptr = data_start;

	for (uint32_t i = 0; i < size; i++)
	{
		if (i % 16 == 0)
			printf("\n");
		printf("%3hx ", ptr[i]);
	}
	printf("\n");
}
