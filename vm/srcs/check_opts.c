#include "corewar.h"

static int		is_flag(char *s)
{
	if (!ft_strcmp("-d", s))
		return (1);
	if (!ft_strcmp("-s", s))
		return (2);
	if (!ft_strcmp("-v", s))
		return (3);
	if (!ft_strcmp("-a", s))
		return (4);
	if (!ft_strcmp("-b", s))
		return (5);
	if (!ft_strcmp("--stealth", s))
		return (6);
	return (0);
}

static t_opt	*init_opts(void)
{
	t_opt	*res;

	if (!(res = (t_opt *)malloc(sizeof(t_opt))))
		return (NULL);
	res->has_d = 0;
	res->has_v = 0;
	res->has_s = 0;
	res->has_a = 0;
	res->a_stealth = 0;
	res->has_b = 0;
	res->b_stealth = 0;
	res->fds = NULL;
	res->fds_nb = 0;
	res->d = -1;
	res->v = -1;
	res->s = -1;
	return (res);
}

static void	set_opt_flag(t_opt *opts, int flag, int val)
{
	if (flag == 1)
	{
		opts->has_d = 1;
		opts->d = val;
	}
	if (flag == 2)
	{
		opts->has_s = 1;
		opts->s = val;
	}
	if (flag == 3)
	{
		opts->has_v = 1;
		opts->v = val;
	}
}

void		append_fds_tab(t_opt *opts, int size, int val)
{
	// free_leaks
	int i;
	int	*old;

	i = 0;
	old = opts->fds;
	opts->fds = NULL;
	if (size < 0)
		return ;
	if (!(opts->fds = (int *)malloc(sizeof(int) * (size + 1))))
		return ;
	while (i < size)
	{
		opts->fds[i] = old[i];
		i++;
	}
	opts->fds[size] = val;
	free(old);
	old = NULL;
}

int		check_opts_flags(t_opt *opts, int *flag_indx, int ac, char **av)
{
	if (flag_indx[0] < 4 && flag_indx[0] > 0 && flag_indx[1] + 1 >= ac)
	{
		ft_printf("flag %s needs to have a value\n", av[flag_indx[1]]);
		return (0);
	}
	if (flag_indx[0] < 6 && flag_indx[0] > 0)
	{
		if (flag_indx[1] + 1 < ac && flag_indx[0] < 4)
		{
			flag_indx[1]++;
			set_opt_flag(opts, flag_indx[0], ft_atoi(av[flag_indx[1]]));
			flag_indx[0] = 0;
		}
		else if (flag_indx[0] == 4)
		{
			opts->a_stealth = 0;
			opts->has_a = 1;
			if (flag_indx[1] + 1 < ac && !ft_strcmp(av[flag_indx[1] + 1], "--stealth"))
			{
				opts->a_stealth = 1;
				flag_indx[1]++;
			}
		}
		else if (flag_indx[0] == 5)
		{
			opts->b_stealth = 0;
			opts->has_b = 1;
			if (flag_indx[1] + 1 < ac && !ft_strcmp(av[flag_indx[1] + 1], "--stealth"))
			{
				opts->b_stealth = 1;
				flag_indx[1]++;
			}
			flag_indx[0] = 0;
		}
		else
		{
			ft_printf("Can't read source file %s\n", av[flag_indx[1]]);
			return (0);
		}
	}
	return (1);
}

int			check_opts_fds(t_opt *opts, int *flag_indx, char **av)
{
	if ((flag_indx[0] = open(av[flag_indx[1]], O_RDONLY)) == -1)
	{
		ft_printf("Can't read source file %s\n", av[flag_indx[1]]);
		return (0);
	}
	else
		append_fds_tab(opts, opts->fds_nb, flag_indx[0]);
	opts->fds_nb++;
	flag_indx[0] = 0;
	return (1);
}

t_opt		*check_opts(int ac, char **av)
{
	// free_leaks;
	t_opt	*opts;
	int		flag_indx[2];

	flag_indx[1] = 1;
	if (!(opts = init_opts()))
		return (perror_ptr("Error: inside check_opts", NULL));
	while (flag_indx[1] < ac)
	{
		flag_indx[0] = is_flag(av[flag_indx[1]]);
		if (flag_indx[0] < 6 && flag_indx[0] > 0)
		{
			if (!(check_opts_flags(opts, flag_indx, ac, av)))
				return (NULL);
		}
		else
		{
			if (!(check_opts_fds(opts, flag_indx, av)))
				return (NULL);
		}
		flag_indx[1]++;
	}
	if (!opts->fds)
	{
		ft_putendl("Print Usage here");
		return (NULL);
	}
	return (opts);
}
