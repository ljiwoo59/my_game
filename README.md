# my_game
Recoding Wolfenstein 3D

<img width="638" alt="스크린샷 2021-06-29 오후 3 58 12" src="https://user-images.githubusercontent.com/54715744/123751569-d8728080-d8f2-11eb-80ce-b7108e924328.png">

## MiniLibX
[A Simple graphical interface library.](https://qst0.github.io/ft_libgfx/man_mlx.html)

#### *void \*mlx_init()*
* Initializes the connection between software and display.
* Returns a *void\* connection identifier* if successful, otherwise returns NULL.

#### *void \*mlx_new_window(void \*mlx_ptr, int size_x, int size_y, char \*title)*
* Creates a new window on a screen with *size_x* and *size_y* as a width and height, *title* as a text displayed in the window's title bar.
* Returns a *void\* window identifier* if successful, otherwise returns NULL.

#### *void \*mlx_new_image(void \*mlx_ptr, int width, int height)*
* Creates a new image in memory.
* Returns a *void\* image identifier* if successful, otherwise returns NULL.

#### *void \*mlx_xpm_file_to_image(void \*mlx_ptr, char \*filename, int \*width, int \*height)*
* Creates a new image in memory using specified filename.
  - Width and height of the image will be stored.

#### *char \*mlx_get_data_addr(void \*img_ptr, int \*bits_per_pixel, int \*size_line, int \*endian)*
* Returns a *char\* address* that represents the beginning of the memory area where the image is stored.
  - **img_ptr** : specifies an image to use.
  - **bits_per_pixel** : will be filled with the number of bits needed to represent a pixel color.
  - **size_line** : the number of bytes used to store one line of the image in memory.
  - **endian** : indicates whether the pixel color in the image needs to be stored in little endian or big endian.

#### *int mlx_put_image_to_window(void \*mlx_ptr, void \*win_ptr, void \*img_ptr, int x, int y)*
* Dumps the image inside a specified window in a specified x, y coordinates.

#### *int mlx_hook(void \*win_ptr, int x_event, int x_mask, int (\*funct_ptr)(), void \*param)*
* An infinite loop that waits for a specified event, then calls a user-defined function.
  - Param address will be passed to the function.

#### *int mlx_loop_hook(void \*mlx_ptr, int (\*funct_ptr)(), void \*param)*
* An infinite loop calling a user-defined function.

#### *int mlx_loop(void \*mlx_ptr)*
* An infinite loop.

#### *int mlx_destroy_image(void \*mlx_ptr, void \*img_ptr)*
* Destroys given image.

#### *int mlx_clear_window(void \*mlx_ptr, void \*win_ptr)*
* Clears given window.

#### *int mlx_destroy_window(void \*mlx_ptr, void \*win_ptr)*
* Destroys given window.

## Raycasting
A rendering technique to create a 3D perspective in a 2D map.

```c
typedef struct s_param
{
  double pos_x; // player x-position
  double pos_y; // player y-position
  double dir_x; // direction x-vector
  double dir_y; // direction y-vector
  
  double plane_x; // camera plane of player
  double plane_y; // should be perpendicular to direction vector
  
  double camera_x; // x-coordinate in camera space (-1 <= x <= 1)
  double ray_dir_x; // ray direction x-vector
  double ray_dir_y; // ray direction y-vector
  int map_x; // solid x-position of map
  int map_y; // soilid y-postion of map
  
  double side_dist_x; // initially a distance of ray from its start position to the first side
  double side_dist_y; // then indicates total distance of ray
  
  double delta_dist_x; // distance of ray from x-side to next x-side
  double delta_dist_y; // distance of ray from y-side to next y-side
  double perp_wall_dist; // distance to the wall projected on camera direction (avoiding fisheye effect)
  int step_x; // -1 if ray direction has negative x-component, 1 if positive x-component
  int step_y; // -1 if ray direction has negative y-component, 1 if positive y-component
  int hit; // 1 if wall is hit
  int side; // 0 if x-side is hit, 1 if y-side is hit
  int line_height; // height of wall to draw
  
  // will draw wall vertically
  double wall_x; // where exactly the wall was hit
  double step; // how much to increase the texture coordinate per screen pixel
  double tex_x; // x-coordinate of texture
  double text_y; // y-coordinate of texture
  double tex_pos; // starting texture coordinate
 }             t_param;
 ```
 
 ### Basic concept of DDA Algorithm
 [A loop that increments the ray with 1 square everytime until the ray hits a wall.](https://lodev.org/cgtutor/raycasting.html)
 
 ### Implementation of key events
 [X11 events and masks.](https://harm-smits.github.io/42docs/libs/minilibx/events.html)
 * W, S, A, D : move the position of player
 * Left arrow, right arrow : rotate the view
 * Esc, clicking x-button : Quit the program
 
 ## Map parsing
 <img width="233" alt="스크린샷 2021-06-29 오후 3 45 34" src="https://user-images.githubusercontent.com/54715744/123750050-15d60e80-d8f1-11eb-8450-6ed5cfe54ed0.png">

 * A first argument must be a description file with **.cub** extention.
 * Each element contains a type identifier and specific information.
   - NO  path to the north texture
   - SO  path to the south texture
   - WE  path to the west texture
   - EA  path to the east texture
   - F  R,G,B colors of floor in range \[0, 255]
   - C  R,G,B colors of ceiling in range \[0, 255]
 * Each element can be seperated by empty lines.
 * Each information from an element can be seperated by spaces.
 * Each element can be ordered randomly.
 * Map content always has to be the last.
 * Map content must composed by only 6 characters.
   - 0 : empty space
   - 1 : wall
   - N, S, W, E : player position and direction
 * Map must be surrounded by walls.

If any misconfiguration of any kind is encountered in the file or during the program, program exits properly and return "Error\n".

## References
* [Guide for 42 School Graphics Custom Library](https://qst0.github.io/ft_libgfx/man_mlx.html)
* [42Docs/Libs](https://harm-smits.github.io/42docs/libs/minilibx)
* [Lode's Computer Graphics Tutorial](https://lodev.org/cgtutor/raycasting.html)
