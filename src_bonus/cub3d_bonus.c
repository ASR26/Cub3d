/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 14:15:35 by ysmeding          #+#    #+#             */
/*   Updated: 2023/09/05 11:42:00 by ysmeding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

// void    ft_set_player(t_player_info *player, t_cub_info *info);
// void    rot_player(t_player_info *player, int i);
// void    move_player(t_cub_info *cub, t_player_info *player, int i);

// void	ft_initwindow(t_window_info	*window);
// void	ft_hook(void *arg);
// void	ft_game(t_cub_info *info, t_player_info *player);


// void	ft_init_info(t_cub_info *info);
// void    ft_set_player(t_player_info *player, t_cub_info *info);

void	ft_init_info(t_cub_info *info)
{
	info->scene = NULL;
	info->map = NULL;
	info->n_wall = NULL;
	info->s_wall = NULL;
	info->w_wall = NULL;
	info->e_wall = NULL;
	info->door = NULL;
	info->floor_col[0] = -1;
	info->floor_col[1] = -1;
	info->floor_col[2] = -1;
	info->ceil_col[0] = -1;
	info->ceil_col[1] = -1;
	info->ceil_col[2] = -1;
	info->doordir = 0;
	info->doorx = -1;
	info->doory = -1;
}

int	ft_cub3d(char *scenefile)
{
	t_cub_info		info;
	t_player_info	player;

	ft_init_info(&info);
	ft_parse_scene(scenefile, &info);
	ft_set_player(&player, &info);
	// printf("player x-> %f\n", player.xpos);
	// printf("player y-> %f\n", player.ypos);
	// printf("player rotx-> %f\n", player.xdir);
	// printf("player roty-> %f\n", player.ydir);
	// printf("player camx-> %f\n", player.xcamera);
	// printf("player camy-> %f\n", player.ycamera);
	// printf("player pov-> %f\n", player.pov);
	// rot_player(&player, 1);
	// int i = 0;
	// while (i < 20)
	// {
	// 	move_player(&info, &player, 'S');
	// 	i++;
	// }
	// printf("player newopsx-> %f\n", player.xpos);
	// printf("player newposy-> %f\n", player.ypos);
	ft_game(&info, &player);
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
