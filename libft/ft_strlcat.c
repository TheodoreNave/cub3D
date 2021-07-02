/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnave <tnave@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 18:38:52 by tnave             #+#    #+#             */
/*   Updated: 2021/05/23 19:01:38 by tnave            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len_dest;
	size_t	len_src;
	size_t	j;

	i = 0;
	len_dest = ft_strlen(dst);
	len_src = ft_strlen(src);
	j = len_dest + len_src;
	if (dstsize <= len_dest)
		return (len_src + dstsize);
	while (src[i] && len_dest + i < dstsize - 1)
	{
		dst[len_dest + i] = src[i];
		i++;
	}
	dst[len_dest + i] = '\0';
	return (j);
}
