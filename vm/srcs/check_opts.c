/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_opts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 10:21:51 by vbaudron          #+#    #+#             */
/*   Updated: 2018/03/15 11:46:00 by bfruchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int				init_opts(t_arena **arena)
{
	if (!((*arena)->opts = (t_opt *)malloc(sizeof(t_opt))))
		return (perror_int("error ", 0));
	(*arena)->opts->has_d = 0;
	(*arena)->opts->has_v = 0;
	(*arena)->opts->has_s = 0;
	(*arena)->opts->has_a = 0;
	(*arena)->opts->has_b = 0;
	(*arena)->opts->d = -1;
	(*arena)->opts->v = -1;
	(*arena)->opts->is_v0 = 1;
	(*arena)->opts->is_v1 = 0;
	(*arena)->opts->is_v2 = 0;
	(*arena)->opts->is_v4 = 0;
	(*arena)->opts->is_v8 = 0;
	(*arena)->opts->is_v16 = 0;
	(*arena)->opts->s = -1;
	(*arena)->opts->a_stealth = 0;
	(*arena)->opts->b_stealth = 0;
	(*arena)->opts->current_s = 0;
	return (1);
}

static int		check_opts_fds(t_file *file, int *flag_indx, char **av)
{
	file->name = addstr(av[flag_indx[1]]);
	if ((file->fd = open(av[flag_indx[1]], O_RDONLY)) == -1)
	{
		ft_printf("Can't read source file %s\n", file->name);
		return (0);
	}
	flag_indx[0] = 0;
	return (1);
}

int				init_files(t_arena *arena)
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
			return (perror_int("Error ", 0));
		arena->files[i]->name = NULL;
		arena->files[i]->fd = -1;
		i++;
	}
	return (1);
}

int				check_opts(t_arena *arena, int ac, char **av)
{
	int		flag_indx[2];

	flag_indx[1] = 1;
	if (!(init_opts(&arena)) || init_files(arena) == 0)
		return (0);
	while (flag_indx[1] < ac)
	{
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
				return (perror_int("Error : Too many champions", 0));
			if (!(check_opts_fds(arena->files[arena->nb_players - 1],
			flag_indx, av)))
				return (0);
		}
		flag_indx[1]++;
	}
	return (1);
}
