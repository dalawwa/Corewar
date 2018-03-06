#include "corewar.h"

void		print_proc_num_name(t_exe *exe)
{
	if (exe->process->process_num < 1000)
	{
		ft_putchar('P');
		put_n_char(' ', 5 - intlen((short)exe->process->process_num));
		ft_printf("%d | %s ", exe->process->process_num, exe->bdd_op->name);
	}
	else
		ft_printf("P %d | %s ", exe->process->process_num, exe->bdd_op->name);
}

void		print_exe_opts(t_arena *arena, t_exe *exe)
{
	int	i;

	i = 0;
	if (arena->opts->has_v == 1)
	{
		if (arena->opts->is_v16)
		{
			if (exe->process->pc == 0)
				ft_printf("ADV %d (0x0000 -> %#.4x) ", exe->ocp_op->size_adv, exe->process->pc + (exe->ocp_op->size_adv));
			else if (exe->process->pc + (exe->ocp_op->size_adv) == 0)
				ft_printf("ADV %d (0x%.4x -> 0x0000) ", exe->ocp_op->size_adv, exe->process->pc);
			else
				ft_printf("ADV %d (0x%.4x -> 0x%.4x) ", exe->ocp_op->size_adv, exe->process->pc, exe->process->pc + exe->ocp_op->size_adv);
			while (i < exe->ocp_op->size_adv)
			{
					ft_printf("%.2x ", arena->mem[get_adv(exe->process->pc + i)]);
				i++;
			}
			ft_putchar('\n');
		}
	}
}
