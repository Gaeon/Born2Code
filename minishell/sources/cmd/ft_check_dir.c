/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_dir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeon <gaeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 15:57:33 by johyyoon          #+#    #+#             */
/*   Updated: 2023/04/02 17:05:00 by gaeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_check_dir(char c)
{
	char	*str;
	char	*p;

	str = "&()|;/><";
	p = ft_strchr(str, c);
	if (p != NULL)
		return (1);
	return (0);
}
