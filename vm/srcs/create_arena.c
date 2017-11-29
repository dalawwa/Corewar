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

int		cors_no(int *fds)
{
	int i;

	i = 0;
	while (fds && fds[i] != -1)
		i++;
	return (i);
}

int		*get_fds(t_arena **arena, int ac, char **av)
{
	//  le tableau prend les fds dans l'ordre d'apparition des .cor dans le terminal
	//  On termine le tableau par -1 pour ne pas avoir a se trimballer sans cesse la len de fds, -1 car c'est un invalid fd
	int		*fds;
	int		i;
	int		j;

	(*arena)->nb_players = get_cors_no(ac, av);
	i = 1;
	j = 0;
	fds = NULL;
	if ((*arena)->nb_players > MAX_PLAYERS)
	{
		ft_putendl("Error : Too many champions");
		return (NULL);
	}
	if (!(fds = (int *)malloc(sizeof(int) * ((*arena)->nb_players))))
		return (NULL);
	while (i < ac)
	{
		if (is_cor(av[i])) // gerer les erreurs d'open
		{
			fds[j] = open(av[i], O_RDONLY);
			if (fds[j] == -1)
			{
				free(fds);
				ft_printf("Can't read source file %s\n", av[i]); // meme gestion que la VM de zaz
				return (NULL);
			}
			j++;
		}
		i++;
	}
	return (fds);
}

void		close_cors(int *fds, t_arena *arena)
{
	int i;

	i = 0;
	while (fds && i < arena->nb_players)
		close(fds[i++]);
}

int		 create_arena(int ac, char **av, t_arena **arena)
{
	if ((*arena = (t_arena *)malloc(sizeof(t_arena))) == NULL)
		return (perror_int("Error ", 0));
	if (!((*arena)->opts = check_opts(ac, av)))
	{
		ft_putendl("inside create_arena, check_opts returned NULL");
		return (0);
	}
	if (!((*arena)->fds = get_fds(arena, ac, av)))
	{
		ft_putendl("inside create_arena, get_fds returned NULL");
		return (0);
	}
	if (!create_players(*arena))
	{
		ft_putendl("inside create_arena, create_players returned NULL");
		return (0);
	}
	if (create_mem(*arena) == 0)
	{
		ft_putendl("inside create_arena, create_mem returned NULL");
		return (0);
	}
	if (create_bdd(*arena) == 0)
	{
		ft_putendl("inside create_arena, create_bdd returned NULL");
		return (0);
	}
	setup_players(*arena);
	if (initialized_start_process(*arena) == 0)
	{
		ft_putendl("inside create_arena, initialized_start_process returned 0");
		return (0);
	}
	close_cors((*arena)->opts->fds, *arena);
    return (1);
}
