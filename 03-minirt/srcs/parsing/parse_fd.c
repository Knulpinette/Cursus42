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

//read_fd(int fd, t_info *infos)
//{
	
//}

int	open_fd(char *argv) //, t_info *infos)
{
	int	fd;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return (-1);
	//read_fd(fd, infos);
	if (close(fd) == -1)
		return (-1);
	return (1);
}
