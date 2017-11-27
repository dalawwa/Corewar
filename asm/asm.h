/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfruchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 11:29:30 by bfruchar          #+#    #+#             */
/*   Updated: 2017/11/27 17:37:47 by bfruchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"
# include "../libft/includes/ft_printf.h"


typedef struct		s_head
{
	char			*name;
	char			*comment;
}					t_head;

typedef struct		s_champ
{
	char			*line;
	char			*op;
	int				is_label;
	int				position;
	char			**params;
	struct s_champ	*next;
	struct s_champ	*prev;
}					t_champ;

int		main(int ac, char **av);
int		launch_parsing(char *str);
void	get_champ_data(t_champ *champ, int fd);
void	start_struct(t_head *head);
void	start_struct_champ(t_champ *champ);
void	get_champ_data(t_champ *champ, int fd);
void	check_name_comment(t_head *head, int fd);
int		check_no_printable_char(char *str);
void	value_parent(char *str, t_head *head, int x, int j);
void	check_valid_name(char *str);
void	ciao_bye_bye(int i);

#endif
