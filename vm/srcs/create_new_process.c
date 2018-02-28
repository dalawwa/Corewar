#include "corewar.h"

void		initialized_from_scratch(t_play *player, t_proc *process)
{
	int	i;

	i = 2;
	process->reg[0][0] = 0;
	process->reg[0][1] = 0;
	process->reg[0][2] = 0;
	process->reg[0][3] = 0;
	process->reg[1][0] = 0;
	process->reg[1][1] = 0;
	process->reg[1][0] = player->play_live_num[0];
	process->reg[1][1] = player->play_live_num[1];
	process->reg[1][2] = player->play_live_num[2];
	process->reg[1][3] = player->play_live_num[3];
	while (i < 17)
	{
		process->reg[i][0] = 0;
		process->reg[i][1] = 0;
		process->reg[i][2] = 0;
		process->reg[i][3] = 0;
		i++;
	}
	process->parent = NULL;
	process->pc = player->idx_start;
	process->carry = 0;
	process->nb_live = 0;
	process->last_cycle_alive = 0;
	process->is_process_launched = 1;
	process->parent_last_live = 0;
}

void		copy_parent_data(t_proc *parent, t_proc *son)
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
	son->pc = parent->pc;
	son->parent = parent;
	if (ft_strcmp(parent->exe_op->bdd_op->name, "fork") == 0)
	{
//		ft_printf("d_value %d\n", parent->exe_op->arg1->d_value);
		if (parent->exe_op->arg1->d_value > 0x7fff)
			son->pc = (short)((parent->exe_op->arg1->d_value + parent->pc) - 0x10000) % IDX_MOD;
		else
			son->pc = (short)(parent->exe_op->arg1->d_value + parent->pc) % IDX_MOD;
		son->is_process_launched = 0;
//			inc_pc(son, parent->exe_op->arg1->d_value);
//		else
//			inc_pc(son, parent->exe_op->arg1->d_value);
	}
	else if (ft_strcmp(parent->exe_op->bdd_op->name, "lfork") == 0)
	{
		inc_pc(son, parent->exe_op->arg1->d_value);
		son->is_process_launched = 0;
	}
	else
		ft_putendl("Something Wrong with creation EXE with Parent");
	son->carry = parent->carry;
//	ft_printf("New Process : parent pc = %d new pc = %d\n", parent->pc, son->pc);
	son->nb_live = 0; // REALLY ??
	son->last_cycle_alive = 0;
	son->parent_last_live = parent->last_cycle_alive;
}

void		link_it(t_proc_base *list, t_proc *process)
{
	if (list->last == NULL)
	{
		process->prev = NULL;
		process->next = NULL;
		list->first = process;
		list->last = process;
	}
	else
	{
		list->last->next = process;
		process->prev = list->last;
		list->last = process;
		process->next = NULL;
	}
}

int			initialized_proc_base(t_arena *arena)
{
	arena->list_proc = (t_proc_base *)malloc(sizeof(t_proc_base));
	if (arena->list_proc == NULL)
		return (perror_int("Error ", 0));
	arena->list_proc->first = NULL;
	arena->list_proc->last = NULL;
	arena->list_proc->nb_proc = 0;
	arena->list_proc->total_proc = 0;
	arena->list_proc->nb_live_total = 0;
	return (1);
}

int			create_new_process(t_arena *arena, t_play *player, t_proc *parent)
{
	t_proc	*process;

	process = (t_proc *)malloc(sizeof(t_proc));
	if (process == 0)
		return (perror_int("Error ", 0));
	if (arena->list_proc == NULL && initialized_proc_base(arena) == 0)
		return (0);
	if (parent != NULL)
		copy_parent_data(parent, process);
	else
		initialized_from_scratch(player, process);
	process->next = NULL;
	process->prev = NULL;
	process->player = player;
	process->exe_op = NULL;
	process->op_success = 0;
	link_it(arena->list_proc, process);
	arena->list_proc->nb_proc++;
	arena->list_proc->total_proc++;
	process->process_num = arena->list_proc->total_proc;
	return (1);
}
