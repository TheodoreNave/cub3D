/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_charset.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnave <tnave@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 14:05:51 by tnave             #+#    #+#             */
/*   Updated: 2021/06/27 16:26:34 by tnave            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check(char c, char *str)
{
	int		i;

	i = 0;
	if (str[0] == '\0')
		return (0);
	while (str[i])
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_word_count_charset(char *str, char *charset)
{
	int		i;
	int		count;
	int		cmpt;

	i = 0;
	count = 0;
	cmpt = 0;
	if (charset[0] == '\0')
		return (1);
	while (str[i])
	{
		if (cmpt == 1 && ft_check(str[i], charset) == 1)
			cmpt = 0;
		if (cmpt == 0 && ft_check(str[i], charset) == 0)
		{
			cmpt = 1;
			count++;
		}
		i++;
	}
	return (count);
}

int	full_word_length(char *str, int k, char *charset)
{
	int		i;

	i = 0;
	if (!charset)
	{
		while (str[i])
			i++;
		return (i);
	}
	while (str[k] && ft_check(str[k], charset) == 0)
	{
		k++;
		i++;
	}
	return (i);
}

char	*new_full_string_charset(char *str, int l, int size)
{
	char	*new;
	int		i;

	i = 0;
	new = (char *)malloc(sizeof(char) * (size + 1));
	if (!new)
		return (NULL);
	while (i < size)
	{
		new[i] = str[l];
		l++;
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	**ft_split_charset(char *str, char *charset)
{
	char	**split;
	int		words;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (str == NULL)
		return (NULL);
	words = ft_word_count_charset(str, charset);
	split = (char **)malloc(sizeof(char *) * (words + 1));
	if (!(split))
		return (NULL);
	while (words > 0)
	{
		while (ft_check(str[j], charset) == 1)
			j++;
		split[i] = new_full_string_charset(str, j,
				full_word_length(str, j, charset));
		i++;
		words--;
		j = j + full_word_length(str, j, charset);
	}
	split[i] = NULL;
	return (split);
}
