#include "../inc/ft_traceroute.h"

//------------------------------------------------------------------------------
void						parse_flag_cluster(t_traceroute_env *env, char *arg)
{
	for (uint32_t i = 1; arg[i] != '\0'; i++)
	{
		env->flags.h = arg[i] == 'h' ? true : env->flags.h;
		if (arg[i] == 'v')
		{
			env->flags.v = true;
			env->flags.verbose_level++;
		}
		if (arg[i] == 'd')
		{
			env->flags.d = true;
			env->flags.debug_level++;
		}
	}
}

//------------------------------------------------------------------------------
static void					handle_flag_q(t_traceroute_env *env, char **args)
{
	int						nq = ft_atoi(args[1]);

	if (nq < 0)
	{
		printf("Bad value for -q flag, nqueries will use default value\n");
		return ;
	}
	env->flags.q = true;
	env->nqueries = nq;
}

//------------------------------------------------------------------------------
static void					handle_flag_f(t_traceroute_env *env, char **args)
{
	int						first_ttl = ft_atoi(args[1]);
	if (first_ttl < 0)
	{
		printf("Bad value for -f flag, first_ttl will use default value\n");
		return ;
	}
	env->flags.f = true;
	env->first_ttl = first_ttl;
}

//------------------------------------------------------------------------------
static void					handle_flag_m(t_traceroute_env *env, char **args)
{
	int						max_ttl = ft_atoi(args[1]);
	if (max_ttl < 0)
	{
		printf("Bad value for -m flag, max_ttl will use default value\n");
		return ;
	}
	env->flags.m = true;
	env->max_ttl = max_ttl;
}

//------------------------------------------------------------------------------
static void					handle_flag_help(t_traceroute_env *env, char **args)
{
	(void)env;
	(void)args;
	usage();
	exit(EXIT_SUCCESS);
}

//------------------------------------------------------------------------------
static void					handle_flag_ipv6(t_traceroute_env *env, char **args)
{
	(void)args;
	env->flags.ipv6 = true;
}

//------------------------------------------------------------------------------
static int32_t				check_arg_flags(t_traceroute_env *env, char **args)
{
	const t_traceroute_arg_flags	traceroute_arg_flags[] = {
		{ "-m", 1, handle_flag_m },
		{ "-f", 1, handle_flag_f },
		{ "-q", 1, handle_flag_q },
		{ "-ipv6", 1, handle_flag_ipv6 },
		{ "--help", 0, handle_flag_help },
		{ NULL, 0, NULL }
	};

	for (uint32_t j = 0; traceroute_arg_flags[j].flag != NULL; j++)
	{
		if (!ft_strcmp(traceroute_arg_flags[j].flag, *args))
		{
			if (ft_check_nb_args_required(args, traceroute_arg_flags[j].nb_args) == true)
			{
				traceroute_arg_flags[j].flag_handler(env, args);
				return (traceroute_arg_flags[j].nb_args);
			}
			else
				break ;
		}
	}
	return -1;
}

//------------------------------------------------------------------------------
void						parse_traceroute(t_traceroute_env *env)
{
	int32_t					arg_flag_size;

	for (int i = 1; i < env->argc; i++)
	{
		arg_flag_size = check_arg_flags(env, &env->argv[i]);
		if (arg_flag_size == -1)
		{
			if (env->argv[i][0] == '-')
				parse_flag_cluster(env, env->argv[i]);
			else
			{
				if (env->dest_arg == NULL)
				{
					env->dest_arg = env->argv[i];
				}
			}
		}
		else
			i += arg_flag_size;
	}
}
