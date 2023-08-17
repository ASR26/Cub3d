/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 14:15:35 by ysmeding          #+#    #+#             */
/*   Updated: 2023/08/15 12:54:39 by ysmeding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_init_info(t_cub_info *info)
{
	info->scene = NULL;
	info->map = NULL;
	info->n_wall = NULL;
	info->s_wall = NULL;
	info->w_wall = NULL;
	info->e_wall = NULL;
	info->floor_col[0] = -1;
	info->floor_col[1] = -1;
	info->floor_col[2] = -1;
	info->ceil_col[0] = -1;
	info->ceil_col[1] = -1;
	info->ceil_col[2] = -1;
}

int	ft_cub3d(char *scenefile)
{
	t_cub_info	info;

	ft_init_info(&info);
	ft_parse_scene(scenefile, &info);
	printf("Got to the end.\n");//remove this later
	ft_free_info(&info);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		ft_cub3d(argv[1]);
	}	
	else
	{
		if (argc < 2)
			ft_putendl_fd("The program requires a scene description file.", 2);
		else if (argc > 2)
			ft_putendl_fd("Too many arguments passed to the program.", 2);
		return (1);
	}
}
