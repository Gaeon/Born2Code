/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 13:58:55 by gaeokim           #+#    #+#             */
/*   Updated: 2022/07/21 14:46:42 by gaeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_word_cnt(char const *s, char c)
{
	int	idx;
	int	cnt;

	idx = 0;
	cnt = 0;
	while (s[idx])
	{
		if (s[idx] != c && (s[idx + 1] == c || s[idx + 1] == '\0'))
			cnt++;
		idx++;
	}
	return (cnt);
}

int	ft_make(char const *s, char c, char **array)
{
	unsigned int	i;
	unsigned int	k;
	unsigned int	word_len;

	i = 0;
	k = 0;
	while (i < ft_strlen(s))
	{
		word_len = 0;
		while (s[i + word_len] && s[i + word_len] != c)
			word_len++;
		if (word_len > 0)
		{
			array[k] = (char *)malloc(sizeof(char) * (word_len + 1));
			if (array[k] == 0)
				return (k);
			ft_strlcpy(array[k], &s[i], word_len + 1);
			k++;
		}
		i += word_len + 1;
	}
	array[k] = 0;
	return (-1);
}

char	**ft_split(char const *s, char c)
{
	int		flag;
	char	**array;

	flag = 0;
	if (s == 0)
		return (0);
	array = (char **)malloc(sizeof(char *) * (ft_word_cnt(s, c) + 1));
	if (array == 0)
		return (0);
	flag = ft_make(s, c, array);
	if (flag != -1)
	{
		while (flag >= 0)
		{
			free(array[flag]);
			flag--;
		}
		free(array);
		return (0);
	}
	return (array);
}
