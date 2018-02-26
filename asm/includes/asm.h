/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfruchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 11:29:30 by bfruchar          #+#    #+#             */
/*   Updated: 2018/01/30 15:16:02 by bfruchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../../libft/includes/libft.h"
# include "../../libft/includes/get_next_line.h"
# include "../../libft/includes/ft_printf.h"

# define IND_SIZE				2
# define REG_SIZE				4
# define DIR_SIZE				REG_SIZE

# define REG_CODE				1
# define DIR_CODE				2
# define IND_CODE				3

# define MAX_ARGS_NUMBER			4
# define MAX_PLAYERS				4
# define MEM_SIZE				(4*1024)
# define IDX_MOD					(MEM_SIZE / 8)
# define CHAMP_MAX_SIZE			(MEM_SIZE / 6)

# define COMMENT_CHAR			'#'
# define LABEL_CHAR				':'
# define DIRECT_CHAR				'%'
# define SEPARATOR_CHAR			','

# define LABEL_CHARS				"abcdefghijklmnopqrstuvwxyz_0123456789"

# define NAME_CMD_STRING			".name"
# define COMMENT_CMD_STRING		".comment"

# define REG_NUMBER				16

# define CYCLE_TO_DIE			1536
# define CYCLE_DELTA				50
# define NBR_LIVE				21
# define MAX_CHECKS				10

# define T_REG					1
# define T_DIR					2
# define T_IND					4
# define T_LAB					8

# define PROG_NAME_LENGTH		(128)
# define COMMENT_LENGTH			(2048)
# define COREWAR_EXEC_MAGIC		0xea83f3

int						g_position;
int						g_size_line;
int						g_temp;
int						g_error_msg;
int						g_line_error;

typedef struct			s_champ
{
	char				*label;
	int					position;
	struct s_champ		*next;
}						t_champ;

typedef struct			s_header
{
	unsigned int		magic;
	char				prog_name[PROG_NAME_LENGTH + 1];
	unsigned int		prog_size;
	char				comment[COMMENT_LENGTH + 1];
}						t_header;

int						main(int ac, char **av);
void					global_variables_size(void);
int						launch_parsing(char *str, int opt, char *file, int i);
int						label_or_not(char *line);
int						char_label(char c);
void					start_struct_champ(t_champ *champ);
t_champ					*get_champ_data(char **file, int fd, int i, char *line);
int						check_name_comment(int fd, t_header *op, int x, int y);
int						check_no_printable_char(char *str);
int						value_parent(char *str, int x, int j, t_header *op);
int						check_valid_name(char *str);
void					ciao_bye_bye(int i);
int						freedom_for_list(t_champ *lab);
t_champ					*ft_lstadd_lines(t_champ *begin, char *line, int i);
int						get_the_op_code(char *str);
void					add_number_args(t_champ *list);
int						check_args_valid(char **str, int op);
int						check_is_indirect(int i, char **str);
int						check_is_direct(int i, char **str, int opc);
int						check_is_reg(int i, char **str);
int						label_is_real(char *line, t_champ *champ);
int						ciao_bye(int i, char *str);
int						ciao_bye_name(int i, t_header *top);
void					ciao_free_end(t_champ *champ);
int						creat_cor(char *f, t_champ *c, t_header *op, char *s);
int						change_magic_order_second(int i);
void					move_in_the_file(char **str);
void					create_up_file(int fd, t_header *op);
int						change_magic_order(int i);
int						position_label(t_champ *champ, char *file);
int						put_in_file_reg(char **file, int fd);
int						put_in_file_dir(int i, t_champ *c, char **f, int fd);
int						put_in_file_indir(t_champ *champ, char **file, int fd);
int						get_the_op_code2(char *str);
void					l_writing_out(char *f, t_champ *c, t_header *op, int i);
int						next_order(char *str, int j);
void					opcod_number(char *str, int *o, int i, int c);
char					*name_dot_cor(char *str);
char					*after_command(char *str, int i);
int						next_order(char *str, int j);
char					*delete_comments(char *str);
int						next_order_space(char *str, int j);
int						get_opcode_a(char **str, int i);
int						put_in_file_reg_a(char *str);
int						put_in_file_indir_a(t_champ *champ, char *str);
int						find_translat_a(t_champ *champ, char **str, int i);
int						find_translat_a2(t_champ *champ, char **str, int i);
int						put_in_file_dir_a(int i, t_champ *champ, char *str);
void					temp_advance(int co, char *str);
void					treat_and_temp(char *str, int i);

#endif
