/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cube.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-cit <tvan-cit@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/22 15:58:03 by tvan-cit      #+#    #+#                 */
/*   Updated: 2020/04/23 19:53:31 by vancitters    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H
# define LOOK_LEFT 123
# define LOOK_RIGHT 124
# define MOVE_UP 13
# define MOVE_DOWN 1
# define MOVE_RIGHT 0
# define MOVE_UP2 126
# define MOVE_DOWN2 125
# define MOVE_LEFT 2
# define HALFPI 1.57079632679
# define PI 3.14159265359
# define ONEPFPI 4.71238898038
# define TWOPI 6.28318530718
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <limits.h>
# include <math.h>

typedef struct		s_list
{
	int				res_w;
	int				res_h;
	char			*no_texture;
	char			*so_texture;
	char			*we_texture;
	char			*ea_texture;
	char			*sprite_texture;
	int				f_color_red;
	int				f_color_green;
	int				f_color_blue;
	int				c_color_red;
	int				c_color_green;
	int				c_color_blue;
	unsigned long	f_hex;
	unsigned long	c_hex;
	char			*map_str;
	int				row_count;
	int				column_count;
	char			**map_2d;
	int				n_count;
	int				save;
	int				begin_map;
	int				comma;
}					t_list;

typedef struct		s_ray_data
{
	float			temp_x;
	float			temp_y;
	float			ray_dir;
	float			x_dir;
	float			y_dir;
	float			delta_x;
	float			delta_y;
	float			hit_x;
	float			hit_y;
	float			dist_x;
	float			dist_y;
	int				step_x;
	int				step_y;
	int				map_x;
	int				map_y;
	int				side;
	float			eucl_dist;
	float			perp_dist;
	float			pos_wall;
	float			dist;
}					t_ray_data;

typedef struct		s_texture_no
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	void			*mlx;
	int				img_width;
	int				img_height;
	int				img_h;
	int				h1;
	int				half_res_h;
	float			pix_height;
	int				height_text;
	int				y_count;
	float			text_step;
}					t_texture_no;

typedef struct		s_texture_so
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	void			*mlx;
	int				img_width;
	int				img_height;
	int				img_h;
	int				h1;
	int				half_res_h;
	float			pix_height;
	int				height_text;
	int				y_count;
	float			text_step;
}					t_texture_so;

typedef struct		s_texture_we
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	void			*mlx;
	int				img_width;
	int				img_height;
	int				img_h;
	int				h1;
	int				half_res_h;
	float			pix_height;
	int				height_text;
	int				y_count;
	float			text_step;
}					t_texture_we;

typedef struct		s_texture_ea
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	void			*mlx;
	int				img_width;
	int				img_height;
	int				img_h;
	int				h1;
	int				half_res_h;
	float			pix_height;
	int				height_text;
	int				y_count;
	float			text_step;
}					t_texture_ea;

typedef struct		s_sprite
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	void			*mlx;
	int				img_width;
	int				img_height;
	float			pos_wall[255];
	float			eucl_dist[255];
	float			step;
	int				count;
	float			sp_angle_l;
	float			sp_angle_r;
	float			pix_height;
	int				height_text;
	int				y_count;
	float			text_step;
	float			ray_start;
	float			sp_start;
	float			sp_step;
	float			ray_step;
	float			ray;
	float			i;
	int				img_h;
	int				h_res_h;
	int				h1;
}					t_sprite;

typedef	struct		s_vars
{
	// int				tile_width;
	// int				tile_height;
	float			x;
	float			y;
	// void			*img;
	// char			*addr;
	// int				bits_per_pixel;
	// int				line_length;
	// int				endian;
	// void			*mlx;
	// void			*win;
	// int				img_widthr;
	// int				img_height;
	float			mid_ray;
	float			mid_ray_x;
	float			mid_ray_y;
	t_list			*map;
	t_ray_data		*r;
	t_texture_no	*no;
	t_texture_so	*so;
	t_texture_we	*we;
	t_texture_ea	*ea;
	t_sprite		*sp;
	void			*img1;
	void			*img2;
	char			*addr1;
	char			*addr2;
	int				bits_per_pixel2;
	int				line_length2;
	int				endian2;
	void			*mlx2;
	void			*win2;
	int				res3d_h;
	int				res3d_w;
	int				x_count;
	int				screen_x;
	int				screen_y;
	float			mid_line;
	int				addr_count;
	float			move;
	float			turn;
	float			crab;
}					t_vars;

int					main(int argc, char **argv);

int					get_next_line(int fd, char **line);
int					ft_strlen(const char *str);
char				*ft_strjoin_gnl(char const *s1, char const *s2);
char				*ft_strdup(const char *src);
void				*ft_memmove(void *dst, const void *src, size_t len);
char				*ft_strchr(const char *s, int c);

void				initialize_ray_struct(t_ray_data *r);
void				clear_struct(t_list *map);

int					all_map_functions(t_list *map, int argc, char **argv);

int					get_map_info(char *line, t_list *map);
int					get_color(char *line, t_list *map);
int					convert_color(char *line, int *i, t_list *map);
int					check_character(t_list *map, char c);
int					get_resolution(char *line, t_list *map);
int					get_texture(char *line, t_list *map, char c);

int					get_map(char *line, t_list *map);
int					check_if_valid_map(t_list *map);
char				*ft_strjoin_cube(char *s1, char *s2);
int					ft_strlen_and_line_check(int i, t_list *map);

int					check_if_valid_info(t_list *map);
void				put_color_to_hex(t_list *map);
int					check_rgb(t_list *map);
int					check_2d_array(t_list *map);

void				find_wall(t_vars *t, t_ray_data *r);

void				maze(t_list *map, t_vars *t);
void				draw_map(t_vars *t);

void				main_world(t_vars *t, t_ray_data *r);
void				my_mlx_pixel_put3d(t_vars *t, int x, int y, int color);

void				set_player_direction(t_vars *t, char c);
void				screen_cleaner(t_vars *t);
int					exit_program(t_vars *t);
void				set_tile_width_and_height(t_vars *t);
int					put_str(char *str, int num);
char				**free_willy(char **newstr, int i_n);
void				convert_2d_array(t_list *map);
void				find_step(t_vars *t, t_ray_data *r);
int					check_end_line(char *line, int *i);
int					check_character_info(char *line, t_list *map);
void				skip_beginning(char **line, t_list *map);
int					check_double_path(t_list *map, char c);
int					convert_color(char *line, int *i, t_list *map);
int					leave_game(t_vars *t);
void				shoot_rays(t_vars *t);
void				draw_ray(float ray_angle, t_vars *t);
int					check_double_color_ceiling(t_list *map);
int					check_double_color_floor(t_list *map);
int					fill_floor_color(char *line, t_list *map, int *i);
int					fill_ceiling_color(char *line, t_list *map, int *i);
int					check_color_value_ceiling(t_list *map);
int					check_color_value_floor(t_list *map);
int					convert_res_height(char **line, t_list *map);
int					convert_res_width(char **line, t_list *map);
void				hit_sprite_x2(t_vars *t, t_ray_data *r);
void				rotate_player(float rot, t_vars *t);

void				make_bmp(char *name, char *addr, int width, int height);

void				texture_north(t_vars *t, t_ray_data *r);
void				texture_south(t_vars *t, t_ray_data *r);
void				texture_east(t_vars *t, t_ray_data *r);
void				texture_west(t_vars *t, t_ray_data *r);
void				texture_north2(t_vars *t);
void				texture_south2(t_vars *t);
void				texture_east2(t_vars *t);
void				texture_west2(t_vars *t);
int					initialize_textures(t_vars *t);

int					initialize_sprites(t_vars *t);
void				get_sprite_pos(t_vars *t, t_ray_data *r);
void				draw_sprites(t_vars *t);
int					initialize_data(t_vars *t, t_list *map);
void				init_angles(t_vars *t, t_ray_data *r);

void				draw_floor_and_ceiling(t_vars *t, int y_count, int x_count);

void				move_crab(t_vars *t, float move);
void				move_player(t_vars *t, float move);

#endif
