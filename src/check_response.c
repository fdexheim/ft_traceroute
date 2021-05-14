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
void					check_response(t_traceroute_env *env, struct msghdr *hdr, size_t read_size)
{
	suseconds_t			rtt;
	struct sockaddr_in	*addr = hdr->msg_name;
	char				addr_str[100];
	(void)read_size;

	rtt = get_rtt_sus(&env->tv_start, &env->tv_end);
	check_checksums(env, env->in_buffer);
	ft_bzero(addr_str, 100);
	inet_ntop(AF_INET, &addr->sin_addr, addr_str, 99);
	printf("%ld.%03ldms ", rtt / 1000, rtt % 1000);
//	printf("From %s ", addr_str);
//	if (ft_strcmp(env->dest, env->addr_str))
//		printf("(%s) ", addr_str);
}

/*
   static const char		*get_icmp_type_msg(uint8_t type)
   {
   const char			*icmp_type_msg[] = {
   [ICMP_ECHOREPLY] = "Echo Reply",
   [1] = "Unknown type",
   [2] = "Unknown type",
   [ICMP_DEST_UNREACH] = "Destination Unreachable",
   [ICMP_SOURCE_QUENCH] = "Source Quench",
   [ICMP_REDIRECT] = "Redirect (change route)",
   [6] = "Unknown type",
   [7] = "Unknown type",
   [ICMP_ECHO] = "Echo Request",
   [9] = "Unknown type",
   [10] = "Unknown type",
   [ICMP_TIME_EXCEEDED] = "Time to live exceeded",
   [ICMP_PARAMETERPROB] = "Parameter Problem",
   [ICMP_TIMESTAMP] = "Timestamp Request",
   [ICMP_TIMESTAMPREPLY] = "Timestamp Reply",
   [ICMP_INFO_REQUEST] = "Information Request",
   [ICMP_INFO_REPLY] = "Information Reply",
   [ICMP_ADDRESS] = "Address Mask Request",
   [ICMP_ADDRESSREPLY] = "Address Mask Reply"
   };

   if (type > NR_ICMP_TYPES)
   return ("Unknown type");
   return (icmp_type_msg[type]);
}
*/
