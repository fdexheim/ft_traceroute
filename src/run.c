#include "../inc/ft_traceroute.h"

//------------------------------------------------------------------------------
static void				init_default_values(t_traceroute_env *env)
{
	if (env->flags.f == false)
		env->first_ttl = 1;
	if (env->flags.h == true)
		ft_putstr("-h flag ? I just think it's neat\n");
	if (env->flags.m == false)
		env->max_ttl = 30;
	if (env->flags.q == false)
		env->nqueries = 3;
	if (env->flags.ipv6 == true)
	{
		env->ip_header_size = IP_HEADER_SIZE_V6;
		env->icmp_header_size = ICMP_HEADER_SIZE_V6;
		env->icmp_payload_size = ICMP_PAYLOAD_SIZE_V6;
		env->init_ip_header = init_ipv6_header;
		env->init_icmp_header = init_icmp_header_ipv6;
	}
	else
	{
		env->ip_header_size = IP_HEADER_SIZE;
		env->icmp_header_size = ICMP_HEADER_SIZE;
		env->icmp_payload_size = ICMP_PAYLOAD_SIZE;
		env->init_ip_header = init_ipv4_header;
		env->init_icmp_header = init_icmp_header_ipv4;
	}
	env->full_packet_size = env->ip_header_size + env->icmp_header_size
		+ env->icmp_payload_size;
}

//------------------------------------------------------------------------------
static uint8_t			exchange(t_traceroute_env *env, uint32_t ttl)
{
	int					type;

	give_ping(env, ttl);
	type = get_pong(env);
	return (type);
}

//------------------------------------------------------------------------------
static uint8_t			probe_gate(t_traceroute_env *env, uint32_t ttl)
{
	uint8_t				type;

	if (ttl < 10)
		printf(" ");
	printf("%d ", ttl);
	for (uint32_t probe = 0; probe < env->nqueries; probe++)
	{
		printf(" ");
		type = exchange(env, ttl);
	}
	return (type);
}

//------------------------------------------------------------------------------
static void				loop(t_traceroute_env *env)
{
	uint8_t				type;

	for (uint32_t ttl = env->first_ttl; ttl <= env->max_ttl; ttl++)
	{
		type = probe_gate(env, ttl);
		printf("\n");
		if (type == ICMP_ECHOREPLY)
			break;
	}
}

//------------------------------------------------------------------------------
void				run(t_traceroute_env *env)
{
	init_default_values(env);
	if (env->flags.ipv6 == true)
	{
		printf("[Warning] Please note that Ipv6 handling is not yet implemented. Exiting...\n");
		return ;
	}
	if (setup_socket(env) == -1)
	{
		printf("[Error] Failed to setup socket\n");
		return ;
	}
	if (env->dest_arg == NULL)
	{
		ft_putstr("No destination address detected in args\n");
		return ;
	}
	printf("traceroute to %s (%s), %d hops max, %ld byte packets\n",
		env->dest_arg, env->addr_str,
		env->max_ttl, env->icmp_header_size + env->icmp_payload_size);
	loop(env);
}
