/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clipboard_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 14:37:31 by tgouedar          #+#    #+#             */
/*   Updated: 2019/08/24 15:21:45 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cursor.h"

void	ft_save_in_clipboard(t_cursor *cursor, char *to_save, size_t len)
{
	ft_bzero(cursor->clipboard, MAX_LINE);
	ft_memcpy(cursor->clipboard, to_save, len);
}
