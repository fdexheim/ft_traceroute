#include "../inc/ft_traceroute.h"

//------------------------------------------------------------------------------
static void				init_payload(void *payload_start, size_t size)
{
	unsigned char *ptr = payload_start;

	for (size_t i = 0; i < size; i++)
	{
		ptr[i] = 42;
	}
}

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

	init_payload(header_start + ICMP_HEADER_SIZE, ICMP_PAYLOAD_SIZE);

	hdr->type = ICMP_ECHO;
	hdr->code = 0;
	hdr->un.echo.id = htons(42);
	hdr->un.echo.sequence = htons(seq);
	hdr->checksum = 0;
	hdr->checksum = calculate_checksum(header_start, icmp_size / 2);
}
