#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "ft_printf.h"

int main()
{
/*	
	char	a;
	int		r;
	int		t;


	a = 'a';
	r = ft_printf("|abc%.10i123|\n", -42);
	t =    printf("|abc%.10i123|\n", -42);
	printf("r = %i\nt = %i\n", r, t);
*/	
/*
	printf("rien=	|%s|\n", "miaou mieou");
	printf("plus=	|%+s|\n", "miaou mieou");
	printf("minus=	|%-s|\n", "miaou mieou");
	printf("zero=	|%0s|\n", "miaou mieou");
	printf("Width=	|%20s|\n", "miaou mieou");
	printf("preci=	|%.20s|\n", "miaou mieou");
*/

	int r;
	//int v;

	r = printf("\n|%10x|\n", 42);
	//v = printf("\n|%10x|\n", 42);
	printf("r = %i\n", r);
}