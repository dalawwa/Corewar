#include "corewar.h"

void		initialized_from_scratch(t_play *player, t_proc *process)
{
	int	i;

	i = 2;
	process->reg[0] = 0;
	process->reg[1] = player->play_live_num;
	while (i < 17)
	{
		process->reg[i] = 0;
		i++;
	}
	process->pc = 0;
	process->carry = 0;

}

void		copy_parent_data(t_proc *parent, t_proc *son)
{
	int	i;

	i = 0;
	while (i < 17)
	{
		son->reg[i] = parent->reg[i];
		i++;
	}
	son->pc = parent->pc;
	son->carry = parent->carry;
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
