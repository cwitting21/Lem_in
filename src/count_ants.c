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
	int		i;
	char	*s;

	i = 0;
	map->val->part = 1;
	map->ants_str = ft_join(map->ants_str, line, 0);
	if (line[0] == '#')
		return ;
	s = ft_strtrim(line);
	if ((map->ants = ft_atoi(s)) <= 0)
		free_map(map, 1);
	while (s[i] != '\n' && s[i] != 0)
	{
		if (!ft_isdigit(s[i++]))
			free_map(map, 1);
	}
}