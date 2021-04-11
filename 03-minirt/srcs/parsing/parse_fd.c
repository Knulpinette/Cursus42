/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fd.c                                         :+:      :+:    :+:   */
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

int	parse_fd(char *line, t_info *infos)
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
		else if (*line == 's' && *(line + 1) == 'p' && *(line + 2) == ' ')
			get_sphere((line + 2), infos);
		else if (*line == 's' && *(line + 1) == 'q' && *(line + 2) == ' ')
			get_square((line + 2), infos);
		else if (*line == 'p' && *(line + 1) == 'l' && *(line + 2) == ' ')
			get_plane((line + 2), infos);
		else if (*line == 'c' && *(line + 1) == 'y' && *(line + 2) == ' ')
			get_cylinder((line + 2), infos);
		else if (*line == 't' && *(line + 1) == 'r' && *(line + 2) == ' ')
			get_triangle((line + 2), infos);
		else
			return (0);
	}
	return (1);
}

int	open_fd(char *argv, t_info *infos)
{
	int		fd;
	int		ret;
	char	*line;
	int		line_count;
	int		i;

	i = 0;
	line_count = 0;
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return (-1);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		i = parse_fd(line, infos);
		if (!i)
			printf("ERROR\n");
		printf("[Return: %d] Line #%d: %s\n", ret, line_count, line);
		line_count++;
	}
	if (ret == -1)
		printf("\n An error happened\n");
	else if (!ret && line)
	{
		printf("[Return: %d] Line #%d: %s\n", ret, line_count, line);
		if (line)
			i = parse_fd(line, infos);
		if (!i)
			printf("ERROR\n");
		printf("\n EOF has been reached\n");
	}
	if (close(fd) < 0)
		return (-1);
	return (1);
}