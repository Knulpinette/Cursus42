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
** BUFFER_SIZE is defined in libft.h
*/

int	parse_fd(char *line) //, t_info *info)
{
	while (*line == ' ')
		line++;
	if (ft_isalnum(*line)) // check that for all cases (no spaces) => also whitespace or tab ok or not ?
	{
		if (*line == 'R' && *(line + 1) == ' ')
			printf("found a resolution\n");
		else if (*line == 'A')
			printf("found ambient atmosphere\n");
		else if (*line == 'l' && *(line + 1) == ' ')
			printf("found a light\n");
		else if (*line == 'c' && *(line + 1) == ' ')
			printf("found a camera\n");
		else if (*line == 's' && *(line + 1) == 'p' && *(line + 2) == ' ')
			printf("found a sphere\n");
		else if (*line == 's' && *(line + 1) == 'q' && *(line + 2) == ' ')
			printf("found a square\n");
		else if (*line == 'p' && *(line + 1) == 'l' && *(line + 2) == ' ')
			printf("found a plane\n");
		else if (*line == 'c' && *(line + 1) == 'y' && *(line + 2) == ' ')
			printf("found a cylinder\n");
		else if (*line == 't' && *(line + 1) == 'r' && *(line + 2) == ' ')
			printf("found a triangle\n");
		else
			return (-1);
	}
	return (0);
}

int	open_fd(char *argv) //, t_info *infos)
{
	int		fd;
	int		ret;
	char	*line;
	int		line_count;
	int		i;

	line_count = 0;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return (-1);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		i = parse_fd(line); //, infos);
		if (i == -1)
			printf("ERROR\n");
		printf("[Return: %d] Line #%d: %s\n", ret, line_count, line);
		line_count++;
	}
	if (ret == -1)
		printf("\n An error happened\n");
	else if (ret == 0 && line)
	{
		printf("[Return: %d] Line #%d: %s\n", ret, line_count, line);
		if (line)
			i = parse_fd(line); //, infos);
		if (i == -1)
			printf("ERROR\n");
		printf("\n EOF has been reached\n");
	}
	if (close(fd) == -1)
		return (-1);
	return (1);
}