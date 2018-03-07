#ifndef COREWAR_H
# define COREWAR_H
# include "../../libft/includes/libft.h"
# include "../../libft/includes/get_next_line.h"
# include "../../libft/includes/ft_printf.h"
# include <fcntl.h>

//typedef int		(*t_fct)(struct s_vm*, struct s_exe*);
// op.h
//

// checker la taille des datas...

# define IND_SIZE				2
# define REG_SIZE				4
# define DIR_SIZE				REG_SIZE

# define REG_CODE				1
# define DIR_CODE				2
# define IND_CODE				3

# define MAX_ARGS_NUMBER		4
# define MAX_PLAYERS			4
# define MEM_SIZE				(4*1024)
# define IDX_MOD				(MEM_SIZE / 8)
# define CHAMP_MAX_SIZE			(MEM_SIZE / 6)

# define COMMENT_CHAR			'#'
# define LABEL_CHAR				':'
# define DIRECT_CHAR			'%'
# define SEPARATOR_CHAR			','

# define LABEL_CHARS			"abcdefghijklmnopqrstuvwxyz_0123456789"

# define NAME_CMD_STRING		".name"
# define COMMENT_CMD_STRING		".comment"

# define REG_NUMBER				16

# define CYCLE_TO_DIE			1536
# define CYCLE_DELTA			50
# define NBR_LIVE				21
# define MAX_CHECKS				10

/*
 * **
 * */

typedef char					t_arg_type;

# define T_REG					1
# define T_DIR					2
# define T_IND					4
# define T_LAB					8


# define PROG_NAME_LENGTH		(128)
# define COMMENT_LENGTH			(2048)
# define COREWAR_EXEC_MAGIC		0xea83f3

# define NB_OP					16

typedef struct	s_header
{
	unsigned int	magic;
	char			prog_name[PROG_NAME_LENGTH + 1];
	unsigned int	prog_size;
	char			comment[COMMENT_LENGTH + 1];
}				t_header;

/*
 * FIN DE op.h
 */

typedef struct	s_opt
{
	int		has_d;
	int		d;
	int		has_v;
	char	v;
	int		is_v0;
	int		is_v1;
	int		is_v2;
	int		is_v4;
	int		is_v8;
	int		is_v16;
	int		has_s;
	int		show_cycle;
	int		show_op;
	int		show_death;
	int		show_live;
	int		show_pc_mvt; 
	int		s;
	int		has_a;
	int		a_stealth;
	int		has_b;
	int		b_stealth;
}				t_opt;

typedef struct	s_file
{
	int		fd;
	char	*name;
}				t_file;

typedef struct	s_proc
{
	int				process_num;
	unsigned char	reg[REG_NUMBER + 1][REG_SIZE];
	int				pc;
	int				carry;
	struct s_play	*player;
	struct s_exe	*exe_op;
	int				op_success;
	int				nb_live;
	int				last_cycle_alive;
	int				creation_cycle;
	int				is_process_launched;
	struct s_proc	*parent;
	struct s_proc	*next;
	struct s_proc	*prev;
}				t_proc;

typedef struct	s_play
{
	int				play_num;
	int				size;
	unsigned char	play_live_num[REG_SIZE];
	int				idx_start;
	char			*name;
	char			*comment;
	int				body_len;
	unsigned char	*body;
	int				last_live;
}				t_play;

typedef struct	s_arg
{
	unsigned char	*value;
	int				d_value;
	char			type;
	int				size;
	unsigned char	*data;
	int				d_data;
}				t_arg;

typedef struct	s_exe
{
	unsigned char	opcode;
	unsigned char	ocp;
	t_arg			*arg1;
	t_arg			*arg2;
	t_arg			*arg3;
	int				to_wait;
	int				size_failed_adv;
	t_proc			*process;
	struct s_bdd	*bdd_op;
	struct s_ocp	*ocp_op;
}				t_exe;

typedef struct	s_proc_base
{
	int		nb_proc;
	int		total_proc;
	int		nb_live_total;
	t_proc	*first;
	t_proc	*last;
}				t_proc_base;

typedef struct	s_arena
{
	int				nb_players;
	int				current_nb_check;
	t_play			**players;
	unsigned char	mem[MEM_SIZE];
	struct s_bdd	**bdd;
	t_proc_base		*list_proc;
	t_opt			*opts;
	t_file			**files;
	t_play			*last_player_alive;
	int				ctd;
	int				current_cycle;
	int				total_cycle;
	int				max_check;
	int				c_delta;
}				t_arena;

typedef struct	s_ocp
{
	unsigned char		ocp;
	int		size_adv;
	char	type_arg1;
	int		size_arg1;
	char	type_arg2;
	int		size_arg2;
	char	type_arg3;
	int		size_arg3;
	int		(*fct)(t_arena*, t_exe*);
}				t_ocp;

typedef struct	s_bdd
{
	char			*name;
	unsigned char	opcode;
	int				has_ocp;
	int				nb_ocp;
	t_ocp			**ocp;
	int				nb_args;
	int				nb_cycle;
	char			*meaning;
}				t_bdd;

/* 
 * Create ARENA 
 */
int				init_arena(t_arena **arena);
int				check_opts(t_arena *arena, int ac, char **av);
void			set_v_values(t_opt *opts, int val);
int				create_arena(int ac, char **av, t_arena **arena);
int				*get_fds(t_arena **arena, int ac, char **av);
int				is_cor(char *s);
void			close_cors(t_arena *arena);
int				create_mem(t_arena *arena);

/* 
 * Create PLAYERS 
 */
int				create_players(t_arena *arena);
int				has_nb_magic(t_file *file);
unsigned char	*add_that(unsigned char *body, char c, int where);
unsigned char	*clean_body(unsigned char *body, t_play **player);
char			*find_comment(t_file *file);
char			*find_name(t_file *file);

/* 
 * Create BDD 
 */
int				create_bdd(t_arena *arena);
int				create_ocp(t_bdd *bdd_i, int i);
int				set_bdd_ocp(t_arena *arena);
int				set_ocp_and_size(t_bdd **bdd);
int				set_args_type(t_bdd *bdd_i, int i);

/* 
 * Setup Match
 */
int				setup_players(t_arena *arena);
int				initialized_start_process(t_arena *arena);


/* 
 * Gestion PROCESS & EXE
 */
int				create_new_process(t_arena *arena, t_play *player, t_proc *parent);
void			copy_parent_data(t_proc *parent, t_proc *son);
int				create_new_exe(t_arena *arena, t_proc *process);
int				fill_new_exe(t_arena *arena, t_proc *process);
int				set_args_values(t_proc *process, t_arena *arena, int *i);
int				set_data(t_arg *arg, t_arena *arena, t_proc *process, int i);

/* 
 * OP
 */
int				op_ld(t_arena *arena, t_exe *exe);
int				op_lld(t_arena *arena, t_exe *exe);
int				op_lldi(t_arena *arena, t_exe *exe);
int				op_ldi(t_arena *arena, t_exe *exe);
int				op_st(t_arena *arena, t_exe *exe);
int				op_sti(t_arena *arena, t_exe *exe);
int				op_aff(t_arena *arena, t_exe *exe);
int				op_live(t_arena *arena, t_exe *exe);
int				op_and(t_arena *arena, t_exe *exe);
int				op_add(t_arena *arena, t_exe *exe);
int				op_or(t_arena *arena, t_exe *exe);
int				op_xor(t_arena *arena, t_exe *exe);
int				op_sub(t_arena *arena, t_exe *exe);
int				op_fork(t_arena *arena, t_exe *exe);
int				op_lfork(t_arena *arena, t_exe *exe);
int				op_zjmp(t_arena *arena, t_exe *exe);

/* 
 * Gestion MATCH & OP
 */
int				get_adv(int adv);
void			go_match(t_arena *arena);
int				deal_exe(t_arena *arena);
void			kill_process(t_proc *to_kill, t_proc_base *list_proc);
int				start_match(t_arena *arena);
int				is_carry_to_modify(t_exe *exe);
int				is_valid_op(t_arena *arena, t_proc *proc);
int				inc_pc(t_proc *process, int adv);
unsigned char	find_char_at_mem_pc_adv(int pc, int adv, t_arena *arena);
int				count_failed_adv(t_arena *arena, t_exe *exe);
int				find_pc_adv(int pc, int adv, int stop);
int				is_valid_ocp(int opcode, int ocp);

/*
 * Gestion PRINT
 */
void			print_usage(void);
void			print_exe_opts(t_arena *arena, t_exe *exe);
void			print_proc_num_name(t_exe *exe);
void			print_add_sub(t_arena *area, t_exe *exe);
void			print_failed_exe(t_arena *arena, t_exe *exe, int size);
void			print_mem(t_arena *arena);

/* 
 * FREE Memory
 */
void			free_arena(t_arena **arena);
void			free_fds(int **fds);
void			free_opts(t_opt *opts);
void			free_players(t_play **players, int nb_players);
void			free_bdd(t_bdd **bdd);
void			free_exe(t_exe *exe, t_proc *process);
void			free_arg(t_arg *arg);

/* 
 * UTILS
 */
int				ft_abs(int n);
unsigned char	*ft_unsi_strdup(unsigned char *s, int len);
unsigned char	*ft_ito_hexa(uintmax_t n);
int				intlen(int n);
void			put_n_char(char c, int n);
int				perror_int(char *s, int ret);
void			*perror_ptr(char *s, void *ret);
char			*addstr(char *s);
unsigned int	a_hexa_to_i(unsigned char *s, int len);

#endif