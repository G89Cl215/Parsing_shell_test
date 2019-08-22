/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 12:06:54 by tgouedar          #+#    #+#             */
/*   Updated: 2019/08/22 14:36:24 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "parsing.h"
#include "dispatcher.h"
#include "libft.h"
#include "d_list.h"
#include "word_tools.h"

void	ft_load_history(t_cursor *cursor)
{
	size_t	len;

	ft_bzero(cursor->cmd_line, MAX_LINE);
	len = ft_strlen((cursor->history)->cmd_line);
	ft_memcpy(cursor->cmd_line, (cursor->history)->cmd_line, len);
	cursor->char_cursor = len;
	cursor->line_len = len;
	cursor->display_cursor = ft_display_len(cursor->cmd_line);
}

void	ft_clean_history(t_dlist **history)
{
	t_dlist		*voyager;

	if ((*history))
	{
		voyager = *history;
		while ((voyager->prev))
			voyager = voyager->prev;
		*history = voyager;
		while ((voyager))
		{
			if (voyager->status == CUR_CMD)
				voyager = ft_del_dnod(voyager);
			else
				voyager = voyager->next;
		}
	}
}

int		ft_up_cursor(t_cursor *cursor)
{
	if (!(cursor->in_history))
	{
		cursor->in_history = 1;
		ft_dlistadd_start(&(cursor->history), ft_new_dnod(cursor->cmd_line, CUR_CMD));
	}
	if ((cursor->history) && ((cursor->history)->next))
	{
		cursor->history = (cursor->history)->next;
		ft_load_history(cursor);
		ft_update_line(cursor, NULL);
	}
	return (1);
}

int		ft_down_cursor(t_cursor *cursor)
{
	if (!(cursor->in_history))
	{
		cursor->in_history = 1;
		ft_dlistadd_start(&(cursor->history), ft_new_dnod(cursor->cmd_line, CUR_CMD));
	}
	if ((cursor->history) && (cursor->history)->prev)
	{
		cursor->history = (cursor->history)->prev;
		ft_load_history(cursor);
		ft_update_line(cursor, NULL);
	}
	return (1);
}
