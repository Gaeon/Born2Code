/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 17:07:36 by gaeokim           #+#    #+#             */
/*   Updated: 2022/07/21 17:53:00 by gaeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	s_buff[BUFFER_SIZE + 1];
	char		*buff;

	if (fd == 0 || fd > OPEN_MAX || BUFFER_SIZE < 1)
		return (0);
	while (ft_strchr(buff, '\n') != 0)
	{
		read(fd, buff, BUFFER_SIZE);	
	}
	return (0);
}
