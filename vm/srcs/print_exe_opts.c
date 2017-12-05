#include "corewar.h"

void		print_exe_opts(t_arena *arena, t_exe *exe)
{
	int	i;

	i = 0;
	if (arena->opts->has_v == 1)
	{
//		ft_printf("Process num %d\n", exe->process->process_num);
		if (arena->opts->v >= 4 && exe->bdd_op->opcode != 16)
		{
			ft_printf("P    %d | %s ", exe->process->process_num, exe->bdd_op->name);
			if (exe->arg1->type == 'r')
				ft_printf("r");
			ft_printf("%d ", exe->arg1->d_value);
			if (exe->arg2)
			{
				if (exe->arg2->type == 'r')
					ft_printf("r");
				ft_printf("%d ", exe->arg2->d_value);
			}
			if (exe->arg3)
			{
			if (exe->arg3->type == 'r')
				ft_printf("r");
			ft_printf("%d", exe->arg3->d_value);
			}
			if (exe->bdd_op->opcode == 9)
			{
				if (exe->process->carry == 1)
					ft_printf("OK");
				else
					ft_printf("KO");
			}
			ft_putchar('\n');
		}
		if (arena->opts->v >= 16 && exe->bdd_op->opcode != 9)
		{
			if (exe->process->pc == 0)
				ft_printf("ADV %d (0x0000 -> %#.4x)", exe->ocp_op->size_adv, exe->process->pc + (exe->ocp_op->size_adv));
			else if (exe->process->pc + (exe->ocp_op->size_adv) == 0)
				ft_printf("ADV %d (%#.4x -> 0x0000)", exe->ocp_op->size_adv, exe->process->pc);
			else
				ft_printf("ADV %d (%#.4x -> %#.4x)", exe->ocp_op->size_adv, exe->process->pc, exe->process->pc + exe->ocp_op->size_adv);
			while (i < exe->ocp_op->size_adv)
			{
				ft_printf(" %.2x", arena->mem[exe->process->pc + i]);
				i++;
			}
			ft_putchar('\n');
		}
	}
}
