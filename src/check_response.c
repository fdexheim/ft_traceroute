#include "../inc/ft_traceroute.h"

static void				check_checksums(t_traceroute_env *env, void *full_packet)
{
	uint16_t			ip_sum;
	uint16_t			icmp_sum;

	ip_sum = calculate_checksum(full_packet, env->ip_header_size / 2);
	icmp_sum = calculate_checksum(full_packet + env->ip_header_size,
			(env->icmp_header_size + env->icmp_payload_size) / 2);
	if (env->flags.v == true && (ip_sum != 0 || icmp_sum != 0))
		printf("[WARNING] some checksums do not match :\n"\
				"ip checksum   = %x\nicmp checksum = %x\n",
				ip_sum, icmp_sum);
}

//------------------------------------------------------------------------------
static suseconds_t		get_rtt_sus(struct timeval *start,
		struct timeval *end)
{
	time_t				diff_sec;
	suseconds_t			diff_usec;

	diff_sec = end->tv_sec - start->tv_sec;
	diff_usec = 1000000 * diff_sec + (end->tv_usec - start->tv_usec);
	return (diff_usec);
}

//------------------------------------------------------------------------------
static void				print_host_addr(t_traceroute_env *env, struct sockaddr_in *addr)
{
	char				addr_str[100];
	char				host_str[100];
	char				serv_str[100];

	if (env->flags.v == true)
	{
		ft_bzero(addr_str, 100);
		ft_bzero(host_str, 100);
		ft_bzero(serv_str, 100);
		inet_ntop(AF_INET, &addr->sin_addr, addr_str, 99);
		getnameinfo((struct sockaddr*)addr, sizeof(struct sockaddr_in), host_str,
			99, serv_str, 99, 0);
		printf("%-64s %-15s ", host_str, addr_str);
	}
	else
	{
		ft_bzero(addr_str, 100);
		inet_ntop(AF_INET, &addr->sin_addr, addr_str, 99);
		printf("%-15s ", addr_str);
	}
}

//------------------------------------------------------------------------------
void					check_response(t_traceroute_env *env, uint32_t queri)
{
	suseconds_t			rtt;
	struct sockaddr_in	*addr = env->rep.msg.msg_name;

	if (env->rep.read_size < 0)
	{
		printf("*");
	}
	else
	{
		rtt = get_rtt_sus(&env->tv_start, &env->tv_end);
		check_checksums(env, env->in_buffer);
		if ((env->sock.last_hop.sin_addr.s_addr != addr->sin_addr.s_addr)
			|| queri == 0)
		{
			env->sock.last_hop = *addr;
			print_host_addr(env, addr);
		}
		printf("% 4ld.%03ldms ", rtt / 1000, rtt % 1000);
	}
	if (env->rep.icmp_type == ICMP_DEST_UNREACH)
		printf("!N ");
}
