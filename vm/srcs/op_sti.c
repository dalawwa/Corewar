#include "corewar.h"

int		op_sti(t_arena *arena, t_exe *exe)
{
	short int	result;
	int			pc_adv;
	int			i;
	int			test;

	result = (short int)(exe->arg2->d_data + exe->arg3->d_data);
	test = (exe->arg2->d_data + exe->arg3->d_data);
//	if (result > 0xffffffff)
//	{
//		ft_putendl("op_sti failed");
//		return (0);
//	}
	i = 1024;
//	ft_printf("test AVANT IDX_MOD = %d\n", test);
//	ft_printf("test %% IDX_MOD = %d\n", test % IDX_MOD);
//	result = result % IDX_MOD;
//	ft_printf("result %% %d = %d\n", i, (intmax_t)result % i);
	pc_adv = find_pc_adv(exe->process->pc, result % IDX_MOD, 1);
	arena->mem[pc_adv] = exe->process->reg[exe->arg1->d_value][0];
	pc_adv = find_pc_adv(pc_adv, 1, 1);
	arena->mem[pc_adv] = exe->process->reg[exe->arg1->d_value][1];
	pc_adv = find_pc_adv(pc_adv, 1, 1);
	arena->mem[pc_adv] = exe->process->reg[exe->arg1->d_value][2];
	pc_adv = find_pc_adv(pc_adv, 1, 1);
	arena->mem[pc_adv] = exe->process->reg[exe->arg1->d_value][3];
/*	arena->mem[find_pc_adv(exe->process->pc, result % IDX_MOD, 1)] = exe->process->reg[exe->arg1->d_value][0];
	arena->mem[find_pc_adv(exe->process->pc, (result) % IDX_MOD + 1, 1)] = exe->process->reg[exe->arg1->d_value][1];
	arena->mem[find_pc_adv(exe->process->pc, (result) % IDX_MOD + 2, 1)] = exe->process->reg[exe->arg1->d_value][2];
	arena->mem[find_pc_adv(exe->process->pc, (result) % IDX_MOD + 3, 1)] = exe->process->reg[exe->arg1->d_value][3];*/
	if (arena->opts->is_v4)
	{
		ft_printf("P    %d | %s ", exe->process->process_num, exe->bdd_op->name);
		ft_printf("r%d ", exe->arg1->d_value);
		if (exe->arg2->type == 'i')
			ft_printf("%d ", exe->arg2->d_data);
		else if (exe->arg2->type == 'r')
			ft_printf("%d ", exe->arg2->d_data);
		else
			ft_printf("%hd ", (short)exe->arg2->d_data);
		ft_printf("%hd", (short)exe->arg3->d_data);
		ft_putchar('\n');
		put_n_char(' ', intlen((short)(exe->process->process_num)));
		put_n_char(' ', 6);
//		ft_printf("| -> store to %d + %hd = ", (exe->arg2->type == 'd') ? (short)exe->arg2->d_data : exe->arg2->d_data, (short)exe->arg3->d_data);
		ft_printf("| -> store to ");
		if (exe->arg2->type == 'i')
			ft_printf("%d ", exe->arg2->d_data);
		else if (exe->arg2->type == 'r')
			ft_printf("%d ", exe->arg2->d_data);
		else
			ft_printf("%hd ", (short)exe->arg2->d_data);
		ft_printf("+ %hd = ", (short)exe->arg3->d_data);
		if (exe->arg2->type != 'i')
			ft_printf("%hd ", test);
		else
			ft_printf("%d ", exe->arg2->d_data + (short)exe->arg3->d_data);

//			ft_printf("\n\nHANDLE mod --> Datas Available :\nResult = (short int)exe->arg2->d_data + exe->arg3->d_data) =\n%%hd :_%hd_\n%%d :_d\n", result, result);
//			ft_printf("Test = (exe->arg2->d_data + exe->arg3->d_data) =\n%%hd :_%hd_\n%%d :_%d\ntest %% 512 : %%d = %d\n%%hd : %hd\n\n", test, test, test % 512, test % 512);
//			ft_printf("Test + PC =\n%%hd :_%hd_\n%%d :_%d\ntest %% 512 + PC : %%d = %d\n%%hd : %hd\n\n", test + exe->process->pc, test + exe->process->pc, test % 512 + exe->process->pc, test % 512 + exe->process->pc);
		if (((exe->arg2->type != 'i' && (short)test < 0) || (exe->arg2->type == 'i' && (intmax_t)(exe->arg2->d_data + (short)exe->arg3->d_data) < 0 )) && (exe->arg2->d_data + (short)exe->arg3->d_data) + exe->process->pc > -65336 )
		{
			if (-IDX_MOD + (test % IDX_MOD) + exe->process->pc == -512)
				ft_printf("(with pc and mod 0)\n");
			else
				ft_printf("(with pc and mod %d)\n", (unsigned char)(-IDX_MOD + (test % IDX_MOD) + exe->process->pc));
		}
		else if (exe->arg2->d_data + (short)exe->arg3->d_data + exe->process->pc > -65336)
			ft_printf("(with pc and mod %hd)\n", test % IDX_MOD + exe->process->pc);
		else
			ft_printf("(with pc and mod %hd)\n", test % IDX_MOD + exe->process->pc);
//		ft_printf("(with pc and mod %hd)\n", IDX_MOD + result % IDX_MOD);

//		ft_printf("| -> store to %d + %hd = %d (with pc and mod %hd)\n", exe->arg2->d_data, (short)exe->arg3->d_data, ((exe->arg3->d_data + exe->arg2->d_data) % IDX_MOD), (short)(exe->process->pc + (exe->arg2->d_data + (short)exe->arg3->d_data) % IDX_MOD));
//		AU DESSUS C'EST TON ORIGINAL QUE J'ai mis en comment pour le garder, j'ai fait une modif par rapport a sti_1.s mais j'ai pas checker si ca casse pas qqch ailleurs, donc j'ai laisse ton code original la
//	print_sti_v4(exe, exe->ocp);
	}
	print_exe_opts(arena, exe);
	return (1);
}
/* attention si result + 3 > mem_size */
