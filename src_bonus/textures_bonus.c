#include "../inc/cub3d_bonus.h"

void	ft_setdraw(t_draw *draw, t_cub_info *cub, mlx_t *mlx)
{
	(void)mlx;//??
	draw->n_wall = mlx_load_png(cub->n_wall);
	draw->s_wall = mlx_load_png(cub->s_wall);
	draw->w_wall = mlx_load_png(cub->w_wall);
	draw->e_wall = mlx_load_png(cub->e_wall);
	if (cub->door[0] != 0)
		draw->door = mlx_load_png(cub->door);
}

int	ft_checkdraw(t_draw draw, t_cub_info *cub)
{
	if (!draw.n_wall || !draw.s_wall || !draw.e_wall || !draw.w_wall)
		return (-1);
	else if (cub->door[0] != 0 && !draw.door)
		return (-1);
	return (0);
}