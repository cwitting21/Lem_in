/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_mapap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fculator <maparvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 18:51:05 by fculator          #+#    #+#             */
/*   Updated: 2020/01/09 18:51:08 by fculator         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	initialize_map(t_map *map)
{
	map = (t_map*)ft_memalloc(sizeof(t_map));
	map->links = ft_strnew(1);
	map->ants_str = ft_strnew(1);
	map->rooms_list = ft_strnew(1);
	map->n_rooms = 0;
	map->num_ants = 0;
	map->format_part = 0;
	map->curr_room = 0;
	map->p_ind = 0;
	map->init_2 = 0;
	map->good[0] = 0;
	map->good[1] = 0;
	map->rooms = NULL;
	map->matrix = NULL;
	map->path = NULL;
}

void	free_map(t_map *map)
{
	int i;

	free(map->links);
	free(map->ants_str);
	free(map->rooms_list);
	if (map->init_2)
	{
		free(map->path);
		free_array(map->n_rooms, map, 0);
		i = -1;
		while (++i < map->n_rooms)
			free(map->matrix[i]);
		free(map->matrix);
	}
	free(map);
}
