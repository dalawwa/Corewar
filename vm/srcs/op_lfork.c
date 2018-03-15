/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lfork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 10:24:31 by vbaudron          #+#    #+#             */
/*   Updated: 2018/03/15 12:36:46 by bfruchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		op_lfork(t_arena *arena, t_exe *exe)
{
	if (arena->opts->is_v4)
	{
		print_proc_num_name(exe);
		ft_printf("%hd (%hd)\n", (short)exe->arg1->d_value,
				(short)(exe->arg1->d_value + exe->process->pc));
	}
	print_exe_opts(arena, exe);
	create_new_process(arena, exe->process->player, exe->process);
	return (1);
}
