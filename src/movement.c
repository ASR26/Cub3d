#include "../inc/cub3d.h"

void    move_player(t_cub_info *cub, t_player_info *player)
{
    player->xpos -= cos(player->pov);
    player->ypos += sin(player->pov);
}

void    rot_player(t_cub_info *cub, t_player_info *player, int i)
{
    if (i == 1)
    player->xdir -= M_PI/8;
}