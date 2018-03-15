/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 10:24:00 by vbaudron          #+#    #+#             */
/*   Updated: 2018/03/15 12:36:26 by bfruchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	kill_process(t_proc *to_kill, t_proc_base *list_proc)
{
	if (to_kill)
	{
		if (list_proc->first == to_kill)
			kill_first(to_kill, list_proc);
		else if (list_proc->last == to_kill)
		{
			list_proc->last = to_kill->prev;
			list_proc->last->next = NULL;
			free_process(to_kill);
		}
		else
		{
			to_kill->next->prev = to_kill->prev;
			to_kill->prev->next = to_kill->next;
			free_process(to_kill);
		}
		list_proc->nb_proc--;
	}
}
