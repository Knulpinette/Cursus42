/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 15:14:52 by osurcouf          #+#    #+#             */
/*   Updated: 2021/04/26 15:14:53 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int     main(int argc, char **argv)
{
    t_rt    rt;

    ft_bzero(&rt, sizeof(t_rt));
    if (argc < 2)
        return (-1);
    if (argc > 2)
        return (-1);
    get_infos(argv[1], &rt);
    start_minirt(&rt);
}
