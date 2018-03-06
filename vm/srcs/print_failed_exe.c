#include "corewar.h"


void		print_failed_exe(t_arena *arena, t_exe *exe, int size)
{
	int	i;

	i = 0;
	if (arena->opts->has_v && arena->opts->is_v16)
	{
		ft_printf("ADV %d (0x%.4x -> 0x%.4x) ", size, exe->process->pc, exe->process->pc + size);
		while (i < size)
		{
			ft_printf("%.2x ", arena->mem[find_pc_adv(exe->process->pc, i, 0)]);
			i++;
		}
		ft_putchar('\n');
	}
}
