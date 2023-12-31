/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 14:19:31 by ysmeding          #+#    #+#             */
/*   Updated: 2023/09/25 12:13:16 by ysmeding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H 

# include "../libft/libft.h"
# include "../MLX/include/MLX42/MLX42.h"

/* close read write */
# include <unistd.h>
/* exit malloc free */
# include <stdlib.h>
/* perror printf */
# include <stdio.h>
/* strerror */
# include <string.h>
/* open */
# include <fcntl.h>
/* errno */
# include <errno.h>

# include <math.h>

# define ROT_SPEED 0.01745329251f
# define MOV_SPEED 0.05f
# define WID 1000
# define HEI 800
# define WALL_HEI 600

typedef struct s_draw
{
	mlx_texture_t	*n_wall;
	mlx_texture_t	*s_wall;
	mlx_texture_t	*w_wall;
	mlx_texture_t	*e_wall;
}					t_draw;

typedef struct s_cub_info
{
	char	**scene;
	char	**map;
	int		hei;
	int		wid;
	char	*n_wall;
	char	*s_wall;
	char	*w_wall;
	char	*e_wall;
	int		floor_col[3];
	int		ceil_col[3];
}			t_cub_info;

typedef struct s_player_info
{
	double	xpos;
	double	ypos;
	double	xdir;
	double	ydir;
	double	zdir;
	double	pov;
	double	xcamera;
	double	ycamera;
}			t_player_info;

typedef struct s_impact
{
	double	dist;
	char	wall;
	double	posx;
	double	posy;
	double	projx;
	double	projy;
	double	deltadist;
}			t_impact;

typedef struct s_window_info
{
	mlx_t		*mlx;
	int			wid;
	int			hei;
	mlx_image_t	*g_img;
	t_impact	dist;
	int			frame;
	int			menu;
	mlx_image_t	*menustr[4];
}			t_window_info;

typedef struct s_dist
{
	double	distx;
	double	disty;
	double	deltax;
	double	deltay;
	double	angx;
	double	angy;
	double	rayang;
	double	raydirx;
	double	raydiry;
	int		xcross;
	int		ycross;
	int		dirx;
	int		diry;
	float	ang;
}			t_dist;

typedef struct s_all_info
{
	t_cub_info		*info;
	t_window_info	*window;
	t_player_info	*player;
	t_draw			*draw;
}			t_all_info;

/* ------------------------------- arr_utils.c ------------------------------ */

int		ft_arrlen(char **arr);
char	*ft_strtrimnl(char *str);
char	**ft_arrapp(char **arr, char *app);
char	**ft_arrremove(char **arr, int pos);
char	**ft_arrdup(char **arr);

/* ------------------------------- calc_dist.c ------------------------------ */

float	x_projection(float angle, float dist);
float	y_projection(float angle, float dist);

/* ------------------------------- check_dup.c ------------------------------ */

void	ft_check_dup_in_line(char *line, int *ct);
void	ft_check_dup_param(t_cub_info *info);

/* --------------------------------- cub3d.c -------------------------------- */

void	ft_init_info(t_cub_info *info);
int		ft_cub3d(char *scenefile);

/* ----------------------- distance_crossings.c ----------------------- */

void	ft_xcross_util(t_all_info *all, t_dist *dist, t_impact *impact);
void	ft_loopxcrossings(t_all_info *all, t_dist *dist, t_impact *impact);
void	ft_ycross_util(t_all_info *all, t_dist *dist, t_impact *impact);
void	ft_loopycrossings(t_all_info *all, t_dist *dist, t_impact *impact);

/* -------------------------- distance_init.c ------------------------- */

void	ft_setdistxvar(t_dist *dist, t_player_info *player);
void	ft_setdistyvar(t_dist *dist, t_player_info *player);
void	ft_init_impact(t_impact *impact);
void	ft_init_dist(t_dist *dist, t_player_info *player, double ang);

/* ------------------------- distance_utils.c ------------------------- */

double	ft_abs(double a);
double	ft_setang(double ang);
double	ft_getangx(double ang);
double	ft_getangy(double ang);

/* ------------------------------- distance.c ------------------------------- */

void	ft_copy_impact(t_impact *copy, t_impact src);
void	ft_calculatedist(t_all_info *all, double ang, t_impact *impact);
double	ft_calculate_deltaang(int i);
//void	ft_angleloop(t_all_info	*all);

/* ------------------------------- errorfunc.c ------------------------------ */

void	ft_errexit(char *errormessage);
void	ft_errfreeexit(char *errormessage, t_cub_info *info);
void	ft_errfreeexit2(char *errormessage, t_cub_info *info, t_draw *draw);

/* ------------------------------ ft_freefunc.c ----------------------------- */

void	ft_freearr(char **arr);
void	ft_freearr2(char **arr, char **newarr);
void	ft_free_info(t_cub_info *info);
void	ft_free_draw(t_draw *draw);

/* ------------------------------- ft_getstr.c ------------------------------ */

int		ft_findchar(char *str, char c);
char	*ft_straddfree(char *str, char chr);
int		ft_addwhilenotchar(char *line, char **name, char c);
char	*ft_getstr(char *line, int len, int *total);

/* ---------------------------- ft_parse_utils.c ---------------------------- */

int		ft_whiledigit(char *str);
void	ft_skipspace(char *line, int *len);
void	ft_skipcomma(char *line, int *len, t_cub_info *info);
void	ft_skip_emptyline(t_cub_info *info, int i);
void	ft_delandinsertspace(char **str, int p, int n);

/* -------------------------- ft_parse_checkfunc.c -------------------------- */

void	ft_check_char(char c, t_cub_info *info);
void	ft_checkmapline(t_cub_info *info, int i);
void	ft_check_closedmap(t_cub_info *info);

/* ---------------------- ft_parse_check_and_getfunc.c  --------------------- */

int		ft_checkext(char *scenefile);
void	ft_checkend(char *line, int len, t_cub_info *info);
void	ft_getcolor(char *line, t_cub_info *info, char c);
void	ft_get_map(t_cub_info *info, int i);
void	ft_get_elements(t_cub_info *info);

/* ----------------------------- ft_parse_map.c ----------------------------- */

int		ft_strlen_no_space_end(char *str);
char	*ft_addspaces(char *str, int len, int maxlen);
void	ft_makemap_rectangular(t_cub_info *info);
int		ft_step(char **map, int row, int col, t_cub_info *info);
void	ft_fillx(char **map, int row, int col, t_cub_info *info);

/* ---------------------------- ft_parse_scene.c ---------------------------- */

void	ft_read_scene(char *scenefile, t_cub_info *info);
int		ft_wfc(t_cub_info *info);
void	ft_assignvalue(char *line, int *len, int *var, t_cub_info *info);
void	ft_search_typeid(char *line, t_cub_info *info);
int		ft_parse_scene(char *scenefile, t_cub_info *info);

/* ----------------------------- ft_set_player.c ---------------------------- */

double	find_player_x(t_cub_info *info);
double	find_player_y(t_cub_info *info);
void	set_player_rot(t_player_info *player, char c);
void	find_player_rot(t_player_info *player, t_cub_info *info);
void	ft_set_player(t_player_info *player, t_cub_info *info);

/* game_enable_image.c */

void	ft_put_menu(t_window_info *w);
void	ft_disable_menu(t_all_info *all);
void	ft_enable_menu(t_all_info *all);
void	ft_enable_images(t_all_info *all);
void	ft_put_images(t_all_info *all);

/* game_image.c */

void	makeimage_walls(t_window_info *window, t_all_info *all, int i, int j);
void	makeimage(t_window_info	*window, t_all_info *all);

/* game_key.c */

void	ft_move_and_image(t_all_info *all, int move);
void	ft_tabkey(t_all_info *all);
void	ft_mlx_keyfunc(mlx_key_data_t keydata, void *param);

/* game_putpixels.c */

void	ft_put_pixel_color(t_all_info *all, int i, int j, char c);
void	ft_put_texturex(t_all_info *all, int i, int j, mlx_texture_t *texture);
void	ft_put_texturey(t_all_info *all, int i, int j, mlx_texture_t *texture);
void	ft_puttexturemirx(t_all_info *all, int i, int j, mlx_texture_t *txtur);
void	ft_puttexturemiry(t_all_info *all, int i, int j, mlx_texture_t *txtur);

/* game_utils.c */

int		ft_fl(float pos);
int		ft_dir(t_player_info *player, char c);

/* --------------------------------- game.c --------------------------------- */

void	ft_initwindow(t_window_info	*window);
void	ft_hook(void *arg);
void	ft_delete_textures(t_all_info *all);
void	ft_game(t_cub_info *info, t_player_info *player);

/* -------------------------------- matrix.c -------------------------------- */

void	rotate_z(double *x, double *y, double ang);

/* ------------------------------- movement.c ------------------------------- */

int		ft_checkdiagmove(t_cub_info *cub, t_player_info *player, int tmp[2]);
void	move_player_front(t_cub_info *cub, t_player_info *player, int i);
void	move_player_lateral(t_cub_info *cub, t_player_info *player, int i);
void	move_player(t_cub_info *cub, t_player_info *player, int i);
void	rot_player(t_player_info *player, int i);

/* ----------------------------- parse_scene1.c ----------------------------- */

void	ft_check_oneplayer(t_cub_info *info);

/* ------------------------------- str_utils.c ------------------------------ */

int		ft_strchr_r(const char *str, char *check);
int		ft_strchr_i(const char *s, int c);
char	*ft_substrfree(char *str, unsigned int start, size_t len);
char	*ft_strjoinfree(char *begin, char *end, int num);

/* ------------------------------- textures.c ------------------------------- */

void	ft_setdraw(t_draw *draw, t_cub_info *cub);
void	ft_checkdraw(t_draw *draw, t_cub_info *cub);

#endif