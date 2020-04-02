/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cube3D.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-cit <tvan-cit@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/22 15:58:03 by tvan-cit       #+#    #+#                */
/*   Updated: 2020/03/26 13:58:32 by tim           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <limits.h>
# include <math.h>

# define BUFFER_SIZE 30

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
	void			*img_no;
	char			*addr_no;
	int				bits_per_pixel_no;
	int				line_length_no;
	int				endian_no;
	void			*mlx_no;
	int				img_width_no;
	int				img_height_no;
}					t_texture_no;

typedef struct		s_texture_so
{
	void			*img_so;
	char			*addr_so;
	int				bits_per_pixel_so;
	int				line_length_so;
	int				endian_so;
	void			*mlx_so;
	int				img_width_so;
	int				img_height_so;
}					t_texture_so;

typedef struct		s_texture_we
{
	void			*img_we;
	char			*addr_we;
	int				bits_per_pixel_we;
	int				line_length_we;
	int				endian_we;
	void			*mlx_we;
	int				img_width_we;
	int				img_height_we;
}					t_texture_we;

typedef struct		s_texture_ea
{
	void			*img_ea;
	char			*addr_ea;
	int				bits_per_pixel_ea;
	int				line_length_ea;
	int				endian_ea;
	void			*mlx_ea;
	int				img_width_ea;
	int				img_height_ea;
}					t_texture_ea;

typedef struct 		s_sprite
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	void			*mlx;
	int				img_width;
	int				img_height;
	float 			pos_wall[10];
	float 			eucl_dist[10];
	float 			step;
	int				count;
	float			sp_angle_l;
	float			sp_angle_r;
	
}					t_sprite;

typedef	struct		s_vars
{
	int				tile_width;
	int				tile_height;
	float			x;
	float			y;
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	void			*mlx;
	void			*win;
	int				img_width;
	int				img_height;
	float			mid_ray;
	float			mid_ray_x;
	float			mid_ray_y;
	t_list			*map;
	t_ray_data		*r;
	t_texture_no	*no;
	t_texture_so	*so;
	t_texture_we 	*we;
	t_texture_ea	*ea;
	t_sprite		*sp;
	void			*img2;
	char			*addr2;
	int				bits_per_pixel2;
	int				line_length2;
	int				endian2;
	void			*mlx2;
	void			*win2;
	int				res3d_h;
	int 			res3d_w;
	int				x_count;
}					t_vars;

int		main(int argc, char **argv);

// Functions GET NEXT LINE
int					get_next_line(int fd, char **line);
size_t				ft_strlen(const char *s);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strdup(const char *s1);
void				*ft_memmove(void *dst, const void *src, size_t len);
char				*ft_strchr(const char *s, int c);

// Function clear struct
void				clear_struct(t_list *map);

// Main function getting map
int					all_map_functions(t_list *map, int argc, char **argv);

// Functions getting top map data
int					get_map_info(char **line, t_list *map);
void				get_color(char **line, t_list *map);
int					convert_color(char **line);
void				get_resolution(char **line, t_list *map);
char				*get_texture(char **line);

// Functions getting bottom map data
int 				get_map(char **line, t_list *map);
int					convert_map(t_list *map);
char				*ft_strjoin_cube(char const *s1, char const *s2);
int					ft_strlen_and_line_check(int i, t_list *map);

// Functions checking if valid map
int					check_if_valid_map(t_list *map);
void				put_color_to_hex(t_list *map);
int					check_rgb(t_list *map);
int					check_2d_array(t_list *map);

//FUNCTIONS FOR RAYCASTING
void				find_wall(t_vars *t, t_ray_data *r);

// Drawing Labyrint
void				maze(t_list *map);
int					my_mlx_pixel_put(t_vars *t, int x, int y, int color);

//Drawing 3D
void 				main_world(t_vars *t, t_ray_data *r);
void				my_mlx_pixel_put3d(t_vars *t, int x, int y, int color);

// UTILS
void 				set_player_direction(t_vars *t, char c);
void				screen_cleaner(t_vars *t);
int					exit_program(t_vars *t);

//Textures
void    			texture_north(t_vars *t, t_ray_data *r);
void    			texture_south(t_vars *t, t_ray_data *r);
void    			texture_east(t_vars *t, t_ray_data *r);
void    			texture_west(t_vars *t, t_ray_data *r);
void    			initialize_textures(t_vars *t);

//Sprites
void    			initialize_sprites(t_vars *t);
void    			get_sprite_pos(t_vars *t, t_ray_data *r);
void    			draw_sprites(t_vars *t);

// Floor and Ceiling
void    			draw_floor_and_ceiling(t_vars *t, int y_count, int x_count);

//move player:
void				move_crab(t_vars *t, float move);
void				move_player(t_vars *t, float move);

#endif
