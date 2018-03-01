#include "corewar.h"

int		args_signs(int arg1, int arg2)
{
	if ((short)arg1 >= 0 && (short)arg2 >= 0)
		return (1);
	if ((short)arg1 < 0 && (short)arg2 >=0)
		return (2);
	if ((short)arg1 >= 0 && (short)arg2 < 0)
		return (3);
	return (4);
}

int		op_sti_2(t_arena *arena, t_exe *exe)
{
	int			pc_adv;
	int			mod;
	int			args_types;
	int			dest;

	args_types = args_signs(exe->arg2->d_data, exe->arg3->d_data);
	dest = (exe->arg2->d_data + (short)exe->arg3->d_value);
	pc_adv = 0;
	mod = 0;
    ft_printf("---------->     OLD STI\n");
//	ft_printf("\n\nARENA->MEM[(PC)]: %d | (PC): %d | OCP: %d | arg1->d_value: %d | arg1->d_data: %d\n", arena->mem[(exe->process->pc)], exe->process->pc, exe->ocp_op->ocp, exe->arg1->d_value, exe->arg1->d_data);
	// if (arena->mem[exe->process->pc + 1] == 0)
	// {
	// 	print_failed_exe(arena, exe, 2);
	// 	return (1);
	// }
	// if ((exe->arg1->type == 'r' && (exe->arg1->d_value < 1 || exe->arg1->d_value > REG_NUMBER)) || (exe->arg3->type == 'r' && (exe->arg3->d_value < 1 || exe->arg3->d_value > REG_NUMBER)))
	// {
	// 	print_exe_opts(arena, exe);
	// 	return (1);
	// }
	if (arena->opts->is_v4)
	{

//			ft_printf("P    %d | %s ", exe->process->process_num, exe->bdd_op->name);
			ft_putchar('P');
			put_n_char(' ', 5 - intlen((short)exe->process->process_num));
			ft_printf("%d | %s ", exe->process->process_num, exe->bdd_op->name);
		ft_printf("r%d ", exe->arg1->d_value);
		if (exe->arg2->type == 'i')
			ft_printf("%d ", exe->arg2->d_data);
		else if (exe->arg2->type == 'r')
			ft_printf("%d ", exe->arg2->d_data);
		else
			ft_printf("%hd ", (short)exe->arg2->d_data);
		if (exe->arg3->type == 'r')
			ft_printf("%d", exe->arg3->d_data);
		else
			ft_printf("%hd", (short)exe->arg3->d_data);
		ft_putchar('\n');
		put_n_char(' ', 7);
		ft_printf("| -> store to ");
		if (exe->arg2->type == 'i')
		{
			ft_printf("%d ", exe->arg2->d_data);
		}
		else if (exe->arg2->type == 'r')
			ft_printf("%d ", exe->arg2->d_data);
		else
			ft_printf("%hd ", (short)exe->arg2->d_data);
		if (exe->arg3->type == 'r')
			ft_printf("+ %d = ", exe->arg3->d_data);
		else
			ft_printf("+ %hd = ", (short)exe->arg3->d_data);
		if (exe->arg2->type != 'i' && exe->arg3->type != 'r')
			ft_printf("%hd ", dest);
		else if (exe->arg3->type == 'r')
			ft_printf("%d ", exe->arg2->d_data + exe->arg3->d_data);
		else
			ft_printf("%d ", exe->arg2->d_data + (short)exe->arg3->d_data);
		if (((exe->arg2->type != 'i' && (short)dest < 0) || (exe->arg2->type == 'i' && (intmax_t)(exe->arg2->d_data + (short)exe->arg3->d_data) < 0 )) && (exe->arg2->d_data + (short)exe->arg3->d_data) + exe->process->pc > -65536 )
		{
			if (-IDX_MOD + (dest % IDX_MOD) + exe->process->pc == -512)
			{
				mod = 0;
				ft_printf("(with pc and mod 0)\n");
			}
			else
			{
				if (exe->arg2->d_data + exe->arg3->d_data + exe->process->pc < 0)
				{
					mod = dest - (512 * ((dest / 512)));
					dest = mod % IDX_MOD + exe->process->pc;
					ft_printf("(with pc and mod %hd)\n", dest);
					ft_printf("LALA(with pc and mod %hd)\n", dest);

					if (dest < 0) {
					arena->mem[get_adv(dest)] = exe->process->reg[exe->arg1->d_value][0];
					arena->mem[get_adv(dest + 1)] = exe->process->reg[exe->arg1->d_value][1];
					arena->mem[get_adv(dest + 2)] = exe->process->reg[exe->arg1->d_value][2];
					arena->mem[get_adv(dest + 3)] = exe->process->reg[exe->arg1->d_value][3];
					print_exe_opts(arena, exe);
					return (1);
					}
				}
				else
				{
					if ((short)exe->arg3->d_data < 0 && (short)exe->arg2->d_data >= 0)
					{
						mod = dest % IDX_MOD + exe->process->pc;
					}
					else if ((short)exe->arg3->d_data < 0 && (short)exe->arg2->d_data < 0)
					{
						mod = dest % IDX_MOD + exe->process->pc - IDX_MOD;
					}
					else
					{
						// ft_printf("\nCAS C\n");
						mod = ((exe->arg2->d_data + exe->arg3->d_data + exe->process->pc) % IDX_MOD );
					}
					ft_printf("(with pc and mod %hd)\n", mod);
					 ft_printf("RORO(with pc and mod %hd)\n", mod);
				}
			}
		}
		else
		{
			if (exe->arg1->type == 'r')
			{
//				ft_printf("\nCAS 1\n");
				mod = exe->process->pc + ((short)exe->arg2->d_data + (short)exe->arg3->d_data) % IDX_MOD;
			}
			else if ((short)exe->arg3->d_data < 0)
			{
//				ft_printf("\nCAS 2\n");
				mod = dest % IDX_MOD + exe->process->pc; /*Pour faire fonctionner sti_ind_full */
			}
			else
			{
//				ft_printf("\nCAS 3\n");
				mod = (exe->arg2->d_data + exe->arg3->d_data) % IDX_MOD + exe->process->pc;
			}
//			ft_printf("\nDEST: %d | DEST %% IDX_MOD: %d | exe->process->pc: %d | exe->arg2->d_value: %d | (short)exe->arg2->d_value: %hd | exe->arg3->d_value: %d | (short)exe->arg3->d_value: %hd | exe->arg3->d_data: %d | exe->arg1->d_data: %d | (short)exe->arg1->d_data: %hd | exe->arg1->d_value: %d | (short)exe->arg1->d_value: %hd | exe->arg2->d_data: %d | (short)exe->arg2->d_data: %hd | args->types: %d\n", dest, dest % IDX_MOD, exe->process->pc, exe->arg2->d_value, (short)exe->arg2->d_value, exe->arg3->d_value, (short)exe->arg3->d_value, exe->arg3->d_data, exe->arg1->d_data, (short)exe->arg1->d_data, exe->arg1->d_value, (short)exe->arg1->d_value, exe->arg2->d_data, (short)exe->arg2->d_data, args_types);
			ft_printf("(with pc and mod %hd)\n", mod);
			ft_printf("HUIHIH(with pc and mod %hd)\n", mod);
		}
	}
	// if (!mod)
	// 	mod = (dest % MEM_SIZE % IDX_MOD + exe->process->pc);
	// ft_printf("\nget_adv(mod++): %d\n", get_adv(mod));

	arena->mem[get_adv(mod)] = exe->process->reg[exe->arg1->d_value][0];
//	ft_printf("\nget_adv(mod++): %d\n", get_adv(mod + 1));
	arena->mem[get_adv(mod + 1)] = exe->process->reg[exe->arg1->d_value][1];
//	ft_printf("\nget_adv(mod++): %d\n", get_adv(mod + 2));
	arena->mem[get_adv(mod + 2)] = exe->process->reg[exe->arg1->d_value][2];
//	ft_printf("\nget_adv(mod++): %d\n", get_adv(mod + 3));
	arena->mem[get_adv(mod + 3)] = exe->process->reg[exe->arg1->d_value][3];
	print_exe_opts(arena, exe);
	return (1);
}

void    print_sti(t_exe *exe, int mod)
{
    ft_putchar('P');
    put_n_char(' ', 5 - intlen((short)exe->process->process_num));
    ft_printf("%d | %s ", exe->process->process_num, exe->bdd_op->name);
    ft_printf("r%d ", exe->arg1->d_value);

    // ARG 2
    if (exe->arg2->type == 'd')
        ft_printf("%hd ", (short)exe->arg2->d_data);
    else
        ft_printf("%d ", exe->arg2->d_data);

    // ARG 3
    if (exe->arg3->type == 'r')
        ft_printf("%d", exe->arg3->d_data);
    else
        ft_printf("%hd", (short)exe->arg3->d_data);
    
    // STORE TO

    ft_putchar('\n');
    put_n_char(' ', 7);
    ft_printf("| -> store to ");

    // ARG 2
    if (exe->arg2->type == 'd')
        ft_printf("%hd ", (short)exe->arg2->d_data);
    else
        ft_printf("%d ", exe->arg2->d_data);
    
    // ARG 3
    if (exe->arg3->type == 'r')
        ft_printf("+ %d = ", exe->arg3->d_data);
    else
        ft_printf("+ %hd = ", (short)exe->arg3->d_data);
    
    // RESULT

    // if (exe->arg2->type != 'i' && exe->arg3->type != 'r')
    //     ft_printf("%hd ", exe->arg2->d_data + (short)exe->arg3->d_value);
    // else if (exe->arg3->type == 'r')
    //     ft_printf("%d ", exe->arg2->d_data + exe->arg3->d_data);
    // else
    //     ft_printf("%d ", exe->arg2->d_data + (short)exe->arg3->d_data);

    if (exe->arg2->type == 'i')
    {
        if (exe->arg3->type == 'd')
            ft_printf("%d ", exe->arg2->d_data + (short)exe->arg3->d_data);
        else
            ft_printf("%d ", exe->arg2->d_data + exe->arg3->d_data);
    }
    else
        ft_printf("%hd ", exe->arg2->d_data + exe->arg3->d_data);

    
    // MOD
    ft_printf("(with pc and mod %hd)\n", (short)mod);

    // Debug
    // ft_printf("Result 1 : %hd\n", exe->arg2->d_data + (short)exe->arg3->d_value);
    // ft_printf("Result 2 : %d\n", exe->arg2->d_data + exe->arg3->d_data);
    // ft_printf("Result 3 : %d\n", exe->arg2->d_data + (short)exe->arg3->d_data);
    // ft_printf("Result 4 : %hd  + PC = %d\n", exe->arg2->d_data + exe->arg3->d_data, (short)(exe->arg2->d_data + exe->arg3->d_data) + exe->process->pc);
    // ft_printf("Result 5 : %d\n", exe->arg2->d_data + exe->arg3->d_data);
}

int		op_sti(t_arena *arena, t_exe *exe)
{
	int			pc_adv;
	int			mod;
	int			args_types;
	int			dest;
    int         where;
    int         result;
    int         pc;

	args_types = args_signs(exe->arg2->d_data, exe->arg3->d_data);
	dest = (exe->arg2->d_data + (short)exe->arg3->d_value);
	pc_adv = 0;
	mod = 0;
    where = 0;
    pc = exe->process->pc;
    

    // OLD STI
    // return(op_sti_2(arena, exe));

    // NEW HYPOTHESE
    result = exe->arg2->d_data + exe->arg3->d_data;
    if (exe->arg2->type == 'i')
	{
		if (exe->arg3->type == 'd')
			result = exe->arg2->d_data + (short)exe->arg3->d_data;
        mod = pc + (result % IDX_MOD);
	}
    else
        mod = (short)(pc + ((short)result % IDX_MOD));



    // ft_printf("---------->     NEW STI\n\nBASE\n");
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
    



    // if (((exe->arg2->type != 'i' && (short)dest < 0) || (exe->arg2->type == 'i' && (intmax_t)(exe->arg2->d_data + (short)exe->arg3->d_data) < 0 )) && (exe->arg2->d_data + (short)exe->arg3->d_data) + exe->process->pc > -65536 )
    // {
    //     ft_printf("CAS 1 : ARG_2 != 'i' && (short)dest < 0) || (Arg_2 == 'i' && (intmax_t)(Arg_2 + (short)Arg_3) < 0 )) && (Arg_2 + (short)Arg_3) + PC > -65536 \n");
    //     if (-IDX_MOD + (dest % IDX_MOD) + exe->process->pc == -512)
    //     {
    //         ft_printf("CAS 1.a : -IDX_MOD + (dest %% IDX_MOD) + PC == -512\n");
    //         mod = 0;
    //     }
    //     else
    //     {
    //         if (exe->arg2->d_data + exe->arg3->d_data + exe->process->pc < 0)
    //         {
    //             ft_printf("CAS 1.b.1 : Arg_2 + Arg_3 + PC < 0\n");
    //             mod = dest - (512 * ((dest / 512)));
    //             mod = mod % IDX_MOD + exe->process->pc;
    //         }
    //         else
    //         {
    //             ft_printf("CAS 1.b.2 : Arg_2 + Arg_3 + PC >= 0\n");
    //             if ((short)exe->arg3->d_data < 0 && (short)exe->arg2->d_data >= 0)
    //             {
    //                 ft_printf("CAS 1.b.2.a : (short)Arg_3 < 0 && (short)Arg_2 >= 0\n");
    //                 mod = dest % IDX_MOD + exe->process->pc;
    //             }
    //             else if ((short)exe->arg3->d_data < 0 && (short)exe->arg2->d_data < 0)
    //             {
    //                 ft_printf("CAS 1.b.2.b : (short)Arg_3 < 0 && (short)Arg_2 <0\n");
    //                 mod = dest % IDX_MOD + exe->process->pc - IDX_MOD;
    //             }
    //             else
    //             {
    //                 ft_printf("CAS 1.b.2.c : (short)Arg_3 > 0\n");
    //                 mod = ((exe->arg2->d_data + exe->arg3->d_data + exe->process->pc) % IDX_MOD );
    //             }
    //         }
    //     }
    // }
    // else
    // {
    //     ft_printf("CAS 2 : EXCLU  Arg_2 != 'i' && (short)dest < 0) || (Arg_2 == 'i' && (intmax_t)(eArg_2 + (short)Arg_3) < 0 )) && (Arg_2 + (short)Arg_3) + PC > -65536 \n");
    //     mod = exe->process->pc + ((short)exe->arg2->d_data + (short)exe->arg3->d_data) % IDX_MOD;
    //     ft_printf("PC + ((short)Arg_2 + (short)Arg_3) %% IDX_MOD\n");
    // }
    
    // ft_printf("\nMOD : %hd\n", mod);
    if (mod < 0)
        where = MEM_SIZE + mod;
    else
        where = mod;

    // ft_printf("\nWHERE : %d\n", where);
    arena->mem[where] = exe->process->reg[exe->arg1->d_value][0];
	// ft_printf("\nget_adv(mod++): %d\n", get_adv(where + 1));
	arena->mem[get_adv(where + 1)] = exe->process->reg[exe->arg1->d_value][1];
	// ft_printf("\nget_adv(mod++): %d\n", get_adv(where + 2));
	arena->mem[get_adv(where + 2)] = exe->process->reg[exe->arg1->d_value][2];
	// ft_printf("\nget_adv(mod++): %d\n", get_adv(where + 3));
	arena->mem[get_adv(where + 3)] = exe->process->reg[exe->arg1->d_value][3];

    if (arena->opts->is_v4)
        print_sti(exe, mod);

	print_exe_opts(arena, exe);
    return (1);
}

