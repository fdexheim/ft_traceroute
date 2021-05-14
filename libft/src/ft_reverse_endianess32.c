#include "../inc/libft.h"

uint32_t			ft_reverse_endianess32(const uint32_t src)
{
	uint32_t		ret;

	ret = ((src >> 24) & 0xff)
		| ((src << 8) & 0xff0000)
		| ((src >> 8) & 0xff00)
		| ((src << 24) & 0xff000000);
	return (ret);
}
