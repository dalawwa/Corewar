#include "corewar.h"

void    print_ldi(t_exe *exe)
{
   print_proc_num_name(exe);
    if (exe->arg1->type == 'd')
		ft_printf("%hd ", (short)exe->arg1->d_data);
	else
    	ft_printf("%d ", exe->arg1->d_data);
    if (exe->arg2->type == 'd')
		ft_printf("%hd ", (short)exe->arg2->d_data);
	else
    	ft_printf("%d ", exe->arg2->d_data);
	ft_printf("r%d", exe->arg3->d_value);
    ft_putchar('\n');
    put_n_char(' ', 7);
    ft_printf("| -> load from ");
	if (exe->arg1->type == 'd')
		ft_printf("%hd ", (short)exe->arg1->d_data);
	else
    	ft_printf("%d ", exe->arg1->d_data);
	if (exe->arg2->type == 'd')
		ft_printf("+ %hd = ", (short)exe->arg2->d_data);
	else
    	ft_printf("+ %d = ", exe->arg2->d_data);
}

void	get_result(t_exe *exe, int *result, int *mod, int pc)
{
	if (exe->arg1->type == 'i' || exe->arg1->type == 'r')
	{
		if (exe->arg2->type == 'd')
		{
			*result = exe->arg1->d_data + (short)exe->arg2->d_data;
			*mod = pc + (*result % IDX_MOD);
		}
		else 
		{
			*result = exe->arg1->d_data + exe->arg2->d_data;
			*mod = pc + (*result % IDX_MOD);
		}
	}
	else	
	{
		if (exe->arg2->type == 'd')
		{
			*result = (short)exe->arg1->d_data + (short)exe->arg2->d_data;
			*mod = pc + ((short)*result % IDX_MOD);
		}
		else
		{
			*result = (short)exe->arg1->d_data + exe->arg2->d_data;
			*mod = pc + (*result % IDX_MOD);
		}
	}
}


int		op_ldi(t_arena *arena, t_exe *exe)
{
	int			mod;
    int         result;

	mod = 0;
	result = 0;
	get_result(exe, &result, &mod, exe->process->pc);
	if (arena->opts->is_v4)
	{
        print_ldi(exe);
		if (exe->arg1->type == 'd' && exe->arg2->type == 'd')
			ft_printf("%hd ", (short)result);
		else
			ft_printf("%d ", result);
		ft_printf("(with pc and mod %hd)\n", (short)mod);
	}
	if (mod < 0)
        mod = MEM_SIZE + mod;
	exe->process->reg[exe->arg3->d_value][0] = arena->mem[get_adv(mod)];
	exe->process->reg[exe->arg3->d_value][1] = arena->mem[get_adv(mod + 1)];
	exe->process->reg[exe->arg3->d_value][2] = arena->mem[get_adv(mod + 2)];
	exe->process->reg[exe->arg3->d_value][3] = arena->mem[get_adv(mod + 3)];
	print_exe_opts(arena, exe);
    return (1);
}