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

char	*next_nbr(char *line);
char	*pass_spaces(char *line);
t_obj	*add_mem_obj(int nb_objs, t_obj *objs);
void	del_mem_infos(t_info *infos);

#endif
