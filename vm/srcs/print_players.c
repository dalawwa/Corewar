#include "corewar.h"

void	print_one_player(t_play *player)
{
	int	i;

	i = 0;
	if (player)
	{
		ft_printf("Player Numero %d\n", player->play_num);
		ft_printf("Name = _%s_\n", player->name);
		ft_printf("Size = _%d_\n", player->size);
		ft_printf("Idx_start = _%d_\n", player->idx_start);
		ft_printf("Comment = _%s_\n", player->comment);
		ft_printf("Body_len = _%d_\n", player->body_len);
		ft_printf("Body = ");
		while (i < player->body_len)
		{
			ft_printf("%.2x", (unsigned char)player->body[i]);
			i++;
			if (i < player->body_len)
				ft_printf("%.2x ", (unsigned char)player->body[i]);
			i++;
		}
	}
}

void	print_players(t_arena *arena)
{
	int	i;

	i = 0;
	ft_putendl("print_players");
	if (arena != NULL)
	{
		ft_printf("There is %d Champion(s) to print !\n", arena->nb_players);
		while (i < arena->nb_players)
		{
//			ft_printf("try to print player i = %d\n", i + 1);
			print_one_player(arena->players[i]);
			ft_putchar('\n');
			i++;
		}
	}
	ft_putendl("print_players__END");
}
