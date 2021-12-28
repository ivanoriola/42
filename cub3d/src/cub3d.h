/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioriola <ioriola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 07:56:18 by ioriola           #+#    #+#             */
/*   Updated: 2021/09/21 07:58:59 by ioriola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>

# include <libft.h>
# include <get_next_line.h>
# include <mlx.h>

# define NONE		0xFF000000
# define WHITE		0x00FFFFFF
# define BLACK		0x00000000
# define RED		0x00FF0000
# define GREEN		0x0000FF00
# define BLUE		0x000000FF
# define MAGENTA	0x00FF00FF
# define YELLOW		0x00FFFF00
# define CYAN		0x0000FFFF

# define HALF_PI 		1.570796
# define PI 			3.141592
# define THREEHALF_PI 	4.712388
# define TWO_PI 		6.283184

# define QUARTER 		90
# define HALF 			180
# define THREEQUARTER 	270
# define FULL 			360

# define DIR_UP 	270
# define DIR_RIGHT 	0
# define DIR_DOWN 	90
# define DIR_LEFT 	180

# define FLT_MAX		3.402823466e+38F

# define ESC 	53
# define W 		13
# define A 		0
# define S 		1
# define D 		2
# define LEFT 	123
# define RIGHT 	124

typedef struct s_validate{
	int	notexture_ok;
	int	sotexture_ok;
	int	wetexture_ok;
	int	eatexture_ok;
	int	fcolor_ok;
	int	ccolor_ok;
	int	map_ok;
}	t_validate;

typedef struct s_settings{
	int			xres;
	int			yres;
	char		*notexture;
	char		*sotexture;
	char		*wetexture;
	char		*eatexture;
	uint32_t	fcolor;
	uint32_t	ccolor;
	t_validate	validate;
}	t_settings;

typedef struct s_mlx{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_mlx;

typedef struct s_map{
	char	**map;
	char	*file_name;
	int		width;
	int		height;
	int		rows;
	int		til_map;
	int		til_siz;
	int		mrg;
}	t_map;

typedef struct s_player
{
	int		x;
	int		y;
	float	rel_x;
	float	rel_y;
	int		dir;
}	t_player;

typedef struct s_ray
{
	float	angle;
	float	wall_hit_x;
	float	wall_hit_y;
	float	distance;
	int		hit_ver;
	int		up;
	int		down;
	int		left;
	int		right;
	int		wall_content;
	int		wall_facing;
	float	xintercept;
	float	yintercept;
	float	xstep;
	float	ystep;
	int		x_to_check;
	int		y_to_check;
	int		hor_w_hit;
	float	hor_w_hit_x;
	float	hor_w_hit_y;
	int		hor_w_cont;
	float	ver_touch_x;
	float	ver_touch_y;
	int		ver_w_hit;
	float	ver_w_hit_x;
	float	ver_w_hit_y;
	int		ver_w_cont;
	float	hor_touch_x;
	float	hor_touch_y;
	float	hor_hit_dist;
	float	ver_hit_dist;
}	t_ray;

typedef struct s_raycast
{
	float	fov_angle;
	int		num_of_rays;
	t_ray	*rays;
}	t_raycast;

typedef struct s_image
{
	void		*img_ptr;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
}	t_image;

typedef struct s_texture
{
	void		*img_ptr;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
	int			width;
	int			height;
}	t_texture;

typedef struct s_render
{
	t_image		image;
	uint32_t	*color_buffer;
	float		perp_distance;
	float		dist_proj_plane;
	float		projwall_height;
	int			wall_strip_height;
	int			wall_top_pixel;
	int			wall_bottom_pixel;
	uint32_t	pix_color;
	int			offset_x;
	int			offset_y;
	int			dist_top;
	t_texture	walls[4];
}	t_render;

typedef struct s_all {
	t_map			map;
	t_player		player;
	t_mlx			mlx;
	t_settings		settings;
	t_raycast		rayc;
	t_render		render;
}	t_all;

// main.c //

int		arg_is_cub_ext(char *line);
int		goodbye(t_all *all, char *errmsg);
void	free_memory(t_all *all);

// color_buffer.c //

void	setup_color_buffer(t_all *all);
void	render_color_buffer(t_all *all);
void	draw_frame_image(t_all *all);

// file_open.c //

int		file_open(t_all *all);
void	validate(t_all *all);

// game.c //

void	setup(t_all *all);
void	render(t_all *all);
void	update(t_all *all);

// init_values.c //

void	init_values(t_all *all);
void	init_rayc_values(t_all *all);
void	init_ray_values(t_ray *ray);
void	init_ray_values2(t_ray *ray);

// line_types.c //

int		line_is_texture(char *line);
int		line_is_color(char *line);
int		line_is_map(char *line);
int		char_is_map(char c);

// lines_process.c //

void	lines_map_count(int fd, t_all *all);
void	lines_get(int fd, t_all *all);
char	*line_clean_start_spaces(char *line);
int		char_is_space(char c);

// map_check.c //

int		map_check(t_all *all);
int		map_row_check(char *str);
int		map_col_check(t_all *all, char **m);

// map_player_get.c //

void	get_map(t_all *all, char *line);
char	*line_spaces_at_end(char *line, int width);
void	get_player_initial_pos_and_dir(t_all *all);
int		char_is_player(char c);
void	get_player_dir(t_all *all, char c);

// minimap.c //

void	draw_sqr(int x, int y, int color, t_all *all);
void	draw_minimap(char **map, t_all *all);
void	draw_player(t_all *all);

// mlx_tools.c //

int		init_window(t_all *all);
int		key_hook(int key, t_all *all);

// move.c //

void	move_front(t_all *all, int direction);
void	move_side(t_all *all, int direction);
void	turn(t_all *all, int direction);
void	val_limit_adjust(t_all *all);
int		map_xy_content(t_all *all, int x, int y);

// raycast.c //

void	cast_all_rays(t_all *all);
void	cast_ray(t_all *all, t_ray	*ray);
void	calculate_hit_distance(t_all *all, t_ray *ray);
void	select_minimal_hit_distance(t_ray *ray);

// raycast_rays.c //

void	cast_ray_horizontal(t_all *all, t_ray *ray);
void	cast_ray_horizontal2(t_all *all, t_ray *ray);
void	cast_ray_vertical(t_all *all, t_ray *ray);
void	cast_ray_vertical2(t_all *all, t_ray *ray);
void	wall_facing(t_ray *ray);

// raycast_tools.c //

float	normalize_angle(float angle);
float	get_distance(float x1, float y1, float x2, float y2);

// render_3d.c //

void	load_textures(t_all *all);
void	generate_3d_projection(t_all *all);
void	render_ceiling_floor(int i, t_all *all);
void	render_wall(int i, t_all *all);
void	render_wall2(int i, t_all *all);

// settings_get.c //

int		int_len(int n);
void	get_textures(t_all *all, char *line, int texture);
void	set_textures(t_all *all, char *line, int texture);
void	get_color(t_all *all, char *line, int color);

#endif
