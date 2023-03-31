#include "so_long.h"

int main()
{
    char *str;

    int fd = open("test.txt", O_RDONLY);
    str = get_next_line(fd);
    ft_printf("%s", str);
    str = get_next_line(fd);
    ft_printf("%s", str);
    str = get_next_line(fd);
    ft_printf("%s", str);
    str = get_next_line(fd);
    ft_printf("%s", str);


}