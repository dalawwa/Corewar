#include "corewar.h"

void print_tab_cors(int *tab, int len)
{
	int i;

	i = 0;
	ft_putendl("print_tab_c		ors");
	while (tab != NULL && i < len)
	{
		ft_putnbr(tab[i]);
		i++;
		if (i < len)
			ft_putstr(" - ");
	}
	ft_putendl("\nprint_tab_cors__END");
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

void print_usage(void)
{
	ft_putendl("print usage");
}
