/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnave <tnave@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 12:55:23 by tnave             #+#    #+#             */
/*   Updated: 2021/05/23 19:05:21 by tnave            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ischarset(char c, char const *charset)
{
	int		i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		i;
	char		*s2;
	size_t		len_trimmed;
	size_t		j;

	i = 0;
	j = 0;
	if (!s1 || !set)
		return (NULL);
	len_trimmed = ft_strlen((char *)s1) - 1;
	while (ft_ischarset(s1[i], set))
		i++;
	if (!(s1[i] == '\0'))
		while (ft_ischarset(s1[len_trimmed], set))
			len_trimmed--;
	len_trimmed += 1;
	s2 = malloc(sizeof(char) * (len_trimmed - i) + 1);
	if (!(s2))
		return (NULL);
	while (i < len_trimmed)
		s2[j++] = s1[i++];
	s2[j] = '\0';
	return (s2);
}
