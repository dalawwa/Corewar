/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2_asm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfruchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 17:45:13 by bfruchar          #+#    #+#             */
/*   Updated: 2017/12/11 20:02:23 by bfruchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

//lignes vide ou commentaire non merci
int		this_is_a_comment(char *str)
{
	int	i;
	
	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '#' || str[i] == '\t' || str[i] == '\0' || str[i] == ';')
		return (1);
	else
		return (0);
}

int		line_not_empty(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		while ((str[i] == ' ' || str[i] == '\t') && str[i] != '\0')
			i++;
		if (str[i] == '#' || str[i] == ';' || str[i] == '\0')
			return (0);
		else
			return (1);
		i++;
	}
	return (0);
}

//on va recuperer la liste du fichier que l on va mettre dans une liste doublement chainee
//on ne va pas recuperer les lignes vides et les commentaires
void	get_champ_data(t_champ *champ, int fd)
{
	char	*line;
	int		i;

	i = 0;
	line = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		if (line_not_empty(line) == 1)
			i++;
		if (check_no_printable_char(line) || this_is_a_comment(line) || line_not_empty(line) == 0)
			;
		else 
			ft_lstadd_lines(&champ, line, i);
	}
	while (champ->next)
	{
		ft_printf("LINE: %s. COMMAND: %s. LABEL: %s. NAME: %s. NB PARAMS: %i. SIZE PARAMS: %i %i %i POSITION: %i\n", champ->line, champ->command, champ->label, champ->name, champ->nb_params, champ->size_param1, champ->size_param2, champ->size_param3, champ->position);
		champ = champ->next;
	}
		ft_printf("LINE: %s. COMMAND: %s. LABEL: %s. NAME: %s. NB PARAMS: %i. SIZE PARAMS: %i %i %i POSITION: %i\n", champ->line, champ->command, champ->label, champ->name, champ->size_param1, champ->nb_params, champ->size_param2, champ->size_param3, champ->position);
	return ;
}
