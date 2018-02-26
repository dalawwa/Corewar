#include "corewar.h"

void	print_sti_v4(t_exe *exe, unsigned char ocp)
{
	int	result;

	result = (exe->arg2->d_value + exe->arg3->d_value);
	ocp = ocp + 0;
	if (exe->arg2->type == 'i' && exe->arg3->type == 'd')
	{
		ft_printf("P    %d | %s ", exe->process->process_num, exe->bdd_op->name);
		ft_printf("r%d ", exe->arg1->d_value);
		ft_printf("%d ", (exe->arg2->d_value + exe->arg3->d_value));
		ft_printf("%hd", (short)exe->arg3->d_value);
		ft_putchar('\n');
		put_n_char(' ', intlen((short)(exe->process->process_num)));
		put_n_char(' ', 6);
		ft_printf("| -> store to %d + %hd = ", (exe->arg2->type == 'd') ? (short)exe->arg2->d_data : exe->arg2->d_data, (short)exe->arg3->d_data);
		ft_printf("%d ", exe->arg2->d_data + exe->arg3->d_data);
		ft_printf("(with pc and mod %hd)\n", result % IDX_MOD);
	}
	else
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
		ft_printf("| -> store to %d + %hd = ", (exe->arg2->type == 'd') ? (short)exe->arg2->d_data : exe->arg2->d_data, (short)exe->arg3->d_data);
		if (exe->arg2->type != 'i')
			ft_printf("%hd ", result);
		else
			ft_printf("%d ", exe->arg2->d_data + exe->arg3->d_data);
		ft_printf("(with pc and mod %hd)\n", result % IDX_MOD);
	}
}
