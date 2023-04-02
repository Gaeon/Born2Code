/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_user.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeon <gaeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:02:43 by johyyoon          #+#    #+#             */
/*   Updated: 2023/04/02 16:06:30 by gaeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_update_user(char ***user, int fd)
{
	char	**str;
	char	*tmp;
	char	*line;

	str = NULL;
	line = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		tmp = ft_strtrim(line, "\n");
		free(line);
		str = ft_extend_split(str, tmp);
		free(tmp);
	}
	ft_free_split(user);
	*user = str;
}
