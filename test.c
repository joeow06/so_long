#include "minilibx_opengl_20191021/mlx.h"
#include <stdlib.h>

int main(void)
{
    void *mlx_ptr;
    void *win_ptr;

    // Initialize the MiniLibX connection
    mlx_ptr = mlx_init();
    if (!mlx_ptr)
        return (1); // If mlx_init fails, exit

    // Create a new window (width: 800, height: 600)
    win_ptr = mlx_new_window(mlx_ptr, 800, 600, "My Window");
    if (!win_ptr)
    {
        free(mlx_ptr); // Clean up the mlx pointer if window creation fails
        return (1);
    }

    // Destroy the window
    mlx_clear_window(mlx_ptr, win_ptr);
    mlx_destroy_window(mlx_ptr, win_ptr);

    // Free the MLX instance (optional in macOS)
    free(mlx_ptr);

    return (0);
}

