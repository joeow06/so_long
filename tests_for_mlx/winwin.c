#include "../mlx/mlx.h"
#include <stdlib.h>

int main(void)
{
    void *mlx_ptr;
    void *win_ptr;
    void *img_ptr;

    // Initialize MiniLibX
    mlx_ptr = mlx_init();
    if (!mlx_ptr)
        return (1); // Handle error

    // Create a window
    win_ptr = mlx_new_window(mlx_ptr, 800, 600, "My Window");
    if (!win_ptr)
    {
        free(mlx_ptr); // Clean up in case window creation fails
        return (1);
    }

    // Create a new image
    img_ptr = mlx_new_image(mlx_ptr, 800, 600);
    if (!img_ptr)
    {
        mlx_destroy_window(mlx_ptr, win_ptr); // Clean up window before exiting
        free(mlx_ptr);
        return (1);
    }

    // [Add your code to work with the image here]

    // Destroy the image after use
    //mlx_destroy_image(mlx_ptr, img_ptr);

    // Destroy the window
    //mlx_destroy_window(mlx_ptr, win_ptr);

    // Free the MiniLibX instance (optional on macOS)
    //free(mlx_ptr);

    return (0);
}

