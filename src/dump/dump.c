#include "../../inc/ft_traceroute.h"

//------------------------------------------------------------------------------
void					dump_sockaddr(struct sockaddr *ptr)
{
	printf("ai addr : sa_family = %d | sa_name = %s\n",
	ptr->sa_family, ptr->sa_data);
}

//------------------------------------------------------------------------------
void					dump_addrinfo(struct addrinfo *ptr)
{
	printf(" === ADDRINFO DUMP === \n");
	printf("ai_flags = %d\n", ptr->ai_flags);
	printf("ai_family = %d\n", ptr->ai_family);
	printf("ai_socktype = %d\n", ptr->ai_socktype);
	printf("ai_protocol = %d\n", ptr->ai_protocol);
	printf("ai_addrlen = %d\n", ptr->ai_addrlen);
	dump_sockaddr(ptr->ai_addr);
	printf("ai_canonname = %s\n", ptr->ai_canonname);
}

//------------------------------------------------------------------------------
void					dump_addrinfo_list(struct addrinfo *start)
{
	struct addrinfo		*ptr;

	ptr = start;
	while (ptr != NULL)
	{
		dump_addrinfo(ptr);
		ptr = ptr->ai_next;
	}
}

//------------------------------------------------------------------------------
void					dump_packet(t_traceroute_env *env, void *packet)
{
	void				*ip_start;
	void				*icmp_start;

	ip_start = packet;
	icmp_start = packet + env->ip_header_size;
	dump_ip(ip_start, env->flags.ipv6);
	dump_icmp(icmp_start, env->flags.ipv6);
}
