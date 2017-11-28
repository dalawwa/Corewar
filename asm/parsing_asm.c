/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_asm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfruchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 17:37:17 by bfruchar          #+#    #+#             */
/*   Updated: 2017/11/27 17:45:01 by bfruchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

//On verifie que le fichier est compatible, ".s"
void	check_valid_name(char *str)
{
	int	i;

	i = ft_strlen(str);
	if (i < 3 || str[i - 1] != 's' || str[i - 2] != '.')
		ciao_bye_bye(1);
	return ;
}

//recuperer le char* entre parentheses, c est a dire le nom et le comment et le mettre dans la structure head
void	value_parent(char *str, t_head *head, int x, int j)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '"')
		{
			i++;
			while (str[i] != '"')
			{
				i++;
				j++;
			}
			if (x == 1)
			{
				head->name = ft_strnew(j + 1);
				head->name = ft_strncpy(head->name, &str[i - j], j);
			}
			if (x == 2)
			{
				head->comment = ft_strnew(j + 1);
				head->comment = ft_strncpy(head->comment, &str[i - j], j);
			}
			return ;
		}
		i++;
	}
}

//on va chech qu il s agit bien d une ligne sans autre caractere que des espaces et tabs
int		check_no_printable_char(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isalpha(str[i]))
			return (0);
		i++;
	}
	return (1);
}

//check que l on retrouve bien .name et .comment au debut du fichier, il peut y avoir des lignes vides avant/apres/entre name et comment et il n y a pas un ordre precis
void	check_name_comment(t_head *head, int fd)
{
	char	*line;
	int		i;

	i = 0;
	line = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		if (ft_strnequ(".name", line, 5))
			value_parent(line, head, 1, 0);
		else if (ft_strnequ(".comment", line, 8))
			value_parent(line, head, 2, 0);
		else if (check_no_printable_char(line) == 0)
			ciao_bye_bye(1);
		if (head->name != NULL && head->comment != NULL)
			return ;
		i++;
	}
}

//lancement du parsing, on va d abord chercher a recuperer le nom + comment
////dans un second temps on va recuperer toutes les instructions
int	launch_parsing(char *str)
{
	int		fd;
	t_head	header;
	t_champ	champ;

	if ((fd = open(str, O_RDONLY)) == -1)
		return (-1);
	check_valid_name(str);
	start_struct(&header);
	start_struct_champ(&champ);
	check_name_comment(&header, fd);
	ft_printf("%s\n%s\n", header.name, header.comment);
	get_champ_data(&champ, fd);
	return (0);
}
