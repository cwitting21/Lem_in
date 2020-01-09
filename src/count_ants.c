/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_ants.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fculator <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 19:00:11 by fculator          #+#    #+#             */
/*   Updated: 2020/01/09 19:00:12 by fculator         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	count_ants(t_map *map, char *line)
{
	int 	i;
	char 	*str;

	map->format_part = 1;
	if (line[0] == '#')
		return ;
	str = ft_strtrim(line);
	if ((map->num_ants = ft_atoi(str)) <= 0)
	{
		ft_putstr_fd("Error\n", 2);
		free_map(map);
		exit(1);
	}
	i = -1;
	while (str[++i] != '\n')
		if (!ft_isdigit(str[i]))
		{
			ft_putstr_fd("Error\n", 2);
			free_map(map);
			exit(1);
		}
}