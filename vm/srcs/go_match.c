#include "corewar.h"

void	put_starting_facts(t_arena *arena)
{
	int	i;

	i = 0;
	ft_putendl("Introducing contestants...");
	while (i < arena->nb_players)
	{
		ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n", arena->players[i]->play_num, arena->players[i]->size, arena->players[i]->name, arena->players[i]->comment);
		i++;
	}
}

void	go_match(t_arena *arena)
{
	if (arena)
	{
		ft_putendl("\n\n________________go_match it's magic !____________________");
		put_starting_facts(arena);
	}
	else
		ft_putendl("go_match : ARENA = NULL");
}
