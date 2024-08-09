/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 12:29:20 by erian             #+#    #+#             */
/*   Updated: 2024/08/09 22:00:53 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	create_list(t_list **list, int fd)
{
	int		i;
	char	*buf;

	while (!(found_new_line(*list)))
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (!buf)
			return ;
		i = read(fd, &buf, BUFFER_SIZE);
		if (!i)
		{
			free(buf);
			return ;
		}
		buf[i] = '\0';
		append(*list, buf);
	}
}

char	*get_next_line(int fd)
{
	static t_list	*list;
	char	*next_line;

	if (fd < 0 || BUFFER_SIZE < 1 || (read(fd, &next_line, 0) < 0))
		return (NULL);
	create_list(&list, fd);
	if (!list)
		return (NULL);
	next_line = get_line(list);
	polish_list(*list);
	return (next_line);

}
