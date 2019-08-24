/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 07:52:01 by tgouedar          #+#    #+#             */
/*   Updated: 2019/08/24 15:58:31 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <termios.h>
#include <term.h>
#include "libft.h"
#include "d_list.h"
#include "cursor.h"
#include "dispatcher.h"
#include "parsing.h"

#include <stdio.h>


void	print_bytes(void *ptr, int size)
{
	unsigned char *p = ptr;
	int i;
	for (i=0; i<size; i++)
		printf("%02hhX ", p[i]);
	printf("\n\r");
}

int		ft_pc(int c)
{
	return (write(0, &c, 1));
}

void	ft_clear_line(t_cursor *cursor)
{
	char	*buff;

	ft_cursor_reset(cursor->display_cursor);
	buff = tgetstr("cd", NULL);
	tputs(buff, 1, &ft_pc);
}

int		main()
{
	char		buff[MAX_KEY_SIZE];
	t_cursor	cursor;
	int			i;

	i = 0;
	ft_init_cursor(&cursor, 1);
	cursor.history = NULL;
	ft_memset(buff, '\0', MAX_KEY_SIZE);
	raw_term_mode();
	ft_display_prompt();
	while (read(0, buff, MAX_KEY_SIZE) > 0)
	{
		if (!(i = ft_termcap(buff, &cursor)))
			ft_update_line(&cursor, buff);
//		else if (i == ENTER_SIG)
//			 ;
		else if (i == EXIT_SIG)
			break ;
		ft_memset(buff, '\0', MAX_KEY_SIZE);
	}
	ft_free_dlist(&(cursor.history));
	def_term_mode();
	return (0);
}
