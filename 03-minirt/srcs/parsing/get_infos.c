/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_infos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 18:22:44 by osurcouf          #+#    #+#             */
/*   Updated: 2021/04/02 18:22:45 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** BUFFER_SIZE 1000 is defined in libft.h
*/

static void	parse_obj(char *line, t_info *infos)
{
	int	add_mem;

	add_mem = no;
	if (infos->nb_objs)
		add_mem = yes;
	if (*line == 's' && *(line + 1) == 'p' && *(line + 2) == ' ')
		get_sphere((line + 2), infos, add_mem);
	else if (*line == 's' && *(line + 1) == 'q' && *(line + 2) == ' ')
		get_square((line + 2), infos, add_mem);
	else if (*line == 'p' && *(line + 1) == 'l' && *(line + 2) == ' ')
		get_plane((line + 2), infos, add_mem);
	else if (*line == 'c' && *(line + 1) == 'y' && *(line + 2) == ' ')
		get_cylinder((line + 2), infos, add_mem);
	else if (*line == 't' && *(line + 1) == 'r' && *(line + 2) == ' ')
		get_triangle((line + 2), infos, add_mem);
	else
		handle_error("parsing_obj", infos);
	infos->nb_objs += 1;
}

static void	parse_light(char *line, t_info *infos)
{
	int	add_mem;

	add_mem = no;
	if (infos->scene->nb_light)
		add_mem = yes;
	get_light(line + 1, infos, add_mem);
	infos->scene->nb_light += 1;
}

static void	parse_cam(char *line, t_info *infos)
{
	int	add_mem;

	add_mem = no;
	if (infos->scene->nb_cam)
		add_mem = yes;
	get_cam(line + 1, infos, add_mem);
	infos->scene->nb_cam += 1;
}

static void	parse(char *line, t_info *infos)
{
	static int	res = no;
	static int	amb = no;

	while (*line == ' ')
		line++;
	if (ft_isalnum(*line)) // check that for all cases (no spaces) => also whitespace or tab ok or not ?
	{
		if ((*line == 'R' && *(line + 1) == ' ') && res == no)
		{
			res = yes;
			get_res((line + 1), infos);
		}
		else if ((*line == 'A' && *(line + 1) == ' ') && amb == no)
		{
			amb = yes;
			get_amb((line + 1), infos);
		}
		else if (*line == 'l' && *(line + 1) == ' ')
			parse_light((line), infos);
		else if (*line == 'c' && *(line + 1) == ' ')
			parse_cam((line), infos);
		else if (*line == 'c' || *line == 's' || *line == 'p' || *line == 't')
			parse_obj(line, infos);
		else
			handle_error("parsing scene", infos);
	}
}

void	get_infos(char *argv, t_rt *rt)
{
	int		fd;
	int		ret;
	char	*line;
	int		init;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		handle_error("not open", rt->infos);
	init = init_objs(rt);
	if (!init)
		handle_error("not read", rt->infos);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		parse(line, rt->infos);
		free(line);
	}
	if (ret == -1)
		handle_error("not read", rt->infos);
	else if (!ret && line)
	{
		if (line)
			parse(line, rt->infos);
		free(line);
	}
	if (close(fd) < 0)
		handle_error("not closed", rt->infos);
}