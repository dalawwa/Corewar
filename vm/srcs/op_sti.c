#include "corewar.h"

void    print_sti(t_exe *exe)
{
    print_proc_num_name(exe);
//    ft_printf("r%d ", exe->arg1->d_value);

    // ARG 1
	ft_printf("r%d ", exe->arg1->d_value);

	// ARG 2
    if (exe->arg2->type == 'd')
		ft_printf("%hd ", (short)exe->arg2->d_data);
	else
    	ft_printf("%d ", exe->arg2->d_data);

 	// ARG 3   
    if (exe->arg3->type == 'd')
		ft_printf("%hd", (short)exe->arg3->d_data);
	else
    	ft_printf("%d", exe->arg3->d_data);
    

    // LOAD FROM

    ft_putchar('\n');
    put_n_char(' ', 7);
    ft_printf("| -> store to ");

    // ARG 2
	if (exe->arg2->type == 'd')
		ft_printf("%hd ", (short)exe->arg2->d_data);
	else
    	ft_printf("%d ", exe->arg2->d_data);
    
    // ARG 3
	if (exe->arg3->type == 'd')
		ft_printf("+ %hd = ", (short)exe->arg3->d_data);
	else
    	ft_printf("+ %d = ", exe->arg3->d_data);
}

int		op_sti(t_arena *arena, t_exe *exe)
{
	int			mod;
	int         where;
    int         result;
    int         pc;

	mod = 0;
    where = 0;
    pc = exe->process->pc;
	result = 0;

	if (exe->arg2->type == 'i' || exe->arg2->type == 'r')
	{
		if (exe->arg3->type == 'd')
		{
			// Result 2.%d
			result = exe->arg2->d_data + (short)exe->arg3->d_data;
			mod = pc + (result % IDX_MOD);
		}
		else 
		{
			// Result 1.%d
			result = exe->arg2->d_data + exe->arg3->d_data;
			mod = pc + (result % IDX_MOD);
		}
	}
	else	
	{
		if (exe->arg3->type == 'd')
		{
			// Result 3.%hd
			result = (short)exe->arg2->d_data + (short)exe->arg3->d_data;
			mod = pc + ((short)result % IDX_MOD);
		}
		else
		{
			// Result 4.%d
			result = (short)exe->arg2->d_data + exe->arg3->d_data;
			mod = pc + (result % IDX_MOD);
		}
	}

  if (arena->opts->is_v4)
	{
        print_sti(exe);
		if (exe->arg2->type == 'd' && exe->arg3->type == 'd')
			ft_printf("%hd ", (short)result);
		else
			ft_printf("%d ", result);
		ft_printf("(with pc and mod %hd)\n", (short)mod);
	}

    // ft_printf("\n---------->     NEW STI\n\nBASE\n");
    // ft_printf("PC = %d\n", pc);

    // ft_printf("Arg 2 : type = %c   -   d_data = %d   -   (short)d_data = %hd\n", exe->arg2->type, exe->arg2->d_data, (short)exe->arg2->d_data);
    // ft_printf("Arg 3 : type = %c   -   d_data = %d   -   (short)d_data = %hd\n\n", exe->arg3->type, exe->arg3->d_data, (short)exe->arg3->d_data);

    // result = exe->arg2->d_data + exe->arg3->d_data;
    // ft_printf("Result 1 = Arg_2 + Arg_3\n");
    // ft_printf("Result 1.%%hd : %hd\n", result);
    // ft_printf("%%hd.  Result 1.%%hd + PC : %hd %% IDX_MOD = %hd\n", result + pc, pc + ((short)result % IDX_MOD));
    // ft_printf("Result 1.%%d  : %d\n", result);
    // ft_printf("%%d.   Result 1.%%d  + PC : %d %% IDX_MOD = %d\n", result + pc, pc + (result % IDX_MOD));

    // result = exe->arg2->d_data + (short)exe->arg3->d_data;
    // ft_printf("\nResult 2 = Arg_2 + (short)Arg_3\n");
    // ft_printf("Result 2.%%hd : %hd\n", result);
    // ft_printf("%%hd.  Result 2.%%hd + PC : %hd %% IDX_MOD = %hd\n", result + pc, pc + ((short)result % IDX_MOD));
    // ft_printf("Result 2.%%d  : %d\n--> = dest\n", result);
    // ft_printf("%%d.   Result 2.%%d  + PC : %d %% IDX_MOD = %d\n", result + pc, pc + (result % IDX_MOD));

    // result = ((short)exe->arg2->d_data + (short)exe->arg3->d_data);
    // ft_printf("\nResult 3 = (short)Arg_2 + (short)Arg_3\n");
    // ft_printf("Result 3.%%hd : %hd\n", result);
    // ft_printf("%%hd.  Result 3.%%hd + PC : %hd %% IDX_MOD = %hd\n", result + pc, pc + ((short)result % IDX_MOD));
    // ft_printf("Result 3.%%d  : %d\n--> = dest\n", result);
    // ft_printf("%%d.   Result 3.%%d  + PC : %d %% IDX_MOD = %d\n\n", result + pc, pc + (result % IDX_MOD));
    
    if (mod < 0)
        where = MEM_SIZE + mod;
    else
        where = mod;

    arena->mem[get_adv(where)] = exe->process->reg[exe->arg1->d_value][0];
	arena->mem[get_adv(where + 1)] = exe->process->reg[exe->arg1->d_value][1];
	arena->mem[get_adv(where + 2)] = exe->process->reg[exe->arg1->d_value][2];
	arena->mem[get_adv(where + 3)] = exe->process->reg[exe->arg1->d_value][3];

	print_exe_opts(arena, exe);
    return (1);
}

