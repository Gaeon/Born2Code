/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 16:03:48 by gaeokim           #+#    #+#             */
/*   Updated: 2022/07/09 17:25:55 by gaeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, void *src, size_t n)
{
	int		cnt;
	char	*temp_dst;
	char	*temp_src;

	cnt = 0;
	temp_dst = (char *)dst;
	temp_src = (char *)src;
	while (cnt < n)
	{
		temp_dst[cnt] = temp_src[cnt];
		cnt++;
	}
	return (temp_dst);
}
