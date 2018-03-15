/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_arena.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 10:22:07 by vbaudron          #+#    #+#             */
/*   Updated: 2018/03/15 12:03:50 by bfruchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		get_cors_no(int ac, char **av)
{
	int	res;
	int	i;

	res = 0;
	i = 1;
	while (i < ac)
	{
		if (is_cor(av[i]))
			res++;
		i++;
	}
	return (res);
}

int		handle_is_cor(int *fds, int i, int *j, char **av)
{
	fds[*j] = open(av[i], O_RDONLY);
	if (fds[*j] == -1)
	{
		free(fds);
		ft_printf("Can't read source file %s\n", av[i]);
		return (0);
	}
	j++;
	return (1);
}

int		*get_fds(t_arena **arena, int ac, char **av)
{
	int		*fds;
	int		i;
	int		j;

	i = 1;
	j = 0;
	fds = NULL;
	(*arena)->nb_players = get_cors_no(ac, av);
	if ((*arena)->nb_players > MAX_PLAYERS)
	{
		ft_putendl("Error : Too many champions");
		return (NULL);
	}
	if (!(fds = (int *)malloc(sizeof(int) * ((*arena)->nb_players))))
		return (NULL);
	while (i < ac)
	{
		if (is_cor(av[i]))
		{
			if (handle_is_cor(fds, i, &j, av) == 0)
				return (NULL);
		}
		i++;
	}
	return (fds);
}

void	close_cors(t_arena *arena)
{
	int i;

	i = 0;
	if (!arena || !arena->files)
		return ;
	while (i < arena->nb_players)
		close(arena->files[i++]->fd);
}

int		create_arena(int ac, char **av, t_arena **arena)
{
	if (!(check_opts(*arena, ac, av)))
		return (0);
	if ((*arena)->nb_players == 0)
		return (print_usage());
	if (create_players(*arena) == 0)
		return (0);
	if (create_mem(*arena) == 0)
		return (0);
	if (create_bdd(*arena) == 0)
		return (0);
	setup_players(*arena);
	if (initialized_start_process(*arena) == 0)
		return (0);
	close_cors(*arena);
	(*arena)->last_player_alive = (*arena)->players[(*arena)->nb_players - 1];
	return (1);
}
