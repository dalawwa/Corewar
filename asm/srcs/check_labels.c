/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_labels.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfruchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 10:34:43 by bfruchar          #+#    #+#             */
/*   Updated: 2017/12/20 15:50:59 by bfruchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"


//checker if labels are not present twice
int		labels_not_multiple(t_champ *champ)
{
	t_champ	*test;

	test = champ;
	if (!champ)
		return (1);
	champ = champ->next;
	while (champ)
	{
		if (ft_strcmp(champ->label, test->label) == 0)
			return (0);
		champ = champ->next;
	}
	return (labels_not_multiple(test->next));
}

//on a le label de la ligne, on va checker avec celui qu on a recupere
int		check_label_line(char *line, t_champ *champ)
{
	int	j;

	j = 0;
	while (char_label(line[j]) == 1)
		j++;
	while (champ)
	{
		if (ft_strncmp(line, champ->label, j) == 0)
		{
			if (!champ->label[j])
				return (1);
		}
		champ = champ->next;
	}
	ciao_bye_bye(1);
	return (0);
}

//checker if label in the line is in the line
int		label_in_the_line(char *line, t_champ *champ)
{
	int		i;

	i = 0;
	if (!line)
		return (0);
	while (line[i] && line[i] != '%')
	{
		i++;
		if (line[i] == '%')
		{
			i++;
			if (line[i] == ':')
			{
				i++;
				check_label_line(&line[i], champ);
			}
		}
	}
	return (1);
}


//launch controls on labels
int		label_is_real(char *line, t_champ *champ)
{
	if (labels_not_multiple(champ) == 0)
		return (0);
	if (label_in_the_line(line, champ) == 0)
		return (0);
	return (1);
}
