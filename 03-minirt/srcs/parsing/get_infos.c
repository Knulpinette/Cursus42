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

int	parse_obj(char *line, t_info *infos)
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
		return (0);
	infos->nb_objs += 1;
	return (1);
}

int	parse(char *line, t_info *infos)
{
	while (*line == ' ')
		line++;
	if (ft_isalnum(*line)) // check that for all cases (no spaces) => also whitespace or tab ok or not ?
	{
		if (*line == 'R' && *(line + 1) == ' ')
			get_res((line + 1), infos);
		else if (*line == 'A')
			get_amb((line + 1), infos);
		else if (*line == 'l' && *(line + 1) == ' ')
			get_light((line + 1), infos);
		else if (*line == 'c' && *(line + 1) == ' ')
			get_cam((line + 1), infos);
		else if (*line == 'c' || *line == 's' || *line == 'p' || *line == 't')
			return (parse_obj(line, infos));
		else
			return (0);
	}
	return (1);
}

int	get_infos(char *argv, t_rt *rt)
{
	int		fd;
	int		ret;
	char	*line;
	int		line_count;
	int		error;

	error = no;
	line_count = 0;
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return (-1);
	init_objs(rt);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		error = parse(line, rt->infos);
		if (!error)
			printf("ERROR\n");
		//printf("[Return: %d] Line #%d: %s\n", ret, line_count, line);
		free(line);
		line_count++;
	}
	if (ret == -1)
		printf("\n An error happened\n");
	else if (!ret && line)
	{
		//printf("[Return: %d] Line #%d: %s\n", ret, line_count, line);
		if (line)
			error = parse(line, rt->infos);
		if (!error)
			printf("ERROR\n");
		free(line);
		//printf("\n EOF has been reached\n");
	}
	if (close(fd) < 0)
		return (-1);
	return (1);
}