#include "../inc/cub3d.h"

t_draw	ft_setdraw(t_cub_info *cub, mlx_t *mlx)
{
	t_draw	draw;

	draw.n_wall = mlx_load_png(cub->n_wall);
	draw.s_wall = mlx_load_png(cub->s_wall);
	draw.w_wall = mlx_load_png(cub->w_wall);
	draw.e_wall = mlx_load_png(cub->e_wall);
	return (draw);
}
int	ft_checkdraw(t_draw draw)
{
	if (!draw.n_wall || !draw.s_wall || !draw.e_wall || !draw.w_wall)
		return (-1);
	return (0);
}