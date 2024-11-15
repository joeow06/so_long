#include "../inc/so_long.h"

int	main(int argc, char **argv)
{
	int	fd;
	char *line;

	printf("im in\n");
	fd = open("map.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file\n");
		return (1);
	}
	while(line == get_next_line(fd))
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
