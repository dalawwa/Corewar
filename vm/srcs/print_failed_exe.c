#include "corewar.h"

void		print_failed_exe(t_arena *arena, t_exe *exe, int size)
{
	int	i;

	i = 0;
	if (arena->opts->has_v && arena->opts->v >= 16)
	{
//		ft_printf("Process num %d\n", exe->process->process_num);
		ft_printf("ADV %d (%#.4x -> %#.4x) ", size, exe->process->pc, find_pc_adv(exe->process, size));
		while (i < size)
		{
			ft_printf("%.2x ", arena->mem[find_pc_adv(exe->process, i)]);
			i++;
		}
		ft_putchar('\n');
	}
}
