/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioriola <ioriola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 10:33:04 by ioriola           #+#    #+#             */
/*   Updated: 2021/09/15 10:43:52 by ioriola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	main(int argc, char **argv)
{
	t_all	all;

	init_values(&all);
	if (argc > 3 || argc == 1)
		goodbye(&all, "Error\nINVALID ARGUMENTS");
	all.map.file_name = argv[1];
	if (!arg_is_cub_ext(all.map.file_name))
		goodbye(&all, "Error\nINVALID '.CUB' FILE");
	if (file_open(&all) && map_check(&all))
	{
		init_window(&all);
		init_rayc_values(&all);
		setup(&all);
		update(&all);
		render(&all);
		mlx_key_hook (all.mlx.win_ptr, key_hook, &all);
		mlx_hook(all.mlx.win_ptr, 17, 0L, goodbye, &all);
		mlx_loop(all.mlx.mlx_ptr);
	}
	return (0);
}

int	arg_is_cub_ext(char *str)
{
	char	*ext;

	ext = str + ft_strlen(str) - 4;
	if (!ft_strncmp(ext, ".cub", 4))
		return (1);
	return (0);
}

int	goodbye(t_all *all, char *errmsg)
{
	free_memory(all);
	if (all->mlx.win_ptr)
		mlx_destroy_window(all->mlx.mlx_ptr, all->mlx.win_ptr);
	printf ("%s", errmsg);
	exit(0);
}

void	free_memory(t_all *all)
{
	int	i;

	i = 0;
	while (i < all->map.rows)
	{
		free (all->map.map[i]);
		i++;
	}
	free (all->map.map);
	free (all->rayc.rays);
	free (all->render.color_buffer);
}
