/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnave <tnave@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 17:28:08 by tnave             #+#    #+#             */
/*   Updated: 2021/07/02 23:06:44 by tnave            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	ft_error(int i, char *str, t_data *data)
{
	if (i == 0)
		write(2, str, ft_strlen(str));
	if (i == 1)
	{
		write(2, str, ft_strlen(str));
		free_split((data->parsing));
		data->parsing = NULL;
	}
	if (i == 2)
		write(2, str, ft_strlen(str));
	if (i == 3)
	{
		write(2, str, ft_strlen(str));
		exit(0);
	}
	exit_function(data);
	return (0);
}

void	error_parameters(t_data *data)
{
	if (!data->no)
		ft_error(3, "No sprites found\n", data);
	else if (!data->so)
		ft_error(3, "No sprites found\n", data);
	else if (!data->we)
		ft_error(3, "No sprites found\n", data);
	else if (!data->ea)
		ft_error(3, "No sprites found\n", data);
	else if (!data->s)
		ft_error(3, "No sprites found\n", data);
}
