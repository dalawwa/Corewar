#include "corewar.h"

int		kill_processes_dead(t_proc_base *list)
{
	int		i;
	t_proc	*elem;

	elem = list->first;
	i = 0;
	while (i < list->nb_proc)
	{
		if (elem->nb_live == 0)
		{
			kill_process(elem, list);
			elem = list->first;
			i = 0;
		}
		else
			i++;
	}
	return (1);
}

void		deal_exe(t_arena *arena)
{
	int		i;
	t_proc	*elem;

	i = 0;
	elem = arena->list_proc->first;
	while (i < arena->list_proc->nb_proc)
	{
		if (elem->exe_op)
		{
			elem->exe_op->to_wait--;
			if (elem->exe_op->to_wait == 0)
			{
				elem->exe_op->ocp_op->fct(arena, elem->exe_op);
				elem->pc += elem->exe_op->ocp_op->size_adv;
				free_exe(elem->exe_op, elem);
			}
		}
		else
		{
			if (is_valid_op(arena, elem) == 1)
				create_new_exe(arena, elem, NULL);
			else
				elem->pc++;
		}
		i++;
		elem = elem->next;
	}
}

int		start_match(t_arena *arena)
{
	while (arena->list_proc->nb_proc > 0)
	{
		if (arena->current_cycle == arena->ctd)
		{
			arena->ctd -= CYCLE_DELTA;
			arena->current_cycle = 0;
			kill_processes_dead(arena->list_proc);
		}
		deal_exe(arena);
		arena->current_cycle++;
		arena->total_cycle++;
	}
	return (1);
}
