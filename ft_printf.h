#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

#define BUFFER_SIZE 1024

typedef struct	s_tool
{
	char	*form;
	char	buff[BUFFER_SIZE];
	int		pos;
	int		buff_i;
	int		secu;
	int		r;
	int		if_preci;
	int		preci;
	int		if_width;
	int		width;
	int		plus;
	int		minus;
	int		zero;
	int		space;
}				t_tool;

int		ft_printf(char *form, ...);
void	init_tool(t_tool *tool, char *form);
void	init_tab(void (*tab[128])(t_tool *tool, va_list ap));
void	put_buff(t_tool *tool);
void	tag(void (*tab[128])(t_tool *tool, va_list ap), t_tool *tool, va_list ap);
void	put_width(t_tool *tool, int spaces, char space);
void	to_buff(t_tool *tool, char c);

void	skip(t_tool *tool, va_list ap);
void	plus(t_tool *tool, va_list ap);
void	minus(t_tool *tool, va_list ap);
void	zero(t_tool *tool, va_list ap);
void	asterisk(t_tool *tool, va_list ap);
void	space(t_tool *tool, va_list ap);
void	preci(t_tool *tool, va_list ap);
void	width(t_tool *tool, va_list ap);

void	manage_str(t_tool *tool, va_list ap);
void	manage_char(t_tool *tool, va_list ap);
void	manage_per(t_tool *tool, va_list ap);
void	manage_int(t_tool *tool, va_list ap);


#endif