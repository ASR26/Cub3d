/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 14:15:35 by ysmeding          #+#    #+#             */
/*   Updated: 2023/08/18 08:40:55 by ysmeding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void    ft_set_player(t_player_info *player, t_cub_info *info);

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
	info->pov = 0;
	info->ceil_col[0] = -1;
	info->ceil_col[1] = -1;
	info->ceil_col[2] = -1;
}

int	ft_cub3d(char *scenefile)
{
	t_cub_info		info;
	t_player_info	player;

	ft_init_info(&info);
	ft_parse_scene(scenefile, &info);
	ft_set_player(&player, &info);
	printf("hei-> %i\n", info.hei);
	printf("wid-> %i\n", info.wid);
	printf("n-> %s\n", info.n_wall);
	printf("s-> %s\n", info.s_wall);
	printf("w-> %s\n", info.w_wall);
	printf("e-> %s\n", info.e_wall);
	printf("player x-> %f\n", player.xpos);
	printf("player y-> %f\n", player.ypos);
	printf("player rotx-> %f\n", player.xdir);
	printf("player roty-> %f\n", player.ydir);
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
