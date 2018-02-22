#include "corewar.h"
/*
void	print_ldi(t_arena *arena, t_exe *exe)
{
	int mod;
	int dest;

	dest = (exe->arg2->d_data + (short)exe->arg3->d_value);
	if (arena->opts->is_v4)
	{
//		ft_printf("P    %d | %s ", exe->process->process_num, exe->bdd_op->name);
		ft_putchar('P');
		put_n_char(' ', 5 - intlen((short)exe->process->process_num));
		ft_printf("%d | %s ", exe->process->process_num, exe->bdd_op->name);
		ft_printf("%d ", exe->arg1->d_value);
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
		put_n_char(' ', intlen((short)(exe->process->process_num)));
		put_n_char(' ', 7);
		ft_printf("| -> load from ");
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
				ft_printf("(with pc and mod 0)\n");
			else
			{
				if (exe->arg2->d_data + exe->arg3->d_data + exe->process->pc < 0)
				{
					mod = dest - (512 * ((dest / 512)));
					dest = mod % IDX_MOD + exe->process->pc;
					ft_printf("(with pc and mod %hd)\n", dest);
//					ft_printf("LALA(with pc and mod %hd)\n", dest);
					arena->mem[get_adv(dest)] = exe->process->reg[exe->arg1->d_value][0];
					arena->mem[get_adv(dest + 1)] = exe->process->reg[exe->arg1->d_value][1];
					arena->mem[get_adv(dest + 2)] = exe->process->reg[exe->arg1->d_value][2];
					arena->mem[get_adv(dest + 3)] = exe->process->reg[exe->arg1->d_value][3];
					print_exe_opts(arena, exe);
					return ;
				}
				else
				{
					if ((short)exe->arg3->d_data < 0 && (short)exe->arg2->d_data >= 0)
					{
//						ft_printf("\nCAS A\n");
						mod = dest % IDX_MOD + exe->process->pc;
					}
					else if ((short)exe->arg3->d_data < 0 && (short)exe->arg2->d_data < 0)
					{
//						ft_printf("\nCAS B\n");
						mod = dest % IDX_MOD + exe->process->pc - IDX_MOD;
					}
					else
					{
//						ft_printf("\nCAS C\n");
						mod = ((exe->arg2->d_data + exe->arg3->d_data) % IDX_MOD + exe->process->pc) % IDX_MOD;
					}
					ft_printf("(with pc and mod %hd)\n", mod);
//					ft_printf("RORO(with pc and mod %hd)\n", mod);
				}
			}
		}
		else
		{
			if (exe->arg1->type == 'r')
			{
//				ft_printf("\nCAS 1\n");
				mod = exe->process->pc + (exe->arg2->d_data + exe->arg3->d_data) % IDX_MOD;
			}
			else if ((short)exe->arg3->d_data < 0)
			{
//				ft_printf("\nCAS 2\n");
//				mod = dest % IDX_MOD + exe->process->pc; // faire fonctionner sti_ind_full
			}
			else
			{
//				ft_printf("\nCAS 3\n");
				mod = (exe->arg2->d_data + exe->arg3->d_data) % IDX_MOD + exe->process->pc;
			}
//			ft_printf("\nDEST: %d | DEST % IDX_MOD: %d | exe->process->pc: %d | exe->arg2->d_value: %d | (short)exe->arg2->d_value: %hd | exe->arg3->d_value: %d | (short)exe->arg3->d_value: %hd | exe->arg3->d_data: %d | exe->arg1->d_data: %d | (short)exe->arg1->d_data: %hd | exe->arg1->d_value: %d | (short)exe->arg1->d_value: %hd | exe->arg2->d_data: %d | (short)exe->arg2->d_data: %hd | args->types: %d\n", dest, dest % IDX_MOD, exe->process->pc, exe->arg2->d_value, (short)exe->arg2->d_value, exe->arg3->d_value, (short)exe->arg3->d_value, exe->arg3->d_data, exe->arg1->d_data, (short)exe->arg1->d_data, exe->arg1->d_value, (short)exe->arg1->d_value, exe->arg2->d_data, (short)exe->arg2->d_data, args_types);
			ft_printf("(with pc and mod %hd)\n", mod);
//			ft_printf("HUIHIH(with pc and mod %hd)\n", mod);
		}
	}

}
*/
int		valid_reg(int value)
{
	return (value <= 16 && value >= 1);
}
//exe->arg1->type == 'r' && valid_reg(exe->arg1->d_value) 
int		ocp_valid_regs_ldi(t_exe *exe)
{
	if (exe->opcode != 0xa)
		return (0);
	if (exe->ocp == 0x54)
		return (exe->arg1->type == 'r' && valid_reg(exe->arg1->d_value) && exe->arg2->type == 'r' && valid_reg(exe->arg2->d_value) && exe->arg3->type == 'r' && valid_reg(exe->arg3->d_value));
	if (exe->ocp == 0x64)
		return (exe->arg1->type == 'r' && valid_reg(exe->arg1->d_value) && exe->arg3->type == 'r' && valid_reg(exe->arg3->d_value));
	if (exe->ocp == 0x94 || exe->ocp == 0xd4)
		return (exe->arg2->type == 'r' && valid_reg(exe->arg2->d_value) && exe->arg3->type == 'r' && valid_reg(exe->arg3->d_value));
	if (exe->ocp == 0xa4 || exe->ocp == 0xe4)
		return (exe->arg3->type == 'r' && valid_reg(exe->arg3->d_value));
	return (0);
}

int		exe_ocp_reg_check(t_exe *exe)
{
	t_bdd	*model;
	int		i;

	model = exe->bdd_op;
	i = 0;
	while (i < model->nb_ocp)
	{
		if (model->ocp[i] == exe->ocp_op)
		{
			if (ocp_valid_regs_ldi(exe))
				return (1);
			return (0);
		}
		i++;
	}
	return (0);
}

int		op_ldi(t_arena *arena, t_exe *exe)
{
	int			pc_adv;
	int			mod;
	int			dest;

	dest = ((short)exe->arg1->d_data + (short)exe->arg2->d_value);
	pc_adv = 0;
	mod = 0;
	if ((exe->arg1->type == 'r' && exe->arg1->d_value < 1 && exe->arg1->d_value < REG_NUMBER) || (exe->arg3->type == 'r' && exe->arg3->d_value < 1 && exe->arg3->d_value < REG_NUMBER))
	{
		print_exe_opts(arena, exe);
		return (1);
	}
	if (arena->opts->is_v4)
	{
//		ft_printf("P    %d | %s ", exe->process->process_num, exe->bdd_op->name);
		ft_putchar('P');
		put_n_char(' ', 5 - intlen((short)exe->process->process_num));
		ft_printf("%d | %s ", exe->process->process_num, exe->bdd_op->name);
		ft_printf("%hd ", (short)exe->arg1->d_value);
		if (exe->arg2->type == 'i')
			ft_printf("%d ", exe->arg2->d_data);
		else if (exe->arg2->type == 'r')
			ft_printf("%d ", exe->arg2->d_data);
		else
			ft_printf("%hd ", (short)exe->arg2->d_data);
		if (exe->arg3->type == 'r')
			ft_printf("r%d", exe->arg3->d_value);
		else
			ft_printf("%hd", (short)exe->arg3->d_data);
		ft_putchar('\n');
		put_n_char(' ', 7);
		ft_printf("| -> load from ");
		if (exe->arg1->type == 'i')
		{
			ft_printf("%d ", exe->arg1->d_data);
		}
		else if (exe->arg1->type == 'r')
			ft_printf("%hd ", (short)exe->arg1->d_data);
		else
			ft_printf("%hd ", (short)exe->arg1->d_data);
		if (exe->arg2->type == 'r')
			ft_printf("+ %hd = ", (short)exe->arg2->d_data);
		else
			ft_printf("+ %hd = ", (short)exe->arg2->d_data);
		if (exe->arg2->type != 'i' && exe->arg3->type != 'r')
			ft_printf("%hd ", dest);
		else if (exe->arg3->type == 'r')
			ft_printf("%d ", (short)(exe->arg1->d_data + exe->arg2->d_data));
		else
			ft_printf("%d ", exe->arg2->d_data + (short)exe->arg3->d_data);
		if (((exe->arg2->type != 'i' && (short)dest < 0) || (exe->arg2->type == 'i' && (intmax_t)(exe->arg2->d_data + (short)exe->arg3->d_data) < 0 )) && (exe->arg2->d_data + (short)exe->arg3->d_data) + exe->process->pc > -65536 )
		{
			if (-IDX_MOD + (dest % IDX_MOD) + exe->process->pc == -512)
				ft_printf("(with pc and mod 0)\n");
			else
			{
				if (exe->arg2->d_data + exe->arg3->d_data + exe->process->pc < 0)
				{
					mod = dest - (512 * ((dest / 512)));
					dest = mod % IDX_MOD + exe->process->pc;
					ft_printf("(with pc and mod %hd)\n", dest);
//					ft_printf("LALA(with pc and mod %hd)\n", dest);
					exe->process->reg[exe->arg3->d_value][0] = arena->mem[get_adv(dest)];
					exe->process->reg[exe->arg3->d_value][1] = arena->mem[get_adv(dest + 1)];
					exe->process->reg[exe->arg3->d_value][2] = arena->mem[get_adv(dest + 2)];
					exe->process->reg[exe->arg3->d_value][3] = arena->mem[get_adv(dest + 3)];
					/*
					arena->mem[get_adv(dest)] = exe->process->reg[exe->arg1->d_value][0];
					arena->mem[get_adv(dest + 1)] = exe->process->reg[exe->arg1->d_value][1];
					arena->mem[get_adv(dest + 2)] = exe->process->reg[exe->arg1->d_value][2];
					arena->mem[get_adv(dest + 3)] = exe->process->reg[exe->arg1->d_value][3];
					*/
					print_exe_opts(arena, exe);
					return (1);
				}
				else
				{
					if ((short)exe->arg3->d_data < 0 && (short)exe->arg2->d_data >= 0)
					{
//						ft_printf("\nCAS A\n");
						mod = dest % IDX_MOD + exe->process->pc;
					}
					else if ((short)exe->arg3->d_data < 0 && (short)exe->arg2->d_data < 0)
					{
//						ft_printf("\nCAS B\n");
						mod = dest % IDX_MOD + exe->process->pc - IDX_MOD;
					}
					else
					{
//						ft_printf("\nCAS C\n");
						mod = ((exe->arg1->d_data + exe->arg2->d_data) % IDX_MOD + exe->process->pc) % IDX_MOD;
					}
					ft_printf("(with pc and mod %hd)\n", mod);
//					ft_printf("RORO(with pc and mod %hd)\n", mod);
				}
			}
		}
		else
		{
			if (exe->arg1->type == 'r')
			{
//				ft_printf("\nCAS 1\n");
				mod = exe->process->pc + (exe->arg2->d_data + exe->arg3->d_data) % IDX_MOD;
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
//			ft_printf("\nDEST: %d | DEST % IDX_MOD: %d | exe->process->pc: %d | exe->arg2->d_value: %d | (short)exe->arg2->d_value: %hd | exe->arg3->d_value: %d | (short)exe->arg3->d_value: %hd | exe->arg3->d_data: %d | exe->arg1->d_data: %d | (short)exe->arg1->d_data: %hd | exe->arg1->d_value: %d | (short)exe->arg1->d_value: %hd | exe->arg2->d_data: %d | (short)exe->arg2->d_data: %hd | args->types: %d\n", dest, dest % IDX_MOD, exe->process->pc, exe->arg2->d_value, (short)exe->arg2->d_value, exe->arg3->d_value, (short)exe->arg3->d_value, exe->arg3->d_data, exe->arg1->d_data, (short)exe->arg1->d_data, exe->arg1->d_value, (short)exe->arg1->d_value, exe->arg2->d_data, (short)exe->arg2->d_data, args_types);
			ft_printf("(with pc and mod %hd)\n", mod);
//			ft_printf("HUIHIH(with pc and mod %hd)\n", mod);
		}
	}
	if (!mod)
		mod = (dest % MEM_SIZE % IDX_MOD + exe->process->pc);
	exe->process->reg[exe->arg3->d_value][0] = arena->mem[get_adv(mod)];
	exe->process->reg[exe->arg3->d_value][1] = arena->mem[get_adv(mod + 1)];
	exe->process->reg[exe->arg3->d_value][2] = arena->mem[get_adv(mod + 2)];
	exe->process->reg[exe->arg3->d_value][3] = arena->mem[get_adv(mod + 3)];
	print_exe_opts(arena, exe);
	return (1);
}
/*
int		op_ldi(t_arena *arena, t_exe *exe)
{
	uintmax_t result;

	if (!exe_ocp_reg_check(exe))
	{
//		ft_bzero(exe->process->reg[exe->arg3->d_value], 4);
		print_exe_opts(arena, exe);
		return (1);
	}
//	ft_bzero(exe->process->reg[exe->arg3->d_value], 4);
	result = exe->arg1->d_data + exe->arg2->d_data;
	result = result % IDX_MOD;
//	ft_printf("result = %u\n", result);

	exe->process->reg[exe->arg3->d_value][0] = find_char_at_mem_pc_adv(exe->process->pc, result, arena);
	exe->process->reg[exe->arg3->d_value][1] = find_char_at_mem_pc_adv(exe->process->pc, result + 1, arena);
	exe->process->reg[exe->arg3->d_value][2] = find_char_at_mem_pc_adv(exe->process->pc, result + 2, arena);
	exe->process->reg[exe->arg3->d_value][3] = find_char_at_mem_pc_adv(exe->process->pc, result + 3, arena);

	exe->process->reg[exe->arg3->d_value][0] = arena->mem[get_adv(exe->process->pc + result)];
	exe->process->reg[exe->arg3->d_value][1] = arena->mem[get_adv(exe->process->pc + result + 1)];
	exe->process->reg[exe->arg3->d_value][2] = arena->mem[get_adv(exe->process->pc + result + 2)];
	exe->process->reg[exe->arg3->d_value][3] = arena->mem[get_adv(exe->process->pc + result + 3)];
//	print_ldi(arena, exe);
	print_exe_opts(arena, exe);
	return (1);
}
*/
/* attention si result + 3 > mem_size */
