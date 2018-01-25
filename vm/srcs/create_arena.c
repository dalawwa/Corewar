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

void		close_cors(t_arena *arena)
{
	int i;

	i = 0;
	if (!arena || !arena->files)
		return ;
	while (i < arena->nb_players)
		close(arena->files[i++]->fd);
}

void	set_default_adv(t_arena **arena)
{
	if (!(*arena)->default_adv)
		return ;
	(*arena)->default_adv[0] = 0; // pour garder le meme opcode on commence a [1]
	(*arena)->default_adv[1] = 5;
	(*arena)->default_adv[2] = 7;
	(*arena)->default_adv[3] = 7;
	(*arena)->default_adv[4] = 7;
	(*arena)->default_adv[5] = 7;
	(*arena)->default_adv[6] = 7;
	(*arena)->default_adv[7] = 7;
	(*arena)->default_adv[8] = 7;
	(*arena)->default_adv[13] = 7;
	(*arena)->default_adv[9] = 3;
	(*arena)->default_adv[12] = 3;
	(*arena)->default_adv[14] = 3;
	(*arena)->default_adv[15] = 3;
	(*arena)->default_adv[16] = 3;
}


int		init_arena(t_arena **arena)
{
	if (!(*arena = (t_arena *)malloc(sizeof(t_arena))))
		return (0);
	(*arena)->players = NULL;
	(*arena)->bdd = NULL;
	if (!((*arena)->default_adv = (int *)malloc(sizeof(int) * 17)))
		return (0);
	set_default_adv(arena);
	(*arena)->list_proc = NULL;
	(*arena)->opts = NULL;
	(*arena)->files = NULL;
	(*arena)->nb_players = 0;
	(*arena)->ctd = CYCLE_TO_DIE;
	(*arena)->current_cycle = 0;
	(*arena)->current_nb_check = 0;
	(*arena)->max_check = MAX_CHECKS;
	(*arena)->c_delta = CYCLE_DELTA;
	(*arena)->last_player_alive = 0;
	return (1);
}
int		 create_arena(int ac, char **av, t_arena **arena)
{
//	if (!init_arena(arena))
//		return (perror_int("Error in init_arena", 0));
	if (!(check_opts(*arena, ac, av)))
		return (0);
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
