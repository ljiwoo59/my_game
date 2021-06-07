#ifndef CUB3D_H
# define CUB3D_H

# include "minilibx/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include <limits.h>

# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_RELEASE 3
# define X_EVENT_KEY_EXIT 17
# define KEY_ESC 53
# define KEY_W 13
# define KEY_S 1
# define KEY_A 0
# define KEY_D 2
# define KEY_LEFT 123
# define KEY_RIGHT 124

# define WIDTH 640
# define HEIGHT 480
# define mapWidth 24
# define mapHeight 24
# define tw 64
# define th 64

typedef struct s_param
{
	double	posX;
	double	posY;
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;
	double cameraX;
	double rayDirX;
	double rayDirY;
	int mapX;
	int mapY;
	double sideDistX;
	double sideDistY;
	double deltaDistX;
	double deltaDistY;
	double perpWallDist;
	int stepX;
	int stepY;
	int hit;
	int side;
	int lineHeight;
	int y_start;
	int y_end;
	double wallX;
	int texX;
	double step;
	double texPos;
	int texY;
	double movespeed;
	double rotspeed;
}		t_param;

typedef struct	s_img
{
	void	*img_ptr;
	int	*data;
	int	size_l;
	int	bpp;
	int	endian;
	int	width;
	int	height;
	void	*t_ptr;
	int	*texture;
	int	*texture2;
	int	*texture3;
	int	*texture4;
	int	t_size_l;
	int	t_bpp;
	int	t_endian;
}		t_img;

typedef struct	s_mlx
{
	void	*mlx_ptr;
	void	*win;
	t_img	*img;
	t_param *param;
}		t_mlx;

typedef struct s_info
{
	char *path_no;
	char *path_so;
	char *path_we;
	char *path_ea;
	int path_f;
	int path_c;
}		t_info;

void	error();
int	cub3d();
void	program_init(t_mlx *mlx);
void	texture_init(t_mlx *mlx);
void	imgs_init(t_mlx *mlx);
void	r_param_init(t_mlx *mlx, int x);
void	r_param_init2(t_mlx *mlx);
void	r_param_set(t_mlx *mlx, int x);
void	r_param_set2(t_mlx *mlx);
void	dda_set(t_mlx *mlx);
int	_close(t_mlx *mlx);
void	draw_line(t_mlx *mlx, int x_start);
void	wall_color(t_mlx *mlx, int y, int x_start);
int	rendering(t_mlx *mlx);
int	key_press(int keycode, t_mlx *mlx);
void	key_w(t_mlx *mlx);
void	key_s(t_mlx *mlx);
void	key_a(t_mlx *mlx);
void	key_d(t_mlx *mlx);
void	key_left(t_mlx *mlx);
void	key_right(t_mlx *mlx);

int		get_next_line(int fd, char **line);
int		is_new_line(char *s);
int		ft_strlen(char *s);
int		ft_sstrlen(char **s);
char	*ft_strldup(char *s1, int start, int end);
char	*ft_strldup_file(char *s1, int start, int end);
char	*ft_strdup(char *s1);
char	*ft_strjoin(char *s1, char *s2);
int	ft_wordcount(char *s, char c);
void	ft_strcpy(char *arr, char *start, char *end);
char	**ft_split(char *s, char c);
void	validation(char *str);
int	ft_atoi(char *str);
#endif
