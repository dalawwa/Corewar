#include "corewar.h"

int		ft_unsi_strcmp(unsigned char *s1, unsigned char *s2)
{
	unsigned char *ss1;
	unsigned char *ss2;

	ss1 = s1;
	ss2 = s2;
	while (ss1 && ss2 && *ss1 == *ss2)
	{
		ss1++;
		ss2++;
	}
	return (*ss1 - *ss2);
}
