#include "corewar.h"

int		op_zjmp(t_arena *arena, t_exe *exe)
{
	if (arena->opts->is_v4)
	{
		print_proc_num_name(exe);
		ft_printf("%hd", (short)exe->arg1->d_value);
		if (exe->process->carry == 1)
			ft_printf(" OK\n");
		else
		{
			ft_printf(" FAILED\n");
			print_exe_opts(arena, exe);
		}
	}
	if (exe->process->carry == 1)
	{
		inc_pc(exe->process, (short)exe->arg1->d_value % IDX_MOD); // % IDX_MOD ???
		return (1);
	}
	inc_pc(exe->process, 3);
	return (0);
}
