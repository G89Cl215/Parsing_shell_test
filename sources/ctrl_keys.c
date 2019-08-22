/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 16:21:54 by tgouedar          #+#    #+#             */
/*   Updated: 2019/08/22 14:45:20 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "cursor.h"
#include "word_tools.h"

int		ft_clear_cmd(t_cursor *cursor)
{
	ft_init_cursor(cursor);
	ft_update_line(cursor, NULL);
	return (1);
}

int		ft_end_of_stream(t_cursor *cursor)
{
	(void)cursor;
	return (EXIT_SIG);
}

int		ft_clear_from_cursor(t_cursor *cursor)
{

	(void)cursor;

	return (1);
}

int		ft_clear_screen_key(t_cursor *cursor)
{

	(void)cursor;

	return (1);
}
