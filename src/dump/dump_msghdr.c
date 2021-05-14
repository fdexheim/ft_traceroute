#include "../../inc/ft_traceroute.h"

//------------------------------------------------------------------------------
void			dump_msghdr(void *msg)
{
	struct msghdr *ptr = (struct msghdr *)msg;

	printf("msg_namelen = %d\nmsg_name = " , ptr->msg_namelen);
	ft_dump_brute(ptr->msg_name, ptr->msg_namelen);
	printf("msg_controllen = %ld\nmsg_control = ", ptr->msg_controllen);
	ft_dump_brute(ptr->msg_control, ptr->msg_controllen);
}
