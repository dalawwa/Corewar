#include "corewar.h"

void		initialized_reg(t_play *player, t_proc *process)
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
}

void		initialized_from_scratch(t_play *player, t_proc *process)
{
	initialized_reg(player, process);
	process->parent = NULL;
	process->pc = player->idx_start;
	process->carry = 0;
	process->nb_live = 0;
	process->last_cycle_alive = 0;
	process->is_process_launched = 1;
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
	process->creation_cycle = arena->total_cycle;
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
