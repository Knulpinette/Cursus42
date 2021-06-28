/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 19:36:26 by osurcouf          #+#    #+#             */
/*   Updated: 2021/04/02 19:36:27 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** 🦕
**
** function : handle errors
** Sends the infos block's malloced' memory to get deleted.
** Prints the Error message.
** Exit cleanly the program.
**
** function : verify_end_line doesn't work yet.
**
** 🦕
*/

void	handle_error(char *error, t_info *infos)
{
	del_mem_infos(infos);
	printf(""COLOR_RED"	Error\n"COLOR_WHITE"%s\n", error);
	exit(EXIT_SUCCESS);
}

void	verify_end_line(char *line, t_info *infos)
{
	char	c;
	int		i;

	i = 0;
	c = 0xd;
	while (*line && *line == ' ')
	{
		printf("%c || %x >> %i\n", *line, *line, i);
		line++;
		i++;
	}
	printf("%x >> %i\n", *line, i);
	if (*line != c)
		handle_error("	You have a wandering character at the end of a line.\n",
						infos);
}
