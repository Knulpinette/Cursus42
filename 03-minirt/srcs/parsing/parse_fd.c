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

///, t_scene *scene, t_obj *obj)

int	open_fd(char *argv)
{
	int	fd;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return (-1);
	//read_fd(fd);
	if (close(fd) == -1)
		return (-1);
	return (1);
}
