#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <MLX42/MLX42.h>

#define WIDTH 600
#define HEIGHT 600

/*int map[] =
{
	1,1,1,1,1,1,1,1,
	1,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,1,
	1,1,1,1,1,1,1,1,
};*/

static mlx_image_t*	image;
static mlx_image_t*	pouet;

void ft_set_color(void* arg)
{
	(void)arg;
	int x;
	int y;

	x = 0;
	while (x < (int)image->width)
	{
		y = 0;
		while (y < (int)image->height)
		{
			mlx_put_pixel(image, x, y, 0xFF0000FF);
			y++;
		}
		x++;
	}
}

/*void	draw_map2D(void *arg)
{
	(void)arg;
	int x;
	int y;

	y = 0;
	while (y < 8)
	{
		x = 0;
		while (x < 8)
		{
			if (map[y * 8 + x] == 1)
				mlx_put_pixel(pouet, x * 64, y * 64, 0x000000FF);
			else
				mlx_put_pixel(pouet, x * 64, y * 64, 0xFFFFFFFF);
			x++;
		}
		y++;
	}
}*/

void ft_set_color2(void* arg)
{
	(void)arg;
	int x;
	int y;

	x = 0;
	while (x < (int)pouet->width)
	{
		y = 0;
		while (y < (int)pouet->height)
		{
			mlx_put_pixel(pouet, x, y, 0x000000FF);
			y++;
		}
		x++;
	}
}

void ft_hook(void* arg)
{
	mlx_t* mlx = arg;

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
		image->instances[0].y -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		image->instances[0].y += 5;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		image->instances[0].x -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		image->instances[0].x += 5;
}

int main(int ac, const char** av)
{
	(void)ac;
	(void)av;

	mlx_t* mlx;

	if (!(mlx = mlx_init(WIDTH, HEIGHT, "MLX42", false)))
	{
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	if (!(pouet = mlx_new_image(mlx, 100, 100)))
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	if (mlx_image_to_window(mlx, pouet, 250, 250) == -1)
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	if (!(image = mlx_new_image(mlx, 10, 10)))
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	if (mlx_image_to_window(mlx, image, 280, 280) == -1)
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	mlx_loop_hook(mlx, ft_set_color2/*draw_map2D*/, mlx);
	mlx_loop_hook(mlx, ft_set_color, mlx);
	mlx_loop_hook(mlx, ft_hook, mlx);

	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
