/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khmessah <khmessah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 19:49:04 by khmessah          #+#    #+#             */
/*   Updated: 2024/10/12 22:04:50 by khmessah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_3D
# define CUBE_3D

# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 300
# endif

# define LEFT 97
# define RIGHT 100
# define ABOVE 119
# define LOWEST 115
# define RADIAN 0.0174533
# define SPEED 5
# define MINIMAP_SIZE 150
# define TILE_SIZE 60
# define WIDTH 1000
# define HEIGHT 500
# define SQUARE_SIZE 150
# define PLAYER_SIZE 3
# define WEAPONS 3
# define VECTOR 50
# define RAD (30 * M_PI / 180)
# define VIEW (WIDTH * 60 / 180)

typedef struct s_data
{
	void				*mlx_ptr;
	void				*win_ptr;
	void				*img_ptr;
	char				*img_data;
	int					bpp;
	int					size_line;
	int					endian;
}						t_data;

typedef struct s_garbage
{
	void				*data;
	struct s_garbage	*next;
}						t_garbage;

typedef struct s_image
{
	void				*xpm_ptr;
	void				*image;
	int					w;
	int					h;
	int					endn;
	int					bet_pxl;
	int					size_line;
}						t_image;

typedef struct s_start_images
{
	void				*xpm_ptr;
}						t_start_images;

typedef struct s_info
{
	double				step;
	int					color;
	double				lenght;
	double				point_depart;
	t_image				texture[6];
	t_image				esp;
	int					f_color_int;
	int					c_color_int;
	int					door_stat;
	char				*image;
	int					endn;
	int					bet_pxl;
	int					size_line;
	double				dir_x;
	double				dir_y;
	int					flag;
	void				*mlx;
	void				*img;
	void				*mlx_win;
	char				*save;
	int					bits_per_pixel;
	int					line_length;
	int					endian;
	int					size_map;
	char				**maps;
	int					ac;
	char				*map_name;
	char				*path_no;
	char				*path_so;
	char				*path_we;
	char				*path_ea;
	char				*ceiling_color;
	char				*floor_color;
	int					*c;
	int					*f;
	int					tmp;
	int					check;
	int					last_line;
	int					width;
	char				**av;
	double				x_p;
	double				y_p;
	double				angle;
	char				player;
	double				distance_ay;
	double				distance_ax;
	double				distance_tx;
	double				distance_ty;
	double				intersection_x;
	double				intersection_y;
	double				hitwall_hor_y;
	double				hitwall_hor_x;
	double				hitwall_vir_y;
	double				hitwall_vir_x;
	char				**f_color;
	char				**c_color;
	int					w;
	int					h;
	int					move;
	double				size;
	int					var;
	int					offset_x;
	int					offset_y;
	t_garbage			*garbage;
	t_start_images		start_images[4];
	double				square_color;
	int					gun;
	t_image				images[WEAPONS][10];
	int					index_x;
	int					index_y;
	int					door_flag[2];

}	t_info;

void	put_pixels_as_image(t_info *info, int i, int j, long color);
void	my_mlx_pixel_put(t_info *info, int x, int y, int color);
void	set_pic(t_info *info);
void	calcul_offset(t_info *info);
void	animation(t_info *info);
int		ft_isdegit(char c);
int		strlen_pro(char *str, char flag);
int		check_vergule(char *str, int **tab, t_info *info);
int		ft_atoi_s(const char *str);
int		check_colors(t_info *info);
int		ft_atoi(char *str, int i, int sign);
void	size_maps(t_info *info, int fd);
void	read_maps(t_info *info);
int		check_ligne(char *maps);
int		ft_strcmp(char *s1, char *s2);
int		ft_strlen(char *str);
char	*strdup_new_map(char *str, t_info *info);
int		ft_strlen2(char *str);
char	*ft_strdup(char *str, t_info *info);
int		is_opened(t_info *info, char c, int *x);
void	drawing_floor(t_info *info, double z);
void	drawing_all_wall(t_info *info, double j);
void	drawing_skay(t_info *info, double z);
void	drawing_wall_horizantal(t_info *info, int flag, double j);
void	drawing_wall_vertical(t_info *info, int flag, double j);
void	init_texture(t_info *info);
int		check_valide_mur(t_info *info);
int		check_element_maps(t_info *info);
void	*checker(t_info *info, void *data);
void	init_start_images(t_info *info);
void	render_minimap(t_info *info);
double	norm(double angle);
int		create_trgb(int t, int r, int g, int b);
int		move_player(int c, t_info *info);
void	compare_distance(t_info *info, double angle);
void	check_intersections_hor(t_info *info, double angle);
void	check_intersections_vir(t_info *info, double angle);
void	draw_square(t_info *info);
void	draw_vector(t_info *info);
void	my_mlx_pixel_put(t_info *info, int x, int y, int color);
void	put_pixels_as_image(t_info *info, int i, int j,
			long color);
void	calcul_distance(t_info *info, double angle);
void	init_window(t_info *info);
void	conditions(t_info *info, double angle);
void	init_angle(t_info *info, char c);
int		rendering_2d(t_info *info);
void	draw_vector(t_info *info);
int		is_player(char c);
int		is_space(char c);
void	my_mlx_pixel_put(t_info *info, int x, int y, int color);
int		ft_exit(void);
void	init_window(t_info *info);
int		rendering_2d(t_info *info);
void	put_pixels_as_image(t_info *info, int i, int j,
			long color);
int		ft_strlen2(char *str);
char	*strdup_new_map(char *str, t_info *info);
char	*get_next_line(int fd, t_info *info);
char	*ft_strdup(char *str, t_info *info);
char	*ft_strjoin(char *s1, char *s2, t_info *info);
int		ft_strlen(char *str);
int		ft_strcmp(char *s1, char *s2);
void	init_info(t_info *info, int ac, char **av);
void	ft_putstr(char *str);
void	print_error(char *str);
int		ft_atoi(char *str, int i, int sign);
void	read_maps(t_info *info);
int		check_ligne(char *maps);
int		check_collone(char *maps);
void	check_wall_valide(t_info *info);
void	check_nbr_player(t_info *info);
int		check_extention_map(t_info *info);
int		strcmp_path(char *s1, char *s2, int n);
int		is_space(char c);
char	*set_path(char *str);
int		strlen_pro(char *str, char flag);
void	check_textures_path(t_info *info);
int		the_biggest_line(t_info *info);
int		check_colors(t_info *info);
void	new_fnode(void *data, t_info *info);
void	free_list(t_info *info, int i);
void	*ft_malloc(size_t size, t_info *info);
char	**ft_split(char *s, char c, t_info *info);
int		check_vergule(char *str, int **tab, t_info *info);
int		is_map(char *str);
int		ft_check_crct(char *str);
int		check_valid_caractere(char c);

#endif