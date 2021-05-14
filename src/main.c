#include "../inc/ft_traceroute.h"

//------------------------------------------------------------------------------
void				list_flags()
{
	
}

//------------------------------------------------------------------------------
void				usage(void)
{
	ft_putstr("Usage: ./ft_traceroute command [command opts] [command args]\n");
	list_flags();
	return ;
}

//------------------------------------------------------------------------------
void				close_env(t_traceroute_env *env)
{
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
