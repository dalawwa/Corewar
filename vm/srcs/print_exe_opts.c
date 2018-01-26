#include "corewar.h"

void		print_exe_opts(t_arena *arena, t_exe *exe)
{
	int	i;

	i = 0;
	if (arena->opts->has_v == 1)
	{
		//		ft_printf("Process num %d\n", exe->process->process_num);
/*		if (arena->opts->is_v4 && exe->bdd_op->opcode != 16)
		{
			ft_printf("P    %d | %s ", exe->process->process_num, exe->bdd_op->name);
			if (exe->arg1->type == 'r' && exe->bdd_op->opcode != 10 && exe->bdd_op->opcode != 6 && exe->bdd_op->opcode != 7 && exe->bdd_op->opcode != 8 && exe->bdd_op->opcode != 14)
				ft_printf("r");
			if (exe->bdd_op->opcode == 7 || exe->bdd_op->opcode == 8 || exe->bdd_op->opcode == 10)
				ft_printf("%d ", exe->arg1->d_data);
			else if (exe->bdd_op->opcode == 2 || exe->opcode == 14 || exe->opcode == 13)
				ft_printf("%d ", exe->arg1->d_data);
			else if (exe->bdd_op->opcode == 6 && (exe->arg1->type == 'd' || exe->arg1->type == 'r'))
				ft_printf("%d ", (short)exe->arg1->d_data);
			else if (exe->bdd_op->opcode == 6 && exe->arg1->type == 'i')
				ft_printf("%d ", exe->arg1->d_data);
			else
				ft_printf("%hd ", (short)exe->arg1->d_value);
			if (exe->arg2)
			{
				if (exe->arg2->type == 'r' && exe->bdd_op->opcode != 10 && exe->bdd_op->opcode != 11 && exe->bdd_op->opcode != 6 && exe->bdd_op->opcode != 7 && exe->bdd_op->opcode != 8 && exe->bdd_op->opcode != 14)
					ft_printf("r");
				if (exe->bdd_op->opcode == 11 || exe->bdd_op->opcode == 7 || exe->bdd_op->opcode == 8 || exe->bdd_op->opcode == 14)
					ft_printf("%d ", exe->arg2->d_data);
				else if (exe->bdd_op->opcode == 14)
					ft_printf("%d ", exe->arg2->d_data);
				else if (exe->bdd_op->opcode == 6 && exe->arg2->type == 'r')
					ft_printf("%d ", exe->arg2->d_data);
				else if (exe->bdd_op->opcode == 6 && exe->arg2->type == 'd')
					ft_printf("%d ", exe->arg2->d_data);
				else if (exe->bdd_op->opcode == 6 && exe->arg2->type == 'i')
					ft_printf("%hd ", (short)exe->arg2->d_data);
				else
					ft_printf("%d ", exe->arg2->d_value);
			}
			if (exe->arg3)
			{
				if (exe->arg3->type == 'r' && exe->bdd_op->opcode != 11)
				{
					ft_printf("r");
					ft_printf("%d", exe->arg3->d_value);
				}
				else
					ft_printf("%d", exe->arg3->d_data);
			}
			if (exe->bdd_op->opcode == 9)
			{
				if (exe->process->carry == 1)
					ft_printf("OK");
				else
					ft_printf("FAILED");
			}
			if (exe->bdd_op->opcode == 15 || exe->bdd_op->opcode == 12)
				ft_printf("(%d)", (short int)(exe->process->pc + exe->arg1->d_value));
			if (exe->bdd_op->opcode == 11)
			{
				ft_putchar('\n');
				put_n_char(' ', intlen((short)(exe->process->process_num)));
				put_n_char(' ', 6);
				ft_printf("| -> store to %d + %d = %d (with pc and mod %d)", exe->arg2->d_data, exe->arg3->d_data, exe->arg3->d_data + exe->arg2->d_data, exe->process->pc + (exe->arg2->d_data + exe->arg3->d_data) % IDX_MOD);
			}
			if (exe->bdd_op->opcode == 14)
			{
				ft_putchar('\n');
				put_n_char(' ', intlen((short)(exe->process->process_num)));
				put_n_char(' ', 6);
				ft_printf("| -> load from %d + %d = %d (with pc %d)", exe->arg1->d_data, exe->arg2->d_data, exe->arg1->d_data + exe->arg2->d_data, exe->process->pc + exe->arg2->d_data + exe->arg1->d_data);
			}
			if (exe->bdd_op->opcode == 10)
			{
				ft_putchar('\n');
				put_n_char(' ', intlen((short)(exe->process->process_num)));
				put_n_char(' ', 6);
				ft_printf("| -> load from %d + %d = %d (with pc and mod %d)", exe->arg1->d_data, exe->arg2->d_data, exe->arg1->d_data + exe->arg2->d_data, exe->process->pc + (exe->arg1->d_data + exe->arg2->d_data) % IDX_MOD);
			}
			ft_putchar('\n');
		}*/
		if (arena->opts->is_v16)
		{
			if (exe->process->pc == 0)
				ft_printf("ADV %d (0x0000 -> %#.4x) ", exe->ocp_op->size_adv, exe->process->pc + (exe->ocp_op->size_adv));
			else if (exe->process->pc + (exe->ocp_op->size_adv) == 0)
				ft_printf("ADV %d (%#.4x -> 0x0000) ", exe->ocp_op->size_adv, exe->process->pc);
			else
				ft_printf("ADV %d (%#.4x -> %#.4x) ", exe->ocp_op->size_adv, exe->process->pc, exe->process->pc + exe->ocp_op->size_adv);
			while (i < exe->ocp_op->size_adv)
			{
				ft_printf("%.2x ", arena->mem[find_pc_adv(exe->process->pc, i, 0)]);
				i++;
			}
			ft_putchar('\n');
		}
	}
}
