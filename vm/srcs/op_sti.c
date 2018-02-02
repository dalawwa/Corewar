#include "corewar.h"

int		ft_abs(int n)
{
	return (n < 0 ? -n : n);
}

int		get_adv(int adv)
{
	int		tmp;

	tmp = ft_abs(adv) % MEM_SIZE;
	return (adv < 0 ? (MEM_SIZE - tmp) : tmp);
}

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

int		op_sti(t_arena *arena, t_exe *exe)
{
	int			pc_adv;
	int			mod;
	int			args_types;
	int			dest;

	args_types = args_signs(exe->arg2->d_data, exe->arg3->d_data);
//	ft_printf("\nargs_types: %d\n", args_types);
	dest = (exe->arg2->d_data + (short)exe->arg3->d_value);
	pc_adv = 0;
	mod = 0;
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
		ft_printf("| -> store to ");
		if (exe->arg2->type == 'i')
		{
			ft_printf("%d ", exe->arg2->d_data);
		}
		else if (exe->arg2->type == 'r')
			ft_printf("%d ", exe->arg2->d_data);
		else
			ft_printf("%hd ", (short)exe->arg2->d_data);
		ft_printf("+ %hd = ", (short)exe->arg3->d_data);
		if (exe->arg2->type != 'i')
			ft_printf("%hd ", dest);
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
					arena->mem[get_adv(dest)] = exe->process->reg[exe->arg1->d_value][0];
					arena->mem[get_adv(dest + 1)] = exe->process->reg[exe->arg1->d_value][1];
					arena->mem[get_adv(dest + 2)] = exe->process->reg[exe->arg1->d_value][2];
					arena->mem[get_adv(dest + 3)] = exe->process->reg[exe->arg1->d_value][3];
					print_exe_opts(arena, exe);
					return (1);
				}
				else
				{
					if ((short)exe->arg3->d_data < 0 && (short)exe->arg2->d_data >= 0)
						mod = dest % IDX_MOD + exe->process->pc;
					else if ((short)exe->arg3->d_data < 0 && (short)exe->arg2->d_data < 0)
						mod = dest % IDX_MOD + exe->process->pc - IDX_MOD;
					else
						mod = (exe->arg2->d_data + exe->arg3->d_data) % IDX_MOD + exe->process->pc;
					ft_printf("(with pc and mod %hd)\n", mod);
				}
			}
		}
		else
		{
			if ((short)exe->arg3->d_data < 0)
				mod = dest % IDX_MOD + exe->process->pc; /*Pour faire fonctionner sti_ind_full */
			else
				mod = (exe->arg2->d_data + exe->arg3->d_data) % IDX_MOD + exe->process->pc;
//			ft_printf("\nDEST: %d | DEST % IDX_MOD: %d | exe->process->pc: %d | exe->arg2->d_value: %d | (short)exe->arg2->d_value: %hd | exe->arg3->d_value: %d | (short)exe->arg3->d_value: %hd | exe->arg3->d_data: %d | exe->arg1->d_data: %d | (short)exe->arg1->d_data: %hd | exe->arg1->d_value: %d | (short)exe->arg1->d_value: %hd | exe->arg2->d_data: %d | (short)exe->arg2->d_data: %hd | args->types: %d\n", dest, dest % IDX_MOD, exe->process->pc, exe->arg2->d_value, (short)exe->arg2->d_value, exe->arg3->d_value, (short)exe->arg3->d_value, exe->arg3->d_data, exe->arg1->d_data, (short)exe->arg1->d_data, exe->arg1->d_value, (short)exe->arg1->d_value, exe->arg2->d_data, (short)exe->arg2->d_data, args_types);
			ft_printf("(with pc and mod %hd)\n", mod);
		}
	}
	if (!mod)
		mod = dest % IDX_MOD + exe->process->pc;
	arena->mem[get_adv(mod)] = exe->process->reg[exe->arg1->d_value][0];
	arena->mem[get_adv(mod + 1)] = exe->process->reg[exe->arg1->d_value][1];
	arena->mem[get_adv(mod + 2)] = exe->process->reg[exe->arg1->d_value][2];
	arena->mem[get_adv(mod + 3)] = exe->process->reg[exe->arg1->d_value][3];
	print_exe_opts(arena, exe);
	return (1);
}
/* attention si result + 3 > mem_size */
