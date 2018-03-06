#include "corewar.h"

void    initialized_reg_from_parent(t_proc *parent, t_proc *son)
{
    int	i;

	i = 0;
	while (i <= REG_NUMBER)
	{
		son->reg[i][0] = parent->reg[i][0];
		son->reg[i][1] = parent->reg[i][1];
		son->reg[i][2] = parent->reg[i][2];
		son->reg[i][3] = parent->reg[i][3];
		i++;
	}
}

void		copy_parent_data(t_proc *parent, t_proc *son)
{
    initialized_reg_from_parent(parent, son);
	son->pc = parent->pc;
	son->parent = parent;
	if (ft_strcmp(parent->exe_op->bdd_op->name, "fork") == 0)
	{
		if (parent->exe_op->arg1->d_value < 0x8000)
			son->pc = (short)(parent->exe_op->arg1->d_data % IDX_MOD + parent->pc);
		else
			son->pc = (short)(parent->exe_op->arg1->d_value + parent->pc);
		son->is_process_launched = 0;
	}
	else if (ft_strcmp(parent->exe_op->bdd_op->name, "lfork") == 0)
	{
		inc_pc(son, parent->exe_op->arg1->d_value);
		son->is_process_launched = 0;
	}
	son->carry = parent->carry;
	son->nb_live = 0;
	son->last_cycle_alive = parent->last_cycle_alive;
    son->creation_cycle = parent->last_cycle_alive;
}