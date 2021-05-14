#include "../inc/ft_traceroute.h"

//------------------------------------------------------------------------------
void					init_ipv6_header(void *header_start, size_t full_packet_size, int ttl, void *addr)
{
	(void)header_start;
	(void)full_packet_size;
	(void)ttl;
	(void)addr;
}

//------------------------------------------------------------------------------
void					init_ipv4_header(void *header_start, size_t full_packet_size, int ttl, void *addr)
{
	struct iphdr		*hdr = (struct iphdr *)header_start;

	hdr->version = 4;
	hdr->ihl = 5;
	hdr->tos = 0;
	hdr->tot_len = htons(full_packet_size);
	hdr->id = 0;
	hdr->frag_off = 0;
	hdr->ttl = ttl;
	hdr->protocol = 1;
	hdr->check = 0;
	hdr->saddr = INADDR_ANY;
	hdr->daddr = ((struct sockaddr_in*)addr)->sin_addr.s_addr;
	hdr->check = calculate_checksum(header_start, 10);
}
