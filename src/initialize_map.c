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
	map->links = ft_strnew(1);
	map->ants_str = ft_strnew(1);
	map->rooms_list = ft_strnew(1);
	map->q_rooms = 0;
	map->ants = 0;
	map->val->part = 0;
	map->curr_room = 0;
	map->p_ind = 0;
	map->val->init_2 = 0;
	map->val->good[0] = 0;
	map->val->good[1] = 0;
	map->rooms = NULL;
	map->tab = NULL;
	map->path = NULL;
}

void	initialize_map_2(t_map *map)
{
	int i;
	int j;

	i = -1;
	map->val->init_2 = 1;
	map->path = (int*)ft_memalloc(sizeof(int) * 1000);
	map->tab = (int**)ft_memalloc(sizeof(int*) * map->q_rooms);
	map->rooms = (char**)ft_memalloc(sizeof(char*) * (map->q_rooms + 1));
	while (++i < map->q_rooms)
	{
		map->path[i] = -1;
		map->rooms[i] = NULL;
		map->tab[i] = (int*)ft_memalloc(sizeof(int) * map->q_rooms);
		j = -1;
		while (map->tab[i][++j])
			map->tab[i][j] = 0;
	}
	map->rooms[i] = NULL;
	map->path[0] = 0;
}


void	free_map(t_map *map, int code)
{
	int i;

	free(map->links);
	free(map->ants_str);
	free(map->rooms_list);
	if (map->val->init_2)
	{
		free(map->path);
		free_array(map->rooms, map, 0);
		i = -1;
		while (++i < map->q_rooms)
			free(map->tab[i]);
		free(map->tab);
	}
	free(map);
	if (code)
	{
		ft_putstr_fd("ERROR\n", 2);
		exit(1);
	}
	exit(0);
}

void	free_array(char **array, t_map *map, int code)
{
	int i;

	i = 0;
	while (array[i])
		(array[i]) ? free(array[i++]) : 0;
	free(array);
	if (code)
		free_map(map, 1);
	array = NULL;
}