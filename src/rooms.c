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
	map->format_part = 2;
	map->rooms_list = ft_strjoin(map->rooms_list, line);
	if (line[0] == '#')
		return ;
	map->n_rooms++;
}