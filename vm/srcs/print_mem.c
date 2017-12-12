#include "corewar.h"

void	print_mem(t_arena *arena)
{
	int	i;

	i = 0;
//	ft_putendl("____________print_MEM");
	if (arena)
	{
		while (i < MEM_SIZE)
		{
			if (i == 0)
				ft_printf("0x0000 : ");
			else if (i % 64 == 0)
				ft_printf("%#.4x : ", i);
			ft_printf("%.2x ", arena->mem[i]);
			i++;
			if (i % 64 == 0)
				ft_putchar('\n');
		}
	}
//	ft_putendl("____________print_MEM_END");
}
