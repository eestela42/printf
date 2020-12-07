#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "ft_printf.h"

int main()
{

	char	*a;
	int		r;
	int		t;


	a = malloc(sizeof(char) * 23);

	r = ft_printf("|%p|\n", a);
	t =    printf("|%p|\n", a);
	printf("r = %i\nt = %i\n", r, t);
	
/*
	printf("rien=	|%s|\n", "miaou mieou");
	printf("plus=	|%+s|\n", "miaou mieou");
	printf("minus=	|%-s|\n", "miaou mieou");
	printf("zero=	|%0s|\n", "miaou mieou");
	printf("Width=	|%20s|\n", "miaou mieou");
	printf("preci=	|%.20s|\n", "miaou mieou");
*/
/*
	int r;
	char *tab;
	//int v;

	tab = "abcdef";
	r = printf("\n|%c|\n", tab[2]);
	//v = printf("\n|%10x|\n", 42);
	printf("r = %i\n", r);
	*/
}