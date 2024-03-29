/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_fork.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeon <gaeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:00:05 by johyyoon          #+#    #+#             */
/*   Updated: 2023/04/02 16:01:11 by gaeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	*ft_check_fork(t_data *data, t_list *cmd, int fd[2])
{
	t_cmd	*cmd_c;
	DIR		*dir;

	cmd_c = cmd->content;
	dir = NULL;
	if (cmd_c->f_cmd)
		dir = opendir(*cmd_c->f_cmd);
	if (cmd_c->input_fd == -1 || cmd_c->output_fd == -1)
		return (NULL);
	if ((cmd_c->f_path && !access(cmd_c->f_path, X_OK)) || ft_built(cmd_c))
		ft_fork(data, cmd, fd);
	else if (!ft_built(cmd_c) && ((cmd_c->f_path
				&& !access(cmd_c->f_path, F_OK)) || dir))
		g_status_number = 126;
	else if (!ft_built(cmd_c) && cmd_c->f_cmd)
		g_status_number = 127;
	if (dir)
		closedir(dir);
	return ("");
}
