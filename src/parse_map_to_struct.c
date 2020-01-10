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
	while (get_next_line(STDIN_FILENO, &line) > 0)
	{
		if (map->ants == 0)
			ants(map, line);
		else if (ft_strchr(line, '-') || map->val->part == 3)
			add_link_list(map, line);
		else if ((map->val->part == 1 || map->val->part == 2) && !is_empty(line))
			add_room_list(map, line);
		else
			free_map(map, 1);
	}
	if (map->ants == 0 || map->in->link_list[0] == '\0')
		free_map(map, 1);
}
