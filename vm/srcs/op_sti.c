/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 10:53:16 by vbaudron          #+#    #+#             */
/*   Updated: 2018/03/13 10:53:17 by vbaudron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void    print_sti(t_exe *exe)
{
    print_proc_num_name(exe);
	ft_printf("r%d ", exe->arg1->d_value);
    if (exe->arg2->type == 'd')
		ft_printf("%hd ", (short)exe->arg2->d_data);
	else
    	ft_printf("%d ", exe->arg2->d_data); 
    if (exe->arg3->type == 'd')
		ft_printf("%hd", (short)exe->arg3->d_data);
	else
    	ft_printf("%d", exe->arg3->d_data);
    ft_putchar('\n');
    put_n_char(' ', 7);
    ft_printf("| -> store to ");
	if (exe->arg2->type == 'd')
		ft_printf("%hd ", (short)exe->arg2->d_data);
	else
    	ft_printf("%d ", exe->arg2->d_data);
	if (exe->arg3->type == 'd')
		ft_printf("+ %hd = ", (short)exe->arg3->d_data);
	else
    	ft_printf("+ %d = ", exe->arg3->d_data);
}

void	get_sti_result(t_exe *exe, int *result, int *mod, int pc)
{
	if (exe->arg2->type == 'i' || exe->arg2->type == 'r')
	{
		if (exe->arg3->type == 'd')
		{
			*result = exe->arg2->d_data + (short)exe->arg3->d_data;
			*mod = pc + (*result % IDX_MOD);
		}
		else 
		{
			*result = exe->arg2->d_data + exe->arg3->d_data;
			*mod = pc + (*result % IDX_MOD);
		}
	}
	else	
	{
		if (exe->arg3->type == 'd')
		{
			*result = (short)exe->arg2->d_data + (short)exe->arg3->d_data;
			*mod = pc + ((short)*result % IDX_MOD);
		}
		else
		{
			*result = (short)exe->arg2->d_data + exe->arg3->d_data;
			*mod = pc + (*result % IDX_MOD);
		}
	}
}

int		op_sti(t_arena *arena, t_exe *exe)
{
	int			mod;
    int         result;

	mod = 0;
	result = 0;
	get_sti_result(exe, &result, &mod, exe->process->pc);
  if (arena->opts->is_v4)
	{
        print_sti(exe);
		if (exe->arg2->type == 'd' && exe->arg3->type == 'd')
			ft_printf("%hd ", (short)result);
		else
			ft_printf("%d ", result);
		ft_printf("(with pc and mod %hd)\n", (short)mod);
	}
    if (mod < 0)
        mod = MEM_SIZE + mod;
    arena->mem[get_adv(mod)] = exe->process->reg[exe->arg1->d_value][0];
	arena->mem[get_adv(mod + 1)] = exe->process->reg[exe->arg1->d_value][1];
	arena->mem[get_adv(mod + 2)] = exe->process->reg[exe->arg1->d_value][2];
	arena->mem[get_adv(mod + 3)] = exe->process->reg[exe->arg1->d_value][3];
	print_exe_opts(arena, exe);
    return (1);
}
