/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enunes <eocnunes@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 19:05:39 by enunes            #+#    #+#             */
/*   Updated: 2017/10/06 22:20:00 by enunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	instructions(void)
{
	ft_putendl("\e[1;32mOK\e[0m\n");
	ft_putendl("\t  FDF is controlled with the");
	ft_putendl("\t      numpad mapped as:\n");
	ft_putendl("\t\e[90m ------ ------ ------ ------\e[0m");
	ft_putendl("\t\e[90m|   nl |    = |    / |    * |\e[0m");
	ft_putendl("\t\e[90m|      |      |      |      |\e[0m");
	ft_putendl("\t\e[90m ------ ------ ------ ------\e[0m");
	ft_putendl("\t\e[90m|    7 |    8 |    9 |    - |\e[0m");
	ft_putstr("\t\e[90m|  \e[1;36mM-\e[90m  |  \e[1;32mY+\e[90m  |  ");
	ft_putstr("\e[1;36mM+\e[90m  |  \e[93mS-\e[90m  |\n\e[0m");
	ft_putendl("\t\e[90m ------ ------ ------ ------\e[0m");
	ft_putendl("\t\e[90m|    4 |    5 |    6 |    + |\e[0m");
	ft_putstr("\t\e[90m|  \e[1;31mX-\e[90m  | \e[0mRST\e[90m  |  ");
	ft_putstr("\e[1;31mX+\e[90m  |  \e[93mS+\e[90m  |\n\e[0m");
	ft_putendl("\t\e[90m ------ ------ ------ ------\e[0m");
	ft_putendl("\t\e[90m|    1 |    2 |    3 |      |\e[0m");
	ft_putstr("\t\e[90m|  \e[1;94mR-\e[90m  |  \e[1;32mY-\e[90m  |  ");
	ft_putstr("\e[1;94mR+\e[90m  |      |\n\e[0m");
	ft_putendl("\t\e[90m ------ ------ ------|      |\e[0m");
	ft_putendl("\t\e[90m|             |      |      |\e[0m");
	ft_putendl("\t\e[90m|           0 |    . |  ENT |\e[0m");
	ft_putendl("\t\e[90m ------------- ------ ------\e[0m");
	ft_putendl("\n\t  \e[1;104;97m Press [ESC] to quit FDF \e[0m\n\n");
}

int		fdf_keyhook(int key, t_fdf *f)
{
	f->pos_x >= 360 ? f->pos_x -= 360 : (0);
	f->pos_y >= 360 ? f->pos_y -= 360 : (0);
	f->pos_z >= 360 ? f->pos_z -= 360 : (0);
	f->pos_x <= -360 ? f->pos_x += 360 : (0);
	f->pos_y <= -360 ? f->pos_y += 360 : (0);
	f->pos_z <= -360 ? f->pos_z += 360 : (0);
	(key == ESC) ? exit(0) : (0);
	(key == RESET) ? fdf_defaults(f) : (0);
	(key == HPOS) ? f->height++ : (0);
	(key == HNEG && f->height) ? f->height-- : (0);
	(key == SPOS && f->speed < 10) ? f->speed++ : (0);
	(key == SNEG && f->speed) ? f->speed-- : (0);
	(key == XPOS) ? f->pos_x += f->speed : (0);
	(key == XNEG) ? f->pos_x -= f->speed : (0);
	(key == YPOS) ? f->pos_y += f->speed : (0);
	(key == YNEG) ? f->pos_y -= f->speed : (0);
	(key == RNEG) ? f->pos_z += f->speed : (0);
	(key == RPOS) ? f->pos_z -= f->speed : (0);
	((f->height * f->map_max) > (f->win_y / 2)) ? f->height-- : (0);
	(!f->height) ? f->height++ : (0);
	fdf_img_gen(f);
	return (0);
}