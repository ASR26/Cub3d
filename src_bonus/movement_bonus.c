/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 11:12:43 by ysmeding          #+#    #+#             */
/*   Updated: 2023/09/05 12:01:37 by ysmeding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/cub3d_bonus.h"

//double	ft_setang(double ang);

float   ft_dist(t_cub_info *cub, t_player_info *player)
{
    float dist;
    float diffx;
    float diffy;

    diffx = player->xpos - (cub->doorx + 0.5f);
    diffy = player->ypos - (cub->doory + 0.5f);
    dist = sqrt(diffx * diffx + diffy * diffy);
    return (dist);
}

void    move_player_front(t_cub_info *cub, t_player_info *player, int i)
{
    int tmp[2];

    tmp[0] = player->xpos + MOV_SPEED * player->xdir * i;
    tmp[1] = player->ypos + MOV_SPEED * player->ydir * i;
    if (cub->map[tmp[1]][tmp[0]] != '1' && cub->map[tmp[1]][tmp[0]] != 'D')
    {
        player->xpos += MOV_SPEED * player->xdir * i;
        player->ypos += MOV_SPEED * player->ydir * i;
        if (cub->doordir)
        {
            if (ft_dist(cub, player) > 1.5)
            {
                printf("Did this.\n");
                cub->map[cub->doory][cub->doorx] = 'D';
                cub->doordir = 0;
                cub->doorx = 0;
                cub->doory = 0;
            }
        }
    }
}

void    move_player_lateral(t_cub_info *cub, t_player_info *player, int i)
{
    int tmp[2];
    tmp[0] = player->xpos + MOV_SPEED * player->xcamera * i;
    tmp[1] = player->ypos + MOV_SPEED * player->ycamera * i;
    if (cub->map[tmp[1]][tmp[0]] != '1' && cub->map[tmp[1]][tmp[0]] != 'D')
    {
        player->xpos += MOV_SPEED * player->xcamera * i;
        player->ypos += MOV_SPEED * player->ycamera * i;
         if (cub->doordir)
        {
            if (ft_dist(cub, player) > 1.5)
            {
                printf("Did this2.\n");
                cub->map[cub->doory][cub->doorx] = 'D';
                cub->doordir = 0;
                cub->doorx = 0;
                cub->doory = 0;
            }
        }
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