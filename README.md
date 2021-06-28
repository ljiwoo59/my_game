# my_game
Recoding Wolfenstein 3D

<img width="640" alt="스크린샷 2021-06-28 오후 7 40 49" src="https://user-images.githubusercontent.com/54715744/123623826-dbb13200-d848-11eb-9627-7f76ab9fb75a.png">

## MiniLibX
[A Simple graphical interface library.](https://qst0.github.io/ft_libgfx/man_mlx.html)

### *void \*mlx_init()*
* Initializes the connection between software and display.
* Returns a *void\* connection identifier* if successful, otherwise returns NULL.

### *void \*mlx_new_window(void \*mlx_ptr, int size_x, int size_y, char \*title)*
* Creates a new window on a screen with *size_x* and *size_y* as a width and height, *title* as a text displayed in the window's title bar.
* Returns a *void\* window identifier* if successful, otherwise returns NULL.

### *void \*mlx_new_image(void \*mlx_ptr, int width, int height)*
* Creates a new image in memory.
* Returns a *void\* image identifier* if successful, otherwise returns NULL.

### *void \*mlx_xpm_file_to_image(void \*mlx_ptr, char /*filename, int */width, int */height)*
* Creates a new image in memory using specified filename.
  - Width and height of the image will be stored.

### *char \*mlx_get_data_addr(void \*img_ptr, int \*bits_per_pixel, int \*size_line, int \*endian)*
* Returns a *char\* address* that represents the beginning of the memory area where the image is stored.
  - **img_ptr** : specifies an image to use.
  - **bits_per_pixel** : will be filled with the number of bits needed to represent a pixel color.
  - **size_line** : the number of bytes used to store one line of the image in memory.
  - **endian** : indicates whether the pixel color in the image needs to be stored in little endian or big endian.

### *int mlx_put_image_to_window(void \*mlx_ptr, void \*win_ptr, void \*img_ptr, int x, int y)*
* Dumps the image inside a specified window in a specified x, y coordinates.

### *int mlx_hook(void \*win_ptr, int keycode, int key_mask, int (\*funct_ptr)(), void \*param)*
* An infinite loop that waits for a specified event, then calls a user-defined function.
  - Param address will be passed to the function.

### *int mlx_loop_hook(void \*mlx_ptr, int (\*funct_ptr)(), void \*param)*
* An infinite loop calling a user-defined function.

### *int mlx_loop(void \*mlx_ptr)*
* An infinite loop.

### *int mlx_destroy_image(void \*mlx_ptr, void \*img_ptr)*
* Destroys given image.

### *int mlx_clear_window(void \*mlx_ptr, void \*win_ptr)*
* Clears given window.

### *int mlx_destroy_window(void \*mlx_ptr, void \*win_ptr)*
* Destroys given window.
