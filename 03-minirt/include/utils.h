/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 19:48:47 by osurcouf          #+#    #+#             */
/*   Updated: 2021/04/02 19:48:48 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "minirt.h"

enum e_errors {
	NOT_CLOSED = 1,
	NOT_READ,
	NOT_OPEN,
	NO_WINDOW,
	PARSING_SCENE,
	PARSING_OBJS,
};

void	handle_error(int error);
char	*next_nbr(char *line);
char	*pass_spaces(char *line);
t_obj	*add_mem_obj(int nb_objs, t_obj *objs);
void	del_mem_infos(t_info *infos);

#endif
