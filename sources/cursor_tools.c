/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 16:26:15 by tgouedar          #+#    #+#             */
/*   Updated: 2019/08/22 16:10:56 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termios.h>
#include <term.h>
#include "libft.h"
#include "parsing.h"
#include "word_tools.h"

void	ft_init_cursor(t_cursor *cursor)
{
	ft_memset(cursor->cmd_line, '\0', MAX_LINE);
	cursor->line_len = 0;
	cursor->display_cursor = 0;
	cursor->char_cursor = 0;
	cursor->in_history = 0;
}

void	ft_reajust_cursor_wrap(t_cursor *cursor, int flag)
{
	char		*tc;
	size_t		i;

	i = ft_strlen(PROMPT) + cursor->display_cursor;
	if (flag == UP && !(i % ft_get_term_length()))
	{
		tc = tgetstr("up", NULL);
		tputs(tc, 1, &ft_pc);
	}
	else if (flag == DOWN && !((i + 1) % ft_get_term_length()))
	{
		tc = tgetstr("do", NULL);
		tputs(tc, 1, &ft_pc);
	}
}

void	ft_cursor_reset(size_t ref)
{
	char	*buff;
	size_t	pos;
	size_t	co;

	pos = ft_strlen(PROMPT) + ref;
	co = ft_get_term_length();
	if ((co))
		pos /= co;
	buff = tgetstr("up", NULL);
	while (pos)
	{
		tputs(buff, 1, &ft_pc);
		pos--;
	}
	buff = tgetstr("ch", NULL);
	buff = tgoto(buff, 1, 0);
	tputs(buff, 1, &ft_pc);
}

void	ft_position_cursor(t_cursor *cursor)
{
	char	*buff;
	size_t	pos;
	size_t	co;

	pos = ft_strlen(PROMPT) + cursor->display_cursor;
	co = ft_get_term_length();
	buff = tgetstr("do", NULL);
	while (pos >= co)
	{
		tputs(buff, 1, &ft_pc);
		pos -= co;
	}
	buff = tgetstr("ch", NULL);
	buff = tgoto(buff, 0, pos);
	tputs(buff, 1, &ft_pc);
}
