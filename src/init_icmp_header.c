#include "../inc/ft_traceroute.h"

//------------------------------------------------------------------------------
void					init_icmp_header_ipv6(void *header_start, int seq, size_t icmp_size)
{
	struct icmp6_hdr	*hdr = (struct icmp6_hdr *)header_start;
	(void)hdr;
	(void)seq;
	(void)icmp_size;
}

//------------------------------------------------------------------------------
void					init_icmp_header_ipv4(void *header_start, int seq, size_t icmp_size)
{
	struct icmphdr		*hdr = (struct icmphdr *)header_start;

	hdr->type = ICMP_ECHO;
	hdr->code = 0;
	hdr->un.echo.id = htons(42);
	hdr->un.echo.sequence = htons(seq);
	hdr->checksum = 0;
	hdr->checksum = calculate_checksum(header_start, icmp_size / 2);
}
