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

	int fd = open("../maps/multiple_ways/four_ways", O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		if (map->ants == 0)
			count_ants(map, line);
		else if (ft_strchr(line, '-') || map->val->started == 3)
			links(map, line);
		else if ((map->val->started == 1 || map->val->started == 2) && !is_empty(line))
			rooms(map, line);
		else
			free_map(map, 1);
	}
	if (!map->ants || !map->links[0])
		free_map(map, 1);
	initialize_map_2(map);
}
