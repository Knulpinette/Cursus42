/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 16:48:25 by osurcouf          #+#    #+#             */
/*   Updated: 2021/04/02 16:48:26 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <mlx.h>
# include <math.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>
# include <stdbool.h>
# include "../libft/libft.h"
# include "struct_def.h"
# include "parsing.h"
# include "utils.h"
# include "window.h"
# include "vectors.h"

enum e_y_or_no
{
	no,
	yes,
};

void	start_minirt(t_rt *rt);

#endif