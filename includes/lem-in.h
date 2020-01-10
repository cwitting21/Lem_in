/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fculator <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 18:01:58 by fculator          #+#    #+#             */
/*   Updated: 2020/01/07 18:02:00 by fculator         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libprintf/includes/ft_printf.h"
# include <limits.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# define BUFF_SIZE 32
# define FD_MAX 255

typedef struct	s_valid
{
	int			part;			// a part of validation
	int			good[2];		// a part of validation
	int			new_line;		// a part of validation
	int			init_2;			// a part of validation
}				t_valid;

typedef struct	s_map
{
	char		**rooms;		// array of room names
	char		*rooms_list;	// list of rooms that was passed at the beginning
	char		*ants_str;		// list of ants that was passed at the beginning
	char		*links;			// list of links that was passed at the beginning
	int			q_rooms;		// quantity of rooms
	int			ants;			// quantity of ants
	int			curr_room;		// an index of current room we're in
	int			p_ind;			// last path index, current size of path
	int			*path;			// path
	int			**tab;			// edge table
	t_valid		*val;
}				t_map;

int				get_next_line(const int fd, char **line);
void			initialize_map(t_map *map);
void			free_map(t_map *map, int code);
void			free_array(char **array, t_map *m, int code);
void			parse_map_to_struct(t_map *map);
void			count_ants(t_map *map, char *line);
void			rooms(t_map *map,char *line);
int				is_empty(char *s);
void			links(t_map *map, char *line);
void			validate_room(t_map *m, char *line);
void			is_number(char **r, t_map *m, char *s);
void			initialize_map_2(t_map *map);


# endif
