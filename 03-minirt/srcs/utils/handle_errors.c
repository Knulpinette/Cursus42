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

void	handle_error(int error)
{
	if (error == NOT_OPEN)
		printf("ERROR : can't open file\n");
	if (error == NOT_CLOSED)
		printf("ERROR : can't close file\n");
	if (error == NOT_READ)
		printf("ERROR : can't get the next line of file descriptor\n");
	if (error == NO_WINDOW)
		printf("ERROR : can't create window\n");
	if (error == PARSING_SCENE)
		printf("ERROR : wrong arguments for the scene\n");	
	if (error == PARSING_OBJS)
		printf("ERROR : wrong arguments for the objects\n");
	if (error == PARSING_COLOR)
		printf("ERROR : color value not between 0 and 255\n");		
	exit(EXIT_SUCCESS);
}
