/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_sx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeon <gaeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 17:47:18 by gaeokim           #+#    #+#             */
/*   Updated: 2023/03/01 17:17:52 by gaeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_info *info)
{
	int	temp;

	if (info->a->size < 1)
		return ;
	temp = info->a->arr[0];
	info->a->arr[0] = info->a->arr[1];
	info->a->arr[1] = temp;
	write(1, "sa\n", 3);
}

void	sb(t_info *info)
{
	int	temp;

	if (info->b->size < 1)
		return ;
	temp = info->b->arr[0];
	info->b->arr[0] = info->b->arr[1];
	info->b->arr[1] = temp;
	write(1, "sb\n", 3);
}

void	ss(t_info *info)
{
	int	temp_a;
	int	temp_b;

	if (info->a->size < 1 || info->b->size < 1)
		return ;
	temp_a = info->a->arr[0];
	temp_b = info->b->arr[0];
	info->a->arr[0] = info->a->arr[1];
	info->a->arr[1] = temp_a;
	info->b->arr[0] = info->b->arr[1];
	info->b->arr[1] = temp_b;
	write(1, "ss\n", 3);
}
