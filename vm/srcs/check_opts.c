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

int		init_opts(t_arena *arena)
{
	if (!(arena->opts = (t_opt *)malloc(sizeof(t_opt))))
		return (perror_int("error ", 0));
	arena->opts->has_d = 0;
	arena->opts->has_v = 0;
	arena->opts->has_s = 0;
	arena->opts->has_a = 0;
	arena->opts->has_b = 0;
	arena->opts->d = -1;
	arena->opts->v = -1;
	arena->opts->s = -1;
	arena->opts->a_stealth = 0;
	arena->opts->b_stealth = 0;
	return (1);
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
/*
static void		append_fds_tab(t_opt *opts, int i, int size, int val)
{
	// free_leaks
	int j;
	int	old;

	j = 0;
	old = opts->files[i]->fd;
	opts->files[i]->fd = NULL;
	if (size < 0)
		return ;
//	if (!(opts->files[i]->fd = (int *)malloc(sizeof(int) * (size + 1))))
		return ;
	while (j < size)
	{
		opts->files[i]->fd = old;
		i++;
	}
	opts->files[i]->fd[size] = val;
	free(old);
	old = NULL;
}*/

static int		check_opts_flags(t_opt *opts, int *flag_indx, int ac, char **av)
{
	if (flag_indx[0] < 4 && flag_indx[0] > 0 && flag_indx[1] + 1 >= ac)
	{
		ft_printf("Can't read source file %s\n", av[flag_indx[1]]);
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

static int			check_opts_fds(t_file *file, int *flag_indx, char **av)
{
//	opts->files[i] = (t_file *)malloc(sizeof(t_file));
//	if (opts->files[i] == NULL)
//		return (perror_int("Error ", 0));
	file->name = addstr(av[flag_indx[1]]);
	if ((file->fd = open(av[flag_indx[1]], O_RDONLY)) == -1)
	{
		ft_printf("Can't read source file %s\n", file->name);
		return (0);
	}
//	else
//		append_fds_tab(opts, opts->fds_nb, flag_indx[0]);
//	opts->fds_nb++;
	flag_indx[0] = 0;
	return (1);
}

int		init_files(t_arena *arena)
{
	int	i;

	i = 0;
	arena->files = malloc(sizeof(t_file*) * 4);
	if (arena->files == NULL)
		return (perror_int("Error ", 0));
	while (i < 4)
	{
		arena->files[i] = malloc(sizeof(t_file));
		if (arena->files[i] == NULL)
			return(perror_int("Error ", 0));
		arena->files[i]->name = NULL;
		arena->files[i]->fd = -1;
		i++;
	}
	return (1);
}

int		check_opts(t_arena *arena, int ac, char **av)
{
	// free_leaks;
	int		flag_indx[2];

	flag_indx[1] = 1;
	if (!(init_opts(arena)))
		return (0);
	if (init_files(arena) == 0)
		return (0);
	while (flag_indx[1] < ac)
	{
//		ft_printf("flag_indx[1] = %d - ac = %d arena->nb_players = %d\n", flag_indx[1], ac, arena->nb_players);
		flag_indx[0] = is_flag(av[flag_indx[1]]);
		if (flag_indx[0] < 6 && flag_indx[0] > 0)
		{
			if (!(check_opts_flags(arena->opts, flag_indx, ac, av)))
				return (0);
		}
		else
		{
			arena->nb_players++;
			if (arena->nb_players > 4)
			{
				ft_putendl("Error : Too many champions");
				return (0);
			}
			if (!(check_opts_fds(arena->files[arena->nb_players - 1], flag_indx, av)))
				return (0);
		}
		flag_indx[1]++;
	}
//	arena->nb_players++;
	if (arena->nb_players == 0)
	{
		ft_putendl("Print Usage here");
		return (0);
	}
	return (1);
}
