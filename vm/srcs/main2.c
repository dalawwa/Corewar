#include "corewar.h"
// coucou on fout le bordel
void	print_tab_cors(int *tab, int len)
{
	int	i;

	i = 2;
	ft_putendl("print_tab_cors");
	while (tab != NULL && i < len)
	{
		ft_putnbr(tab[i]);
		i++;
		if (i < len)
			ft_putstr(" - ");
	}
	ft_putendl("\nprint_tab_cors__END");
}

void	print_players(t_play *players, int nb_players)
{
	int	i;

	i = 0;
	ft_putendl("print_players");
	while (i < nb_players)
	{
		ft_printf("\nPLAYER %d :\nName = _%s_\nComment = _%s_\nBody = _%s_\n", players[i].play_no, players[i].name, players[i].comment, players[i].body);
		i++;
	}
	ft_putendl("\nprint_players__END");
}
/*
void	print_arg(int ac, char **av)
{
	int	i;

	i = 0;
	ft_printf("print_arg\nac = %d\n", ac);
	while (i < ac)
	{
		ft_putendl(av[i]);
		i++;
	}
	ft_putendl("print_players__END");
}*/

int		main(int ac, char **av)
{
	t_opt	*opt;
	int		*tab;
	int		nb_cors;
	t_play	*players;

	opt = NULL;
	tab = NULL;
	nb_cors = 0;
	if (ac == 1)
		ft_putstr("usage\n");
	else
	{
//		print_arg(ac, av);
		if (!(check_opts(ac, av, &opt)))
		{
			ft_putendl("check_opts == 0");
			return (0);
		}
		else
		{
			nb_cors = get_nb_cors(ac, av, &tab);
			if (nb_cors <= 0)
				return (0);
			if (tab)
				print_tab_cors(tab, nb_cors);
			players = create_players(tab, nb_cors);
			if (players)
				print_players(players, nb_cors);
		}
		free(tab);
		free(players);
	}
	return (0);
}
