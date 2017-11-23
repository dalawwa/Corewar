#include "corewar.h"

int		perror_int(char *s, int ret)
{
	perror(s);
	return (ret);
}
