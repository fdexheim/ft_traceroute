#include "../../inc/ft_traceroute.h"

static const char *ipv4_format = \
"+--------------------------[ IPV4 HEADER ]---------------------------+\n"
"| vers %2.2x | ihl %2.2x | tos %8.2x | tot_len %24.4x |\n"
"| id %28x | frag_off %23x |\n"
"| ttl %10x | protocol %5x | check %26x |\n"
"| src  addr %56.8x |\n"
"| dest addr %56.8x |\n";

//------------------------------------------------------------------------------
void			dump_ipv6(void *ip_start)
{
	struct ip6_hdr		*ptr;

	ptr = ip_start;
	(void)ptr;
}

//------------------------------------------------------------------------------
void			dump_ipv4(void *ip_start)
{
	struct iphdr		*ptr;

	ptr = ip_start;
	printf(ipv4_format, ptr->version, ptr->ihl, ptr->tos, ptr->tot_len,
	ptr->id, ptr->frag_off, ptr->ttl, ptr->protocol, ptr->check, ptr->saddr,
	ptr->daddr);
}

//------------------------------------------------------------------------------
void			dump_ip(void *ip_start, bool ipv6)
{
	if (ipv6 == true)
		dump_ipv6(ip_start);
	else
		dump_ipv4(ip_start);
}
