#include "../inc/ft_traceroute.h"

//------------------------------------------------------------------------------
static int32_t			browse_addrlist(t_traceroute_env *env, struct addrinfo *start)
{
	struct addrinfo		*ptr;
	char				addrstr[100];
	int					optval = 1;
	struct timeval		timeout = {
		.tv_sec = 0,
		.tv_usec = 900000
	};

	for (ptr = start; ptr != NULL; ptr = ptr->ai_next)
	{
		ft_bzero(addrstr, 100);
		inet_ntop(ptr->ai_addr->sa_family, ptr->ai_addr->sa_data + 2, addrstr, 99);
		env->sock.fd = socket(AF_INET, SOCK_RAW,
			IPPROTO_ICMP);
		if (env->sock.fd == -1)
		{
			printf("Bad socket()\n");
			printf("Make sure you're running the program with the "
				"requirered permissions to open a raw socket\n");
			continue;
		}
		if (setsockopt(env->sock.fd, IPPROTO_IP, IP_HDRINCL,
				&optval, sizeof(int)) < 0
			|| setsockopt(env->sock.fd, SOL_SOCKET, SO_RCVTIMEO,
				&timeout, sizeof(struct timeval)) < 0)
		{
			printf("Bad setsockopt()\n");
			exit(EXIT_FAILURE);
		}
//		env->addr_str = ft_strdup(addrstr);
//		env->socket_data.addr_dest.sin_addr.s_addr =
//			((struct sockaddr_in*)ptr->ai_addr)->sin_addr.s_addr;
		env->sock.addr_dest.sin_family = AF_INET;
		break;
	}
	return (env->sock.fd);
}

//------------------------------------------------------------------------------
int32_t					setup_socket(t_traceroute_env *env)
{
	int					ret;
	struct addrinfo		*start;
	struct addrinfo		hints = {
		.ai_family = env->flags.ipv6 == true ? AF_INET6 : AF_INET,
		.ai_flags = 0,
		.ai_protocol = IPPROTO_ICMP,
		.ai_socktype = SOCK_RAW
	};

	ret = getaddrinfo(env->dest_arg, NULL, &hints, &start);
	if (ret != 0)
	{
		printf("ping: %s: Could not resolve hostname\n", env->dest_arg);
		return (ret);
	}
	browse_addrlist(env, start);
	if (start != NULL)
		freeaddrinfo(start);
	return (env->sock.fd);
}
