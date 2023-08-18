#include "../inc/cub3d.h"
void ft_check_oneplayer(t_cub_info *info)
{
    int found;
    int i;
    int j;

    found = 0;
    i = -1;
    while (info->map && info->map[++i])
    {
        j = -1;
        while (info->map[i][++j])
        {
            if (info->map[i][j] == 'N' || info->map[i][j] == 'S' ||\
                info->map[i][j] == 'E' || info->map[i][j] == 'W')
                found++;
        }
    }
    if (found != 1)
      ft_errfreeexit("There must be 1 player", info);
}

mlx_image_t	*ft_png_to_img(char *pngfile, mlx_t *mlx)
{
	mlx_image_t		*img;
	mlx_texture_t	*texture;

	img = NULL;
	texture = mlx_load_png(pngfile);
	if (texture)
	{
		img = mlx_texture_to_image(mlx, texture);
		mlx_delete_texture(texture);
	}
	return (img);
}

t_draw	ft_setdraw(t_cub_info *cub, mlx_t *mlx)
{
	t_draw	draw;

	draw.n_wall = ft_png_to_img(cub->n_wall, mlx);
	draw.s_wall = ft_png_to_img(cub->s_wall, mlx);
	draw.w_wall = ft_png_to_img(cub->w_wall, mlx);
	draw.e_wall = ft_png_to_img(cub->e_wall, mlx);
	return (draw);
}
int	ft_checkdraw(t_draw draw)
{
	if (!draw.n_wall || !draw.s_wall || !draw.e_wall || !draw.w_wall)
		return (-1);
	return (0);
}