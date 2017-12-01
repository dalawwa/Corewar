#include "corewar.h"

int				count_size_arg(char type, int is_idx)
{
	if (type == '\0')
		return (0);
	if (type == 'r')
		return (1);
	if (type == 'd')
	{
		if (is_idx == 1)
			return (2);
		return (4);
	}
	if (type == 'i')
		return (2);
	return (-1);
}

int				set_size_adv(t_ocp *ocp_j, t_bdd *bdd_i, int i)
{
	int	is_idx;
	int	result;

	is_idx = 0;
	result = 0;
	if (i >= 8 && i <= 14 && i != 12)
		is_idx = 1;
	ocp_j->size_arg1 = count_size_arg(ocp_j->type_arg1, is_idx);
	ocp_j->size_arg2 = count_size_arg(ocp_j->type_arg2, is_idx);
	ocp_j->size_arg3 = count_size_arg(ocp_j->type_arg3, is_idx);
	ocp_j->size_adv = ocp_j->size_arg1 + ocp_j->size_arg2 + ocp_j->size_arg3 + bdd_i->has_ocp + 1;
	return (1);
}

unsigned char	binary_val_arg(char type)
{
	if (type == 'r')
		return ((unsigned char)0b01);
	if (type == 'd')
		return ((unsigned char)0b10);
	if (type == 'i')
		return ((unsigned char)0b11);
	else
		return (0);
}

void			set_binary(t_ocp *ocp)
{
	ocp->ocp = 0;
	ocp->ocp = binary_val_arg(ocp->type_arg1) << 6;
	ocp->ocp += binary_val_arg(ocp->type_arg2) << 4;
	ocp->ocp += binary_val_arg(ocp->type_arg3) << 2;
}

int		set_ocp_and_size(t_bdd **bdd)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 16)
	{
		while (j < bdd[i]->nb_ocp)
		{
			set_binary(bdd[i]->ocp[j]);
			set_size_adv(bdd[i]->ocp[j], bdd[i], i);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}
