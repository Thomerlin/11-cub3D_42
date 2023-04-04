/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n <llopes-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 07:57:47 by tyago-ri          #+#    #+#             */
/*   Updated: 2023/04/04 16:17:30 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_step_xy(t_strc *c)
{
	if (c->dda.raydir.x < 0)
		c->dda.step.x = -1;
	else
		c->dda.step.x = 1;
	if (c->dda.raydir.y < 0)
		c->dda.step.y = -1;
	else
		c->dda.step.y = 1;
}

void	init_dist_to_side(t_strc *c)
{
	t_vector	map_pos;

	map_pos.x = floor(c->player.pos.x);
	map_pos.y = floor(c->player.pos.y);
	if (c->dda.raydir.x < 0)
		c->dda.to_side.x = (c->player.pos.x - map_pos.x) * c->dda.delta.x;
	else
		c->dda.to_side.x = (map_pos.x + 1 - c->player.pos.x)
			* c->dda.delta.x;
	if (c->dda.raydir.y < 0)
		c->dda.to_side.y = (c->player.pos.y - map_pos.y)
			* c->dda.delta.y;
	else
		c->dda.to_side.y = (map_pos.y + 1 - c->player.pos.y)
			* c->dda.delta.y;
	init_step_xy(c);
}

void	init_camera(t_map *map, t_strc *c)
{
	double	multiplier;

	multiplier = 2 * ((double)c->dda.pixel / (double) c->win.width) - 1;
	c->player.camera.pixel.x = c->player.camera.plane.x * multiplier;
	c->player.camera.pixel.y = c->player.camera.plane.y * multiplier;
}

void	init_raydir_and_delta(t_strc *c)
{
	c->dda.raydir.x = c->player.camera.pixel.x + c->player.dir.x;
	c->dda.raydir.y = c->player.camera.pixel.y + c->player.dir.y;
	if (c->dda.raydir.x == 0)
	{
		c->dda.delta.x = 1;
		c->dda.delta.y = 0;
	}
	if (c->dda.raydir.y == 0)
	{
		c->dda.delta.x = 0;
		c->dda.delta.y = 1;
	}
	if (c->dda.raydir.y != 0 && c->dda.raydir.x != 0)
	{
		c->dda.delta.x = fabs(1 / c->dda.raydir.x);
		c->dda.delta.y = fabs(1 / c->dda.raydir.y);
	}
}

void	init_perpendicular(t_strc *c)
{
	if (c->dda.hit.side == 0)
		c->dda.perpendicular = c->dda.line_size.x - c->dda.delta.x;
	else
		c->dda.perpendicular = c->dda.line_size.y - c->dda.delta.y;
	if (c->state.distortion == TRUE)
	{
		if (c->dda.hit.side == 0)
			c->draw.wall_x = c->player.pos.y + c->dda.perpendicular + \
					c->dda.raydir.y;
		else
			c->draw.wall_x = c->player.pos.x + c->dda.perpendicular + \
				c->dda.raydir.x;
	}
	else
	{
		if (c->dda.hit.side == 0)
			c->draw.wall_x = c->player.pos.y + c->dda.perpendicular * \
				c->dda.raydir.y;
		else
			c->draw.wall_x = c->player.pos.x + c->dda.perpendicular * \
				c->dda.raydir.x;
	}
}
