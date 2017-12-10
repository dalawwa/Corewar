#include "corewar.h"

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
		free_arg(exe->arg1);
		free_arg(exe->arg2);
		free_arg(exe->arg3);
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
//	ft_printf("Process to Kill num %d\n", to_kill->process_num);
	list->last = to_kill->prev;
//	ft_printf("List->last->num %d\n", list->last->process_num);
	list->last->next = NULL;
	free_process(to_kill);
}

void		kill_process(t_proc *to_kill, t_proc_base *list_proc)
{
	if (to_kill)
	{
		if (list_proc->first == to_kill)
			kill_first(to_kill, list_proc);
		else if (list_proc->last == to_kill)
			kill_last(to_kill, list_proc);
		else
		{
			if (to_kill->next)
				to_kill->next->prev = to_kill->prev;
			if (to_kill->prev)
				to_kill->prev->next = to_kill->prev;
			free_process(to_kill);
		}
		list_proc->nb_proc--;

	}
}
