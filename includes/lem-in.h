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
	int			part;
	int			good[2];
	int			new_line;
	int			init_2;
}				t_valid;

typedef struct 	s_input
{
	char		*rooms_list;
	char		*ants_list;
	char		*link_list;
}				t_input;

typedef struct	s_map
{
	char		**rooms;
	int			rooms_count;
	int			ants;
	int			curr_room;
	int			w_ind;
	int			*way;
	int			**matrix;
	t_valid		*val;
	t_input 	*in;
}				t_map;

int				get_next_line(const int fd, char **line);
void			initialize_map(t_map *map);
void			free_map(t_map *map, int code);
void			free_array(char **array, t_map *m, int code);
void			parse_map_to_struct(t_map *map);
void			ants(t_map *map, char *line);
void			add_room_list(t_map *map,char *line);
void			room_table(t_map *m);
int				is_empty(char *s);
void			add_link_list(t_map *map, char *line);
void			validate_room(t_map *m, char *line);
void			is_number(char **r, t_map *m, char *s);
void			initialize_map_2(t_map *map);
void			validate_link(t_map *m, char *link);
void			connectivity_matrix(t_map *m);
int				room_index(t_map *m, char *room_name, int start);
void			good(t_map *m, char **line, char **r, int end);
void			check_start_end(t_map *m, char **r, int end);
void			is_valid(t_map *m, int i, char **r);



# endif
