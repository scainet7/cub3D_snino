/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_pars_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 16:20:26 by snino             #+#    #+#             */
/*   Updated: 2022/09/15 20:16:21 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_free_mass(t_map *line)
{
	t_map	*temp;

	while (line)
	{
		temp = line->next;
		free(line->maps_line);
		free(line);
		line = temp;
	}
}

t_map 	*ft_line_new(void *line)
{
	t_map	*new_map;

	new_map = (t_map *)malloc(sizeof(t_map));
	if (!new_map)
		return (NULL);
	new_map->maps_line = line;
	new_map->next = NULL;
	return (new_map);
}

void	ft_lineadd_back(t_map **mass, t_map *new)
{
	t_map 	*last;

	if (!mass || !new)
		return ;
	last = *mass;
	if (!last)
		*mass = new;
	else
	{
		while (last->next)
			last = last->next;
		last->next = new;
	}
}

int	ft_memory_num(t_list *list)
{
	t_list	*tmp;
	int		count;
	char	*str;

	tmp = list;
	count = 1;
	while (tmp)
	{
		str = tmp->content;
		printf(BLU"%s\n"END, str);
		if (tmp->flag == 1)
			break ;
		++count;
		tmp = tmp->next;
	}
	count++;
	printf(MAG"%d\n"END, count);
	return (count);
}

static void	ft_pars(t_game *game, char *line)
{
	int	sp;

	sp = 0;
	while (line && *line)
	{
		if (ft_strchr(line, ' '))
		{
			ft_lstadd_back(&game->map_list, ft_lstnew(ft_strcdup(line, ' ')));
			line = ft_strchr(line, ' ');
			while (*line == ' ')
			{
				sp++;
				line++;
			}
			ft_lstlast(game->map_list)->space = sp;
		}
		else
		{
			ft_lstadd_back(&game->map_list, ft_lstnew(ft_strcdup(line, '\n')));
			ft_lstlast(game->map_list)->flag = 1;
			line = NULL;
		}
	}
}

void	ft_pars_map_list(t_game *game, char *line)
{
	if (*line == '\n' && game->enter == 0)
		;
	else if (*line == '\n' && game->enter != 0)
		ft_error_handler(game, "Error\nINVALID_MAP", leave);
	else
	{
		ft_pars(game, line);
		game->enter++;
	}
}
