#include "corewar.h"


void		print_failed_exe(t_arena *arena, t_exe *exe, int size)
{
	int	i;

	i = 0;
//	if (!arena || !exe || !exe->ocp_op)
//		return ;
	if (arena->opts->has_v && arena->opts->is_v16)
	{
//		ft_printf("Process num %d\n", exe->process->process_num);
		ft_printf("ADV %d (%#.4x -> %#.4x) ", size, exe->process->pc, find_pc_adv(exe->process->pc, size, 0));
		while (i < size)
		{
			ft_printf("%.2x ", arena->mem[find_pc_adv(exe->process->pc, i, 0)]);
			i++;
		}
		ft_putchar('\n');
	}
}
