/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fculator <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 19:35:18 by fculator          #+#    #+#             */
/*   Updated: 2020/01/09 19:35:19 by fculator         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	links(t_map *map, char *line)
{
	if (map->val->started == 2)
		map->val->started = 3;
	if (map->val->started != 3)
		free_map(map, 1);
	map->links = ft_join(map->links, line, 0);
}

