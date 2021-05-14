#include "../inc/libft.h"

uint64_t			ft_reverse_endianess64(const uint64_t src)
{
	uint64_t		ret;

	ret = src;
	ret = (ret & 0x00000000ffffffff) << 32
	| (ret & 0xffffffff00000000) >> 32;
	ret = (ret & 0x0000ffff0000ffff) << 16
	| (ret & 0xffff0000ffff0000) >> 16;
	ret = (ret & 0x00ff00ff00ff00ff) << 8
	| (ret & 0xff00ff00ff00ff00) >> 8;

	return (ret);
}
