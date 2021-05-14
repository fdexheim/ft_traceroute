#include "../inc/ft_traceroute.h"

//------------------------------------------------------------------------------
void				give_ping(t_traceroute_env *env, int ttl)
{
	ssize_t				ret;
	void				*ip_start = env->out_buffer;
	void				*icmp_start = env->out_buffer + env->ip_header_size;

	ft_bzero(env->out_buffer, 4096);
	env->init_icmp_header(icmp_start, ttl, env->icmp_header_size + env->icmp_payload_size);
	env->init_ip_header(ip_start, env->full_packet_size, ttl, &env->sock.addr_dest);

	if (gettimeofday(&env->tv_start, NULL) < 0)
		printf("Bad gettimeofday()");
	ret = sendto(env->sock.fd, env->out_buffer,
		env->full_packet_size, 0, (struct sockaddr *)&env->sock.addr_dest,
		sizeof(env->sock.addr_dest));
	if (env->flags.v == true)
	{
		if (env->flags.verbose_level >= 2)
		{
			printf("Sent packet :\n");
			dump_packet(env, env->out_buffer);
		}
	}
	if (ret < 0)
	{
		if (env->flags.v == true)
			printf("[WARNING] sendto() failed\n");
	}
}

//------------------------------------------------------------------------------
static void				init_msgdr(t_traceroute_env *env, struct msghdr *msg, struct iovec *iov, struct sockaddr_in *addr, char *buffer)
{
	*addr = env->sock.addr_dest;

	iov->iov_base = env->in_buffer;
	iov->iov_len = env->full_packet_size;

	msg->msg_name = addr;
	msg->msg_namelen = sizeof(struct sockaddr_in);
	msg->msg_iov = iov;
	msg->msg_iovlen = 1;
	msg->msg_control = buffer;
	msg->msg_controllen = 64;
	msg->msg_flags = 0;
}

//------------------------------------------------------------------------------
uint8_t					get_pong(t_traceroute_env *env)
{
	ssize_t				ret;
	char				buffer[64];
	struct sockaddr_in	addr;
	struct iovec		iov;
	struct msghdr		msg;
	uint8_t				type = 42;

	while (type != ICMP_ECHOREPLY && type != ICMP_TIME_EXCEEDED)
	{
		ft_bzero(buffer, 64);
		ft_bzero(env->in_buffer, 4096);
		init_msgdr(env, &msg, &iov, &addr, buffer);
		ret = recvmsg(env->sock.fd, &msg, 0);
		type = ((struct icmphdr *)(env->in_buffer + env->ip_header_size))->type;
		if (gettimeofday(&env->tv_end, NULL) < 0)
			printf("bad gettimeofday()\n");
		if (env->flags.v == true)
		{
			if (env->flags.verbose_level >= 2)
			{
				printf("Reveived packet :\n");
				dump_packet(env, env->in_buffer);
			}
		}
		check_response(env, &msg, ret);
		if (ret < 0)
		{
			if (env->flags.v == true)
				printf("[WARNING] recvmsg() failed or timed out\n");
			break ;
		}
	}
	return (type);
}
