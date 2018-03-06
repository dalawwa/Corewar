#include "corewar.h"

int		op_fork(t_arena *arena, t_exe *exe)
{
	int result;
	int pc;

	result = 0;
	pc = exe->process->pc;
//	ft_printf("\n--> ARG 1 + PC :\nArg 1 + pc %%d = %d  -  %%hd = %hd\n", exe->arg1->d_data + exe->process->pc, (short)exe->arg1->d_data + exe->process->pc,(short)(exe->arg1->d_data + exe->process->pc));
	// ft_printf("\nFORK\nARG 1 : HEX = %.4x  -  HEX short = %.4x\n", exe->arg1->d_data, (short)exe->arg1->d_data);
	// ft_printf("Arg 1 : type = %c   -   d_data = %d   -   (short)d_data = %hd\n", exe->arg1->type, exe->arg1->d_data, (short)exe->arg1->d_data);
	// ft_printf("PC = %d\n", pc);

    // result = exe->arg1->d_data + pc;
    // ft_printf("Result 1 = Arg_1 + pc\n");
    // ft_printf("Result 1.%%hd : %hd\n", result);
    // ft_printf("Result 1.%%d  : %d\n", result);

    // result = (short)exe->arg1->d_data + pc;
    // ft_printf("\nResult 2 = (short)Arg_1 + pc\n");
    // ft_printf("Result 2.%%hd : %hd\n", result);
    // ft_printf("Result 2.%%d  : %d\n--> = dest\n", result);

	// result = exe->arg1->d_data % IDX_MOD + pc;
    // ft_printf("\nResult 3 = Arg_1 %% IDX MOD+ pc\n");
    // ft_printf("Result 3.%%hd : %hd\n", result);
    // ft_printf("Result 3.%%d  : %d\n--> = dest\n", result);


	if (arena->opts->is_v4)
	{
		print_proc_num_name(exe);
//		if (exe->arg1->d_value > 0x7fff)
		// if (exe->arg1->d_value % MEM_SIZE > 0x7fff)
		// 	ft_printf("%hd (%hd) - 1\n", exe->arg1->d_value, (short)(((exe->arg1->d_value + exe->process->pc) - 0x10000)));
		// else
		// 	ft_printf("%hd (%hd) - 2\n", exe->arg1->d_value, (short)(((exe->arg1->d_value + exe->process->pc))));
		
		// NEW
		
		if (exe->arg1->d_data < 0x8000)
			ft_printf("%hd (%hd)\n", exe->arg1->d_data, exe->arg1->d_data % IDX_MOD + pc);
		else
			ft_printf("%hd (%hd)\n", exe->arg1->d_data, exe->arg1->d_data + pc);


	}
	print_exe_opts(arena, exe);
	create_new_process(arena, exe->process->player, exe->process);
//	ft_putendl("POST FORK");
//	print_all_process(arena);
//	arena->list_proc->last->
	return (1);
}
