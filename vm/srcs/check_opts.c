#include "corewar.h"

static int		is_flag_with_nb(char *s)
{
	if (!ft_strcmp("-d", s))
		return (1);
	if (!ft_strcmp("-s", s))
		return (2);
	if (!ft_strcmp("-v", s))
		return (3);
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
}

t_opt		*check_opts(int ac, char **av)
{
	// free_leaks;
	int		i;
	t_opt	*opts;
	int		flag;

	i = 1;
	if (!(opts = init_opts()))
		return (NULL);
	while (i < ac)
	{
		flag = is_flag_with_nb(av[i]);
		if (flag)
		{
			if (i + 1 < ac)
			{
				set_opt_flag(opts, flag, ft_atoi(av[++i]));
				flag = 0;
			}
			else
			{
				ft_printf("Can't read source file %s\n", av[i]);
//				ft_putendl("check_opts flag with num not followed by any argument");
				return (NULL);
			}
		}
		else
		{
			if ((flag = open(av[i], O_RDONLY)) == -1)
			{
				ft_printf("Can't read source file %s\n", av[i]);
				return (NULL);
			}
			else
				append_fds_tab(opts, opts->fds_nb, flag);
			opts->fds_nb++;
			flag = 0;
		}
		i++;
	}
	if (!opts->fds)
	{
		ft_putendl("Print Usage here");
		return (NULL);
	}
	return (opts);
}
