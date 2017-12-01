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
				ft_putendl("\nPROCESS AVANT OP :");
				print_one_process(elem);
				if (elem->exe_op->ocp_op->fct != NULL)
					elem->exe_op->ocp_op->fct(arena, elem->exe_op);
				else
					ft_putendl("OP Not linked - But everything is allright");
				elem->pc += elem->exe_op->ocp_op->size_adv;
				free_exe(elem->exe_op, elem);
				ft_putendl("\nPROCESS APRES OP :");
				print_one_process(elem);
			}
		}
		else
		{
//			ft_printf("Cycle %d :\n Process %d\n", arena->total_cycle, elem->process_num);
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
	ft_putendl("Let's the MATCH begins ...");
	ft_printf("There is %d process to start\n", arena->list_proc->nb_proc);
	while (arena->list_proc->nb_proc > 0)
	{
//		ft_printf("Cycle %d :\n", arena->total_cycle);
		if (arena->current_cycle == arena->ctd)
		{
			arena->ctd -= CYCLE_DELTA;
			arena->current_cycle = 0;
			kill_processes_dead(arena->list_proc);
		}
		deal_exe(arena);
		arena->current_cycle++;
		arena->total_cycle++;
		if (arena->opts->has_d == 1 && arena->total_cycle == arena->opts->d)
		{
			print_mem(arena);
			return (1);
		}
	}
	ft_putendl("End of MATCH");
	return (1);
}

/* TODOs
 * les MAX_CHECKS ne sont pas pris en comptent
 */
