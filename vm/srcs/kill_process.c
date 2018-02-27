#include "corewar.h"

void	print_all_process_short_way(t_proc_base *list)
{
	int	i;
	t_proc	*elem;

	i = 0;
	if (!list)
		return ;
	elem = list->first;
	ft_printf("There is %d Process\n", list->nb_proc);
	while (i < list->nb_proc)
	{
		ft_printf("Process %d\n", elem->process_num);
		elem = elem->next;
		i++;
	}
	ft_putendl("END of Print");
}

void	free_arg(t_arg *arg)
{
	if (arg)
	{
		if (arg->value)
			free(arg->value);
		arg->value = NULL;
		if (arg->data)
			free(arg->data);
		arg->data = NULL;
		free(arg);
		arg = NULL;
	}
}

void	free_exe(t_exe *exe, t_proc *process)
{
	if (exe)
	{
		if (exe->size_failed_adv == 0)
		{
			if (exe->arg1)
				free_arg(exe->arg1);
			if (exe->arg2)
			{
				free_arg(exe->arg2);
				if (exe->arg3)
					free_arg(exe->arg3);
			}
		}
		exe->bdd_op = NULL;
		exe->ocp_op = NULL;
		free(exe);
		exe = NULL;
		process->exe_op = NULL;
	}
}

void	free_process(t_proc *to_kill)
{
	if (to_kill)
	{
		to_kill->player = NULL;
		if (to_kill->exe_op)
			free_exe(to_kill->exe_op, to_kill);
		to_kill->next = NULL;
		to_kill->prev = NULL;
		free(to_kill);
		to_kill = NULL;
	}
}

void	kill_first(t_proc *to_kill, t_proc_base *list)
{
	if (list->last == list->first)
	{
		list->first = NULL;
		list->last = NULL;
	}
	else
	{
		list->first = to_kill->next;
		list->first->prev = NULL;
	}
	free_process(to_kill);
}

void	kill_last(t_proc *to_kill, t_proc_base *list)
{
	list->last = to_kill->prev;
	list->last->next = NULL;
	free_process(to_kill);
}

void		kill_process(t_proc *to_kill, t_proc_base *list_proc)
{
	if (to_kill)
	{
//		ft_printf("\nProcess to Kill num %d\nSTART:\n", to_kill->process_num);
//		print_all_process_short_way(list_proc);
		if (list_proc->first == to_kill)
			kill_first(to_kill, list_proc);
		else if (list_proc->last == to_kill)
			kill_last(to_kill, list_proc);
		else
		{
			to_kill->next->prev = to_kill->prev;
			to_kill->prev->next = to_kill->next;
			free_process(to_kill);
		}
		list_proc->nb_proc--;
//		ft_printf("END :\n");
//		print_all_process_short_way(list_proc);
//		ft_printf("Process KILLED\n");
	}
}
