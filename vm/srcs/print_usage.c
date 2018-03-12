#include "corewar.h"

int    print_usage(void)
{
    ft_putendl("Usage: ./corewar [-d N -s N -v N | -b --stealth | -n --stealth] [-a] <champion1.cor> <...>\n");
    ft_putendl("\t-a\t\t: Prints output from aff (Default is to hide it)\n");
    ft_putendl("#### TEXT OUTPUT MODE ##########################################################\n");
    ft_putendl("\t-d N\t\t: Dumps memory after N cycles then exits\n");
    ft_putendl("\t-s N\t\t: Runs N cycles, dumps memory, pauses, then repeats\n");
    ft_putendl("\t-v N\t\t: Verbosity levels, can be added together to enable several\n");
    ft_putendl("\t\t\t\t- 0 : Show only essentials\n");
    ft_putendl("\t\t\t\t- 1 : Show lives\n");
    ft_putendl("\t\t\t\t- 2 : Show cycles\n");
    ft_putendl("\t\t\t\t- 4 : Show operations (Params are NOT litteral ...)\n");
    ft_putendl("\t\t\t\t- 8 : Show deaths\n");
    ft_putendl("\t\t\t\t- 16 : Show PC movements (Except for jumps)\n");
    ft_putendl("#### BINARY OUTPUT MODE ########################################################\n");
    ft_putendl("\t-b\t\t: Binary output mode for corewar.42.fr\n");
    ft_putendl("\t--stealth\t: Hides the real contents of the memory\n");
    ft_putendl("#### NCURSES OUTPUT MODE #######################################################\n");
    ft_putendl("\t-n\t\t: Ncurses output mode\n");
    ft_putendl("\t--stealth\t: Hides the real contents of the memory\n");
    ft_putendl("################################################################################\n");
return (0);
}