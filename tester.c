#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "ft_printf.h"

int main()
{

	char	a;
	int		r;
	int		t;


	a = 'a';
	r = ft_printf("|%*.*s|\n", 20, 6, "abcdefg1234");
	t =    printf("|%*.*s|\n", 20, 6, "abcdefg1234");
	printf("r = %i\nt = %i\n", r, t);


/*
	printf("rien=	|%s|\n", "miaou mieou");
	printf("plus=	|%+s|\n", "miaou mieou");
	printf("minus=	|%-s|\n", "miaou mieou");
	printf("zero=	|%0s|\n", "miaou mieou");
	printf("Width=	|%20s|\n", "miaou mieou");
	printf("preci=	|%.20s|\n", "miaou mieou");
*/


	//printf("\n|%-5c|\n", 'a');
}