/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 10:24:19 by vbaudron          #+#    #+#             */
/*   Updated: 2018/03/13 10:24:19 by vbaudron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		op_fork(t_arena *arena, t_exe *exe)
{
	int result;
	int pc;

	result = 0;
	pc = exe->process->pc;
	if (arena->opts->is_v4)
	{
		print_proc_num_name(exe);
		if (exe->arg1->d_data < 0x8000)
			ft_printf("%hd (%hd)\n", exe->arg1->d_data, exe->arg1->d_data % IDX_MOD + pc);
		else
			ft_printf("%hd (%hd)\n", exe->arg1->d_data, exe->arg1->d_data + pc);
	}
	print_exe_opts(arena, exe);
	create_new_process(arena, exe->process->player, exe->process);
	return (1);
}
