#include "corewar.h"

void print_tab_cors(int *tab)
{
	int i;

	i = 0;
	ft_putendl("print_tab_cors");
	while (tab && tab[i] != -1)
	{
		ft_putnbr(tab[i]);
		i++;
		if (tab[i] != -1)
			ft_putstr(" - ");
	}
	ft_putendl("\nprint_tab_cors__END");
}

void	print_arena_fds(t_arena *arena)
{
	int i;

	i = 0;
	ft_putendl("inside print_arena_fds");
	while (arena->fds && arena->fds[i] != -1)
		ft_printf("%d - ", arena->fds[i++]);
	ft_putchar('\n');
}

void print_players(t_play *players, int nb_players)
{
	int		i;

	i = 0;
	ft_putendl("print_players");
	while (i < nb_players)
	{
		ft_printf("\nPLAYER %d :\nName = _%s_\nComment = _%s_\nBody = _%s_\n", players[i].play_no, players[i].name, players[i].comment, players[i].body);
		i++;
	}
	ft_putendl("\nprint_players__END");
}

void	print_arena(t_arena *arena)
{
	if (!arena)
		return ;
	ft_putendl("Inside print_arena");
	print_arena_fds(arena);
}

void print_usage(void)
{
	ft_putendl("print usage");
}
