/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fculator <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 17:10:04 by fculator          #+#    #+#             */
/*   Updated: 2020/01/10 17:10:06 by fculator         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "lem-in.h"

void		connectivity_matrix(t_map *map)
{
	int		i;
	int		r_1;
	int		r_2;
	char	**l;
	char	**links;

	i = -1;
	links = ft_strsplit(map->in->link_list, '\n');
	while (links[++i])
	{
		if (links[i][0] == '#')
			continue ;
		validate_link(map, links[i]);
		l = ft_strsplit(links[i], '-');
		if ((r_1 = room_index(map, l[0], 1)) >= map->rooms_count ||
			(r_2 = room_index(map, l[1], 1)) >= map->rooms_count)
		{
			free_array(l, map, 0);
			free_array(links, map, 1);
		}
		(r_2) ? (map->matrix[r_1][r_2] = 1) : 0;
		(r_1) ? (map->matrix[r_2][r_1] = 1) : 0;
		free_array(l, map, 0);
	}
	free_array(links, map, 0);
}
