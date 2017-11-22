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

int		*get_fds(t_arena *arena, int ac, char **av)
{
	//  le tableau prend les fds dans l'ordre d'apparition des .cor dans le terminal
	//  On termine le tableau par -1 pour ne pas avoir a se trimballer sans cesse la len de fds, -1 car c'est un invalid fd
	int		*fds;
	int		i;
	int		j;

	arena->nb_players = get_cors_no(ac, av);
	i = 1;
	j = 0;
	if (arena->nb_players > MAX_PLAYERS)
	{
		ft_putendl("Error : Too many champions");
		return (NULL);
	}
	if (!(fds = (int *)malloc(sizeof(int) * (arena->nb_players))))
		return (NULL);
	while (i < ac)
	{
		if (is_cor(av[i])) // gerer les erreurs d'open
		{
			fds[j] = open(av[i], O_RDONLY);
			if (fds[j] == -1)
			{
				free(fds);
				ft_putendl("Error : Failed to open");
				return (NULL);
			}
			j++;
		}
		i++;
	}
	return (fds);
}

void		close_cors(int *fds)
{
	int i;

	i = 0;
	while (fds && fds[i] != -1)
		close(fds[i++]);
}

t_arena *create_arena(int ac, char **av)
{
	t_arena *arena;

	if (!(arena = (t_arena *)malloc(sizeof(t_arena))))
		return (NULL);
	if (!(arena->opts = check_opts(ac, av)))
	{
		ft_putendl("inside create_arena, check_opts returned NULL");
		return (NULL);
	}
	if (!(arena->fds = get_fds(arena, ac, av)))
	{
		ft_putendl("inside create_arena, get_fds returned NULL");
		return (NULL);
	}
	if (!create_players(arena))
	{
		ft_putendl("inside create_arena, create_players returned NULL");
		return (NULL);
	}
	//     // ensuite on créée la mémoire dans arena et on load les champs dedans
	close_cors(arena->fds);
    return (arena);
}
