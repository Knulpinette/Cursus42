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
		handle_error("🧊 While parsing the objects names.\n", infos);
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
	while (*line == ' ')
		line++;
	if (ft_isalnum(*line))
	{
		if ((*line == 'R' && *(line + 1) == ' ') && infos->res == no)
		{
			infos->res = yes;
			get_res((line + 1), infos);
		}
		else if ((*line == 'A' && *(line + 1) == ' ') && infos->amb == no)
		{
			infos->amb = yes;
			get_amb((line + 1), infos);
		}
		else if (*line == 'l' && *(line + 1) == ' ')
			parse_light((line), infos);
		else if (*line == 'c' && *(line + 1) == ' ')
			parse_cam((line), infos);
		else if (*line == 'c' || *line == 's' || *line == 'p' || *line == 't')
			parse_obj(line, infos);
		else
			handle_error("🎦 While parsing the elements names.\n", infos);
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
		handle_error("📂 Cannot open file.\n", rt->infos);
	init = init_objs(rt);
	if (!init)
		handle_error("💧 Fail to malloc struct elements.\n", rt->infos);
	ret = 1;
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		if (ret < 0)
			handle_error("📖 Cannot read the file.\n", rt->infos);
		parse(line, rt->infos);
		//verify_end_line(line, rt->infos);
		free(line);
	}
	if (close(fd) < 0)
		handle_error("❌ Cannot close the file.\n", rt->infos);
}
