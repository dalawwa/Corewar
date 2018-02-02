/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_a_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfruchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 18:42:43 by bfruchar          #+#    #+#             */
/*   Updated: 2018/01/30 15:15:36 by bfruchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		put_in_file_dir_a(int i, t_champ *champ, char *str)
{
	int	j;

	i = 0;
	j = 0;
	if (*str != '%')
		return (0);
	(str)++;
	if (str && *str == ':' && (str)++)
		j = position_label(champ, str);
	else
		j = ft_atoi(str);
	ft_printf("%-18i", j);
	return (1);
}

int		find_translat_a2(t_champ *champ, char **str, int i)
{
	if (i == 9 || i == 12 || i == 15)
		return (put_in_file_dir_a(2, champ, str[1]));
	else if ((i == 10 || i == 14) && (((put_in_file_reg_a(str[1])
						|| put_in_file_dir_a(2, champ, str[1])
						|| put_in_file_indir_a(champ, str[1]))
					&& (put_in_file_reg_a(str[2])
						|| put_in_file_dir_a(2, champ, str[2])))))
		return (put_in_file_reg_a(str[3]));
	else if (i == 11 && ((put_in_file_reg_a(str[1])
					&& (put_in_file_reg_a(str[2])
						|| put_in_file_dir_a(2, champ, str[2])
						|| put_in_file_indir_a(champ, str[2]))
					&& (put_in_file_reg_a(str[3])
						|| put_in_file_dir_a(2, champ, str[3])))))
		return (1);
	else if (i == 16)
		return (put_in_file_reg_a(str[1]));
	return (1);
}

int		find_translat_a(t_champ *champ, char **str, int i)
{
	if (i == 1)
		return (put_in_file_dir_a(4, champ, str[1]));
	else if ((i == 2 || i == 13)
			&& ((put_in_file_dir_a(4, champ, str[1])
					|| put_in_file_indir_a(champ, str[1])))
			&& (put_in_file_reg_a(str[2])))
		return (1);
	else if ((i == 3
				&& put_in_file_reg_a(str[1])
				&& (put_in_file_reg_a(str[2])
					|| put_in_file_indir_a(champ, str[2]))))
		return (1);
	else if ((i == 4 || i == 5)
			&& put_in_file_reg_a(str[1]) && put_in_file_reg_a(str[2])
			&& put_in_file_reg_a(str[3]))
		return (1);
	else if ((i == 6 || i == 7 || i == 8)
			&& ((put_in_file_reg_a(str[1])
					|| put_in_file_dir_a(4, champ, str[1])
					|| put_in_file_indir_a(champ, str[1]))
				&& (put_in_file_reg_a(str[2])
					|| put_in_file_dir_a(4, champ, str[2])
					|| put_in_file_indir_a(champ, str[2]))))
		return (put_in_file_reg_a(str[3]));
	return (find_translat_a2(champ, str, i));
}

void	treat_and_temp(char *str, int i)
{
	g_temp++;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	while (str[i] != ' ' && str[i] != '\t')
		i++;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	while (str[i] != ' ' && str[i] != '\t')
		i++;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == 'r')
		g_temp += 2;
	else
		g_temp += 3;
}
