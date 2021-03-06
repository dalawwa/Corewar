/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 10:52:58 by vbaudron          #+#    #+#             */
/*   Updated: 2018/03/15 12:44:16 by bfruchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	print_ldd(t_arena *arena, t_exe *exe)
{
	if (arena->opts->is_v4)
	{
		print_proc_num_name(exe);
		ft_printf("%d ", a_hexa_to_i(exe->process->reg[exe->arg2->d_value], 4));
		ft_printf("r%d", exe->arg2->d_value);
		ft_putchar('\n');
	}
}

int		op_lld(t_arena *arena, t_exe *exe)
{
	if (exe->arg1->type == 'd')
	{
		exe->process->reg[exe->arg2->d_value][0] = exe->arg1->value[0];
		exe->process->reg[exe->arg2->d_value][1] = exe->arg1->value[1];
		exe->process->reg[exe->arg2->d_value][2] = exe->arg1->value[2];
		exe->process->reg[exe->arg2->d_value][3] = exe->arg1->value[3];
	}
	else
	{
		exe->process->reg[exe->arg2->d_value][0] =
		find_char_at_mem_pc_adv(exe->process->pc, exe->arg1->d_value, arena);
		exe->process->reg[exe->arg2->d_value][1] =
		find_char_at_mem_pc_adv(exe->process->pc, exe->arg1->d_value + 1,
				arena);
		exe->process->reg[exe->arg2->d_value][2] =
		find_char_at_mem_pc_adv(exe->process->pc, exe->arg1->d_value + 2,
				arena);
		exe->process->reg[exe->arg2->d_value][3] =
		find_char_at_mem_pc_adv(exe->process->pc, exe->arg1->d_value + 3,
				arena);
	}
	print_ldd(arena, exe);
	print_exe_opts(arena, exe);
	is_carry_to_modify(exe);
	return (1);
}
