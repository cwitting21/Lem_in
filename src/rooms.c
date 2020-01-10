/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fculator <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 19:25:22 by fculator          #+#    #+#             */
/*   Updated: 2020/01/09 19:25:23 by fculator         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	rooms(t_map *map, char *line)
{
	map->val->part = 2;
	map->rooms_list = ft_join(map->rooms_list, line, 0);
	if (line[0] == '#')
		return ;
	validate_room(map, line);
	map->q_rooms++;
}

void	validate_room(t_map *m, char *line)
{
	char **r;

	r = ft_strsplit(line, ' ');
	if (r[0][0] == 'L' || r[3] != NULL)
		free_array(r, m, 1);
	is_number(r, m, r[1]);
	is_number(r, m, r[2]);
	free_array(r, m, 0);
}
