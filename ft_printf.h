#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

#define BUFFER_SIZE 2

typedef struct	s_tool
{
	char	*form;
	char	buff[BUFFER_SIZE];
	int		pos;
	int		buff_i;
	int		r;
	int		preci;
	int		width;
	int		plus;
	int		minus;
	int		zero;
}				t_tool;

int		ft_printf(char *form, ...);
void	init_tool(t_tool *tool, char *form);
void	init_tab(int (*tab[128])(t_tool *tool, va_list ap));
void	put_buff(t_tool *tool);
int		skip(t_tool *tool, va_list ap);
void	tag(int (*tab[128])(t_tool *tool, va_list ap), t_tool *tool, va_list ap);
#endif