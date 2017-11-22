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
