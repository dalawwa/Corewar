# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/04 03:03:10 by mapandel          #+#    #+#              #
#    Updated: 2017/09/26 12:24:57 by mapandel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	corewar
LIB =	libft.a
#				Compilation

CC = 	gcc
CFLAGS = -Wall -Wextra -Werror -g

#			SOURCES libft

CONV =			conv/ft_atoi.c \
				conv/ft_atoi_iter.c \
				conv/ft_atoi_spacesless.c \
				conv/ft_atoi_spacesless_iter.c \
				conv/ft_atoi_strict.c \
				conv/ft_ctoa.c \
				conv/ft_itoa.c \
				conv/ft_lltoabase_signed.c \
				conv/ft_lltoabase_signless.c \
				conv/ft_lltoabase_unsigned.c \
				conv/ft_wctowa.c \

FT_PRINTF =		ft_printf/ft_printf_c.c \
				ft_printf/ft_printf_cc.c \
				ft_printf/ft_printf_conv.c \
				ft_printf/ft_printf_d.c \
				ft_printf/ft_printf_display.c \
				ft_printf/ft_printf_get_conv.c \
				ft_printf/ft_printf_get_flags.c \
				ft_printf/ft_printf_get_modifier.c \
				ft_printf/ft_printf_get_precision.c \
				ft_printf/ft_printf_get_width.c \
				ft_printf/ft_printf_no_conv.c \
				ft_printf/ft_printf_o.c \
				ft_printf/ft_printf_p.c \
				ft_printf/ft_printf_parsing.c \
				ft_printf/ft_printf_percent.c \
				ft_printf/ft_printf_s.c \
				ft_printf/ft_printf_ss.c \
				ft_printf/ft_printf_u.c \
				ft_printf/ft_printf_x.c \
				ft_printf/ft_printf.c \
				ft_printf/touch_t_printf.c \

GET_NEXT =		get_next/get_next_line.c \
				get_next/get_next_char.c \

IS =			is/ft_isalnum.c \
				is/ft_isalpha.c \
				is/ft_isascii.c \
				is/ft_isblank.c \
				is/ft_iscntrl.c \
				is/ft_isdigit.c \
				is/ft_isgraph.c \
				is/ft_isinf.c \
				is/ft_islessinf.c \
				is/ft_islower.c \
				is/ft_isnan.c \
				is/ft_isprint.c \
				is/ft_ispunct.c \
				is/ft_isspace.c \
				is/ft_isupper.c \
				is/ft_isxdigit.c \
				is/ft_strisalnum.c \
				is/ft_strisalpha.c \
				is/ft_strisascii.c \
				is/ft_strisblank.c \
				is/ft_striscntrl.c \
				is/ft_strisdigit.c \
				is/ft_strisgraph.c \
				is/ft_strislower.c \
				is/ft_strisprint.c \
				is/ft_strispunct.c \
				is/ft_strisspace.c \
				is/ft_strisupper.c \
				is/ft_strisxdigit.c \
				is/ft_tabisdescending.c \
				is/ft_tabisincreasing.c \

LST =			lst/ft_lstadd.c \
				lst/ft_lstdel.c \
				lst/ft_lstdelone.c \
				lst/ft_lstiter.c \
				lst/ft_lstmap.c \
				lst/ft_lstnew.c \

MEM =			mem/ft_bzero.c \
				mem/ft_memalloc.c \
				mem/ft_memccpy.c \
				mem/ft_memchr.c \
				mem/ft_memcmp.c \
				mem/ft_memcpy.c \
				mem/ft_memdel.c \
				mem/ft_memmove.c \
				mem/ft_memset.c \

PUT =			put/ft_putchar.c \
				put/ft_putchar_buffer.c \
				put/ft_putchar_fd.c \
				put/ft_putchar_fd_buffer.c \
				put/ft_putendl.c \
				put/ft_putendl_buffer.c \
				put/ft_putendl_fd.c \
				put/ft_putendl_fd_buffer.c \
				put/ft_puterror.c \
				put/ft_puterror_exit.c \
				put/ft_putllnbr.c \
				put/ft_putllnbr_buffer.c \
				put/ft_putmap.c \
				put/ft_putnbr.c \
				put/ft_putnbr_fd.c \
				put/ft_putstr.c \
				put/ft_putstr_buffer.c \
				put/ft_putstr_fd.c \
				put/ft_putstr_fd_buffer.c \
				put/ft_putwchar.c \
				put/ft_putwchar_buffer.c \
				put/ft_putwchar_fd.c \
				put/ft_putwchar_fd_buffer.c \
				put/ft_putwendl.c \
				put/ft_putwendl_buffer.c \
				put/ft_putwendl_fd.c \
				put/ft_putwendl_fd_buffer.c \
				put/ft_putwstr.c \
				put/ft_putwstr_buffer.c \
				put/ft_putwstr_fd.c \
				put/ft_putwstr_fd_buffer.c \

SORT =			sort/ft_qsort.c \
				sort/ft_strmapsort.c \

STR =			str/ft_stradd.c \
				str/ft_stradd_leakless.c \
				str/ft_strbuffer.c \
				str/ft_strbuffer_leakless.c \
				str/ft_strcat.c \
				str/ft_strcat_nullcrashless.c \
				str/ft_strccat.c \
				str/ft_strccat_nullcrashless.c \
				str/ft_strccmp.c \
				str/ft_strccpy.c \
				str/ft_strccpy_nullcrashless.c \
				str/ft_strchr.c \
				str/ft_strcjoin.c \
				str/ft_strcjoin_leakless.c \
				str/ft_strclen.c \
				str/ft_strclen_nullcrashless.c \
				str/ft_strclr.c \
				str/ft_strcmp.c \
				str/ft_strcpy.c \
				str/ft_strcpy_nullcrashless.c \
				str/ft_strdel.c \
				str/ft_strdup.c \
				str/ft_strequ.c \
				str/ft_strfill.c \
				str/ft_strinc.c \
				str/ft_striter.c \
				str/ft_striteri.c \
				str/ft_strjoin.c \
				str/ft_strjoin_leakless.c \
				str/ft_strlcat.c \
				str/ft_strlen.c \
				str/ft_strlen_nullcrashless.c \
				str/ft_strmap.c \
				str/ft_strmapconcat.c \
				str/ft_strmapconcat_leakless.c \
				str/ft_strmapdel.c \
				str/ft_strmapi.c \
				str/ft_strmaplen.c \
				str/ft_strmaplen_nullcrashless.c \
				str/ft_strncat.c \
				str/ft_strncat_nullcrashless.c \
				str/ft_strncmp.c \
				str/ft_strncpy.c \
				str/ft_strnequ.c \
				str/ft_strnew.c \
				str/ft_strnjoin.c \
				str/ft_strnjoin_leakless.c \
				str/ft_strnstr.c \
				str/ft_strplugc.c \
				str/ft_strrchr.c \
				str/ft_strrev.c \
				str/ft_strrev_leakless.c \
				str/ft_strsplit.c \
				str/ft_strstr.c \
				str/ft_strsub.c \
				str/ft_strsub_leakless.c \
				str/ft_strtolower.c \
				str/ft_strtolower_leakless.c \
				str/ft_strtoupper.c \
				str/ft_strtoupper_leakless.c \
				str/ft_strtrim.c \

TAB =			tab/ft_tabadd.c \
				tab/ft_tabadd_leakless.c \
				tab/ft_tabcpy.c \
				tab/ft_tabdel.c \
				tab/ft_tabdup.c \
				tab/ft_tabfill.c \
				tab/ft_tabfindpos.c \
				tab/ft_tabfindpos_over.c \
				tab/ft_tabfindpos_overeq.c \
				tab/ft_tabfindpos_under.c \
				tab/ft_tabfindpos_undereq.c \
				tab/ft_tabfindrev.c \
				tab/ft_tabfindrev_over.c \
				tab/ft_tabfindrev_overeq.c \
				tab/ft_tabfindrev_under.c \
				tab/ft_tabfindrev_undereq.c \
				tab/ft_tabmax.c \
				tab/ft_tabmax_underone.c \
				tab/ft_tabmaxpos.c \
				tab/ft_tabmaxpos_underone.c \
				tab/ft_tabmedian.c \
				tab/ft_tabmin.c \
				tab/ft_tabmin_overone.c \
				tab/ft_tabminpos_overone.c \
				tab/ft_tabminpos.c \
				tab/ft_tabncpy.c \
				tab/ft_tabnew.c \
				tab/ft_tabpercentile.c \
				tab/ft_tabpush.c \
				tab/ft_tabrev.c \
				tab/ft_tabrev_leakless.c \
				tab/ft_tabrevrotate.c \
				tab/ft_tabrotate.c \
				tab/ft_tabswap.c \

TO =			to/ft_tolower.c \
				to/ft_toupper.c \

WSTR =			wstr/ft_wstradd.c \
				wstr/ft_wstradd_leakless.c \
				wstr/ft_wstrbuffer.c \
				wstr/ft_wstrbuffer_leakless.c \
				wstr/ft_wstrcat.c \
				wstr/ft_wstrcat_nullcrashless.c \
				wstr/ft_wstrclr.c \
				wstr/ft_wstrcpy.c \
				wstr/ft_wstrcpy_nullcrashless.c \
				wstr/ft_wstrdel.c \
				wstr/ft_wstrdup.c \
				wstr/ft_wstrfill.c \
				wstr/ft_wstrjoin.c \
				wstr/ft_wstrjoin_leakless.c \
				wstr/ft_wstrlen.c \
				wstr/ft_wstrlen_nullcrashless.c \
				wstr/ft_wstrlenuni.c \
				wstr/ft_wstrnew.c \
				wstr/ft_wstrsub.c \
				wstr/ft_wstrsub_leakless.c \

SRC :=			$(CONV) $(FT_PRINTF) $(GET_NEXT) $(IS) $(LST) $(MEM) $(PUT) \
				$(SORT) $(STR) $(TAB) $(TO) $(WSTR)

OBJ =			$(SRC:.c=.o)
OBJ_CONV =		$(CONV:.c=.o)
OBJ_FT_PRINTF =	$(FT_PRINTF:.c=.o)
OBJ_GET_NEXT =	$(GET_NEXT:.c=.o)
OBJ_IS =		$(IS:.c=.o)
OBJ_LST =		$(LST:.c=.o)
OBJ_MEM =		$(MEM:.c=.o)
OBJ_PUT =		$(PUT:.c=.o)
OBJ_SORT =		$(SORT:.c=.o)
OBJ_STR =		$(STR:.c=.o)
OBJ_TAB =		$(TAB:.c=.o)
OBJ_TO =		$(TO:.c=.o)
OBJ_WSTR =		$(WSTR:.c=.o)

INC =			includes

LIBFT_CFILES = $(addprefix $(PATH_LIB), $(SRC))
LIBFT_OFILES = $(addprefix $(PATH_LIB), $(OBJ))

#			Sources

PATH_LIB = ../libft/
PATH_SRCS = ./srcs/
PATH_HEAD = ./includes/
PATH_LIBFT_HEAD = ../libft/includes/
PATH_OBJS = ./objs/

SRCS_NAME = main.c \
			get_nb_cors.c \
			check_opts.c \
			create_players.c \
			ft_stradd_c_end.c \
			print_debug.c \
			go_match.c \
			create_arena.c \
			free_all.c \
			print_players.c \
			create_mem.c \
			print_mem.c

CW_SRCS = $(addprefix $(PATH_SRCS), $(SRCS_NAME))
CW_OBJS = $(addprefix $(PATH_OBJS), $(SRCS_NAME:.c=.o))

#			Colors

DEF =			\033[0m
GRA =			\033[1m
SOU =			\033[4m
BLI =			\033[5m
INV =			\033[7m
BLA =			\033[30m
RED =			\033[31m
GRE =			\033[32m
YEL =			\033[33m
BLU =			\033[34m
PUR =			\033[35m
CYA =			\033[36m
WHI =			\033[37m
BACK_BLA =		\033[40m
BACK_RED =		\033[41m
BACK_GRE =		\033[42m
BACK_YEL =		\033[43m
BACK_BLU =		\033[44m
BACK_PUR =		\033[45m
BACK_CYA =		\033[46m
BACK_WHI =		\033[47m

#			Main Rules

.PHONY: all conv ft_printf get_next is lst mem put sort str tab to wstr \
	indexion re glu  clean fclean

all: $(NAME)

$(PATH_LIB)$(LIB): $(LIBFT_OFILES)

$(NAME): $(PATH_LIB)$(LIB) $(LIBFT_OFILES) $(CW_OBJS)
	make -C $(PATH_LIB)
	@echo "$(GRE)--::$(NAME)-> Compilation::--$(DEF)"
	$(CC) $(CFLAGS) -o $@ $(CW_OBJS) $(PATH_LIB)$(LIB)

re: fclean all

$(PATH_OBJS)%.o: $(PATH_SRCS)%.c
	$(CC) $(CFLAGS) -I$(PATH_HEAD) -o $@ -c $^

$(PATH_LIB)%.o: $(PATH_LIB)%.c
	$(CC) $(CFLAGS) -I$(PATH_LIBFT_HEAD) -o $@ -c $^

clean:
	make clean -C $(PATH_LIB)
	rm -f $(CW_OBJS)
	@echo "$(PUR)--::$(NAME)-> Deleting Objects::--$(DEF)"

fclean: clean
	rm -rf $(PATH_LIB)$(LIB)
	@echo "$(RED)--::$(NAME)-> Deleting Exec::--$(DEF)"
	rm -rf $(NAME)
