#include "../inc/so_long.h"

// Helper function to update a specific tile
void update_tile(t_map *map, int x, int y)
{
    if (map->array[y][x] == '1')
        mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img.wall,
            x * IMG_PXL, y * IMG_PXL);
    else if (map->array[y][x] == 'C')
        mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img.collectible,
            x * IMG_PXL, y * IMG_PXL);
    else if (map->array[y][x] == 'E')
        mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img.exit,
            x * IMG_PXL, y * IMG_PXL);
    else
        mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img.floor,
            x * IMG_PXL, y * IMG_PXL);
}

// Function to handle player movement and render updates
void move_player(t_map *map, int new_x, int new_y)
{
    // Redraw the previous player position
    update_tile(map, map->player.x, map->player.y);

    // Update the player's position in the map data
    map->array[map->player.y][map->player.x] = '0'; // Clear the previous tile
    map->player.x = new_x;
    map->player.y = new_y;
    map->array[new_y][new_x] = 'P'; // Set the new tile

    // Redraw the player at the new position
    mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img.player,
        new_x * IMG_PXL + 8, new_y * IMG_PXL);
}

// Movement logic for each direction
void move_up(t_map *map)
{
    int new_x = map->player.x;
    int new_y = map->player.y - 1;

    if (new_y >= 0 && map->array[new_y][new_x] != '1')
    {
        if (map->array[new_y][new_x] == 'E' && map->c == 0)
        {
            printf("WON\n");
            ft_won(map);
            return;
        }
        if (map->array[new_y][new_x] == 'C')
            map->c--; // Collect item

        move_player(map, new_x, new_y);
        map->moves++;
        print_movements(map);
    }
}

void move_down(t_map *map)
{
    int new_x = map->player.x;
    int new_y = map->player.y + 1;

    if (new_y < map->y && map->array[new_y][new_x] != '1')
    {
        if (map->array[new_y][new_x] == 'E' && map->c == 0)
        {
            printf("WON\n");
            ft_won(map);
            return;
        }
        if (map->array[new_y][new_x] == 'C')
            map->c--; // Collect item

        move_player(map, new_x, new_y);
        map->moves++;
        print_movements(map);
    }
}

void move_left(t_map *map)
{
    int new_x = map->player.x - 1;
    int new_y = map->player.y;

    if (new_x >= 0 && map->array[new_y][new_x] != '1')
    {
        if (map->array[new_y][new_x] == 'E' && map->c == 0)
        {
            printf("WON\n");
            ft_won(map);
            return;
        }
        if (map->array[new_y][new_x] == 'C')
            map->c--; // Collect item

        move_player(map, new_x, new_y);
        map->moves++;
        print_movements(map);
    }
}

void move_right(t_map *map)
{
    int new_x = map->player.x + 1;
    int new_y = map->player.y;

    if (new_x < map->x && map->array[new_y][new_x] != '1')
    {
        if (map->array[new_y][new_x] == 'E' && map->c == 0)
        {
            printf("WON\n");
            ft_won(map);
            return;
        }
        if (map->array[new_y][new_x] == 'C')
            map->c--; // Collect item

        move_player(map, new_x, new_y);
        map->moves++;
        print_movements(map);
    }
}

// Initial rendering of the entire map
void render_map(t_map *map)
{
    int x;
    int y;

    y = 0;
    while (y < map->y)
    {
        x = 0;
        while (x < map->x)
        {
            update_tile(map, x, y);
            x++;
        }
        y++;
    }

    // Render the player at the initial position
    mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img.player,
        map->player.x * IMG_PXL + 8, map->player.y * IMG_PXL);
}

