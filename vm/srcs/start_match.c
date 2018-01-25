#include "corewar.h"

int		kill_processes_dead(t_arena *arena, t_proc_base *list)
{
	int		i;
	t_proc	*elem;

	elem = list->last;
	i = 0;
	while (i < list->nb_proc)
	{
		if (elem->nb_live == 0)
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
/*		if (arena->total_cycle > 222)
		{
			ft_printf("Process %d : pc = %d ", elem->process_num, elem->pc);
			if (elem->exe_op != NULL)
				ft_printf("exe = %s - to wait = %d\n", elem->exe_op->bdd_op->name, elem->exe_op->to_wait);
			else
				ft_putchar('\n');
		}*/
		if (elem->exe_op == NULL)
		{
//			ft_printf("Cycle %d -- Process NUM = %d Process->PC = %d\n", arena->current_cycle, elem->process_num, elem->pc);
			if (is_valid_op(arena, elem) == 1)
			{
				create_new_exe(arena, elem, NULL);
				elem->exe_op->to_wait--;
			}
			else
			{
				if (elem->exe_op && elem->exe_op->bdd_op->opcode == 15)
					ft_printf("to_wait = %d\n", elem->exe_op->to_wait);
				inc_pc(elem, 1);
//			ft_printf("ELSE Cycle %d -- INCREASE Process->PC = %d\n", arena->current_cycle, elem->pc);
			}
		}
		if (elem->exe_op)
		{
			if (elem->exe_op->to_wait == 0)
			{
				if (elem->exe_op->ocp_op != NULL)
				{
					if (elem->exe_op->ocp_op->fct != NULL)
					{
						if (arena->opts->has_b == 1)
						{
							ft_putendl("______________Process AVANT OP_____________");
							print_one_process(elem);
						}
						elem->exe_op->ocp_op->fct(arena, elem->exe_op);
						if (arena->opts->has_b == 1)
						{
							ft_putendl("______________Process APRES OP_____________");
							print_one_process(elem);
						}
					}
					else
						ft_putendl("OP Not linked - But everything is allright");
				}
				if (elem->exe_op->ocp_op != NULL)
				{
					if (elem->exe_op->opcode != 9)
						inc_pc(elem, elem->exe_op->ocp_op->size_adv);
				}
				else
				{
//					failed_adv = count_failed_adv(arena, elem->exe_op);
					failed_adv = get_failed_adv_size(elem->exe_op);
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
		{
//			ft_printf("deal_exe killed by 1 nb_proc = %d\n",arena->list_proc->nb_proc);
			return (1);
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

int		start_match(t_arena *arena)
{
//	ft_putendl("Let's the MATCH begins ...");
//	ft_printf("There is %d process to start\n", arena->list_proc->nb_proc);
	if (arena->opts->has_d == 1 && arena->opts->d == 0)
	{
		print_mem(arena);
		return (1);
	}
	while (arena->list_proc->nb_proc > 0)
	{
		arena->total_cycle++;
		arena->current_cycle++;
		if (arena->opts->has_v == 1 && arena->opts->is_v2)
			ft_printf("It is now cycle %d\n", arena->total_cycle);
		if (arena->current_cycle == arena->ctd)
		{
			arena->current_nb_check++;
			kill_processes_dead(arena, arena->list_proc);
			if (arena->list_proc->nb_proc == 0)
				break ;
			if (arena->list_proc->nb_live_total >= NBR_LIVE || arena->current_nb_check >= MAX_CHECKS)
			{
				arena->current_nb_check = 0;
				arena->ctd -= CYCLE_DELTA;
				if (arena->opts->has_v == 1 && arena->opts->is_v2)
					ft_printf("Cycle to die is now %d\n", arena->ctd);
			}
			put_all_processes_live_zero(arena->list_proc);
			arena->current_cycle = 0;
		}
		if (deal_exe(arena) == 0)
			return (-1);
		if (arena->opts->has_d == 1 && arena->total_cycle == arena->opts->d)
		{
			print_mem(arena);
			return (1);
		}
	//	arena->current_cycle++;
	//	arena->total_cycle++;
	}
	ft_printf("Contestant %d, \"%s\", has won !\n", arena->last_player_alive->play_num, arena->last_player_alive->name);
//	ft_putendl("End of MATCH");
	return (1);
}

/* TODOs
 * les MAX_CHECKS ne sont pas pris en comptent
 */
