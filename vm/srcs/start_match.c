#include "corewar.h"

int		kill_processes_dead(t_arena *arena, t_proc_base *list)
{
	int		i;
	t_proc	*elem;

	if (!list)
		return (1);
	elem = list->last;
	i = 0;
	while (i < list->nb_proc)
	{
		if (arena->ctd < 0 || ((elem->is_process_launched == 0 || elem->nb_live == 0) && arena->total_cycle - elem->creation_cycle >= arena->ctd))
		{
			if (arena->opts->has_v == 1 && arena->opts->is_v8)
				ft_printf("Process %d hasn't lived for %d cycles (CTD %d)\n", elem->process_num, arena->total_cycle - elem->last_cycle_alive, arena->ctd);
			kill_process(elem, list);
			elem = list->last;
			i = 0;
		}
		else
		{
			elem = elem->prev;
			i++;
		}
	}
	return (1);
}

void			put_all_processes_live_zero(t_proc_base *list)
{
	int		i;
	t_proc	*elem;

	i = 0;
	elem = list->first;
	while (i < list->nb_proc)
	{
		elem->nb_live = 0;
		i++;
		elem = elem->next;
	}
}

int		end_of_cycle(t_arena *arena)
{
	arena->current_nb_check++;
	kill_processes_dead(arena, arena->list_proc);
	if (arena->list_proc->nb_proc == 0)
		return (0);
	if (arena->list_proc->nb_live_total >= NBR_LIVE || arena->current_nb_check >= MAX_CHECKS)
	{
		arena->current_nb_check = 0;
		arena->ctd -= CYCLE_DELTA;
		if (arena->opts->has_v == 1 && arena->opts->is_v2)
			ft_printf("Cycle to die is now %d\n", arena->ctd);
	}
	put_all_processes_live_zero(arena->list_proc);
	arena->list_proc->nb_live_total = 0;
	arena->current_cycle = 0;
	return (1);
}

void	handle_s_opt(t_arena *arena)
{
	if (arena->opts->has_s == 1)
	{
		if (arena->opts->s == arena->opts->current_s)
		{
			print_mem(arena);
			arena->opts->current_s = 0;
		}
		else
			arena->opts->current_s++;
	}
}

int		start_match(t_arena *arena)
{
	if (arena->opts->has_d == 1 && arena->opts->d == 0)
	{
		print_mem(arena);
		return (1);
	}
	handle_s_opt(arena);
	while (arena && arena->list_proc && arena->list_proc->nb_proc > 0)
	{
		arena->total_cycle++;
		arena->current_cycle++;
		if (arena->opts->has_v == 1 && arena->opts->is_v2)
			ft_printf("It is now cycle %d\n", arena->total_cycle);
		if (deal_exe(arena) == 0)
			return (-1);
		if (arena->current_cycle == arena->ctd || arena->ctd < 0)
		{
			if (end_of_cycle(arena) == 0)
				break ;
		}
		if (arena->opts->has_d == 1 && arena->total_cycle == arena->opts->d)
		{
			print_mem(arena);
			return (1);
		}
	}
	ft_printf("Contestant %d, \"%s\", has won !\n", arena->last_player_alive->play_num, arena->last_player_alive->name);
	return (1);
}