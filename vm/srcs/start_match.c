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
		// OLD
		// if (arena->ctd < 0 || (elem->parent == NULL && elem->nb_live == 0 && arena->total_cycle - elem->creation_cycle >= arena->ctd) || (elem->parent != NULL && (elem->is_process_launched == 0 || elem->nb_live == 0) && arena->total_cycle - elem->parent_last_live >= arena->ctd))
		
		// NEW
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

int		deal_exe(t_arena *arena)
{
	int		i;
	int		failed_adv;
	t_proc	*elem;

	i = 0;
	failed_adv = 0;
	elem = arena->list_proc->last;
	while (i < arena->list_proc->nb_proc)
	{
		if (!elem || elem->exe_op == NULL)
		{
			if (is_valid_op(arena, elem) == 1)
			{
				create_new_exe(arena, elem);
				elem->exe_op->to_wait--;
			}
			else
				inc_pc(elem, 1);
		}
		if (elem->exe_op)
		{
			if (elem->exe_op->to_wait == 0)
			{
				fill_new_exe(arena, elem);
				if (elem->is_process_launched == 0)
					elem->is_process_launched = 1;
				if (elem->exe_op->ocp_op != NULL)
				{
					if (elem->exe_op->ocp_op->fct != NULL)
						elem->exe_op->ocp_op->fct(arena, elem->exe_op);
					if (elem->exe_op->opcode != 9)
						inc_pc(elem, elem->exe_op->ocp_op->size_adv);
				}
				else
				{
					failed_adv = count_failed_adv(arena, elem->exe_op);
					print_failed_exe(arena, elem->exe_op, failed_adv);
					inc_pc(elem, failed_adv);
				}
				free_exe(elem->exe_op, elem);
			}
			else
				elem->exe_op->to_wait--;
		}
		i++;
		elem = elem->prev;
		if (i < arena->list_proc->nb_proc && elem == NULL)
			return (1);
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

int		start_match(t_arena *arena)
{
	if (!arena || !arena->opts)
		return (0);
	if (arena->opts->has_d == 1 && arena->opts->d == 0)
	{
		print_mem(arena);
		return (1);
	}
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
//			ft_printf("arena->ctd : %d - arena->current_Cycle : %d\n",arena->ctd, arena->current_cycle);
			arena->current_nb_check++;
			kill_processes_dead(arena, arena->list_proc);
			if (arena->list_proc->nb_proc == 0)
				break ;
			if (arena->list_proc->nb_live_total >= NBR_LIVE || arena->current_nb_check >= MAX_CHECKS)
			{
//				ft_printf("arena->list_proc->nb_live_total : %d >= NBR_LIVE : %d ||\narena->current_nb_check : %d >= MAX_CHECKS : %d\n",arena->list_proc->nb_live_total, NBR_LIVE, arena->current_nb_check, MAX_CHECKS);
				arena->current_nb_check = 0;
				arena->ctd -= CYCLE_DELTA;
				if (arena->opts->has_v == 1 && arena->opts->is_v2)
					ft_printf("Cycle to die is now %d\n", arena->ctd);
			}
			put_all_processes_live_zero(arena->list_proc);
			arena->list_proc->nb_live_total = 0;
			arena->current_cycle = 0;
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