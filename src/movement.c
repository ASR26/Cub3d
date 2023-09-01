/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 11:12:43 by ysmeding          #+#    #+#             */
/*   Updated: 2023/09/01 08:17:01 by ysmeding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/cub3d.h"

//double	ft_setang(double ang);

void    move_player_front(t_cub_info *cub, t_player_info *player, int i)
{
    int tmp[2];

    tmp[0] = player->xpos + MOV_SPEED * player->xdir * i;
    tmp[1] = player->ypos + MOV_SPEED * player->ydir * i;
    if (cub->map[tmp[1]][tmp[0]] != '1')
    {
        player->xpos += MOV_SPEED * player->xdir * i;
        player->ypos += MOV_SPEED * player->ydir * i;
    }
}

void    move_player_lateral(t_cub_info *cub, t_player_info *player, int i)
{
    int tmp[2];
    tmp[0] = player->xpos + MOV_SPEED * player->xcamera * i;
    tmp[1] = player->ypos + MOV_SPEED * player->ycamera * i;
    if (cub->map[tmp[1]][tmp[0]] != '1')
    {
        player->xpos += MOV_SPEED * player->xcamera * i;
        player->ypos += MOV_SPEED * player->ycamera * i;
    }
}
void    move_player(t_cub_info *cub, t_player_info *player, int i)
{
    if (i == 'W')
        move_player_front(cub, player, -1);
    if (i == 'S')
        move_player_front(cub, player, 1);
    if (i == 'A')
        move_player_lateral(cub, player, -1);
    if (i == 'D')
        move_player_lateral(cub, player, 1);
}

void    rot_player(t_player_info *player, int i)
{
    rotate_z(&player->xdir, &player->ydir, ROT_SPEED * i); //i is the direction to rotate
    rotate_z(&player->xcamera, &player->ycamera, ROT_SPEED * i);
    player->pov += ROT_SPEED * i;
    player->pov = ft_setang(player->pov);
}