#include "../inc/ft_traceroute.h"

//------------------------------------------------------------------------------
static void			flip_bits(uint16_t *target)
{
	uint16_t		mask;

	mask = 0xffff;
	*target ^= mask;
}

//------------------------------------------------------------------------------
uint16_t			calculate_checksum(void *hdr, uint32_t iters)
{
	uint16_t		*ptr;
	uint32_t		tot;
	uint32_t		carry;
	uint16_t		ret;

	ptr = hdr;
	tot = 0;
	carry = 0;
	ret = 0;
	for (uint32_t i = 0; i < iters; i++)
	{
		tot += *ptr;
		ptr++;
	}
	carry = (tot & 0xffff0000) >> 16;
	ret = (tot & 0x0000ffff) + carry;
	flip_bits(&ret);
	return (ret);
}
