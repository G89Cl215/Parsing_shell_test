/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 16:21:54 by tgouedar          #+#    #+#             */
/*   Updated: 2019/08/24 14:45:20 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termios.h>
#include <term.h>
#include "parsing.h"
#include "cursor.h"
#include "word_tools.h"

int		ft_end_of_stream(t_cursor *cursor)
{
	(void)cursor;
	return (EXIT_SIG);
}

int		ft_clear_screen_key(t_cursor *cursor)
{
	char		*tc;

	tc = tgetstr("cl", NULL);
	tputs(tc, 1, &ft_pc);
	ft_update_line(cursor, NULL);
	return (1);
}
