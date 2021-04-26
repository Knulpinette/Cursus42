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

void	parse_obj(char *line, t_info *infos)
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
		handle_error(PARSING_OBJS);
	infos->nb_objs += 1;
}

void	parse_light(char *line, t_scene *scene)
{
	int	add_mem;

	add_mem = no;
	if (scene->nb_light)
		add_mem = yes;
	get_light(line + 1, scene, add_mem);
	scene->nb_light += 1;
}

void	parse_cam(char *line, t_scene *scene)
{
	int	add_mem;

	add_mem = no;
	if (scene->nb_cam)
		add_mem = yes;
	get_cam(line + 1, scene, add_mem);
	scene->nb_cam += 1;
}

void	parse(char *line, t_info *infos, int *res, int *amb)
{
	while (*line == ' ')
		line++;
	if (ft_isalnum(*line)) // check that for all cases (no spaces) => also whitespace or tab ok or not ?
	{
		if ((*line == 'R' && *(line + 1) == ' ') && *res == no)
		{
			*res = yes;
			get_res((line + 1), infos->scene);
		}
		else if ((*line == 'A' && *(line + 1) == ' ') && *amb == no)
		{
			*amb = yes;
			get_amb((line + 1), infos->scene);
		}
		else if (*line == 'l' && *(line + 1) == ' ')
			parse_light((line), infos->scene);
		else if (*line == 'c' && *(line + 1) == ' ')
			parse_cam((line), infos->scene);
		else if (*line == 'c' || *line == 's' || *line == 'p' || *line == 't')
			parse_obj(line, infos);
		else
			handle_error(PARSING_SCENE);
	}
}

void	get_infos(char *argv, t_rt *rt)
{
	int		fd;
	int		ret;
	char	*line;
	int		res;
	int		amb;
	//int		line_count;

	//line_count = 0;
	res = no;
	amb = no;
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		handle_error(NOT_OPEN);
	init_objs(rt);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		parse(line, rt->infos, &res, &amb);
		//printf("[Return: %d] Line #%d: %s\n", ret, line_count, line);
		free(line);
		//line_count++;
	}
	if (ret == -1)
		handle_error(NOT_READ);
	else if (!ret && line)
	{
		//printf("[Return: %d] Line #%d: %s\n", ret, line_count, line);
		if (line)
			parse(line, rt->infos, &res, &amb);
		free(line);
		//printf("\n EOF has been reached\n");
	}
	if (close(fd) < 0)
		handle_error(NOT_CLOSED);
}