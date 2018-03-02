#include "corewar.h"

int		is_carry_to_modify(t_exe *exe)
{
	if ((exe->opcode >= 4 && exe->opcode <= 8) || exe->opcode == 14 || exe->opcode == 2 || exe->opcode == 13)
	{
//		if (exe->arg1->d_value == 0 || (exe->arg2 && exe->arg2->d_value == 0) || (exe->arg3 && exe->arg3->d_value == 0) || (exe->arg1->type == 'r' && exe->arg1->d_data == 0) || (exe->arg2 && exe->arg2->type == 'r' && exe->arg2->d_data == 0) || (exe->arg3 && exe->arg3->type == 'r' && exe->arg3->d_data == 0))
// 		if (exe->process->process_num == 4) 
// 		{
// //			ft_printf("--------------------------> OLD carry = %d\n", exe->process->carry);
// //			print_exe(exe);
// 		}
		if (exe->arg1->d_value == 0 || (exe->arg2 && exe->arg2->d_value == 0) || (exe->arg3 && exe->arg3->d_value == 0) )
			exe->process->carry = 1;
		else
			exe->process->carry = 0;
//		if (exe->process->process_num == 4)
//	ft_printf("--------------------------> NEW carry = %d\n", exe->process->carry);
	}
	return (0);
}
