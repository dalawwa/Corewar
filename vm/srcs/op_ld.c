#include "corewar.h"

void	print_ld(t_arena *arena, t_exe *exe)
{
	int	i;

	i = 0;
	if (arena->opts->is_v4)
	{
		ft_printf("P    %d | %s ", exe->process->process_num, exe->bdd_op->name);
		ft_printf("%d ", exe->arg1->d_data);
		ft_printf("r%hd\n", (short int)exe->arg2->d_value);
	}
	if (arena->opts->is_v16)
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


int		op_ld(t_arena *arena, t_exe *exe)
{
	print_ld(arena, exe);
	if (exe->arg1->type != 'd' && exe->arg1->d_value > IDX_MOD)
	{
		exe->arg1->d_value = exe->arg1->d_value % IDX_MOD;
		free(exe->arg1->value);
		exe->arg1->value = ft_ito_hexa(exe->arg1->d_value);
	}
	/*	if (exe->arg1->type == 'd')
		{
		exe->process->reg[exe->arg2->d_value][0] = exe->arg1->value[0];
		exe->process->reg[exe->arg2->d_value][1] = exe->arg1->value[1];
		exe->process->reg[exe->arg2->d_value][2] = exe->arg1->value[2];
		exe->process->reg[exe->arg2->d_value][3] = exe->arg1->value[3];
		}
		else
		{*/
	exe->process->reg[exe->arg2->d_value][0] = exe->arg1->data[0];
	exe->process->reg[exe->arg2->d_value][1] = exe->arg1->data[1];
	exe->process->reg[exe->arg2->d_value][2] = exe->arg1->data[2];
	exe->process->reg[exe->arg2->d_value][3] = exe->arg1->data[3];
	//	}
	is_carry_to_modify(exe);
	return (1);
}

// + 1 + 2 + 3 ATTENTION si mem[arg1->d_value + 3] > IDX_MOD_MOD
