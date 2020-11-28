#include "ft_printf.h"

void	put_width(t_tool *tool, int spaces, char space)
{
	int	i;

	i = 0;
	while (i++ < spaces)
	{
		tool->buff[tool->buff_i++] = space;
		if (tool->buff_i == BUFFER_SIZE)
			put_buff(tool);
	}
}

void	to_buff(t_tool *tool, char c)
{
	tool->buff[tool->buff_i++] = c;
	if (tool->buff_i == BUFFER_SIZE)
		put_buff(tool);
}