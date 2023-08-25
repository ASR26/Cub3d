#include "../inc/cub3d.h"

void	ft_setdraw(t_draw *draw, t_cub_info *cub, mlx_t *mlx)
{
	(void)mlx;//??
	draw->n_wall = mlx_load_png(cub->n_wall);
	draw->s_wall = mlx_load_png(cub->s_wall);
	draw->w_wall = mlx_load_png(cub->w_wall);
	draw->e_wall = mlx_load_png(cub->e_wall);
}
int	ft_checkdraw(t_draw draw)
{
	if (!draw.n_wall || !draw.s_wall || !draw.e_wall || !draw.w_wall)
		return (-1);
	return (0);
}