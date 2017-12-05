#include "corewar.h"

void		print_failed_exe(t_arena *arena, t_exe *exe)
{
	if (arena->opts->has_v && arena->opts->v >= 16)
	{
//		ft_printf("Process num %d\n", exe->process->process_num);
		ft_printf("ADV 2 (%#.4x -> %#.4x) %.2x %.2x\n", exe->process->pc, exe->process->pc + 2, arena->mem[exe->process->pc], arena->mem[exe->process->pc + 1]);
	}
}
