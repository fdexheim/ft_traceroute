#ifndef FT_TRACEROUTE_H
# define FT_TRACEROUTE_H

#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "../libft/inc/libft.h"

#define PACKET_MAX_SIZE 4096
#define IP_HEADER_SIZE 20
#define IP_HEADER_SIZE_V6 40
#define ICMP_HEADER_SIZE 8
#define ICMP_HEADER_SIZE_V6 8
#define ICMP_PAYLOAD_SIZE 52
#define ICMP_PAYLOAD_SIZE_V6 52
#define FULL_PACKET_SIZE IP_HEADER_SIZE + ICMP_HEADER_SIZE + ICMP_PAYLOAD_SIZE
#define FULL_PACKET_SIZE IP_HEADER_SIZE + ICMP_HEADER_SIZE + ICMP_PAYLOAD_SIZE
#define FULL_PACKET_SIZE_V6 IP_HEADER_SIZE_v6 + ICMP_HEADER_SIZE_v6 + ICMP_PAYLOAD_SIZE_v6

typedef struct			s_traceroute_flags
{
	bool				f;
	bool				h;
	bool				m;
	bool				q;
	bool				v;
	uint8_t				verbose_level;
	bool				ipv6;
}						t_traceroute_flags;

typedef struct			s_socket_data
{
	int					fd;
	struct sockaddr_in	addr_dest;
	struct sockaddr_in	last_hop;
}						t_socket_data;

typedef struct			s_traceroute_env
{
	int					argc;
	char				**argv;
	char				*dest_arg;
	char				*addr_str;
	t_socket_data		sock;
	t_traceroute_flags	flags;
	struct timeval		tv_start;
	struct timeval		tv_end;
	unsigned char		in_buffer[PACKET_MAX_SIZE];
	unsigned char		out_buffer[PACKET_MAX_SIZE];
	unsigned int		first_ttl;
	unsigned int		max_ttl;
	unsigned int		nqueries;
	size_t				ip_header_size;
	size_t				icmp_header_size;
	size_t				icmp_payload_size;
	size_t				full_packet_size;
	void				(*init_ip_header)(void *header, size_t full_packet_size, int ttl, void *addr);
	void				(*init_icmp_header)(void *header, int seq, size_t icmp_size);

}						t_traceroute_env;

typedef struct			s_traceroute_arg_flag
{
	char				*flag;
	uint32_t			nb_args;
	void				(*flag_handler)(t_traceroute_env *, char **);
}						t_traceroute_arg_flags;


void					check_response(t_traceroute_env *env, struct msghdr *hdr, ssize_t read_size);


uint16_t				calculate_checksum(void *start, uint32_t iters);


void					dump_packet(t_traceroute_env *env, void *packet);
void					dump_sockaddr(struct sockaddr *ptr);
void					dump_addrinfo(struct addrinfo *ptr);
void					dump_addrinfo_list(struct addrinfo *start);
void					dump_ip(void *ip_start, bool ipv6);
void					dump_icmp(void *icmp_start, bool ipv6);
void					dump_msghdr(void *msg);

void					init_icmp_header_ipv6(void *header_start, int seq, size_t icmp_size);
void					init_icmp_header_ipv4(void *header_start, int seq, size_t icmp_size);


void					init_ipv6_header(void *header_start, size_t full_packet_size, int ttl, void *addr);
void					init_ipv4_header(void *header_start, size_t full_packet_size, int ttl, void *addr);


void					give_ping(t_traceroute_env *env, int ttl);
uint8_t					get_pong(t_traceroute_env *env);


void					usage(void);
void					close_env(t_traceroute_env *env);


void					parse_traceroute(t_traceroute_env *env);


void					run(t_traceroute_env *env);


int32_t					setup_socket(t_traceroute_env *env);

#endif
