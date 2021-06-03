#include "../inc/ft_traceroute.h"

//------------------------------------------------------------------------------
void				list_flags()
{
	printf("\nFlags :\n");
	printf("--help        | Display help pannel\n");
	printf("-f [ttl]      | Set starting value for ttl\n");
	printf("-h            | Flag required by subject that has no known use in "
	"any implementation of traceroute\n");
	printf("-m [ttl]      | Set a maximum value for ttl\n");
	printf("-q [nqueries] | Set the number of queries for each ttl iteration\n");
	printf("-v            | Verbose for debugging (add more v's for more verbose)\n");
	printf("-ipv6         | ipv6 mode (NYI)\n");
}

//------------------------------------------------------------------------------
void				usage(void)
{
	ft_putstr("Usage: ./ft_traceroute [addr] [flags]\n");
	list_flags();
	return ;
}

//------------------------------------------------------------------------------
void				close_env(t_traceroute_env *env)
{
	if (env->addr_str != NULL)
	{
		free(env->addr_str);
	}
	free(env);
}

//------------------------------------------------------------------------------
static t_traceroute_env			*setup_env(int argc, char **argv)
{
	t_traceroute_env		*env;

	if ((env = malloc(sizeof(t_traceroute_env))) == NULL)
	{
		ft_putstr("[ERROR] Failed memory allocation\n");
		exit(EXIT_FAILURE);
	}
	ft_bzero(env, sizeof(t_traceroute_env));
	env->argc = argc;
	env->argv = argv;
	return (env);
}

//------------------------------------------------------------------------------
int					main(int argc, char **argv)
{
	t_traceroute_env		*env;

	if (argc <= 1)
	{
		usage();
		exit(EXIT_SUCCESS);
	}
	env = setup_env(argc, argv);
	parse_traceroute(env);
	run(env);
	close_env(env);
	return (EXIT_SUCCESS);
}
