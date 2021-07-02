/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnave <tnave@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 10:59:06 by tnave             #+#    #+#             */
/*   Updated: 2021/06/27 16:26:05 by tnave            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

char	*ft_strjoin_free(char *s1, char *s2)
{
	int				i;
	int				j;
	char			*str;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	str = malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!(str))
		return (NULL);
	while (s1[j])
		str[i++] = s1[j++];
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	free(s1);
	str[i] = '\0';
	return (str);
}

char	*get_str_new_line(char *new_line)
{
	int				i;
	int				j;
	char			*str;

	i = 0;
	j = 0;
	if (ft_strchr(new_line, '\n'))
	{
		while (new_line[i] && new_line[i] != '\n')
			i++;
		str = ft_strdup(new_line + i + 1);
		while (new_line[j] && str[j])
		{
			new_line[j] = str[j];
			j++;
		}
		new_line[j] = '\0';
		free(str);
		return (new_line);
	}
	return (NULL);
}

int	get_next_line(int fd, char **line)
{
	char			buff[BUFFER_SIZE + 1];
	static char		*new_line;
	int				len;
	int				rd;

	if (BUFFER_SIZE < 1 || fd < 0 || (read(fd, buff, 0) < 0) || line == NULL)
		return (-1);
	rd = 1;
	if (new_line == NULL)
		new_line = ft_strdup("");
	while (!ft_strchr(new_line, '\n') && rd > 0)
	{
		rd = read(fd, buff, BUFFER_SIZE);
		buff[rd] = '\0';
		new_line = ft_strjoin_free(new_line, buff);
	}
	len = get_len(new_line);
	*line = ft_substr(new_line, 0, len);
	if (get_str_new_line(new_line) == NULL)
	{
		free(new_line);
		new_line = NULL;
		return (0);
	}
	return (1);
}
