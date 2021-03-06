/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharras <acharras@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 15:30:15 by acharras          #+#    #+#             */
/*   Updated: 2020/03/12 13:37:58 by acharras         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

static void	ft_init_config_map(t_cub3d *game)
{
	game->verif_no = 0;
	game->verif_so = 0;
	game->verif_ea = 0;
	game->verif_we = 0;
	game->verif_sp = 0;
	game->verif_f = 0;
	game->verif_c = 0;
	game->left_arrow = 0;
	game->right_arrow = 0;
	game->press_a = 0;
	game->press_d = 0;
	game->press_s = 0;
	game->press_w = 0;
	game->verif_r = 0;
	game->newline_map = 0;
	game->press_h = 0;
	game->sprint = 100;
	game->maxsprint = 100;
	game->wait_sprint = 0;
}

static void	ft_init_config_game(t_cub3d *game)
{
	game->tracked = 0;
	game->mlx_ptr = NULL;
	game->win_ptr = NULL;
	game->map = NULL;
	game->tab_color = NULL;
	game->north = NULL;
	game->south = NULL;
	game->east = NULL;
	game->west = NULL;
	game->sprite = NULL;
	game->color_floor = -1;
	game->color_ceiling = -1;
	game->width = -1;
	game->height = -1;
	game->map_i = 0;
	game->check_map = 0;
	game->map_false = 0;
	game->tmp_map = NULL;
	game->check_space_nbr = 0;
	game->life = 100;
	game->maxlife = 100;
	game->wait_life = 0;
}

static void	ft_texture_init_next(t_cub3d *game)
{
	if (!(game->img_we_ptr = mlx_xpm_file_to_image(game->mlx_ptr, game->west,
		&game->we_width, &game->we_height)))
		ft_exit_texture(game);
	game->tracked = 5;
	if (!(game->data_we = (int *)mlx_get_data_addr(game->img_we_ptr,
		&game->bits_per_pixel, &game->size_line, &game->endian)))
		ft_exit_texture(game);
	if (!(game->img_ea_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
		game->east, &game->ea_width, &game->ea_height)))
		ft_exit_texture(game);
	game->tracked = 6;
	if (!(game->data_ea = (int *)mlx_get_data_addr(game->img_ea_ptr,
		&game->bits_per_pixel, &game->size_line, &game->endian)))
		ft_exit_texture(game);
	if (!(game->sprite_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
		game->sprite, &game->sp_width, &game->sp_height)))
		ft_exit_texture(game);
	game->tracked = 7;
	if (!(game->data_sprite = (int *)mlx_get_data_addr(game->sprite_ptr,
		&game->bits_per_pixel, &game->size_line, &game->endian)))
		ft_exit_texture(game);
}

void		ft_texture_init(t_cub3d *game)
{
	if (!(game->img_ptr = mlx_new_image(game->mlx_ptr, game->width,
		game->height)))
		ft_exit_texture(game);
	game->tracked = 2;
	if (!(game->img_data = (int *)mlx_get_data_addr(game->img_ptr,
		&game->bits_per_pixel, &game->size_line, &game->endian)))
		ft_exit_texture(game);
	if (!(game->img_no_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
		game->north, &game->no_width, &game->no_height)))
		ft_exit_texture(game);
	game->tracked = 3;
	if (!(game->data_no = (int *)mlx_get_data_addr(game->img_no_ptr,
		&game->bits_per_pixel, &game->size_line, &game->endian)))
		ft_exit_texture(game);
	if (!(game->img_so_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
		game->south, &game->so_width, &game->so_height)))
		ft_exit_texture(game);
	game->tracked = 4;
	if (!(game->data_so = (int *)mlx_get_data_addr(game->img_so_ptr,
		&game->bits_per_pixel, &game->size_line, &game->endian)))
		ft_exit_texture(game);
	ft_texture_init_next(game);
}

void		ft_init_game(t_cub3d *game)
{
	ft_init_config_game(game);
	ft_init_config_map(game);
}
