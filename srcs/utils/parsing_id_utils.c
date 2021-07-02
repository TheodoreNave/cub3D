/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_id_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnave <tnave@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 17:21:37 by tnave             #+#    #+#             */
/*   Updated: 2021/07/02 23:06:44 by tnave            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	ft_one(char *str)
{
	int				i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '1')
			return (1);
		i++;
	}
	return (0);
}

int	ft_strequ(char *s1, char *s2)
{
	int				i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	if (s2[i])
		return (0);
	return (1);
}

int	ft_digit_virgule(char **tab, t_data *data)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (tab[i])
	{
		while (tab[i][j])
		{
			if (!(tab[i][j] >= '0' && tab[i][j] <= '9'))
			{
				free_split(tab);
				ft_error(1, "Invalid Number\n", data);
				return (0);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int	count_len_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	count_char_in_string(char *str, char c)
{
	int				i;
	int				count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}
