/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioriola <ioriola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 07:56:18 by ioriola           #+#    #+#             */
/*   Updated: 2021/09/24 10:17:51 by ioriola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>

# include <libft.h>
# include <mlx.h>

// Colors
# define NONE		0xFF000000
# define WHITE		0x00FFFFFF
# define BLACK		0x00000000
# define RED		0x00FF0000
# define GREEN		0x0000FF00
# define BLUE		0x000000FF
# define MAGENTA	0x00FF00FF
# define YELLOW		0x00FFFF00
# define CYAN		0x0000FFFF

// Key codes
# define ESC 	53
# define W 		13
# define A 		0
# define S 		1
# define D 		2
# define R 		15
# define UP 	126
# define DOWN 	125
# define LEFT 	123
# define RIGHT 	124

typedef struct s_color
{
	uint32_t	color;
	float		r;
	float		g;
	float		b;
	float		h;
	float		s;
	float		v;
	float		f;
	float		p;
	float		q;
	float		t;
}	t_color;

typedef struct s_image
{
	void		*img_ptr;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
}	t_image;

typedef struct s_fractal{
	char		set_type;
	t_color		co;
	double		real;
	double		imag;
	double		new_real;
	double		new_imag;
	double		old_real;
	double		old_imag;
	double		zoom;
	double		movex;
	double		movey;
	int			max_iter;
}	t_fractal;

typedef struct s_mlx{
	void		*mlx_ptr;
	void		*win_ptr;
	int			xres;
	int			yres;
	uint32_t	*co_buff;
	t_image		image;
}	t_mlx;

typedef struct s_all
{
	t_mlx		mlx;
	t_fractal	fr;
}	t_all;

// color_manage.c //
void	color_manage(t_all *all, float h_in, float s_in, float v_in);
void	color_manage_conditional(t_all *all);
void	color_switch1(t_all *all, int i);
void	color_switch2(t_all *all, int i);

// core.c //
void	setup(t_all *all);
void	update(t_all *all);
void	render(t_all *all);

// init_values.c //
void	init_values(t_all *all);
void	reset_values(t_all *all);

// main.c //
int		arg_ok(t_all *all, char *str);
int		goodbye(t_all *all, char *errmsg);
void	free_memory(t_all *all);

// mlx_image.c //
void	setup_color_buffer(t_all *all);
void	render_color_buffer(t_all *all);
void	draw_image(t_all *all);
void	screen_info(t_all *all);

// mlx_tools.c //
int		init_window(t_all *all);
int		key_hook(int key, t_all *all);
int		mouse_hook(int button, int x, int y, t_all *all);

// sets.c //
void	julia_set(t_all *all);
void	mandelbrot_set(t_all *all);
void	iteration(int x, int y, t_all *all);

#endif
