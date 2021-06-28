/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 15:14:52 by osurcouf          #+#    #+#             */
/*   Updated: 2021/06/28 16:31:15 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** 🦕
** MiniRT Program
**
** Takes in two arguments ↷
** 		[./minirt] [scene/map]
**
** Then sends the map to get parsed and starts miniRT
**
** 🦕
*/

static int	not_map(char *argv)
{
	int	len;

	len = ft_strlen(argv);
	if (argv[len - 1] != 't')
		return (no);
	if (argv[len - 2] != 'r')
		return (no);
	if (argv[len - 3] != '.')
		return (no);
	return (yes);
}

int	main(int argc, char **argv)
{
	t_rt	rt;

	ft_bzero(&rt, sizeof(t_rt));
	if (argc < 2)
	{
		printf(""COLOR_RED"\n	Error\n");
		printf(""COLOR_WHITE"🥗	I'm hungry. I need more arguments.\n");
		printf(""COLOR_LIGHT_GRAY"🍴	My diet : [./minirt] [scene/map].\n\n");
		return (-1);
	}
	if (argc > 2)
	{
		printf(""COLOR_RED"\n	Error\n");
		printf(""COLOR_WHITE"🍔	You are feeding me too many arguments.\n");
		printf(""COLOR_LIGHT_GRAY"🍴	My diet : [./minirt] [scene/map].\n\n");
		return (-1);
	}
	if (!not_map(argv[1]))
	{
		printf(""COLOR_RED"\n	Error\n");
		printf(""COLOR_WHITE"	I don't eat this map format.\n");
		printf(""COLOR_LIGHT_GRAY"	I only eat [.rt] files.\n\n");
		return (-1);
	}
	get_infos(argv[1], &rt);
	start_minirt(&rt);
}
