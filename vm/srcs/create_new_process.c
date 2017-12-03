#include "corewar.h"

void		initialized_from_scratch(t_play *player, t_proc *process)
{
	int	i;

	i = 2;
	process->reg[0][0] = 0;
	process->reg[0][1] = 0;
	process->reg[1][0] = player->play_live_num[0];
	process->reg[1][1] = player->play_live_num[1];
	while (i < 17)
	{
		process->reg[i][0] = 0;
		process->reg[i][1] = 0;
		i++;
	}
	process->pc = player->idx_start;
	process->carry = 0;
	process->nb_live = 0;
}

void		copy_parent_data(t_proc *parent, t_proc *son)
{
	int	i;

	i = 0;
	while (i <= REG_NUMBER)
	{
		son->reg[i][0] = parent->reg[i][0];
		son->reg[i][1] = parent->reg[i][1];
		i++;
	}
	if (ft_strcmp(parent->exe_op->bdd_op->name, "fork") == 0)
		son->pc = parent->pc + (parent->exe_op->arg1->d_value % IDX_MOD);
	else
		son->pc = parent->exe_op->arg1->d_value % IDX_MOD;
	son->carry = parent->carry;
	son->nb_live = parent->nb_live; // REALLY ??
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
	process->player = player;
	process->exe_op = NULL;
	process->op_success = 0;
	link_it(arena->list_proc, process);
	arena->list_proc->nb_proc++;
	process->process_num = arena->list_proc->nb_proc;
	return (1);
}
