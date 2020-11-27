#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "ft_printf.h"

int main()
{
	char	a;
	int		r;
	int		t;

/*
	a = 'a';
	r = ft_printf("|abcdef123456|\n");
	t =    printf("|abcdef123456|\n");
	printf("r = %i\nt = %i\n", r, t);

*/
	printf("|%0 -5i|", 35);
}