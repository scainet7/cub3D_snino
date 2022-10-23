/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_textures.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 19:40:18 by snino             #+#    #+#             */
/*   Updated: 2022/10/23 19:43:39 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

int	get_color(char c)
{
	int	color;

	if (c == '0')
		color = 0x808080;
	else if (c == '2')
		color = 0x00FF00;
	else if (c == '1' || c == '3')
		color = 0x4b4b4b;
	else
		color = 0;
	return (color);
}

int	create_rgb(int r, int g, int b)
{
	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->mlx_addr + (y * img->line_length + x
			* (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	my_mlx_pixel_get(t_img *img, int x, int y)
{
	int		color;
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	color = *(unsigned int *)dst;
	return (color);
}

void	ft_get_wall_pixels(t_img *img, int type)
{
	int	i;
	int	j;

	i = 0;
	while (i < IMG)
	{
		j = 0;
		while (j < IMG)
		{
			if (type == north)
				img->north_wall[i][j] = my_mlx_pixel_get(img, i, j);
			else if (type == south)
				img->south_wall[i][j] = my_mlx_pixel_get(img, i, j);
			else if (type == west)
				img->west_wall[i][j] = my_mlx_pixel_get(img, i, j);
			else if (type == east)
				img->east_wall[i][j] = my_mlx_pixel_get(img, i, j);
			j++;
		}
		i++;
	}
}
