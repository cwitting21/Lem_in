/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_to_struct.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fculator <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 18:37:45 by fculator          #+#    #+#             */
/*   Updated: 2020/01/09 18:37:47 by fculator         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	parse_map_to_struct(t_map *map)
{
	char	*line;

	int fd = open("../maps/subject-1.map", O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		if (map->num_ants == 0)
			count_ants(map, line);
		else if (ft_strchr(line, '-') || map->format_part == 3)
			links(map, line);
		else if ((map->format_part == 1 || map->format_part == 2) && line != NULL)
			rooms(map, line);
		else
		{
			ft_putstr_fd("Error\n", 2);
			free_map(map);
			exit(1);
		}
	}
	if (map->num_ants == 0 || map->links[0] == 0)
	{
		ft_putstr_fd("Error\n", 2);
		free_map(map);
		exit(1);
	}
}
